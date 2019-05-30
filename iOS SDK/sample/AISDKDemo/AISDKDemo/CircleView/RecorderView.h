//
//  RecorderView.h
//  Dingdang
//
//  Created by ZACARDFANG on 2017/6/13.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, RecorderStatus) {
    STATUS_NORMAL,
    STATUS_WAIT,
    STATUS_EXCEPTION,
    STATUS_LOADING,
};

@protocol RecorderViewDelegate<NSObject>

- (void)onRecorderClick;

@end

// IB_DESIGNABLE
@interface RecorderView : UIView {

    @private RecorderStatus _status;
}

@property (strong, nonatomic) IBOutlet UIView *mContent;
@property (strong, nonatomic) IBOutlet UIButton *mRecorder_bg;
@property (strong, nonatomic) IBOutlet UIImageView *mRecorder_loading;
@property (strong, nonatomic) IBOutlet UIImageView *mRecorder;
@property (strong, nonatomic) IBOutlet UILabel *mRecorder_msg;

@property(nonatomic, weak) id<RecorderViewDelegate> delegate;

- (void) setRecorderStatus : (RecorderStatus) status msg :(NSString *) msg;

- (RecorderStatus) currentStatus;

- (void) setMsgTextHidden : (BOOL) hidden;

- (void)setMsgText:(NSString *)text;

- (void) setTouchEnabled:(BOOL)enable;
@end

