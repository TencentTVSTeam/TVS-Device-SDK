/*!
 @header TtsSession.h
 @brief 文本转语音能力提供者，该类封装了文本转语音能力的所有接口
 @author zacardfang
 @copyright © 2017 TENCENT. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "SpeechEngine.h"

/*! 
 * @brief 文本转语音回调接口
 * TtsSessionDelegate 会在TtsSession对象中注入
 */
@protocol TtsSessionDelegate <NSObject>

/*! 
 * @brief 文本转语音回调
 * @param cmd 参照cmd说明
 * @param code 返回的json数据错误码，参照语义说明文档解析
 * @param pcm 音频数据，pcm格式
 * @param userData 自定义数据
 */
-(void)onOnlineTtsCallback:(NSInteger)cmd code:(NSInteger)code pcm:(NSData *)pcm userData:(id)userData;


/*!
 * @brief 异常回调
 * @param cmd 参照K_AISDK_CMD_TTS_ERROR说明
 * @param code 返回的json数据错误码，参照语义说明文档解析
 * @param message 错误信息
 * @param userData 自定义数据
 */
-(void)onOnlineTtsError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData;

@end

@interface TtsSession : NSObject<SessionDelegate>

@property(nonatomic, weak)id<TtsSessionDelegate> delegate;
@property(nonatomic, strong)dispatch_queue_t ttsQueue;

/*!
 * @brief TTS识别接口， TTS结果通过回调异步回调返回
 * @param text 需要转语音的文本，以utf8格式编码的文本串，以'\0'结尾
 * @param userdata 自定义数据
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)text2Speech:(NSString *)text userData:(id)userdata;


/*!
 * @brief TTS转换接口， TTS结果通过回调异步回调返回
 * @param languageType 语言类型，0：默认，1：中文，2：英文
 * @param text 需要转语音的文本，以utf8格式编码的文本串，以'\0'结尾
 * @param userdata 自定义数据
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)text2SpeechEx:(int)languageType text:(NSString *)text userData:(id)userdata;

/*!
 * @brief 取消此次的TTS请求
 * @warning 取消后， 这一次的tts请求结果不再返回。
 * @return 0:ok other:fail。 错误码定义见K_AISDK_ERROR_*常量
 */
-(int)cancelText2Speech;

@end

//常量定义
/*!
 * @brief 回调接口命令定义，当TTS返回结果时发出
 * @see TtsSessionDelegate
 */
extern const int K_AISDK_CMD_TTS_RESULT;                                  // 返回TTS结果数据包
/*!
 * @brief 回调接口命令定义，当TTS返回出错时发出
 * @see TtsSessionDelegate
 */
extern const int K_AISDK_CMD_TTS_ERROR;                                  // TTS请求出错

// 配置项，key的起始值
extern const int K_AISDK_CONFIG_TTS_ONLINE_BEGIN;

/*!
 * @brief 配置TTS服务的环境
 * @note 设置TTS环境为正式环境 aisdkSetConfig(AISDK_CONFIG_TTS_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)
 * @see aisdkSetConfig()
 */
extern const int K_AISDK_CONFIG_TTS_ENV_TYPE;

// 配置项，key的结束值
extern const int K_AISDK_CONFIG_TTS_ONLINE_END;

/*!
 * @brief TTS的语音包返回code，标识中间语音数据包
 */
extern const int K_AISDK_RESULT_CODE_TTS_DATA;
/*!
 * @brief TTS的最后一个语音包返回code，标识最后一个语音数据包。
 * @note
 * 与AISDK_RESULT_CODE_TTS_DATA的不同在于:当文本较短时，tts语音包较短，只会有AISDK_RESULT_CODE_TTS_LAST_DATA
 */
extern const int K_AISDK_RESULT_CODE_TTS_LAST_DATA;
