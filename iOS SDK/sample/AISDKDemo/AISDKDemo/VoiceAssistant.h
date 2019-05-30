//
//  VoiceAssistant.h
//  AISDKDemo
//
//  Created by fredyfang(方义) on 2018/4/19.
//  Copyright © 2018年 Zacard Fang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AISDK/AISDK.h>
#import "AQRecorder.h"
#import "TTSAudioPlayer.h"

#import "SemanticData.h"

#import "TtsFormater.h"

@interface VoiceAssistant : NSObject


@property(nonatomic, strong)SpeechEngine *aisdk;
@property(nonatomic, strong)VoiceSession *voiceSession;
@property(nonatomic, strong)SemanticSession *semanticSession;
@property(nonatomic, strong)TtsSession *ttsSession;
@property(nonatomic, strong)SpeechWakeup *wakeup;
@property(nonatomic, strong)NSString *buffer_file_dir;

+ (id)sharedInstance;



@end
