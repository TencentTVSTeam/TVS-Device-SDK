//
//  SessionViewController.m
//  Dingdang
//
//  Created by ZACARDFANG on 2017/6/12.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import "DeveloperUIVC.h"
#import "VoiceAssistant.h"
#import <AVFoundation/AVFoundation.h>
#import "LocalPcmreader.h"

#define IS_NULL(x) (x == nil || [x isKindOfClass:[NSNull class]])
#define VOICE_MODE_WAKEUP 1
#define VOICE_MODE_RECOGNIZE 2

@interface DeveloperUIVC ()<VoiceSessionDelegate, SemanticSessionDelegate, TtsSessionDelegate, AQRecorderDelegate, TTSAudioPlayerDelegate, SpeechWakeupDelegate,LocalPcmReaderDelegate> {
    BOOL _customWakeupDetected;
    NSArray* _wakeupKeywords;
    
    NSArray* _testWavFiles;
    BOOL _autoTest;
    int _autoTestIndex;
    LocalPcmReader *_pcmReader;
    NSMutableArray *_testResult;
}

@property(nonatomic, assign)BOOL hadWakeup;
@property(nonatomic, assign)BOOL wakeupFailed;
@property(nonatomic, strong)AQRecorder *aqRecorder;
@property(nonatomic, strong)TTSAudioPlayer *ttsAudioPlayer;
@property(nonatomic, strong) VoiceAssistant *voiceAssitant;
//@property(nonatomic, strong) OneshotSession* oneshotSession;

//暂不支持离线语音识别
//@property(nonatomic, strong) VoiceOfflineSession* customWakeupSession;

@property(nonatomic, strong)NSString *voiceResultText;

@property(nonatomic, strong)NSMutableString * displayLog;

@property(nonatomic, readwrite) int voiceMode;

@property (strong, nonatomic) IBOutlet UITextField *tv_context;
@property (strong, nonatomic) IBOutlet UITextField *tv_type;
@property (weak, nonatomic) IBOutlet UIButton *setContextBtn;

@end

@implementation DeveloperUIVC

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"viewDidLoad");
    // Do any additional setup after loading the view.
    //录音
    _aqRecorder = [[AQRecorder alloc] init];
    _aqRecorder.delegate = self;
    
    //播报
    _ttsAudioPlayer = [TTSAudioPlayer shared];
    _ttsAudioPlayer.delegate = self;
    
    [self initRecorderView];
    _displayLog = [[NSMutableString alloc] init];
    
    [self initData];
//    _testWavFiles = [self prepareAutoTest];
//    NSLog(@"viewDidLoad _testWavFiles = %@", _testWavFiles);
    if (_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
        _voiceMode = VOICE_MODE_WAKEUP;
        [self onRecorderClick];
    }
}

- (void) viewDidDisappear:(BOOL)animated {
    NSLog(@"VIEW DID DISAPEAR");
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)initData {
   
    _voiceAssitant = [VoiceAssistant sharedInstance];
    
    [_voiceAssitant.wakeup setDelegate:self];
    
    NSString *modelPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"keywords_model.bundle"];
    int ret = 0;
    
    if (_serviceType == SERVICE_TYPE_VOICE_WAKEUP || _serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
        ret = [_voiceAssitant.wakeup initOfflineWakupWithPath:modelPath.UTF8String];
        NSLog(@"initSDK initOfflineWakupWithPath ret=%d, path=%@.", ret, modelPath);
        if (ret > 0) {
            _wakeupFailed = YES;
            [self showAlertDialog:@"initOfflineWakupWithPath" withErrNo:ret];
        }
        
        ret = [_voiceAssitant.wakeup startOfflineWakupWithData:nil withLength:0 withFlags:0];
        NSLog(@"startOfflineWakupWithData ret=%d.", ret);
        if (ret > 0) {
            _wakeupFailed = YES;
            [self showAlertDialog:@"startOfflineWakupWithData" withErrNo:ret];
        }
    }
    //voice
    //[_voiceSession setDelegate:self];
    [_voiceAssitant.voiceSession setDelegate:self];
    NSString *vadModelPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"vad_model.bundle"];
    
    ret = [_voiceAssitant.voiceSession initOnlineVoice2TextWithPath:vadModelPath.UTF8String];
    NSLog(@"initSDK initOfflineOnlineWithPath ret = %d, path=%@.", ret, vadModelPath);
    //semantic
    [_voiceAssitant.semanticSession setDelegate:self];
    
    //tts
    [_voiceAssitant.ttsSession setDelegate:self];
    
    //wakeup
    //[_wakeup setDelegate:self];
    
    if (_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
        [self onRecorderClick];
    }
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)initRecorderView {
    [_mRecorderView setDelegate:self];
    [_mRecorderView setRecorderStatus:STATUS_NORMAL msg:@"点击开始录音"];
    [_mRecorderView setMsgTextHidden:NO];
    
    if (_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
        [_mRecorderView setTouchEnabled:FALSE];
    }
}

-(void)semantic {
    if (_serviceType == SERVICE_TYPE_VOICE2WORDS) {
        [self appendToDisplay:[NSString stringWithFormat:@"语音转文字：%@", _voiceResultText]];
        if (_autoTest) {
            //如果是自动化测试，就继续识别下一条
            //[self onRecorderClick];

        }
        return;
    }
    if (_serviceType == SERVICE_TYPE_VOICE_WAKEUP) {
        [self appendToDisplay:[NSString stringWithFormat:@"语音唤醒：failed"]];
        return;
    }
    
    if (_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
        
        [self appendToDisplay:@"语音识别结束，等待唤醒中..."];
        
        return;
    }
    if (_voiceResultText != nil && _voiceResultText.length > 0) {
        [_voiceAssitant.semanticSession text2semantic:_voiceResultText userData:self flags:0];// flags:K_AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION];
    }
}

#pragma mark RecorderViewDelegate
- (void)onRecorderClick{
    if (_autoTest) {
        if ([LocalPcmReader hasTestFile]) {
            NSLog(@"autoTest onRecorderClick start one test");
        } else {
            NSLog(@"autoTest onRecorderClick end _testResult = %@", _testResult);
            [LocalPcmReader writeTestResult:_testResult];
            return;
        }
        if (self->_serviceType == SERVICE_TYPE_VOICE2WORDS) {
            NSLog(@"autoTest VOICE2WORDS start");
            _pcmReader = [[LocalPcmReader alloc] init];
            _pcmReader.delegate = self;
            [self->_voiceAssitant.voiceSession cancelVoice2Text];
            [self->_voiceAssitant.voiceSession startVoice2text:0];
            [self appendToDisplay:@"开始读取"];
            
        }
        return;
    }
    
    [[AVAudioSession sharedInstance] requestRecordPermission:^(BOOL granted) {
    dispatch_async(dispatch_get_main_queue(), ^{
        if (granted) {
            int status = [self->_mRecorderView currentStatus];

            NSLog(@"onRecorderClick start status = %d, serviceType = %d, voiceMode = %d", status,self->_serviceType, self->_voiceMode);
            if (status == STATUS_NORMAL || status == STATUS_EXCEPTION) {
            // 停止播报
                [self->_ttsAudioPlayer clearAll];

            // 如果是固定唤醒，就不启动识别
                if (self->_serviceType != SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
                    if (self->_serviceType == SERVICE_TYPE_VOICE_WAKEUP) {
                        dispatch_async(dispatch_get_main_queue(), ^{
                            [self->_aqRecorder start];
                        });
                    } else {
                        [self->_voiceAssitant.voiceSession cancelVoice2Text];
                        [self->_voiceAssitant.voiceSession startVoice2text:0];
                    }
                } else {
                    if (self->_voiceMode == VOICE_MODE_WAKEUP) {
                        dispatch_async(dispatch_get_main_queue(), ^{
                            [self->_aqRecorder start];
                        });
                    } else if (self->_voiceMode == VOICE_MODE_RECOGNIZE){
                        //测试双通道，不主动取消，底层会cancel
                        //[self->_voiceAssitant.voiceSession cancelVoice2Text];
                        [self->_voiceAssitant.voiceSession startVoice2text:0];
                    }
                }
                // && self->_serviceType != SERVICE_CUSTOM_WAKEUP
                if (self->_serviceType != SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
                    [self clearToDisplay];
                }

            [self appendToDisplay:@"开始录音"];
                [self->_aqRecorder start];
                [self setRecordStatus:STATUS_LOADING msg:@""];
            }
        } else {
            [self showAlertDialog:@"未开启录音权限" withErrNo:-1];
        }
    });

    NSLog(@"onRecorderClick end");
    }];
}

- (void)setRecordStatus:(NSInteger)status msg:(NSString *)msg{
    [_mRecorderView setRecorderStatus:status msg:msg];
}

#pragma mark log
- (void)appendToDisplay:(NSString *)content {
    [_displayLog appendString:content];
    [_displayLog appendString:@"\n"];
    [self onDisplayChanged: _displayLog];
}

- (void)clearToDisplay {
    [_displayLog setString:@""];
    [self onDisplayChanged: _displayLog];
}

- (void)onDisplayChanged:(NSString *)content{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->_tv_log setText:content];
        
        [self->_tv_log scrollRangeToVisible:NSMakeRange(self->_tv_log.text.length - 1, 1)];
    });
    
}

#pragma mark VoiceSessionDelegate
-(void)onOnlineVocieCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData{
    NSLog(@"onOnlineVocieCallback cmd=%ld.", (long)cmd);
    dispatch_async(dispatch_get_main_queue(), ^{
        if (cmd == K_AISDK_CMD_ONLINE_RECO_START){
            // 在线识别开始，接受录音数据
            [self appendToDisplay:@"在线识别开始"];
            if (_autoTest && self->_serviceType == SERVICE_TYPE_VOICE2WORDS) {
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    [_pcmReader start];
                });
                
                return;
            }
            if (self->_serviceType != SERVICE_ONESHOT) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self->_aqRecorder start];
                });
            }
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_SPEECH_START){
            // 在线语音VAD检测到开始
            [self appendToDisplay:@"VAD检测到开始"];
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_SUCCESS){
            // 在线语音VAD检测到开始
            [self appendToDisplay:@"获取语音识别Session成功，标识云端已为始语音识别做好准备"];
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_SPEECH_END){
            // 在线语音vad检测完成，可以停止输入录音数据
            if (self->_serviceType != SERVICE_ONESHOT) {
                [self appendToDisplay:@"识别完成，可以停止输入录音数据"];
                if (_autoTest && self->_serviceType == SERVICE_TYPE_VOICE2WORDS) {
                    [_pcmReader stop];
                    return;
                }
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self->_aqRecorder stop];
                    [self setRecordStatus:STATUS_NORMAL msg:self->_voiceResultText];
                });
            } else {
                [self appendToDisplay:@"识别完成"];
            }
            
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_RESULT){
            // 返回在线识别结果
            if (self->_serviceType != SERVICE_ONESHOT) {
                NSLog(@"语音识别完成,返回结果：%@", data);
                if (_autoTest && self->_serviceType == SERVICE_TYPE_VOICE2WORDS) {
                    [_testResult addObject:data];
                    [_pcmReader stop];
                    [self appendToDisplay:[NSString stringWithFormat:@"识别结果：%@", data]];
                    
                    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                        [self onRecorderClick];
                    });
                    
                    return;
                }
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self->_aqRecorder stop];
                    [self setRecordStatus:STATUS_NORMAL msg:self->_voiceResultText];
                    
                    if (self->_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
                        self->_voiceMode = VOICE_MODE_WAKEUP;
                        [self onRecorderClick];
                    }
                });
                
                self->_voiceResultText = data;
                [self->_mRecorderView setMsgText:self->_voiceResultText];
                
                [self appendToDisplay:[NSString stringWithFormat:@"识别结果：%@", data]];
                [self semantic];
                NSLog(@"%@", [SpeechEngine.getInitedInstance getSDKVersion]);
            } else {
                //oneshot
                NSLog(@"语音识别完成：%@", data);
                self->_voiceResultText = data;
                [self->_mRecorderView setMsgText:self->_voiceResultText];
                
                [self appendToDisplay:[NSString stringWithFormat:@"oneshot 识别结果：%@", data]];
                //[self semantic];
            }
            
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT){
            // 上报在线识别的中间结果
            NSLog(@"语音识别中：%@", data);
            if (!_autoTest) {
                self->_voiceResultText = data;
                [self->_mRecorderView setMsgText:self->_voiceResultText];
            }

        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_DATA_VOLUME){
            // 上报输入音频数据的音量值
            NSLog(@"RECO_DATA_VOLUME value：%f", [data floatValue]);
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_CANCELED){
            if (!_autoTest && self->_serviceType != SERVICE_ONESHOT) {
            // 已取消在线识别
                [self appendToDisplay:@"已取消在线识别"];
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self->_aqRecorder stop];
                    [self setRecordStatus:STATUS_NORMAL msg:self->_voiceResultText];
                });
            }
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_FAILURE){
            if (!_autoTest && self->_serviceType != SERVICE_ONESHOT) {
                // 获取语音识别Session失败，本次语音识别还未开始就结束了
                [self appendToDisplay:@"获取语音识别Session失败，本次语音识别还未开始就结束了"];
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self->_aqRecorder stop];
                    [self setRecordStatus:STATUS_NORMAL msg:self->_voiceResultText];
                });
            }
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_ERROR) {
            [self appendToDisplay:[NSString stringWithFormat:@"出现错误 %ld", (long)code]];
            if (!_autoTest) {
                
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self->_aqRecorder stop];
                    [self setRecordStatus:STATUS_NORMAL msg:self->_voiceResultText];
                });
            }
        }
        
    });
}

-(void)onOnlineVocieError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSString *msg = message;
        if (cmd == K_AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT) {
            msg = @"本地VAD检测静音超时";
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT) {
            msg = @"在线识别服务端无结果";
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_TIMEOUT) {
            msg = @"在线识别超时，没有识别到有效输入";
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_ERROR) {
            msg = @"在线识别出错";
        }
        
        [self appendToDisplay:[NSString stringWithFormat:@"onOnlineVocieError cmd =%ld, message=%@", (long)cmd, msg]];
        [self setRecordStatus:STATUS_NORMAL msg:self->_voiceResultText];
        if (_autoTest) {
            [_testResult addObject:[NSString stringWithFormat:@"onOnlineVocieError cmd =%ld, message=%@", (long)cmd, msg]];
            [self onRecorderClick];
        } else {
            [self->_aqRecorder stop];
            if (self->_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
                self->_voiceMode = VOICE_MODE_WAKEUP;
                [self onRecorderClick];
            }
        }
    });
}

#pragma mark SemanticSessionDelegate
-(void)onOnlineSemanticCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData {
    NSLog(@"onOnlineSemanticCallback cmd = %ld", (long)cmd);
    // 语义回调，解析业务场景
    [self appendToDisplay:[NSString stringWithFormat:@"语义回调结果：%@", data]];
    if (K_AISDK_CMD_SEMANTIC_RESULT == cmd && self.serviceType == SERVICE_TYPE_VOICE_ASSISTANT) {
        SemanticData *sd = [SemanticData valueFromJson:data];
        // 处理业务，此处直接演示tts功能
        if (sd.speakText && ![sd.speakText isEqualToString:@""]) {
            [_voiceAssitant.ttsSession text2Speech:sd.speakText userData:self];
        } else {
            [_voiceAssitant.ttsSession text2Speech:sd.tipsText userData:self];
        }
    } else {
        //NO TTS, DO NOTHING
    }
}

- (void)onOnlineSemanticError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData {
    [self appendToDisplay:[NSString stringWithFormat:@"语义回调错误：%@", message]];
}

#pragma mark TtsSessionDelegate
-(void)onOnlineTtsCallback:(NSInteger)cmd code:(NSInteger)code pcm:(NSData *)pcm userData:(id)userData{
    if (pcm) {
        // 转换pcm格式为wav格式播放，也可调用系统AudioQueue播放pcm
        [_ttsAudioPlayer addData:[TtsFormater translatePcm2Wav:pcm]];
    }
}

-(void)onOnlineTtsError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData{
    //NSLog(@"tts error cmd:%ld data:%@", cmd, data);
}

#pragma mark AQRecorderDelegate
-(void)onInputVoice:(NSData *)data {
    //if (!_hadWakeup && !_wakeupFailed) {
    /*
    if (_serviceType == SERVICE_CUSTOM_WAKEUP) {
        int ret = [_customWakeupSession appendAudioData:data];
        return;
       
    }
    if (_serviceType == SERVICE_COMBINE_WAKEUP) {
        //NSLog(@"onInputVoice at SERVICE_COMBINE_WAKEUP");
        [_voiceAssitant.wakeup inputOfflineWakeupAudioData:data.bytes withLength:data.length];
        [_customWakeupSession appendAudioData:data];
        
        return;
    }
      */
    if (_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE) {
        //双通道输入测试
        //NSLog(@"onInputVoice at SERVICE_TYPE_WAKEUP_AND_RECOGNIZE _voiceMode = %d", _voiceMode);
        if (_voiceMode == VOICE_MODE_RECOGNIZE) {
            [_voiceAssitant.voiceSession inputVoice2TextAudioData:data];
        }
        [_voiceAssitant.wakeup inputOfflineWakeupAudioData:data.bytes withLength:data.length];
    } else if (_serviceType == SERVICE_TYPE_VOICE_WAKEUP /*|| (_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE && _voiceMode == VOICE_MODE_WAKEUP)*/) {
        //不需要主动往唤醒模块传数据，底层识别模块会往唤醒模块传数据；
        [_voiceAssitant.wakeup inputOfflineWakeupAudioData:data.bytes withLength:data.length];
    } else {
        [_voiceAssitant.voiceSession inputVoice2TextAudioData:data];
    }
    
}

#pragma mark TTSAudioPlayerDelegate
- (void)TTSAudioPlayerFinishedAll:(BOOL)success {
    // TODO 恢复其他播放
}

- (void)showAlertDialog:(NSString *)title withErrNo:(int)ret {
    NSString *errMsg = [NSString stringWithFormat:@"错误码：%d.", ret];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:errMsg preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:nil]];
    //[alertController addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleDefault handler:nil]];
    //[alertController show:YES];
    [self presentViewController:alertController animated:YES completion:nil];
}

#pragma mark SpeechWakeupDelegate

-(void)onSpeechWakeupCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData {
    NSLog(@"onSpeechWakeupCallback cmd = %ld", (long)cmd);
    if (cmd == K_AISDK_CMD_WAKEUP_RECO_RESULT) {
        _hadWakeup = YES;
    
        dispatch_async(dispatch_get_main_queue(), ^{
            if (self->_serviceType == SERVICE_TYPE_WAKEUP_AND_RECOGNIZE/* && self->_voiceMode == VOICE_MODE_WAKEUP*/) {
                [self->_aqRecorder stop];
                //[self showAlertDialog:@"唤醒成功" withErrNo:0];
                [self setRecordStatus:STATUS_NORMAL msg:@"叮当叮当"]; //_voiceResultText
                
                float f = [self->_voiceAssitant.wakeup getSensitive];
                [self appendToDisplay:[NSString stringWithFormat:@"唤醒成功，灵敏度为 %.3f", f]];
                self->_voiceMode = VOICE_MODE_RECOGNIZE;
                [self onRecorderClick];
            } else if (self->_serviceType == SERVICE_TYPE_VOICE_WAKEUP) {
                float f = [self->_voiceAssitant.wakeup getSensitive];
                [self appendToDisplay:[NSString stringWithFormat:@"唤醒成功，灵敏度为 %.3f", f]];
                [self setRecordStatus:STATUS_LOADING msg:@"叮当叮当"]; //_voiceResultText
                //[self appendToDisplay:@"唤醒成功"];
            }else if (self->_serviceType == SERVICE_ONESHOT) {
                [self appendToDisplay:@"ONESHOT唤醒成功"];
            }
        });

    }
}

-(void)onSpeechWakeupError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData {
    if (cmd == K_AISDK_CMD_WAKEUP_RECO_ERROR) {

        dispatch_async(dispatch_get_main_queue(), ^{
            [self->_aqRecorder stop];
            //[self showAlertDialog:@"唤醒失败" withErrNo:K_AISDK_CMD_WAKEUP_RECO_ERROR];
            [self setRecordStatus:STATUS_NORMAL msg:@"唤醒中。。。"];
            [self appendToDisplay:@"唤醒失败"];
        });
    }
}

-(BOOL)isKeyword:(NSString*)detected {
    for (NSString* keyword in _wakeupKeywords) {
        if ([keyword isEqual:detected]) return YES;
    }
    return NO;
}

- (IBAction)btnBackOnClick:(id)sender {
    [_aqRecorder stop];
    _aqRecorder = nil;
    [_pcmReader stop];
    _pcmReader = nil;
    [LocalPcmReader cleanAllData];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)switchButtonValueChanged:(id)sender {
    UISwitch * switchView = (UISwitch *)sender;
    _autoTest = switchView.isOn;
    if (_autoTest) {
        _testResult = [NSMutableArray array];
        [LocalPcmReader initLocalFiles];
    } else {
        if ([_pcmReader isWorking]) {
            [_pcmReader stop];
        }
    }
}

-(void)localOnInputVoice:(NSData *)data
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.03 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self onInputVoice:data];
    });
    
}

- (IBAction)btnSetContextOnClick:(id)sender {
    //    NSString *contextString = _tv_context.text;
    //    int type = [_tv_type.text intValue];
    //    [self appendToDisplay:[NSString stringWithFormat:@"设置场景：context = %@, type = %d", contextString, type]];
    //    [_voiceAssitant.voiceSession setOnlineVoiceContext:contextString.UTF8String withType:type];
}

@end
