//
//  Word2VoiceViewController.m
//  AISDKDemo
//
//  Created by fredyfang(方义) on 2018/4/19.
//  Copyright © 2018年 Zacard Fang. All rights reserved.
//

#import "Word2VoiceViewController.h"
#import "VoiceAssistant.h"

@interface Word2VoiceViewController ()<SemanticSessionDelegate, TtsSessionDelegate, TTSAudioPlayerDelegate>
@property (weak, nonatomic) IBOutlet UITextView *tv_log;
@property (weak, nonatomic) IBOutlet UITextView *inputWords;

@property(nonatomic, strong) VoiceAssistant *voiceAssitant;
@property(nonatomic, strong)TTSAudioPlayer *ttsAudioPlayer;
@property(nonatomic, strong) NSMutableString * displayLog;

@property (weak, nonatomic) IBOutlet UIButton *word2Voice;
@property (weak, nonatomic) IBOutlet UIButton *word2Semantic;
@end

@implementation Word2VoiceViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self initData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)btnBackOnClick:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)translateWord2Voice:(id)sender {
    NSString *words = _inputWords.text;
    if (words != nil && words.length > 0) {
        [self setBtnUnclickable];
        [_voiceAssitant.ttsSession text2Speech:words userData:self];
        [self clearToDisplay];
        [self appendToDisplay:[NSString stringWithFormat:@"文字转语音中......"]];
    }
}


- (IBAction)translateWord2Semantic:(id)sender {
    NSString *words = _inputWords.text;
    if (words != nil && words.length > 0) {
        [self setBtnUnclickable];
        [self clearToDisplay];
        [_voiceAssitant.semanticSession text2semantic:words userData:self flags:0];// flags:K_AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION];
    }
}

- (void)initData {
    
    _displayLog = [[NSMutableString alloc] init];
    
    //播报
    _ttsAudioPlayer = [TTSAudioPlayer shared];
    _ttsAudioPlayer.delegate = self;
    
    _voiceAssitant = [VoiceAssistant sharedInstance];
    
    //semantic
    //[_semanticSession setDelegate:self];
    [_voiceAssitant.semanticSession setDelegate:self];
    
    //tts
    //[_ttsSession setDelegate:self];
    [_voiceAssitant.ttsSession setDelegate:self];

}

- (void)resetBtnStatus {
    [_word2Semantic setUserInteractionEnabled:true];
    [_word2Voice setUserInteractionEnabled:true];
}

- (void)setBtnUnclickable {
    [_word2Semantic setUserInteractionEnabled:false];
    [_word2Voice setUserInteractionEnabled:false];
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
        [_tv_log setText:content];
        [_tv_log scrollRangeToVisible:NSMakeRange(_tv_log.text.length - 1, 1)];
    });
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/


#pragma mark SemanticSessionDelegate
-(void)onOnlineSemanticCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData {
    NSLog(@"Word2VoiceViewController onOnlineSemanticCallback cmd = %ld", cmd);
    // 语义回调，解析业务场景
    [self appendToDisplay:[NSString stringWithFormat:@"语义回调结果：%@", data]];
    [self resetBtnStatus];
    if (K_AISDK_CMD_SEMANTIC_RESULT == cmd) {
//        SemanticData *sd = [SemanticData valueFromJson:data];
//        // 处理业务，此处直接演示tts功能
//        if (sd.speakText && ![sd.speakText isEqualToString:@""]) {
//            [_voiceAssitant.ttsSession text2Speech:sd.speakText userData:self];
//        } else {
//            [_voiceAssitant.ttsSession text2Speech:sd.tipsText userData:self];
//        }
    }
}

- (void)onOnlineSemanticError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData {
    [self appendToDisplay:[NSString stringWithFormat:@"语义回调错误：%@", message]];
    [self resetBtnStatus];
}

#pragma mark TtsSessionDelegate
-(void)onOnlineTtsCallback:(NSInteger)cmd code:(NSInteger)code pcm:(NSData *)pcm userData:(id)userData{
    if (pcm) {
        // 转换pcm格式为wav格式播放，也可调用系统AudioQueue播放pcm
        [_ttsAudioPlayer addData:[TtsFormater translatePcm2Wav:pcm]];
    } else {
        [self resetBtnStatus];
        [self clearToDisplay];
    }
}

-(void)onOnlineTtsError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData{
    //NSLog(@"tts error cmd:%ld data:%@", cmd, data);
    [self resetBtnStatus];
    [self clearToDisplay];
}

#pragma mark TTSAudioPlayerDelegate
- (void)TTSAudioPlayerFinishedAll:(BOOL)success {
    // TODO 恢复其他播放
    NSLog(@"TTSAudioPlayerFinishedAll");
    [self resetBtnStatus];
    [self clearToDisplay];
}

@end
