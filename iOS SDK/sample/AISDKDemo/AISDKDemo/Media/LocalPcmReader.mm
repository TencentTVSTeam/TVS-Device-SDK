//
//  LocalPcmReader.m
//  AISDKDemo
//
//  Created by Aimee on 27/4/2019.
//  Copyright © 2019 tencent. All rights reserved.
//
#import "LocalPcmReader.h"
#import <AVFoundation/AVFoundation.h>

@interface LocalPcmReader()
{
    __block BOOL _isWorking;//是否正在工作
    __block BOOL _isStoped;
    
}
@end

static NSMutableArray * pcmFileNames;
static int _currentIndex;

@implementation LocalPcmReader

//初始化文件路径
+ (void)initLocalFiles {
    NSString *filePath = [NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/voice_test"];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    BOOL isDir = FALSE;
    BOOL isDirExist = [fileManager fileExistsAtPath:filePath isDirectory:&isDir];
    if(!(isDirExist && isDir)) {
        
        BOOL bCreateDir = [fileManager createDirectoryAtPath:filePath withIntermediateDirectories:YES attributes:nil error:nil];
        if(!bCreateDir){
            NSLog(@"autoTest Create Audio Directory Failed.");
        }
        NSLog(@"autoTest %@",filePath);
    }
    
    NSString *audioFileNamePath = [NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/voice_test/file_lists.txt"];
    NSString *audioFileNameString = [NSString stringWithContentsOfFile:audioFileNamePath encoding:NSUTF8StringEncoding error:nil];
    NSArray *fileNameList = [audioFileNameString componentsSeparatedByString:@"\n"];
    pcmFileNames = [NSMutableArray array];
    for (int i = 0 ; i < fileNameList.count ; i ++) {
        NSString *fileName  = [fileNameList objectAtIndex:i];
        NSString *localName = [NSString stringWithFormat:@"%@/%@",filePath,fileName];
        if ([fileManager fileExistsAtPath:localName]) {
            NSLog(@"autoTest initLocalFiles localName = %@",localName);
            [pcmFileNames addObject:localName];
        }
    }
    
}
+(void)writeTestResult:(NSArray *)resultRecord {
    NSString *filePath = [NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/dingdang_test_result.txt"];
    [resultRecord writeToFile:filePath atomically:YES];
    
}
+(BOOL)hasTestFile {
    if (pcmFileNames == nil || pcmFileNames.count == 0) {
        return false;
    } else if (pcmFileNames.count == _currentIndex) {
        return false;
    } else {
        return true;
    }
}

+ (void)cleanAllData
{
    [pcmFileNames removeAllObjects];
    _currentIndex = 0;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _aqueue = dispatch_queue_create("reader_queue", DISPATCH_QUEUE_SERIAL);
    }
    return self;
}

- (void)start {
    _isWorking = true;
    _isStoped = false;
    [self run];
}

- (void)stop {
    _isWorking = false;
    _isStoped = true;
}

- (BOOL)isWorking {
    return _isWorking;
}

//线程执行过程中，循环调用
-(void)run {
    NSLog(@"autoTest run _isStoped = %d, _isWorking = %d",_isStoped, _isWorking);
    if (_isStoped) {
        NSLog(@"autoTest run stoped");
        return;
    }
    if (pcmFileNames.count) {
        NSLog(@"autoTest run _currentIndex = %d, _pcmFileNames.count = %lu",_currentIndex, (unsigned long)pcmFileNames.count);
        if (_currentIndex >= pcmFileNames.count) {
            _currentIndex = 0;
            return;
        }
        dispatch_async(_aqueue, ^{
            if (_isStoped) {
                return;
            }
            NSString *filePath = [pcmFileNames objectAtIndex:_currentIndex];
            NSLog(@"autoTest run filePath = %@",filePath);
            NSData *data = [[NSData alloc] initWithContentsOfURL:[NSURL fileURLWithPath:filePath]];
            if ([filePath  hasSuffix:@".wav"]) {
                NSLog(@"autoTest run wav");
                data = [data subdataWithRange:NSMakeRange(44, data.length-44)];
            }
            NSInteger locaction = 0;
            while (locaction < data.length) {
                NSData *subData = nil;
                if (locaction + BUFFER_SIZE <= data.length) {
                    subData = [data subdataWithRange:NSMakeRange(locaction, BUFFER_SIZE)];
                }else{
                    subData = [data subdataWithRange:NSMakeRange(locaction, data.length - locaction)];
                }

                if ([self.delegate respondsToSelector:@selector(localOnInputVoice:)]) {
                    [self.delegate localOnInputVoice:subData];
                }
                locaction += subData.length;
            }
            _currentIndex++;
            char nullData[BUFFER_SIZE] = "\0";
            NSData *buffer = [NSData dataWithBytes:&nullData length:BUFFER_SIZE];
            if ([self.delegate respondsToSelector:@selector(localOnInputVoice:)]) {
                [self.delegate localOnInputVoice:buffer];
            }
            });
    }
}



-(void)dealloc {
    NSLog(@"autoTest LocalPcmReader dealloc");
}

@end
