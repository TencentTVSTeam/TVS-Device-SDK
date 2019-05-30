//
//  SettingViewController.m
//  AISDKDemo
//
//  Created by Aimee on 2019/3/5.
//  Copyright © 2019 Zacard Fang. All rights reserved.
//

#import "SettingViewController.h"
#import "VoiceAssistant.h"

@interface SettingViewController ()<UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UISegmentedControl *networkSegment;
@property (weak, nonatomic) IBOutlet UITextField *timeoutField;
@property (weak, nonatomic) IBOutlet UITextField *peerSizeField;
@property (weak, nonatomic) IBOutlet UISwitch *sandboxOpen;
@property (weak, nonatomic) IBOutlet UISwitch *serviceVADOpen;
@property (weak, nonatomic) IBOutlet UISwitch *needSaveASR;
@property (weak, nonatomic) IBOutlet UISwitch *useLocalVAD;
@property (weak, nonatomic) IBOutlet UISwitch *onlyCheckVAD;
@property (weak, nonatomic) IBOutlet UISwitch *ignoreWakeup;
@property (weak, nonatomic) IBOutlet UISwitch *saveWeakupBuffer;
@property (weak, nonatomic) IBOutlet UISegmentedControl *networkUpload;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;


//1、网络环境（测试/体验/正式）：AISDK_CONFIG_ENV_TYPE
//2、网络请求超时时间：AISDK_CONFIG_REQ_TIMEOUT
//3、网络包大小
//4、云端vad开关：AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD
//5、是否保存ASR录音：AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH
//6、识别过程中忽略唤醒：K_AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO
//7、是否只检查vad：AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD
//8、沙箱环境：AISDK_CONFIG_OPEN_SANDBOX
//9、是否保存切上报唤醒录音（每次唤醒一个文件）：AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED

@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self initConfigUI];
}

- (void)initConfigUI
{
    VoiceAssistant *voiceAssitant = [VoiceAssistant sharedInstance];
    NSString *networkconfig = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_ENV_TYPE];
    self.networkSegment.selectedSegmentIndex = [networkconfig integerValue];
    
    NSString *timeOutTime = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_REQ_TIMEOUT];
    self.timeoutField.text = timeOutTime;
    
    NSString *peerSize = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE];
    self.peerSizeField.text = peerSize;
    
    NSString *sandbox = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_OPEN_SANDBOX];
    [self.sandboxOpen setOn:[sandbox boolValue]];
    
    NSString *voiceOnlineEnable = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD];
    [self.serviceVADOpen setOn:[voiceOnlineEnable boolValue]];
    
    NSString *voiceOnelineSaveSpeech = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH];
    [self.needSaveASR setOn:[voiceOnelineSaveSpeech boolValue]];
    
    NSString *voiceOnelineUserLocalVad = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD];
    [self.useLocalVAD setOn:[voiceOnelineUserLocalVad boolValue]];
    
    NSString *onlyDetectVad = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD];
    [self.onlyCheckVAD setOn:[onlyDetectVad boolValue]];
    
    NSString *ignoreWakeupWhenReco = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO];
    [self.ignoreWakeup setOn:[ignoreWakeupWhenReco boolValue]];
    
    NSString *weakupBUfferSave = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED];
    [self.saveWeakupBuffer setOn:[weakupBUfferSave boolValue]];

    NSString *networkupload = [voiceAssitant.aisdk getConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE];
    self.networkUpload.selectedSegmentIndex = [networkupload integerValue];
    
    NSString *version = [NSString stringWithFormat:@"Version:%@", [voiceAssitant.aisdk getSDKVersion]];
    [self.versionLabel setText:version];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (IBAction)netWorkChange:(id)sender
{
    
    UISegmentedControl *segmentControl = (UISegmentedControl *)sender;
    NSString *index = [NSString stringWithFormat:@"%ld",(long)segmentControl.selectedSegmentIndex];
    
    VoiceAssistant *voiceAssitant = [VoiceAssistant sharedInstance];
    //设置网络环境（测试/体验/正式）
    [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_ENV_TYPE value:[index UTF8String]];
}
- (IBAction)switchButtonValueChanged:(id)sender
{
    VoiceAssistant *voiceAssitant = [VoiceAssistant sharedInstance];
    UISwitch * switchView = (UISwitch *)sender;
    NSInteger index = switchView.tag - 1000;
    switch (index) {
        case 1://沙箱环境
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_OPEN_SANDBOX value:switchView.isOn ? "1" : "0"];
        }
            break;
        case 2://云端vad开关
        {
           [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD value:switchView.isOn ? "1" : "0"];
        }
            break;
        case 3://是否保存ASR录音
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH value:switchView.isOn ? "1" : "0"];
        }
            break;
        case 4://是否使用本地vad
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD value:switchView.isOn ? "1" : "0"];
        }
            break;
        case 5://是否只检查vad
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD value:switchView.isOn ? "1" : "0"];
        }
            break;
        case 6://识别过程中忽略唤醒
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO value:switchView.isOn ? "1" : "0"];
        }
            break;
        case 7://是否保存且上报唤醒录音
        {
            if (switchView.isOn) {
                //打开上传唤醒音频后，设置路径
                [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED value:"1"];
                [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH value:[voiceAssitant.buffer_file_dir UTF8String]];
            } else {
                //关掉上传唤醒音频时，保存路径置空
                [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED value: "0"];
                [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH value:""];
            }
        }
            break;
            
            
        default:
            break;
    }
}
- (IBAction)backAction:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)setNetworkEnableType:(UISegmentedControl *)segmentControl
{
    VoiceAssistant *voiceAssitant = [VoiceAssistant sharedInstance];
    switch (segmentControl.selectedSegmentIndex) {
        case 0:
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE value:"0"];
        }
            break;
        case 1:
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE value:"1"];
        }
            break;
        case 2:
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE value:"2"];
        }
            break;
        case 3:
        {
            [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE value:"3"];
        }
            break;
            
        default:
            break;
    }
    
}



- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    VoiceAssistant *voiceAssitant = [VoiceAssistant sharedInstance];
    NSLog(@"setConfig textField.tag=%ld.", (long)textField.tag);
    if (textField.tag == 2001) {
        //网络请求超时时间
        [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_REQ_TIMEOUT value:[textField.text UTF8String]];
    } else if (textField.tag == 2002) {
        //包大小
        [voiceAssitant.aisdk setConfig:K_AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE value:[textField.text UTF8String]];
    }
    [textField resignFirstResponder];
    return YES;
}

@end
