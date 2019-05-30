/*!
 @header VoiceSession.h
 @brief 语音识别能力提供者
 @author zacardfang
 @copyright © 2017 TENCENT. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "SpeechEngine.h"

/*!
 * @brief 语音识别回调接口，在VoiceSession对象中注入
 */
@protocol VoiceSessionDelegate <NSObject>

/*!
 * @brief 语音识别回调
 * @param cmd 参照cmd说明,K_AISDK_CMD_ONLINE_RECO_xx
 * @param code 通常返回0
 * @param data 识别结果
 * @param userData 自定义数据
 */
-(void)onOnlineVocieCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 @brief 语音识别异常回调
 @param cmd 参照cmd说明, K_AISDK_ERROR_ONLINE_RECO_xx
 @param code 返回的json数据错误码，参照语义说明文档解析
 @param message 错误信息
 @param userData 自定义数据
 */
-(void)onOnlineVocieError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData;

@end

@interface VoiceSession : NSObject<SessionDelegate>

@property(nonatomic, weak)id<VoiceSessionDelegate> delegate;
@property(nonatomic, strong)dispatch_queue_t voiceQueue;

/*！
 * @brief 开始一次语音识别流程
 * @param flags 控制标志，参考K_AISDK_FLAG_ONLINE_RECO_*常量定义。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
-(int)startVoice2text:(NSInteger)mode;

/*！
 * @brief 开始一次语音识别流程
 * @param userdata 自定义数据指针。callback时带回。
 * @param flags 控制标志，参考K_AISDK_FLAG_ONLINE_RECO_*常量定义。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
-(int)startVoice2text:(NSInteger)mode userData:(id)userdata;

/*!
 * @brief 初始化语音识别功能，如果没有接入新版vad，不需要调用此方法
 * @param resDir VAD模型所在的根目录
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
//AISDK_API_EXPORTS int aisdkInitOnlineVoice2Text(char* modelPath);
-(int)initOnlineVoice2TextWithPath:(const char *)modelPath;

/*!
 * @brief 输入录音数据
 * @param audioBuffer 上传音频数据
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 * @warning:
 *      上层应用应当把实时录音数据通过该接口输入到SDK（建议每次输入4096字节长度的音频）。
 *   在调用此接口过程中，会有VAD检测到开始、VAD检测到结束、实时音量、语音识别到结果等
 *   状态的回调。遇到AISDK_CMD_ONLINE_RECO_CANCELED/AISDK_CMD_ONLINE_RECO_TIME
 *   OUT/AISDK_CMD_ONLINE_RECO_ERROR/AISDK_CMD_ONLINE_RECO_RESULT时，停止调用
 *   该函数。
 */
-(int)inputVoice2TextAudioData:(NSData *)audioBuffer;

/*!
 * @brief 取消本次语音识别
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
-(int)cancelVoice2Text;

/*!
 * @brief 停止本次语音识别，获取语音识别结果。
 * @warning 停止后，不会中断语音识别，SDK会将现在已经接收到的音频发送到后台请求语音识别结果。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
-(int)stopVoice2Text;

/**
 * 设置ASR语音识别上下文
 * @param jsonContext 上下文内容，json字符串
 * @param type 用于区分上下文内容，例如：1：微信，2：联系人，3：手机地图
 * @return 设置成功返回0：AISDK_RESULT_OK
 */
//-(int)setOnlineVoiceContext:(char *)jsonContext withType:(NSInteger)type;

@end

//常量定义

/*------语音识别--------*/
/*!
 * @brief 回调接口命令定义,在线识别开始，接受录音数据
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_START;

/*!
 * @brief 回调接口命令定义,在线语音VAD检测到开始
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_SPEECH_START;          // 在线语音VAD检测到开始

/*!
 * @brief 回调接口命令定义,在线语音vad检测完成，可以停止输入录音数据
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_SPEECH_END;                     // 在线语音vad检测完成，可以停止输入录音数据
/*!
 * @brief 回调接口命令定义,返回在线识别结果
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_RESULT;                   // 返回在线识别结果
/*!
 * @brief 回调接口命令定义,上报在线识别的中间结果
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT;      // 上报在线识别的中间结果
/*!
 * @brief 回调接口命令定义,上报输入音频数据的音量值
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_DATA_VOLUME;      // 上报输入音频数据的音量值
/*!
 * @brief 回调接口命令定义,已取消在线识别
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_CANCELED;                   // 已取消在线识别
/*!
 * @brief 回调接口命令定义,在线识别超时，没有识别到有效输入
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_TIMEOUT;                   // 在线识别超时
/*!
 * @brief 回调接口命令定义,在线识别出错，返回错误信息
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_ERROR;                   // 在线识别出错

/*!
 * @brief 回调接口命令定义，在线识别服务端无结果返回
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT;

/*!
 * @brief 回调接口命令定义，本地静音超时
 * @see VoiceSessionDelegate
 */
extern const int K_AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT;

/*!
 * 错误码定义
 *
 * 模块还没有初始化
 */
extern const int K_AISDK_ERROR_ONLINE_RECO_NOT_STARTED;

/*!
 * 错误码定义
 *
 * 创建在线识别模块失败
 */
extern const int K_AISDK_ERROR_ONLINE_RECO_CREATE_HANDLE_FAILED;

/*!
 * 回调接口命令定义
 *
 * 获取语音识别Session成功，标识云端已为始语音识别做好准备
 */
extern const int K_AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_SUCCESS;

/*!
 * 回调接口命令定义
 *
 * 回调接口命令定义，获取语音识别Session失败，本次语音识别还未开始就结束了
 */
extern const int K_AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_FAILURE;
/*!
 * 配置项键值定义
 */
// 配置项，key的起始值
extern const int K_AISDK_CONFIG_VOICE_ONLINE_BEGIN;
/*!
 *
 * @see setConfig:value:
 *
 * @brief 配置在线语音超时时间
 *
 * 配置项关键字。
 * ## 功能
 * 配置在线语音超时时间，单位ms
 * ## 值
 * 超时时长
 * ## 示例：
 * ```
 * // 设置在线语音超时时长为10s
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_TIMEOUT,"10000")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_TIMEOUT;
/*!
 *
 * @see setConfig:value:
 *
 * @brief 配置连续对话超时时间
 *
 * 配置项关键字。
 * ## 功能
 * 配置连续对话超时时间，单位ms
 * ## 值
 * 超时时长
 * ## 示例：
 * ```
 * // 设置连续对话超时时长为10s
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_MORESPEECH_TIMEOUT,"10000")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_MORESPEECH_TIMEOUT;

/*!
 *
 * @see setConfig:value:
 *
 * @brief 配置是否开启云端VAD
 *
 * 配置项关键字。
 * ## 功能
 * 配置是否开启云端VAD
 * ## 值
 * 值 |  说明
 *---|---
 * AISDK_CONFIG_VALUE_ENABLE|开启
 * AISDK_CONFIG_VALUE_DISABLE|关闭
 * ## 示例：
 * ```
 * //设置开启云端VAD
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD,AISDK_CONFIG_VALUE_ENABLE)
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD;

/*!
 *
 * @see setConfig:value:
 *
 * @brief 配置是否开启计算音量
 *
 * 配置项关键字
 * ## 功能
 * 配置是
 * 否开启计算音量
 * ## 值
 * 值 |  说明
 *---|---
 * AISDK_CONFIG_VALUE_ENABLE|开启
 * AISDK_CONFIG_VALUE_DISABLE|关闭
 * ## 示例
 * ```
 * //设置开启计算音量
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME,AISDK_CONFIG_VALUE_ENABLE)
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME;


/*!
 *
 * @see setConfig:value:
 *
 * @brief 配置vad静音超时时间，默认500ms
 *
 * 配置项关键字
 * ## 功能
 * 配置vad静音超时时间
 * ## 值
 * ## 示例
 * ```
 * //设置静音时间为500ms
 * aisdkSetConfig(AISDK_CONFIG_VAD_SILENT_MAX,"500")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_VAD_SILENT_MAX;

/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 设置语音识别的语言类型
 *
 * 配置项关键字
 * ## 功能
 * 配置是
 * 设置语音识别的语言类型（仅支持讯飞语音识别引擎）
 * ## 值
 * 值 |  说明
 *---|---
 * 0|默认(普通话)
 * 1|普通话
 * 2|英语
 * ## 示例
 * ```
 * //设置语音类型为普通话
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_LANGUAGE_TYPE,0)
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_LANGUAGE_TYPE;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否保存录音
 *
 * 配置项关键字
 * ## 功能
 * 配置是否保存录音
 * ## 值
 * ## 示例
 * ```
 * //保存录音
 * aisdkSetConfig(AISDK_CONFIG_VOICE_SAVE_SPEECH,"1")
 * //不保存录音
 * aisdkSetConfig(AISDK_CONFIG_VOICE_SAVE_SPEECH,"0")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH;

extern const int K_AISDK_CONFIG_VOICE_VAD_SILENT_MAX;

/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 设置语音识别时静音超时时间
 * ## 默认值 10000ms
 * 配置项关键字
 * ## 示例
 * ```
 * //设置静音超时10s
 * aisdkSetConfig(K_AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT,"10000");
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT;

//extern const int K_AISDK_CONFIG_VOICE_VAD_SILENT_MAX;

/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 设置判断语音结束的静音时间
 * ## 默认值 500ms
 * 配置项关键字
 * ## 示例
 * ```
 * //设置语音结束静音时间为500ms
 * aisdkSetConfig(K_AISDK_CONFIG_VOICE_ONLINE_SIL_TIME,"500")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_SIL_TIME;

/*!
 * @brief 配置语音识别环境
 * @note 配置语音识别环境为正式环境 aisdkSetConfig(AISDK_CONFIG_VOICE_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)
 * @see aisdkSetConfig()
 */
extern const int K_AISDK_CONFIG_VOICE_ENV_TYPE;

/*!
 * @brief 忽略在语音识别中的唤醒
 * // 识别过程中忽略唤醒
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO,"1")
 * // 识别过程中可以唤醒
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO,"0")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO;

/**
 *
 * @brief 在线识别每一次发送网络请求的最小语音数据包，默认0字节，即不缓存每一帧都发出
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE;

/*!
 *@brief 在线识别发SDK处理的每一帧语音的最小数据包，默认3200字节,如果输入的一帧数据不到这个值，SDK会累积到这个值再处理
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_AUDIO_PACKET_SIZE;

// 配置项，key的结束值
extern const int K_AISDK_CONFIG_VOICE_ONLINE_END;

/*!
 * @brief flags标志取值定义:语音识别改为模式。
 */
//extern const int K_AISDK_FLAG_ONLINE_RECO_CLEAR_PREV_SESSION;     // 清空上一次请求的上下文

/*!
 * @brief flags标志取值定义:语音识别改为手动模式。
 */
extern const int K_AISDK_FLAG_ONLINE_RECO_MANUAL_MODE;     // 语音识别改为手动模式。

/*!
 * @brief 返回的json数据中的code定义,成功
 */
extern const int K_AISDK_RESULT_CODE_ONLINE_OK;

/*!
 * @brief 配置是否只识别VAD
 * @note 配置是否只识别VAD，配置后不会发起在线语音识别，只回调VAD的开始和结束
 * 
 * ## 示例：
 * ```
 * // 配置开启只识别VAD
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD,"1")
 * // 配置关闭只识别VAD
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD,"0")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD;

/*!
 * @brief 是否使用本地vad结束，默认开启
 *
 * ## 功能
 * 配置是否使用本地vad结束
 * ## 值
 * ## 示例
 * ```
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD,"1")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD;

/*!
 * @brief 配置输入音频是否已编码，默认关闭，对输入已编码的音频SDK不会再做编码，默认输入未编码音频
 *
 * ## 值
 * ## 示例：
 * ```
 * // 配置输入已编码音频
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_INPUT_ENCODED_DATA,"1")
 * // 配置输入未编码音频
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_INPUT_ENCODED_DATA,"0")
 * ```
 * @note 注意：因为SDK不会对已编码音频做解码，输入已编码音频不会去做本地VAD检查
 *
 * @see AISDK_CONFIG_AUDIO_FORMAT 编码格式由这个配置指定
 */
extern const int K_AISDK_CONFIG_VOICE_ONLINE_INPUT_ENCODED_DATA;
