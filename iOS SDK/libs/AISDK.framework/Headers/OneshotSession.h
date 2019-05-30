/*!
@header OneshotSession.h
@brief 通用语音识别相关接口，只有一路音频输入的情况使用这个接口即可完成唤醒识别和语音识别流程
Created by Chuancong Zhu on 2018/9/21.
Copyright © 2018年 Zacard Fang. All rights reserved.
*/

#ifndef OneshotSession_h
#define OneshotSession_h
#import "VoiceSession.h"
#import "SemanticSession.h"
#import "SpeechWakeup.h"

/*!
 * @brief OneShot回调接口，在OneshotSession对象中注入
 */
@protocol OneShotSessionDelegate <NSObject>

/*!
 * @brief OneShot模式开启完成
 * @param cmd 参照cmd说明,K_AISDK_CMD_xx
 * @param code 通常返回0
 * @param data 识别结果
 * @param userData 自定义数据
 */
-(void)onOneShotStart:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 * @brief OneShot模式结束
 * @param cmd 参照cmd说明,K_AISDK_CMD_xx
 * @param code 通常返回0
 * @param data 识别结果
 * @param userData 自定义数据
 */
-(void)onOneShotStop:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 * @brief OneShot唤醒识别回调
 * @param cmd 参照cmd说明,K_AISDK_CMD_xx
 * @param code 通常返回0
 * @param data 识别结果
 * @param userData 自定义数据
 */
-(void)onOneShotWakeupCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 @brief OneShot唤醒识别异常回调
 @param cmd 参照cmd说明, K_AISDK_ERROR_xx
 @param code 返回的json数据错误码，参照语义说明文档解析
 @param message 错误信息
 @param userData 自定义数据
 */
-(void)onOneShotWakeupError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData;

/*!
 * @brief OneShot语音识别回调
 * @param cmd 参照cmd说明,K_AISDK_CMD_xx
 * @param code 通常返回0
 * @param data 识别结果
 * @param userData 自定义数据
 */
-(void)onOneShotVocieCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 @brief OneShot语音识别异常回调
 @param cmd 参照cmd说明, K_AISDK_ERROR_xx
 @param code 返回的json数据错误码，参照语义说明文档解析
 @param message 错误信息
 @param userData 自定义数据
 */
-(void)onOneShotVocieError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData;

@end


@interface OneshotSession: NSObject<SessionDelegate>

@property (nonatomic, weak) id<OneShotSessionDelegate> delegate;
@property(nonatomic, strong)dispatch_queue_t oneshotQueue;

/*!
 * @brief OneShot初始化，只需要初始化一次。
 * @param voiceModelPath 本地VAD模型所在路径，如果不需要本地VAD可以传NULL
 * @param wakeupModelPath 唤醒词模型所在路径，必传，否则无法唤醒
 */
-(instancetype)init:(NSString*)voiceModelPath wakeupModelPath:(NSString*)wakeupModelPath;


/*!
 * @brief 开始通用语音识别流程，启动一次即可一直输入语音，不需要反复启动，SDK内部会在唤醒识别和语音识别之间切换
 * @param userData 自定义数据指针。callback时带回。
 * @param flags 控制标志，参考AISDK_FLAG_*常量定义，支持多flag或运算。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)start:(void*)userData voiceType:(NSInteger)flags;

/*!
 * @brief 开始一次语音识别，用于直接唤醒开始交互
 * @param userData 自定义数据指针。callback时带回。
 * @param flags 控制标志，参考AISDK_FLAG_*常量定义，支持多flag或运算。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
-(int)startOneShotOnlineVoice2Text:(void*)userData voiceType:(NSInteger)flags;

/*!
 * @brief 取消通用语音识别流程，会停掉正在进行中的唤醒和者语音识别
 * @return 0：ok，other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)stopOneShot;

/*!
 * @brief 停止本次语音识别并获取结果，用于长按开启语音识别的场景
 * @return 0：ok，other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)stopOneShotOnlineVoice2Text;

/*!
 * @brief 取消本次语音识别
 * @return 0：ok，other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)cancelOneShotOnlineVoice2Text;

/*!
 * @brief 输入音频数据，在OneShot流程中全程需要输入
 * @param audioBuffer 录音数据存储区域。建议长度为4096.
 * @return 0：ok，other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)inputVoice2TextAudioData:(NSData *)audioBuffer;

@end

//常量定义

/*----------oneshot------*/

/*!
 * @brief  ONESHORT模式开启完成
 * @see OneShotSessionDelegate
 */
extern const int K_AISDK_CMD_ONE_SHOT_START; //13000

/*!
 * @brief ONESHORT模式结束
 * @see OneShotSessionDelegate
 */
extern const int K_AISDK_CMD_ONE_SHOT_STOP;

#endif /* OneshotSession_h */
