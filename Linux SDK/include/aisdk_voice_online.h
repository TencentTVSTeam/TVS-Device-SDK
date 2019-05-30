
/**
 * @file
 * @author shengyujin
 * @date 2017/8/1
 * @brief 在线语音识别相关接口
 * @note
 * @copyright © 2017 TENCENT. All rights reserved.
 */
#ifndef PACKAGE_TMS_AISDK_AISDK_VOICE_ONLINE_H
#define PACKAGE_TMS_AISDK_AISDK_VOICE_ONLINE_H

#ifdef WIN32
#define AISDK_API_EXPORTS __declspec(dllexport)
#define AISDK_CALL_CONV __stdcall
#else
#define AISDK_API_EXPORTS
#define AISDK_CALL_CONV
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 回调接口命令定义,在线识别开始，接受录音数据
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_START = 6000;

/**
 * @brief 回调接口命令定义,在线语音VAD检测到开始
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_SPEECH_START = AISDK_CMD_ONLINE_RECO_START + 1;

/**
 * @brief 回调接口命令定义,在线语音vad检测完成，可以停止输入录音数据
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_SPEECH_END = AISDK_CMD_ONLINE_RECO_START + 2;

/**
 * @brief 回调接口命令定义,返回在线识别结果
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_RESULT = AISDK_CMD_ONLINE_RECO_START + 3;

/**
 * @brief 回调接口命令定义,返回在线识别的中间结果
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT = AISDK_CMD_ONLINE_RECO_START + 4;

/**
 * @brief 回调接口命令定义,返回输入音频数据的音量值
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_DATA_VOLUME = AISDK_CMD_ONLINE_RECO_START + 5;

/**
 * @brief 回调接口命令定义,已取消在线识别
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_CANCELED = AISDK_CMD_ONLINE_RECO_START + 6;

/**
 * @brief 回调接口命令定义,在线识别超时，没有识别到有效输入
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_TIMEOUT = AISDK_CMD_ONLINE_RECO_START + 7;

/**
 * @brief 回调接口命令定义,在线识别出错，返回错误信息
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_ERROR = AISDK_CMD_ONLINE_RECO_START + 8;

/**
 * @brief 回调接口命令定义,在线识别云端长时间没有识别到结果
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT = AISDK_CMD_ONLINE_RECO_START + 9;

/**
 * @brief 回调接口命令定义,完整模式的在线识别流程结束（以FULL_MODE启动时才会回调）
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_FULL_MODE_FINISHED = AISDK_CMD_ONLINE_RECO_START + 10;

/**
 * @brief 回调接口命令定义，本地VAD检测静音超时
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT = AISDK_CMD_ONLINE_RECO_START + 11;

/**
 * @brief 回调接口命令定义，获取语音识别Session成功，标识云端已为始语音识别做好准备
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_SUCCESS = AISDK_CMD_ONLINE_RECO_START + 12;

/**
 * @brief 回调接口命令定义，获取语音识别Session失败，本次语音识别还未开始就结束了
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_FAILURE = AISDK_CMD_ONLINE_RECO_START + 13;

/**
 * @brief 回调接口命令定义，oneshot短模式检测vad开始静音超时
 * 如果唤醒后在很短的时间内没有检测到说话，就会回调这个命令，此时接入方可以播放唤醒提示音，
 * 反之如果唤醒后在很短的时间内检测到说话了，就不会回调这个命令，这样用户连续输入不会被提示音干扰
 * 超时时间配置见@see AISDK_CONFIG_VOICE_VAD_SILENT_MAX
 * 目前不建议在除了Linux以外的端使用短模式
 */
const int AISDK_CMD_ONLINE_RECO_ONESHOT_SHORT_MODE_TIMEOUT = AISDK_CMD_ONLINE_RECO_START + 14;

/**
 * 函数返回错误码定义
 *
 * 模块还没有初始化
 */
const int AISDK_ERROR_ONLINE_RECO_NOT_STARTED = 6000;

/**
 * 创建在线识别模块失败
 */
const int AISDK_ERROR_ONLINE_RECO_CREATE_HANDLE_FAILED = AISDK_ERROR_ONLINE_RECO_NOT_STARTED + 1;

/**
 * 语音识别已经启动，不需要重复启动
 */
const int AISDK_ERROR_ONLINE_RECO_ALREADY_STARTED = AISDK_ERROR_ONLINE_RECO_NOT_STARTED + 2;

/**
 * 配置项键值定义
 */
// 配置项，key的起始值
const int AISDK_CONFIG_VOICE_ONLINE_BEGIN = 6000;
/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置在线语音超时时间，默认10s
 *
 * 配置项关键字。
 * ## 功能
 * 配置在线语音超时时间，单位ms
 * ## 值
 * 超时时长，默认10s
 * ## 示例：
 * ```
 * // 设置在线语音超时时长为10s
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_TIMEOUT,"10000")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_TIMEOUT = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 1;

///**
// *
// * @see aisdkSetConfig()
// *
// * @brief 配置连续对话超时时间
// *
// * 配置项关键字。
// * ## 功能
// * 配置连续对话超时时间，单位ms
// * ## 值
// * 超时时长
// * ## 示例：
// * ```
// * // 设置连续对话超时时长为10s
// * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_MORESPEECH_TIMEOUT,"10000")
// * ```
// */
////const int AISDK_CONFIG_VOICE_ONLINE_MORESPEECH_TIMEOUT = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 2;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否开启云端VAD，默认开启
 *
 * 配置项关键字。
 * ## 功能
 * 配置是否开启云端VAD
 * ## 值
 * 值 |  说明
 *---|---
 * AISDK_CONFIG_VALUE_ENABLE|开启(默认)
 * AISDK_CONFIG_VALUE_DISABLE|关闭
 * ## 示例：
 * ```
 * //设置开启云端VAD
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD,AISDK_CONFIG_VALUE_ENABLE)
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 3;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否开启计算音量，默认关闭
 *
 * 配置项关键字
 * ## 功能
 * 配置是
 * 否开启计算音量
 * ## 值
 * 值 |  说明
 *---|---
 * AISDK_CONFIG_VALUE_ENABLE|开启
 * AISDK_CONFIG_VALUE_DISABLE|关闭(默认)
 * ## 示例
 * ```
 * //设置开启计算音量
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME,AISDK_CONFIG_VALUE_ENABLE)
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 4;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置oneshot短模式检测vad开始静音超时时间，默认500ms
 * 用于检查唤醒后用户在启动识别后的指定时间内是否开始说话，如果没有说话可以播放唤醒提示音，避免用户唤醒后连续说话时播放提示音干扰用户
 * 超时的回调命令是AISDK_CMD_ONLINE_RECO_ONESHOT_SHORT_MODE_TIMEOUT
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
const int AISDK_CONFIG_VOICE_VAD_SILENT_MAX = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 5;

/**
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
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_LANGUAGE_TYPE,"0")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_LANGUAGE_TYPE = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 6;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否保存录音，默认关闭
 *
 * 配置项关键字
 * ## 功能
 * 配置是否保存录音
 * ## 值
 * ## 示例
 * ```
 * //保存录音
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH,"1")
 * //不保存录音
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH,"0")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 7;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 设置语音识别的静音超时时间，默认10s
 *
 * 配置项关键字
 * ## 功能
 * 配置语音识别的静音超时时间
 * ## 值
 * ## 示例
 * ```
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT,"10000")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 8;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 设置语音识别的尾部静音结束时间，默认500ms
 *
 * 配置项关键字
 * ## 功能
 * 配置语音识别的尾部静音结束时间
 * ## 值
 * ## 示例
 * ```
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_SIL_TIME,"500")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_SIL_TIME = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 9;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 是否使用本地vad结束，默认开启
 *
 * 配置项关键字
 * ## 功能
 * 配置是否使用本地vad结束
 * ## 值
 * ## 示例
 * ```
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD,"1")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 10;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 在线识别发SDK处理的每一帧语音的最小数据包，默认3200字节
 *
 * 配置项关键字
 * ## 功能
 * 在线识别发SDK处理的每一帧语音的最小数据包，如果输入的一帧数据不到这个值，SDK会累积到这个值再处理
 * ## 值
 * ## 示例
 * ```
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_AUDIO_PACKET_SIZE,"2048")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_AUDIO_PACKET_SIZE = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 11;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置语音识别环境，默认正式环境
 *
 * ## 功能
 * 配置语音识别环境。
 * ## 值
 * 值|说明
 * ## 示例：
 * ```
 * // 配置语音识别环境为正式环境
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)
 * ```
 */
const int AISDK_CONFIG_VOICE_ENV_TYPE = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 12;

/**
 * @brief 在语音识别过程中是否忽略唤醒，不自动停止语音识别，默认关闭
 *
 * 配置项关键字。
 * ## 功能
 * 在语音识别过程中是否忽略唤醒，不自动停止语音识别
 *
 * ## 值
 * ## 示例：
 * ```
 * // 识别过程中忽略唤醒
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO,"1")
 * // 识别过程中可以唤醒
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO,"0")
 * ```
*/
const int AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 13;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置输入音频是否已编码，默认关闭
 *
 * 配置项关键字。
 * ## 功能
 * 配置语音识别的输入音频是否已编码，对输入已编码的音频SDK不会再做编码，默认输入未编码音频
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
const int AISDK_CONFIG_VOICE_ONLINE_INPUT_ENCODED_DATA = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 14;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否只识别VAD，默认关闭
 *
 * 配置项关键字。
 * ## 功能
 * 配置是否只识别VAD，配置后不会发起在线语音识别，只回调VAD的开始和结束
 *
 * ## 值
 * ## 示例：
 * ```
 * // 配置开启只识别VAD
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD,"1")
 * // 配置关闭只识别VAD
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD,"0")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 15;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 在线识别每一次发送网络请求的最小语音数据包，默认0字节，即不缓存每一帧都发出
 *
 * 配置项关键字
 * ## 功能
 * 在线识别每一次发送网络请求的最小语音数据包，如果输入的数据累积达不到这个值，就缓存等到超过这个值再发送请求
 * ## 值
 * ## 示例
 * ```
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_AUDIO_PACKET_SIZE,"2048")
 * ```
 */
const int AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE = AISDK_CONFIG_VOICE_ONLINE_BEGIN + 16;

// 配置项，key的结束值
const int AISDK_CONFIG_VOICE_ONLINE_END = 6999;

/**
 * @brief flags标志取值定义:语音识别改为完整模式，一个接口完成语音、语义、TTS流程。
 */
const int AISDK_FLAG_ONLINE_RECO_FULL_MODE = 0x01;

/**
 * @brief flags标志取值定义:语音识别改为手动模式。
 */
const int AISDK_FLAG_ONLINE_RECO_MANUAL_MODE = 0x02;

/**
 * 清空上一次请求的上下文
 */
const int AISDK_FLAG_ONLINE_SEMANTIC_CLEAR_PREV_SESSION = 0x04;

/**
 * 退出当前请求的上下文
 */
const int AISDK_FLAG_ONLINE_SEMANTIC_EXIT_CUR_SESSION = 0x08;

/**
 * 返回的json数据中的code定义
 */
 /**
  * 成功
  */
const int AISDK_RESULT_CODE_ONLINE_OK = 0;

/**
 * 语音识别被唤醒打断
 */
const int AISDK_RESULT_CODE_ONLINE_CANCELED_BY_WAKEUP = 1;

/**
 * @brief 初始化语音识别vad模型，如果没有接入新版vad，不需要调用此方法
 * @param resDir VAD模型所在的根目录
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkInitOnlineVoice2Text(const char* modelPath);

/**
 * @brief 开始一次语音识别流程
 * @param userData 自定义数据指针。callback时带回。
 * @param len 自定义数据长度。
 * @param flags 控制标志，参考AISDK_FLAG_ONLINE_RECO_*常量定义，支持多flag或运算。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkStartOnlineVoice2Text(void* userData, int len, int flags);

/**
 * @brief 输入在线录音数据
 * @param data 录音数据存储区域。建议长度为4096.
 * @param dataLen 录音数据长度。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 * @warning:
 *      上层应用应当把实时录音数据通过该接口输入到SDK（建议每次输入4096字节长度的音频）。
 *   在调用此接口过程中，会有VAD检测到开始、VAD检测到结束、实时音量、语音识别到结果等
 *   状态的回调。遇到AISDK_CMD_ONLINE_RECO_CANCELED/AISDK_CMD_ONLINE_RECO_TIME
 *   OUT/AISDK_CMD_ONLINE_RECO_ERROR/AISDK_CMD_ONLINE_RECO_RESULT时，停止调用
 *   该函数。
 */
AISDK_API_EXPORTS int aisdkInputOnlineVoice2TextAudioData(char* data, int dataLen);

/**
* @brief 取消本次语音识别
* @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
*/
AISDK_API_EXPORTS int aisdkCancelOnlineVoice2Text();

/**
* @brief 停止本次语音识别，获取语音识别结果。
 *@warning 停止后，不会中断语音识别，SDK会将现在已经接收到的音频发送到后台请求语音识别结果。
* @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
*/
AISDK_API_EXPORTS int aisdkStopOnlineVoice2Text();

/**
* @brief 获取本地vad库和模型的版本号
* @return 版本号字符串
*/
AISDK_API_EXPORTS const char* aisdkGetVadVersion();

#ifdef __cplusplus
}
#endif

#endif //PACKAGE_TMS_AISDK_AISDK_VOICE_ONLINE_H
