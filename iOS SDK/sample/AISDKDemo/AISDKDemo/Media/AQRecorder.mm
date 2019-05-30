//
//  BufferedRecorder.m
//  Dingdang
//
//  Created by RincLiu on 20/06/2017.
//  Copyright © 2017 tencent. All rights reserved.
//
#import "AQRecorder.h"
#import <AVFoundation/AVFoundation.h>

void AudioInputCallback(void* inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer, const AudioTimeStamp* inStartTime,
                        UInt32 inNumberPacketDescriptions, const AudioStreamPacketDescription* inPacketDescs) {

    //NSLog(@"AudioInputCallback start");
    if (inUserData == nil) {
        return;
    }
    AQRecorder *recorder = (__bridge AQRecorder *)inUserData;

    RecordState recordState = recorder.recordState;
    
    if (inNumberPacketDescriptions == 0 && recordState.dataFormat.mBytesPerPacket != 0) {
        inNumberPacketDescriptions = inBuffer->mAudioDataByteSize / recordState.dataFormat.mBytesPerPacket;
    }

    if (inBuffer->mAudioDataByteSize <= 0) {
        return;
    }
    if (recorder.delegate) {
        NSData *buffer = [NSData dataWithBytes:inBuffer->mAudioData length:inBuffer->mAudioDataByteSize];
        [recorder.delegate onInputVoice:buffer];
    }
    
    #ifdef DEBUG
    AudioFileWritePackets(recordState.audioFile, false, inBuffer->mAudioDataByteSize, inPacketDescs,
                                            recordState.currentPacket, &inNumberPacketDescriptions, inBuffer->mAudioData);
    #endif

    //NSLog(@"AudioQueueEnqueueBuffer inBuffer size = %d ,currentPacket = %d", (unsigned int)inBuffer->mAudioDataByteSize, (int)recordState.currentPacket);
    recordState.currentPacket += inNumberPacketDescriptions;
    if (!recordState.working) {
        return;
    }
    AudioQueueEnqueueBuffer(recordState.queue, inBuffer, 0, NULL);
    recorder.recordState = recordState;
    //NSLog(@"AudioInputCallback end");
}

void DeriveBufferSize(AudioQueueRef audioQueue, AudioStreamBasicDescription ASBDescription, Float64 seconds, UInt32 *outBufferSize) {
    static const int maxBufferSize = 0x50000;
    int maxPacketSize = ASBDescription.mBytesPerPacket;
    if (maxPacketSize == 0) {
        UInt32 maxVBRPacketSize = sizeof(maxPacketSize);
        AudioQueueGetProperty(audioQueue, kAudioConverterPropertyMaximumOutputPacketSize, &maxPacketSize, &maxVBRPacketSize);
    }
    
    Float64 numBytesForTime = ASBDescription.mSampleRate * maxPacketSize * seconds;
    *outBufferSize = (UInt32)((numBytesForTime < maxBufferSize) ? numBytesForTime : maxBufferSize);
}

@implementation AQRecorder

-(NSError*)start {
    if (_recordState.working == true) {
        NSLog(@"AQRecorder start isWorking!!!");
        return nil;
    }
    [self setupAudioFormat:&_recordState.dataFormat];
    
    OSStatus status = AudioQueueNewInput(&_recordState.dataFormat, AudioInputCallback, (__bridge void *)self, CFRunLoopGetCurrent(),
                                kCFRunLoopCommonModes, 0, &_recordState.queue);
    if (status == 0) {
        status = [self createAudioFile];
        if (status == 0) {
            DeriveBufferSize(_recordState.queue, _recordState.dataFormat, 0.5, &_recordState.bufferByteSize);
            
            for (int i = 0; i < BUFFER_NUM; i++) {
                AudioQueueAllocateBuffer(_recordState.queue, BUFFER_SIZE, &_recordState.buffers[i]);
                AudioQueueEnqueueBuffer(_recordState.queue, _recordState.buffers[i], 0, NULL);
            }
            
            UInt32 enableMetering = YES;
            AudioQueueSetProperty(_recordState.queue, kAudioQueueProperty_EnableLevelMetering, &enableMetering, sizeof(enableMetering));
            
            AVAudioSession* session = [AVAudioSession sharedInstance];
            NSError* err;
            [session setCategory:AVAudioSessionCategoryPlayAndRecord error:&err];
            if (err) {
                NSLog(@"AQRecorder setSessionCategory failed:%@", err.localizedDescription);
            }
            [session setActive:YES error:&err];
            
            status = AudioQueueStart(_recordState.queue, NULL);
            NSLog(@"start AudioQueueStart status = %d",(int)status);
            if (status == 0) {
                _recordState.currentPacket = 0;
                _recordState.working = true;
                return nil;
            }
        } else {
        
            NSLog(@"start createAudioFile status  = %d",(int)status);
        }
    } else {
        NSLog(@"start AudioQueueNewInput status = %d",(int)status);
    }
    
    return [NSError errorWithDomain:NSOSStatusErrorDomain code:status userInfo:nil];
}

-(BOOL)pause {
    return _recordState.queue && AudioQueuePause(_recordState.queue) == 0 ? YES : NO;
}

-(BOOL)resume {
    return _recordState.queue && AudioQueueStart(_recordState.queue, NULL) == 0 ? YES : NO;
}

-(NSData*)stop {
    if (_recordState.working) {
        _recordState.working = false;
        AudioQueueFlush(_recordState.queue);
        AudioQueueStop(_recordState.queue, true);
        for (int i = 0; i < BUFFER_NUM; i++) {
            AudioQueueFreeBuffer(_recordState.queue, _recordState.buffers[i]);
        }
        AudioQueueDispose(_recordState.queue, true);
        AudioFileClose(_recordState.audioFile);
        
        NSLog(@"AQRecorder stopped");
        
        return [NSData dataWithContentsOfURL:(__bridge NSURL*)mFileURL];
    }
    return nil;
}

-(BOOL)isRecording {
    return _recordState.working;
}

-(void)setupAudioFormat:(AudioStreamBasicDescription*)format {
    format->mSampleRate = 16000.0;
    format->mFormatID = kAudioFormatLinearPCM;
    format->mBitsPerChannel = 16;
    format->mFramesPerPacket = 1;
    format->mReserved = 0;
    format->mChannelsPerFrame = 1;
    format->mBytesPerPacket = format->mBytesPerFrame = 2 * format->mChannelsPerFrame;
    format->mFormatFlags = kLinearPCMFormatFlagIsPacked | kLinearPCMFormatFlagIsSignedInteger;
}

-(OSStatus)createAudioFile {
    NSLog(@"createAudioFile...");
    const UInt8* pFilePath = (const UInt8*)[[NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/recording.wav"] UTF8String];
    mFileURL = CFURLCreateFromFileSystemRepresentation(kCFAllocatorDefault, pFilePath, strlen((const char*)pFilePath), false);
    return AudioFileCreateWithURL(mFileURL, kAudioFileWAVEType, &_recordState.dataFormat,
                                    kAudioFileFlags_EraseFile, &_recordState.audioFile);
}

-(instancetype)init {
    if(self = [super init]) {
        _aqueue = dispatch_queue_create("aqueue", DISPATCH_QUEUE_SERIAL);
    }
    return self;
}

-(void)dealloc {
    NSLog(@"Recorder dealloc");
    if (mFileURL) {
        CFRelease(mFileURL);
    }
}

@end
