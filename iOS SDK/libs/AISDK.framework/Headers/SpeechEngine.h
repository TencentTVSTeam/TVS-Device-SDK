/*!
 @header SpeechEngine.h
 @brief AISDK核心类，封装了sdk初始化、参数设定、语音语义以及TTS调度管理
 @author zacardfang
 @copyright © 2017 TENCENT. All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol SessionDelegate <NSObject>

-(NSString *)keyOfSession;
-(void)onSessionCallback:(NSInteger)cmd data:(NSString *)data userData:(id)userData extraData:(NSData *)extraData;
-(BOOL)onSessionIntercept:(NSInteger)cmd;

@end

@interface SpeechEngine : NSObject
@property(nonatomic, strong) NSMutableDictionary *sDelegates;

/*!
 *@brief 获取已经初始化的SpeechEngine实例
 *
 */
+(id)getInitedInstance;

/*!
 *@brief 获取SpeechEngine实例
 *@param app_key 申请的appkey
 *@param acess_token 申请的acesstoken
 *@param dsn uuid 手机的唯一标示
 */
+(id)sharedInstance:(NSString *)app_key acess_token:(NSString*)acess_token withDsn:(NSString *)dsn;

/*!
 *@brief 获取版本信息
 *@return 平台sdkversion-基础sdkversion
 */
-(NSString *)getSDKVersion;

/*!
 *@brief 设置QUA
 *@param vendor 厂商
 *@param product    产品名称
 *@param version    版本名称
 *@param versionNum 版本序列号
 *@param package    bundlerId
 *@param device 设备类型
 */
-(void)setQUA:(NSString*)vendor
      product:(NSString *)product version:(NSString *)version versionNum:(NSString *)versionNum
      package:(NSString *)package device:(NSString *)device;

//-(void)setConfig:(NSInteger)key value:(NSString *)value;

/*!
 * @brief 设置配置项 参看以K_AISDK_CONFIG_*开头的常量定义
 * @param key 配置项关键字 ，见K_AISDK_CONFIG_开头的常量
 * @param value 配置项的值，见K_AISDK_CONFIG_VALUE_开头的常量
 * @see K_AISDK_CONFIG_TTS_TYPE
 * @see K_AISDK_CONFIG_ENV_TYPE
 * @see K_AISDK_CONFIG_AUDIO_FORMAT
 * @see K_AISDK_CONFIG_REQ_TIMEOUT
 * @see K_AISDK_CONFIG_VAD_RATION
 * @see K_AISDK_CONFIG_LOG_LEVEL
 * @see K_AISDK_CONFIG_VOICE_ENGINE
 * @see K_AISDK_CONFIG_TTS_ENGINE
 */
-(void)setConfig:(int)key value:(const char *)value;

/*!
 * @brief 获得相应配置项的值
 * @param key 配置项关键字
 * @return 配置项的值
 */
-(NSString *)getConfig:(NSInteger)key;

/*!
 * @brief 重置状态，释放资源
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
-(NSInteger)releaseSDK;

/*!
 * @brief 注册session
 * @param delegate 根据需要传入VoiceSession、SemanticSession、TtsSession实例
 */
-(void)addSession:(id<SessionDelegate>)delegate;

/*!
 * @brief 注销session
 * @param key session对象的key
 */
-(void)removeSDelegate:(NSString *)key;

/*!
 * 0  -> no net
 * 1 -> WIFI
 * 2 -> 3G/4G
 */
-(void)setNetworkType:(int)type;

@end

// 映射c层常量
/*!
 * @brief 成功
 */
extern const int K_AISDK_RESULT_OK;
/*!
 * @brief 未知错误
 */
extern const int K_AISDK_ERROR_COMMON_UNKNOWN_ERROR;
/*!
 * @brief SDK未初始化
 */
extern const int K_AISDK_ERROR_COMMON_NOT_INITIALIZED;
/*!
 * @brief 内部错误
 */
extern const int K_AISDK_ERROR_COMMON_INTERNAL_ERROR;
/*!
 * @brief 语音超时
 */
//extern const int AISDK_ERROR_COMMON_VOICE_TIMEOUT = 4;

/*!
 * @brief 网络请求发送失败
 */
extern const int K_AISDK_ERROR_COMMON_NETWORK_FAIL;

/*!
 * @brief 网络请求回包失败
 */
extern const int K_AISDK_ERROR_COMMON_NETWORK_RESPONSE_FAIL;

/*!
 * @brief 网络请求超时
 */
extern const int K_AISDK_ERROR_COMMON_NETWORK_TIMEOUT;
// SDK配置文件不存在
// extern const int AISDK_ERROR_COMMON_CONFIG_DOES_NOT_EXIST = 8;

/*!
 * @brief 传入参数错误或不合法
 */
extern const int K_AISDK_ERROR_COMMON_PARAM_INVALID;

/*!
 * @brief 服务返回异常
 */
extern const int K_AISDK_ERROR_COMMOM_SERVICE_RESP;

//========================================================================================

// 通用配置项，key的起始值
extern const int K_AISDK_CONFIG_COMMON_BEGIN;
/*!
 *@see setConfig:value:
 *
 * @brief 配置网络环境
 *
 * 配置项关键字。
 * ## 功能
 * 配置网络环境（服务器）
 * ## 值
 *  AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL - 正式环境
 *  AISDK_CONFIG_VALUE_ENV_TYPE_TEST - 测试环境
 *  AISDK_CONFIG_VALUE_ENV_TYPE_EXP - 体验环境
 * ## 示例：
 * ```
 * //设置环境为测试环境
 * aisdkSetConfig(AISDK_CONFIG_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_TEST)
 * //设置环境为正式环境
 * aisdkSetConfig(AISDK_CONFIG_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)
 * //设置环境为灰度环境
 * aisdkSetConfig(AISDK_CONFIG_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_EXP)
 * ```
 */
extern const int K_AISDK_CONFIG_ENV_TYPE;

/*!
 * @see setConfig:value:
 * @brief 配置TTS返回音频格式
 *
 * 配置项关键字。
 * ## 功能
 * 配置TTS返回音频格式
 * ## 值
 *  K_AISDK_CONFIG_VALUE_TTS_TYPE_MP3-MP3格式
 *
 *  K_AISDK_CONFIG_VALUE_TTS_TYPE_WAV-WAV格式，单声道，采样率为16000,16bit
 *
 *  K_AISDK_CONFIG_VALUE_TTS_TYPE_AMR-AMR格式
 * ## 示例：
 * ```
 * //设置tts类型为mp3
 * aisdkSetConfig(AISDK_CONFIG_TTS_TYPE,AISDK_CONFIG_VALUE_TTS_TYPE_MP3)
 * //设置tts类型为wav
 * aisdkSetConfig(AISDK_CONFIG_TTS_TYPE,AISDK_CONFIG_VALUE_TTS_TYPE_WAV)
 * //设置tts类型为AMR
 * aisdkSetConfig(AISDK_CONFIG_TTS_TYPE,AISDK_CONFIG_VALUE_TTS_TYPE_AMR)
 * ```
 */
extern const int K_AISDK_CONFIG_TTS_TYPE;

/*!
 * @see setConfig:value:
 *
 * @brief 配置请求的语音格式
 *
 * 配置项关键字。
 * ## 功能
 * 配置语音识别的语音编码格式
 * ## 值
 * 值|说明
 * --|--
 * 0|speex
 * 1|wav
 * 2|pcm
 * 3|AMR
 * ## 示例：
 * ```
 * // 配置语音识别的语音编码格式为wav
 * aisdkSetConfig(AISDK_CONFIG_AUDIO_FORMAT,"1")
 * ```
 */
extern const int K_AISDK_CONFIG_AUDIO_FORMAT;


/*!
 * @see setConfig:value:
 *
 * @brief 配置网络请求超时时间
 *
 * 配置项关键字。
 * ## 功能
 * 配置网络请求超时时间，单位ms
 * ## 值
 * 超时时长
 * ## 示例：
 * ```
 * // 设置请求超时时长为5s
 * aisdkSetConfig(AISDK_CONFIG_REQ_TIMEOUT,"5000")
 * ```
 */
extern const int K_AISDK_CONFIG_REQ_TIMEOUT;

/*!
 *@see setConfig:value:
 *
 * @brief 配置VAD灵敏度
 *
 * 配置项关键字。
 * ## 功能
 * 配置VAD灵敏度，值越大，灵敏度越低，建议使用1.1
 * ## 值
 * 时间
 * ## 示例：
 * ```
 * // 设置vad灵敏度为1.1
 * aisdkSetConfig(AISDK_CONFIG_VAD_RATION,"1.1")
 * ```
 */
extern const int K_AISDK_CONFIG_VAD_RATION;

/*!
 * @see setConfig:value:
 * @brief 配置LOG打印级别
 *
 * 配置项关键字。
 * ## 功能
 * 配置LOG打印级别
 * ## 值
 * 值|说明
 * --|--
 * AISDK_CONFIG_VALUE_LOG_LEVEL_DEBUG|只打印debug级别以上日志。
 * AISDK_CONFIG_VALUE_LOG_LEVEL_INFO|只打印info级别以上日志。
 * AISDK_CONFIG_VALUE_LOG_LEVEL_WARN|只打印warn级别以上日志。
 * AISDK_CONFIG_VALUE_LOG_LEVEL_ERROR|只打印error级别以上日志。
 * AISDK_CONFIG_VALUE_LOG_LEVEL_NONE|不打印日志
 * ## 示例：
 * ```
 * // 设置打印日志级别为debug
 * aisdkSetConfig(AISDK_CONFIG_LOG_LEVEL,AISDK_CONFIG_VALUE_LOG_LEVEL_DEBUG)
 * ```
 */
extern const int K_AISDK_CONFIG_LOG_LEVEL;

/*!
 * @see setConfig:value:
 * @brief 配置语音识别引擎
 *
 * 配置项关键字。
 * ## 功能
 * 配置语音识别引擎
 * ## 值
 * 值|说明
 * --|--
 * 0|NONE
 * 1|baidu，百度识别引擎
 * 2|WX，微信识别引擎
 * 3|IFLY，讯飞识别引擎
 * 4|YIYA，腾讯智平(武汉)识别引擎
 * 5|BETA，beta贝塔识别引擎
 * ## 示例：
 * ```
 * // 设置引擎为默认引擎
 * aisdkSetConfig(AISDK_CONFIG_VOICE_ENGINE,"0")
 * ```
 */
extern const int K_AISDK_CONFIG_VOICE_ENGINE;

/*!
 * @see setConfig:value:
 * @brief 配置TTS引擎
 *
 * 配置项关键字。
 * ## 功能
 * 配置TTS引擎
 * ## 值
 * 值|说明
 * --|--
 * 0|NONE
 * 1|baidu，百度引擎
 * 2|WX，微信引擎
 * 3|IFLY，讯飞引擎
 * 4|YIYA，腾讯智平(武汉)引擎
 * 5|BETA，beta贝塔引擎
 * ## 示例：
 * ```
 * // 设置TTS引擎为默认引擎
 * aisdkSetConfig(AISDK_CONFIG_TTS_ENGINE,"0")
 * ```
 */
extern const int K_AISDK_CONFIG_TTS_ENGINE;

/*!
 * @see setConfig:value:
 * @brief 配置位置信息
 *
 * 配置项关键字。
 * ## 功能
 * 配置位置信息,格式：经度|纬度，例如：113.930770|22.543501
 * ## 值
 * 经度纬度用"|"分开传入，例如"113.930770|22.543501"
 *
 * ## 示例：
 * ```
 * // 设置经纬度
 * aisdkSetConfig(AISDK_CONFIG_LBS_DATA,"113.930770|22.543501")
 * ```
 */
extern const int K_AISDK_CONFIG_LBS_DATA;

/*!
 * @see setConfig:value:
 * @brief 配置语音识别模型
 *
 * 配置项关键字。
 * ## 功能
 * 配置语音识别模型
 * ## 值
 * 数值类型，例如：10：通用模型，80：音箱模型，90：车机模型
 *
 * ## 示例：
 * ```
 * // 设置经纬度
 * aisdkSetConfig(AISDK_CONFIG_ASR_DOMAIN,"80")
 * ```
 */
extern const int K_AISDK_CONFIG_ASR_DOMAIN;

/*!
 * @see setConfig:value:
 * @brief 配置聊天机器人
 *
 * 配置项关键字。
 * ## 功能
 * 配置聊天机器人
 * ## 值
 * 字符串类型，包括botType和botID，以"|"隔开
 *
 * ## 示例：
 * ```
 *
 * aisdkSetConfig(AISDK_CONFIG_CHAT_BOT,"ABC|123")
 * ```
 */
extern const int K_AISDK_CONFIG_CHAT_BOT;

/*!
 * @see aisdkSetConfig()
 *
 * @brief 单独配置app key和access token。
 *
 * 配置项关键字。
 * ## 功能
 *
 * ## 值
 * 字符串类型，包括appkey和access token，以"|"隔开
 *
 * ## 示例：
 *
 * ```
 *
 * aisdkSetConfig(AISDK_CONFIG_APP_KEY_AND_TOKEN,"ABC|123")
 * ```
 */
extern const int K_AISDK_CONFIG_APP_KEY_AND_TOKEN;

/*!
 * @see aisdkGetConfig()
 *
 * @brief 获得设备当前GUID
 *
 * ## 功能
 * 获得设备当前GUID
 * ## 示例：
 *
 * ```
 * aisdkGetConfig(AISDK_CONFIG_GUID)
 * ```
 */
extern const int K_AISDK_CONFIG_GUID;

/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置保存录音的路径，默认是保存在工作目录下的
 *
 * 配置项关键字
 * ## 功能
 * 配置保存录音的路径
 * ## 值
 * ## 示例
 * ```
 * //保存录音路径
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH,"/data/wakeup_audio")
 * ```
 */
extern const int K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH;

/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否保存录音，每次唤醒保存一个文件
 *
 * 配置项关键字
 * ## 功能
 * 配置是否保存录音
 * ## 值
 * ## 示例
 * ```
 * //保存录音
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED,"1")
 * //不保存录音
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED,"0")
 * ```
 */
extern const int K_AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED;


/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置唤醒音频上传的网络
 *
 * 配置项关键字
 * ## 功能 （NO_UPLOADING = "0"，ONLY_WIFI = "1"，ONLY_4G = "2"，BOTH_WIFI_AND_4G = "3"）
 *
 */
extern const int K_AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE;

/*!
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置保存文件的最大数量
 *
 * 配置项关键字
 * ## 功能
 * 配置保存文件的最大数量
 * ## 值
 * ## 示例
 * ```
 * //保存录音文件的最大数量
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE,"10")
 * ```
 */
extern const int K_AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE;

/*!
 * @see aisdkSetConfig()
 *
 * @brief 配置APP版本号
 *
 * ## 功能
 * 配置渠道号
 *
 */
extern const int K_AISDK_CONFIG_APP_VERSION_NUM;

/*!
 * @brief 唤醒录音文件控制命令，内部使用
 *
 * 配置项关键字
 * ## 功能 (CMD_DO_UPLOAD = "1", CMD_CANCEL_UPLOAD = "2")
 * 唤醒录音文件控制命令
 * ## 值
 */
extern const int K_AISDK_CONFIG_WAKEUP_BUFFER_CONTROL;

/*!
 * @brief 配置是否开启沙箱环境，默认关闭
 *
 * ## 功能
 * 配置是否开启沙箱环境，默认关闭
 * ## 值
 * 值|说明
 * --|--
 * K_AISDK_CONFIG_VALUE_ENABLE|开启沙箱环境
 * K_AISDK_CONFIG_VALUE_DISABLE|关闭沙箱环境
 *
 */
extern const int K_AISDK_CONFIG_OPEN_SANDBOX;


extern const int K_AISDK_CONFIG_WAKEUP_SAVE_SPEECH;


// 通用配置项，key的结束值
extern const int K_AISDK_CONFIG_COMMON_END;

// 配置项的值 begin

/*!
 *
 * @brief 开启
 */
extern const char* const K_AISDK_CONFIG_VALUE_ENABLE;

/*!
 * @brief 禁用
 */
extern const char* const K_AISDK_CONFIG_VALUE_DISABLE;

/*!
 * @brief 网络环境：正式环境
 */
extern const char* const K_AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL;
//
/*!
 * @brief 网络环境：测试环境
 */
extern const char* const K_AISDK_CONFIG_VALUE_ENV_TYPE_TEST;
//
/*!
 * @brief 网络环境：体验环境
 */
extern const char* const K_AISDK_CONFIG_VALUE_ENV_TYPE_EXP;
//
/*!
 * @brief TTS格式：MP3
 */
extern const char* const K_AISDK_CONFIG_VALUE_TTS_TYPE_MP3;
//
/*!
 * @brief TTS格式：WAV
 */
extern const char* const K_AISDK_CONFIG_VALUE_TTS_TYPE_WAV;
//
/*!
 * @brief TTS格式：AMR
 */
extern const char* const K_AISDK_CONFIG_VALUE_TTS_TYPE_AMR;
// Log begin
/*!
 * @brief 日志级别，debug
 */
extern const char* const K_AISDK_CONFIG_VALUE_LOG_LEVEL_DEBUG;
/*!
 * @brief 日志级别，info
 */
extern const char* const K_AISDK_CONFIG_VALUE_LOG_LEVEL_INFO;
/*!
 * @brief 日志级别，warn
 */
extern const char* const K_AISDK_CONFIG_VALUE_LOG_LEVEL_WARN;
/*!
 * @brief 日志级别，error
 */
extern const char* const K_AISDK_CONFIG_VALUE_LOG_LEVEL_ERROR;
/*!
 * @brief 日志级别，none
 */
extern const char* const K_AISDK_CONFIG_VALUE_LOG_LEVEL_NONE;
// Log info
// 配置项的值 end
