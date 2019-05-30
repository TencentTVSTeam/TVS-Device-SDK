//
//  LocalPcmReader.h
//  AISDKDemo
//
//  Created by Aimee on 27/4/2019.
//  Copyright © 2019 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

#define BUFFER_SIZE 4096
#define BUFFER_NUM 3


@protocol LocalPcmReaderDelegate <NSObject>
-(void)localOnInputVoice:(NSData *)data;
@end

@interface LocalPcmReader : NSObject{

}

@property(nonatomic, assign) id<LocalPcmReaderDelegate> delegate;

@property(nonatomic, strong) dispatch_queue_t aqueue;

+(void)initLocalFiles;

+(void)writeTestResult:(NSArray *)resultRecord;

+(BOOL)hasTestFile;

+ (void)cleanAllData;

-(void)start;

-(void)stop;

-(BOOL)isWorking;


@end
