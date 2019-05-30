//
//  VoiceAssistant.m
//  AISDKDemo
//
//  Created by fredyfang(方义) on 2018/4/19.
//  Copyright © 2018年 Zacard Fang. All rights reserved.
//

#import "VoiceAssistant.h"

@interface VoiceAssistant()


@end

@implementation VoiceAssistant

+ (id)sharedInstance
{
    static VoiceAssistant *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init{
    if (self = [super init]){
        [self initSDK];
    }
    return self;
}

- (NSString *)prepareWakeupBufferDir {
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString* voiceDir = NULL;
    NSArray *documentDirectories = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    if ([documentDirectories count] > 0) {
        voiceDir = [[documentDirectories objectAtIndex:0] stringByAppendingPathComponent:@"wakeup_buffer"];
    }
    if (voiceDir == NULL) return voiceDir;
    
    if (![fileManager fileExistsAtPath:voiceDir]) {
        NSLog(@"VOICE DIR %@ DOES NOT EXISTS", voiceDir);
        [fileManager createDirectoryAtPath:voiceDir withIntermediateDirectories:YES attributes:nil error:NULL];
    }
    return voiceDir;
}

- (void)initSDK {
    NSString *app_key = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"AI_APPKEY"];
    NSString *acess_token = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"AI_ACCESSTOKEN"];
    NSString* identifier = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    _aisdk = [SpeechEngine sharedInstance:app_key acess_token:acess_token withDsn:identifier];
    NSLog(@"sdk version = %@", [_aisdk getSDKVersion]);
    
    [_aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME value:K_AISDK_CONFIG_VALUE_ENABLE];
    //[_aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO value:"1"];
    [_aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE value:"1000"];
    
    //上传唤醒音频相关配置
    //[_aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED value:"1"];
    [_aisdk setNetworkType:[self getNetWorkType]];
    _buffer_file_dir = [self prepareWakeupBufferDir];
    //设置路径要写在允许上传唤醒音频之后
    [_aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH value:[_buffer_file_dir UTF8String]];
    //[_aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE value:"1"];
    
    //fredy add
    [_aisdk setConfig:K_AISDK_CONFIG_ENV_TYPE value:K_AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL];
    // 识别模型设置,默认为手机
    [_aisdk setConfig:K_AISDK_CONFIG_ASR_DOMAIN value:"10"];
    
    //voice
    _voiceSession = [[VoiceSession alloc] init];
    [_aisdk addSession:_voiceSession];
    //semantic
    _semanticSession = [[SemanticSession alloc]init];
    [_aisdk addSession:_semanticSession];
    //tts
    _ttsSession = [[TtsSession alloc]init];
    [_aisdk addSession:_ttsSession];
    
    _wakeup = [[SpeechWakeup alloc] init];
    [_aisdk addSession:_wakeup];
    
}

- (int)getNetWorkType {
    //TODO: 此处要根据网络变化设置!!!
    return 1;
}


@end
