//
//  OneShotViewController.m
//  AISDKDemo
//
//  Created by Aimee on 2019/3/2.
//  Copyright © 2019 Zacard Fang. All rights reserved.
//

#import "OneShotViewController.h"
#import "VoiceAssistant.h"
#import "RecorderView.h"
#import <AVFoundation/AVFoundation.h>

@interface OneShotViewController ()<OneShotSessionDelegate,AQRecorderDelegate,RecorderViewDelegate>
{
    BOOL _isStartOneShotManual;//记录是不是手动录音
    BOOL _startOneShot;
    BOOL _startOneShotOnece;
    
}
@property (weak, nonatomic) IBOutlet UIButton *startOneShotButton;
@property (weak, nonatomic) IBOutlet UIButton *oneTimeButton;
@property (weak, nonatomic) IBOutlet UINavigationBar *navigationBar;
@property (strong, nonatomic) IBOutlet UITextView *tv_log;

@property(nonatomic, assign)BOOL hadWakeup;
@property(nonatomic, assign)BOOL wakeupFailed;
@property(nonatomic, strong) OneshotSession* oneshotSession;
@property(nonatomic, strong)AQRecorder *aqRecorder;
@property(nonatomic, strong)NSString *voiceResultText;
@property (weak, nonatomic) IBOutlet RecorderView *recordView;
@property(nonatomic, strong)NSMutableString * displayLog;
@end

@implementation OneShotViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.displayLog = [[NSMutableString alloc] init];
    //录音
    self.aqRecorder = [[AQRecorder alloc] init];
    _aqRecorder.delegate = self;
    
    [self initOneshot];
    [self initRecorderView];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self.oneshotSession start:nil voiceType:0];
    [self.aqRecorder start];
    [self.recordView setRecorderStatus:STATUS_LOADING msg:nil];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [self.oneshotSession stopOneShot];
    [self.oneshotSession stopOneShotOnlineVoice2Text];
    [self.aqRecorder stop];
    
}

- (void)viewDidDisappear:(BOOL)animated {
    
    [SpeechEngine.getInitedInstance removeSDelegate:[_oneshotSession keyOfSession]];
}

- (void)initOneshot {
    NSString *modelPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"keywords_model.bundle"];
    NSString *vadModelPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"vad_model.bundle"];
    self.oneshotSession = [[OneshotSession alloc] init:vadModelPath wakeupModelPath:modelPath];
    [self.oneshotSession setDelegate:self];
    VoiceAssistant *voiceAssistant = [VoiceAssistant sharedInstance];
    [voiceAssistant.aisdk addSession:_oneshotSession];
}

- (void)initRecorderView {
    [_recordView setDelegate:self];
    [_recordView setRecorderStatus:STATUS_NORMAL msg:@"点击开始录音"];
    [_recordView setMsgTextHidden:NO];
    
    
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
        [self.tv_log setText:content];
        [self->_tv_log scrollRangeToVisible:NSMakeRange(self->_tv_log.text.length - 1, 1)];
    });
    
}

- (void)onRecorderClick
{
    [[AVAudioSession sharedInstance] requestRecordPermission:^(BOOL granted) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (granted) {
                if (_isStartOneShotManual) {
                    [self appendToDisplay:@"停止手动录音"];
                    [self.oneshotSession stopOneShotOnlineVoice2Text];
                }else{
                    [self appendToDisplay:@"开始手动录音"];
                    [self.oneshotSession startOneShotOnlineVoice2Text:nil voiceType:0];
                }
                _isStartOneShotManual = !_isStartOneShotManual;
            } else {
                [self showAlertDialog:@"未开启录音权限" withErrNo:-1];
            }
        });
        
        NSLog(@"onRecorderClick end");
    }];
}

- (void)setRecordStatus:(NSInteger)status msg:(NSString *)msg{
    [self.recordView setRecorderStatus:status msg:msg];
}

#pragma mark AQRecorderDelegate
-(void)onInputVoice:(NSData *)data {
    int ret = [_oneshotSession inputVoice2TextAudioData:data];
}

#pragma mark OneShotSessionDelegate

-(void)onOneShotWakeupCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData {
    NSLog(@"onOneShotWakeupCallback cmd = %ld", (long)cmd);
    if (cmd == K_AISDK_CMD_WAKEUP_RECO_RESULT) {
        _hadWakeup = YES;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self appendToDisplay:@"ONESHOT唤醒成功"];
        });
        
    }
}

-(void)onOneShotWakeupError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData{
    NSLog(@"onOneShotWakeupError cmd = %ld", (long)cmd);
    if (cmd == K_AISDK_CMD_WAKEUP_RECO_ERROR) {
        _hadWakeup = NO;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.aqRecorder stop];
            [self.oneshotSession stopOneShot];
            [self appendToDisplay:@"ONESHOT唤醒失败"];
            [self.oneTimeButton setTitle:@"手动录音" forState:UIControlStateNormal];
            [self.startOneShotButton setTitle:@"开启oneshot" forState:UIControlStateNormal];
        });
        
    }
}

-(void)onOneShotVocieCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData{
    NSLog(@"onOneShotVocieCallback cmd=%ld.", (long)cmd);
            dispatch_async(dispatch_get_main_queue(), ^{
        if (cmd == K_AISDK_CMD_ONLINE_RECO_START){
            // 在线识别开始，接受录音数据
            [self appendToDisplay:@"在线识别开始，接受录音数据"];
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_SPEECH_START){
            // 在线语音VAD检测到开始
            [self appendToDisplay:@"VAD检测到开始"];
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_SPEECH_END){
            // 在线语音vad检测完成，可以停止输入录音数据
            [self appendToDisplay:@"检测完成，可以停止输入录音数据"];
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_RESULT){
            // 返回在线识别结果
            [self appendToDisplay:[NSString stringWithFormat:@"oneshot识别结果：%@", data]];
            _isStartOneShotManual = NO;
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"oneshot 语音识别完成：%@", data);
                [self.recordView setMsgText:data];
                self.voiceResultText = data;
            });
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT){
            // 上报在线识别的中间结果
            self->_voiceResultText = data;
            NSLog(@"语音识别中：%@", self->_voiceResultText);
            [self.recordView setMsgText:self->_voiceResultText];
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_DATA_VOLUME){
            // 上报输入音频数据的音量值
            NSLog(@"RECO_DATA_VOLUME value：%f", [data floatValue]);
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_CANCELED){
            // 已取消在线识别
            [self appendToDisplay:@"已取消在线识别"];
            _isStartOneShotManual = NO;
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_ERROR) {
            [self appendToDisplay:[NSString stringWithFormat:@"出现错误 %ld", (long)code]];
            _isStartOneShotManual = NO;
        }
        
    });
}

-(void)onOneShotVocieError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData{
    _isStartOneShotManual = NO;
    __block NSString *errorMsg = message;
    dispatch_async(dispatch_get_main_queue(), ^{
        _hadWakeup = NO;
        if (cmd == K_AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT) {
            errorMsg = @"本地VAD检测静音超时";
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT) {
            errorMsg = @"在线识别服务端无结果";
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_TIMEOUT) {
            errorMsg = @"在线识别超时，没有识别到有效输入";
        } else if (cmd == K_AISDK_CMD_ONLINE_RECO_ERROR) {
            errorMsg = @"在线识别出错";
        }
        [self appendToDisplay:[NSString stringWithFormat:@"onOneShotVocieError cmd =%ld,code =%ld, message=%@", (long)cmd, (long)code, errorMsg]];
    });
}

- (void)onOneShotStart:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData {
    NSLog(@"onOneShotStart");
    [self appendToDisplay:@"OneShot 开始"];
}

- (void)onOneShotStop:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData {
    NSLog(@"onOneShotStop");
    [self appendToDisplay:@"OneShot 结束"];
}

- (IBAction)backToMainView:(id)sender
{
    [_aqRecorder stop];
    _aqRecorder = nil;
    [self dismissViewControllerAnimated:YES completion:nil];
}


- (void)showAlertDialog:(NSString *)title withErrNo:(int)ret {
    NSString *errMsg = [NSString stringWithFormat:@"错误码：%d.", ret];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:errMsg preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:alertController animated:YES completion:nil];
}
@end
