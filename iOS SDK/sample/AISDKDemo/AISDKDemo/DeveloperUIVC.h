//
//  SessionViewController.h
//  Dingdang
//
//  Created by ZACARDFANG on 2017/6/12.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RecorderView.h"

enum {SERVICE_TYPE_VOICE2WORDS = 0x01, SERVICE_TYPE_VOICE_WAKEUP = 0x02, SERVICE_TYPE_VOICE_ASSISTANT = 0x03, SERVICE_TYPE_VOICE_ASSISTANT_NO_TTS = 0x04, SERVICE_TYPE_WAKEUP_AND_RECOGNIZE = 0x05, SERVICE_ONESHOT = 0x06,
    //暂时不支持离线唤醒和联合唤醒
    //SERVICE_CUSTOM_WAKEUP = 0x07, SERVICE_COMBINE_WAKEUP = 0x08
};


@interface DeveloperUIVC : UIViewController<RecorderViewDelegate>

@property (strong, nonatomic) IBOutlet RecorderView *mRecorderView;
@property (strong, nonatomic) IBOutlet UITextView *tv_log;

@property (weak, nonatomic) IBOutlet UILabel *funcTitle;

@property (nonatomic,assign) int serviceType; //1---voice2words,

@end
