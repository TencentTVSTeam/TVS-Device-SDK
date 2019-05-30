//
//  SpeechWakeup.h
//  AISDK
//
//  Created by fredyfang(方义) on 2018/3/16.
//  Copyright © 2018年 Zacard Fang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpeechEngine.h"

/*!
 * @brief 唤醒识别回调接口，在SpeechWakeup对象中注入
 */
@protocol SpeechWakeupDelegate <NSObject>

/*!
 * @brief 唤醒识别回调
 * @param cmd 参照cmd说明,K_AISDK_CMD_WAKEUP_RECO_xx
 * @param code 通常返回0
 * @param data 识别结果
 * @param userData 自定义数据
 */
-(void)onSpeechWakeupCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 @brief 唤醒识别异常回调
 @param cmd 参照cmd说明, K_AISDK_ERROR_WAKEUP_RECO_xx
 @param code 返回的json数据错误码，参照语义说明文档解析
 @param message 错误信息
 @param userData 自定义数据
 */
-(void)onSpeechWakeupError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData;

@end

@interface SpeechWakeup : NSObject<SessionDelegate>
@property(nonatomic, strong)dispatch_queue_t wakeupQueue;
@property(nonatomic, weak)id<SpeechWakeupDelegate> delegate;

/*!
 * 回调接口命令定义
 */
/**
 * @brief 回调接口命令定义，唤醒识别开始，接受录音数据
 * @see AISDK_CALLBACK
 */
extern const int K_AISDK_CMD_WAKEUP_RECO_START;// = 7000;
/*!
 *
 * @brief 回调接口命令定义，唤醒vad检测完成，可以停止输入录音数据，返回唤醒识别结果
 * @see AISDK_CALLBACK
 */
extern const int K_AISDK_CMD_WAKEUP_RECO_RESULT;// = AISDK_CMD_WAKEUP_RECO_START + 1;
/*!
 *
 * @brief 回调接口命令定义，唤醒识别出错
 * @see AISDK_CALLBACK
 */
extern const int K_AISDK_CMD_WAKEUP_RECO_ERROR;// = AISDK_CMD_WAKEUP_RECO_START + 2;
/*!
 * @brief 回调接口命令定义，已取消唤醒识别
 * @see AISDK_CALLBACK
 */
extern const int K_AISDK_CMD_WAKEUP_RECO_CANCELED;// = AISDK_CMD_WAKEUP_RECO_START + 3;
/*************************************************************
 * START:配置项key定义
 * ***********************************************************/
// 配置项，key的起始值
extern const int K_AISDK_CONFIG_WAKEUP_BEGIN;// = 7000;

extern const int K_AISDK_CONFIG_WAKEUP_TIMEOUT;// = AISDK_CONFIG_WAKEUP_BEGIN + 1;
/*!
 * @brief 唤醒录音文件控制命令，内部使用
 *
 * ## 示例：
 * ```
 * // 上传唤醒录音文件
 * aisdkSetConfig(K_AISDK_CONFIG_WAKEUP_BUFFER_CONTROL,"1")
 * // 取消上传唤醒录音文件
 * aisdkSetConfig(K_AISDK_CONFIG_WAKEUP_BUFFER_CONTROL,"2")
 * ```
 */
extern const int K_AISDK_CONFIG_WAKEUP_BUFFER_CONTROL;// = AISDK_CONFIG_WAKEUP_BEGIN + 6;

/*!
 * @brief 获取唤醒模型的MD5，仅支持获取，不支持设置
 */
extern const int K_AISDK_CONFIG_WAKEUP_MODEL_MD5;//AISDK_CONFIG_WAKEUP_BEGIN + 7
// 配置项，key的结束值
extern const int K_AISDK_CONFIG_WAKEUP_END;// = 7999;

/*************************************************************
 * END：配置项key定义
 * ***********************************************************/


/*************************************************************
 * START:错误码定义
 * ***********************************************************/
/*!
 * @brief 错误码定义：模块还未初始化
 */

extern const int K_AISDK_ERROR_WAKEUP_RECO_FAILED;// = 7000;
/*!
 * @brief 错误码定义：未开始识别就输入语音
 */
extern const int K_AISDK_ERROR_WAKEUP_RECO_NOT_STARTED;// = AISDK_ERROR_WAKEUP_RECO_FAILED + 1;
/*!
 * @brief 错误码定义：创建在线识别模块失败
 */
extern const int K_AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED;// = AISDK_ERROR_WAKEUP_RECO_FAILED + 2;
/*!
 * @brief 错误码定义：SDK没有包含唤醒模块
 */
extern const int K_AISDK_ERROR_WAKEUP_RECO_MODULE_UNAVAILABLE;// = AISDK_ERROR_WAKEUP_RECO_FAILED + 3;
extern const int K_AISDK_ERROR_WAKEUP_RECO_FATAL;
/*************************************************************
 * END:错误码定义
 * ***********************************************************/

/*************************************************************
 * START:返回的json数据中的code定义
 * ***********************************************************/
/*!
 * @brief json code定义：唤醒成功
 */
extern const int K_AISDK_RESULT_CODE_WAKEUP_OK;// = 0;
/*************************************************************
 * END:返回的json数据中的code定义
 * ***********************************************************/
/*!
 * @brief 唤醒初始化，只需要初始化一次。
 * @param modelPath 唤醒词模型路径
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
- (int)initOfflineWakupWithPath:(const char *)modelPath;

/*!
 * @brief 开始一次唤醒识别
 * @param userData 用户自定义数据， callback时将会原样带回。
 * @param len 用户自定义数据长度
 * @param flags 控制标志，参考AISDK_FLAG_WAKEUP_*常量定义，支持多flag或运算。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
- (int)startOfflineWakupWithData:(void*)userData withLength:(int)len withFlags:(int)flags;

/*!
 * @brief 输入录音数据
 * @param data 录音数据存储区域
 * @param dataLen 录音数据长度
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 * @warning 建议每次调用输入的录音数据长度为4096字节。
 *
 */
- (int)inputOfflineWakeupAudioData:(char *)data  withLength:(int)dataLen;

/*!
 * @brief 取消本次语音唤醒识别流程。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
- (int)cancelOfflineWakeup;

/*!
 * @brief 设置当前唤醒模型的灵敏度
 * @param sensitive 灵敏度，取值范围：0.0~1.0
 * @return 0：ok，other：fail。
 */
- (int)setSensitive:(float)sensitive;

/*!
 * @brief 获取当前唤醒模型的灵敏度
 * @return 灵敏度，取值范围：0.0~1.0
 */
- (float)getSensitive;

/*!
 * @brief 获取上一次唤醒的置信度
 * @return 置信度，取值范围：0.0~1.0
 */
- (float)getScore;
@end
