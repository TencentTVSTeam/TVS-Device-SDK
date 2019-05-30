//
//  RecorderView.m
//  Dingdang
//
//  Created by ZACARDFANG on 2017/6/13.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import "RecorderView.h"

@interface RecorderView()

@end

@implementation RecorderView

/*
 // Only override drawRect: if you perform custom drawing.
 // An empty implementation adversely affects performance during animation.
 - (void)drawRect:(CGRect)rect {
 // Drawing code
 }
 */

- (instancetype)initWithFrame:(CGRect)frame{
    if(self = [super initWithFrame:frame]) {
        [[NSBundle mainBundle] loadNibNamed:@"RecorderView" owner:self options:nil];
        [self addSubview:self.mContent];
        self.mContent.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
        
        [self setRecorderStatus:STATUS_NORMAL msg:@""];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder{
    if(self = [super initWithCoder:aDecoder]) {
        [[NSBundle mainBundle] loadNibNamed:@"RecorderView" owner:self options:nil];
        [self addSubview:self.mContent];
        self.mContent.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
    }
    return self;
}

- (void)awakeFromNib{
    [super awakeFromNib];
}

- (IBAction)onRecordClick:(id)sender {
    //DDLogDebug(@"RecorderView onRecordClick");
    if (_delegate) {
        [_delegate onRecorderClick];
    }
}

- (void)setRecorderStatus:(RecorderStatus)status msg:(NSString *)msg{
    [_mRecorder_msg setText:msg];
    _status = status;
    switch (status) {
        case STATUS_NORMAL:
            [self stopRotateAnimation];
            [_mRecorder_msg setTextColor:[UIColor grayColor]];
            [_mRecorder_loading setImage:nil];
            break;
            
        case STATUS_WAIT:
            [self stopRotateAnimation];
            [_mRecorder_msg setTextColor:[UIColor grayColor]];
            [_mRecorder_loading setImage:[UIImage imageNamed:@"record_ready"]];
            break;
            
        case STATUS_LOADING:
            [self startRotateAnimation];
            [_mRecorder_msg setTextColor:[UIColor grayColor]];
            [_mRecorder_loading setImage:[UIImage imageNamed:@"record_loading"]];
            
            break;
            
        case STATUS_EXCEPTION:
            [self stopRotateAnimation];
            [_mRecorder_msg setTextColor:[UIColor redColor]];
            [_mRecorder_loading setImage:[UIImage imageNamed:@"record_error"]];
            
            break;
            
        default:
            break;
    }
}

- (void)startRotateAnimation{
    // 执行动画
    CABasicAnimation* rotationAnimation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
    rotationAnimation.byValue = [NSNumber numberWithFloat:M_PI_2];
    rotationAnimation.duration = .2f;
    rotationAnimation.cumulative = YES;
    rotationAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn];
    rotationAnimation.repeatCount = 1000;
    
    [_mRecorder_loading.layer addAnimation:rotationAnimation forKey:@"rotationAnimation"];
}

-(void) stopRotateAnimation{
    [_mRecorder_loading.layer removeAllAnimations];
}


- (RecorderStatus)currentStatus{
    return _status;
}

- (void)setMsgTextHidden:(BOOL)hidden{
    [_mRecorder_msg setHidden:hidden];
}

- (void)setMsgText:(NSString *)text{
    [_mRecorder_msg setText:text];
}

- (void)setTouchEnabled:(BOOL)enable {
    [_mRecorder_bg setEnabled:enable];
}

@end
