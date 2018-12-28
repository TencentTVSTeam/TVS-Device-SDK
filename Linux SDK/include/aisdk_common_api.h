/**
 * @file
 * @author shengyujin
 * @date 2017/8/1
 * @brief AISDK通用接口
 * @note
 * @copyright © 2017 TENCENT. All rights reserved.
 */
#ifndef PACKAGE_TMS_AISDK_AISDK_COMMON_API_H
#define PACKAGE_TMS_AISDK_AISDK_COMMON_API_H

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
 * @brief 回调接口命令定义，收到服务端的push消息
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_COMMON_PUSH_MSG = 1;

/**
 * @brief 通用错误码定义
 */
/**
 * @brief 成功
 */
const int AISDK_RESULT_OK = 0;
/**
 * @brief 未知错误
 */
const int AISDK_ERROR_COMMON_UNKNOWN_ERROR = 1;
/**
 * @brief SDK未初始化
 */
const int AISDK_ERROR_COMMON_NOT_INITIALIZED = 2;
/**
 * @brief 内部错误
 */
const int AISDK_ERROR_COMMON_INTERNAL_ERROR = 3;
/**
 * @brief 语音超时
 */
//const int AISDK_ERROR_COMMON_VOICE_TIMEOUT = 4;

/**
 * @brief 网络请求发送失败
 */
const int AISDK_ERROR_COMMON_NETWORK_FAIL = 5;

/**
 * @brief 网络请求回包失败
 */
const int AISDK_ERROR_COMMON_NETWORK_RESPONSE_FAIL = 6;

/**
 * @brief 网络请求超时
 */
const int AISDK_ERROR_COMMON_NETWORK_TIMEOUT = 7;
// SDK配置文件不存在
// const int AISDK_ERROR_COMMON_CONFIG_DOES_NOT_EXIST = 8;

/**
 * @brief 传入参数错误或不合法
 */
const int AISDK_ERROR_COMMON_PARAM_INVALID = 9;
/**
 * @brief 服务返回异常
 */
const int AISDK_ERROR_COMMON_SERVICE_RESP = 10;

/**
 * @brief 运行不佳
 */
const int AISDK_ERROR_COMMON_BAD_PERFORMANCE = 11;

/**
 * @brief 初始化时未设置Appkey和AccessToken
 */
const int AISDK_ERROR_COMMON_APPKEY_NOT_SET = 12;

// 通用配置项，key的起始值
const int AISDK_CONFIG_COMMON_BEGIN = 0;
/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置网络环境
 *
 * 配置项关键字。
 * ## 功能
 * 配置网络环境（服务器）
 * ## 值
 *  AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL-正式环境
 *
 *  AISDK_CONFIG_VALUE_ENV_TYPE_TEST-测试环境
 * ## 示例：
 * ```
 * //设置环境为测试环境
 * aisdkSetConfig(AISDK_CONFIG_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_TEST)
 * //设置环境为正式环境
 * aisdkSetConfig(AISDK_CONFIG_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)
 * ```
 */
const int AISDK_CONFIG_ENV_TYPE = AISDK_CONFIG_COMMON_BEGIN + 1;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置TTS返回音频格式
 *
 * 配置项关键字。
 * ## 功能
 * 配置TTS返回音频格式
 * ## 值
 *  AISDK_CONFIG_VALUE_TTS_TYPE_MP3-MP3格式
 *
 *  AISDK_CONFIG_VALUE_TTS_TYPE_WAV-WAV格式，单声道，采样率为16000,16bit
 *
 *  AISDK_CONFIG_VALUE_TTS_TYPE_AMR-AMR格式
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
const int AISDK_CONFIG_TTS_TYPE = AISDK_CONFIG_COMMON_BEGIN + 2;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置请求的语音格式
 *
 * 配置项关键字。
 * ## 功能
 * 配置语音识别的语音编码格式
 * ## 值
 * 值|说明
 * --|--
 * 1|pcm
 * 2|wav
 * 4|pcm
 * 5|AMR
 * ## 示例：
 * ```
 * // 配置语音识别的语音编码格式为wav
 * aisdkSetConfig(AISDK_CONFIG_AUDIO_FORMAT,"1")
 * ```
 */
const int AISDK_CONFIG_AUDIO_FORMAT = AISDK_CONFIG_COMMON_BEGIN + 3;


/**
 * @see aisdkSetConfig()
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
const int AISDK_CONFIG_REQ_TIMEOUT = AISDK_CONFIG_COMMON_BEGIN + 4;

/**
 *
 * @see aisdkSetConfig()
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
const int AISDK_CONFIG_VAD_RATION = AISDK_CONFIG_COMMON_BEGIN + 5;

/**
 * @see aisdkSetConfig()
 *
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
const int AISDK_CONFIG_LOG_LEVEL = AISDK_CONFIG_COMMON_BEGIN + 6;

/**
 * @see aisdkSetConfig()
 *
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
const int AISDK_CONFIG_VOICE_ENGINE = AISDK_CONFIG_COMMON_BEGIN + 7;

/**
 * @see aisdkSetConfig()
 *
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
const int AISDK_CONFIG_TTS_ENGINE = AISDK_CONFIG_COMMON_BEGIN + 8;

/**
 * @see aisdkSetConfig()
 *
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
const int AISDK_CONFIG_LBS_DATA = AISDK_CONFIG_COMMON_BEGIN + 9;

/**
 * @see aisdkSetConfig()
 *
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
 * // 设置识别模型
 * aisdkSetConfig(AISDK_CONFIG_ASR_DOMAIN,"80")
 * ```
 */
const int AISDK_CONFIG_ASR_DOMAIN = AISDK_CONFIG_COMMON_BEGIN + 10;

/**
 * @see aisdkSetConfig()
 *
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
const int AISDK_CONFIG_CHAT_BOT = AISDK_CONFIG_COMMON_BEGIN + 11;

/**
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
const int AISDK_CONFIG_APP_KEY_AND_TOKEN = AISDK_CONFIG_COMMON_BEGIN + 12;



/**
 * @see aisdkSetConfig()
 *
 * @brief 配置LOG是否同步打印
 *
 * 配置项关键字。
 * ## 功能
 * 配置LOG是否同步打印，默认异步打印。
 * ## 值
 * 值|说明
 * --|--
 * AISDK_CONFIG_VALUE_ENABLE|开启同步打印日志。
 * AISDK_CONFIG_VALUE_DISABLE|异步打印日志。
 * ## 示例：
 * ```
 * // 设置同步打印日志
 * aisdkSetConfig(AISDK_CONFIG_LOG_SYNC,AISDK_CONFIG_VALUE_ENABLE)
 * ```
 */
const int AISDK_CONFIG_LOG_SYNC = AISDK_CONFIG_COMMON_BEGIN + 14;

/**
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
const int AISDK_CONFIG_GUID = AISDK_CONFIG_COMMON_BEGIN + 15;

/**
 * @see aisdkGetConfig()
 *
 * @brief 获得设备当前QUA
 *
 * ## 功能
 * 获得设备当前QUA
 * ## 示例：
 *
 * ```
 * aisdkGetConfig(AISDK_CONFIG_QUA)
 * ```
 */
const int AISDK_CONFIG_QUA= AISDK_CONFIG_COMMON_BEGIN + 16;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置LOG打印的时间格式
 *
 * 配置项关键字。
 * ## 功能
 * 配置LOG打印的时间格式
 * ## 值
 * 值|说明
 * --|--
 * "1"|打印日志的时间戳为秒级别。
 * "2"|打印日志的时间戳为毫秒级别，慎用，有性能损耗。
 * ## 示例：
 * ```
 * // 设置打印日志级别为debug
 * aisdkSetConfig(AISDK_CONFIG_LOG_TIME_FORMAT,"1")
 * ```
 */
const int AISDK_CONFIG_LOG_TIME_FORMAT = AISDK_CONFIG_COMMON_BEGIN + 17;



/**
 * @see aisdkSetConfig()
 *
 * @brief 配置当前网络类型
 *
 * ## 功能
 * 配置当前网络类型
 * ## 值
 * 取值参考AISDK_CONFIG_VALUE_APN_XXX
 * ## 示例：
 *
 * ```
 * aisdkSetConfig(AISDK_CONFIG_APN_TYPE, XXX)
 * ```
 */
const int AISDK_CONFIG_NETWORK_TYPE = AISDK_CONFIG_COMMON_BEGIN + 18;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置当前网络状态
 *
 * ## 功能
 * 配置当前网络状态
 * ## 值
 * "1":有网
 * "0":无网
 * ## 示例：
 *
 * ```
 * //配置当前网络为有网
 * aisdkSetConfig(AISDK_CONFIG_NETWORK_STATUS, "1")
 * ```
 */
const int AISDK_CONFIG_NETWORK_STATUS = AISDK_CONFIG_COMMON_BEGIN + 19;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置渠道号
 *
 * ## 功能
 * 配置渠道号
 *
 */
const int AISDK_CONFIG_CHANNEL_ID = AISDK_CONFIG_COMMON_BEGIN + 20;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置回复语规范
 *
 * ## 功能
 * 配置回复语规范，取值范围：1，2
 *
 */
const int AISDK_CONFIG_RSP_VERSION = AISDK_CONFIG_COMMON_BEGIN + 21;

/**
 * @see aisdkSetConfig()
 *
 * @brief 配置日志文件大小
 *
 * ## 功能
 * 配置配置日志文件大小，单位MB，此配置只能在init方法调用之前设置
 *
 */
const int AISDK_CONFIG_LOG_MAX_SIZE = AISDK_CONFIG_COMMON_BEGIN + 22;

// 通用配置项，key的结束值
const int AISDK_CONFIG_COMMON_END = 999;

// 配置项的值 begin

/**
 *
 * 开启
 */
const char* const AISDK_CONFIG_VALUE_ENABLE = "1";

/**
 * 禁用
 */
const char* const AISDK_CONFIG_VALUE_DISABLE = "0";

/**
 * 网络环境：正式环境
 */
const char* const AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL = "0";
//
/**
 * 网络环境：测试环境
 */
const char* const AISDK_CONFIG_VALUE_ENV_TYPE_TEST = "1";
//
/**
 * TTS格式：MP3
 */
const char* const AISDK_CONFIG_VALUE_TTS_TYPE_MP3 = "0";
//
/**
 * TTS格式：WAV
 */
const char* const AISDK_CONFIG_VALUE_TTS_TYPE_WAV = "1";
//
/**
 * TTS格式：AMR
 */
const char* const AISDK_CONFIG_VALUE_TTS_TYPE_AMR = "2";
// Log begin
/**
 * 日志级别，debug
 */
const char* const AISDK_CONFIG_VALUE_LOG_LEVEL_DEBUG = "5";
/**
 * 日志级别，info
 */
const char* const AISDK_CONFIG_VALUE_LOG_LEVEL_INFO = "4";
/**
 * 日志级别，warn
 */
const char* const AISDK_CONFIG_VALUE_LOG_LEVEL_WARN = "3";
/**
 * 日志级别，error
 */
const char* const AISDK_CONFIG_VALUE_LOG_LEVEL_ERROR = "2";
/**
 * 日志级别，none
 */
const char* const AISDK_CONFIG_VALUE_LOG_LEVEL_NONE = "1";
// Log info
// 配置项的值 end

/**
 * APN类型：未知
 */
const char* const AISDK_CONFIG_VALUE_WIFI = "0";
/**
 * APN类型：CMWAP
 */
const char* const AISDK_CONFIG_VALUE_APN_CMWAP = "1";
/**
 * APN类型：CMNET
 */
const char* const AISDK_CONFIG_VALUE_APN_CMNET = "2";
/**
 * APN类型：UNWAP
 */
const char* const AISDK_CONFIG_VALUE_APN_UNWAP = "3";
/**
 * APN类型：UNNET
 */
const char* const AISDK_CONFIG_VALUE_APN_UNNET= "4";
/**
 * APN类型：CTWAP
 */
const char* const AISDK_CONFIG_VALUE_APN_CTWAP = "5";
/**
 * APN类型：CTNET
 */
const char* const AISDK_CONFIG_VALUE_APN_CTNET = "6";
/**
 * APN类型：3GWAP
 */
const char* const AISDK_CONFIG_VALUE_APN_3GWAP = "7";
/**
 * APN类型：3GNET
 */
const char* const AISDK_CONFIG_VALUE_APN_3GNET = "8";

/**
 * @define 设置回调函数原型

 * @param cmd 当前的指令，指示参数data的内容解析方式和含义, 定义由各模块指定(AISDK_CMD_*开头的常量)
 * @param data 数据存储区域
 * @param len data的长度
 * @param userData 传回用户自定义数据，此数据是在用户发起请求是传入的
 * @param userDataLen 用户自定义数据长度
 * @param extraData 附加数据，如果没有返回NULL
 * @param extraDataLen 附加数据长度
 * @warning 不要在回调函数内做任何阻塞的操作。否则会阻塞其他回调。
 *
 * 回调命令
 * @see 参见各接口头文件的AISDK_CMD_*常量定义
 *
*/
typedef void (AISDK_CALL_CONV *AISDK_CALLBACK)(int cmd, char* data, int dataLen, void* userData, int userDataLen,
                                               void *extraData, int extraDataLen);

/**
 * @brief 设置回调函数
 * @param in callbackPtr 回调函数指针
 * @return
 * @note
 *
 */
AISDK_API_EXPORTS void aisdkSetCallback(AISDK_CALLBACK callbackPtr);

/**
 * @brief 初始化函数
 * @param in folderPath 配置路径
 * @param in appKey 应用的appkey，需要从平台申请
 * @param in accessToken 应用的access token
 * @return <em>0</em>:ok others:fail。 错误码定义见AISDK_ERROR_*常量
 * @note
 */
AISDK_API_EXPORTS int aisdkInit(const char* folderPath, const char* appKey, const char* accessToken);

/**
 * @brief 初始化函数
 * @param in folderPath 配置路径
 * @param in sharedFilePath 共享文件路径（用于多个接入应用共享的文件存储）
 * @param in appKey 应用的appkey，需要从平台申请
 * @param in accessToken 应用的access token
 * @return <em>0</em>:ok others:fail。 错误码定义见AISDK_ERROR_*常量
 * @note
 */
AISDK_API_EXPORTS int aisdkFullInit(const char* folderPath, const char* sharedFilePath, const char* appKey, const char* accessToken);
/**
 * @brief 设置QUA
 * @param platform  平台
 * @param vendor  厂商
 * @param product 产品名称
 * @param versionNum 版本序列号
 * @param package 包名
 * @param device 设备类型
 * @note
 *
 */
AISDK_API_EXPORTS void aisdkSetQUA(const char* platform,
                                   const char* vendor,
                                   const char* product,
                                   const char* versionNum,
                                   const char* package,
                                   const char* device
                                    );

/**
 * @brief 设置配置项
 * @param in key 配置项关键字 ，见AISDK_CONFIG_开头的常量
 * @param in value 配置项的值，见AISDK_CONFIG_VALUE_开头的常量
 *
 * @see AISDK_CONFIG_TTS_TYPE <br>
 *      AISDK_CONFIG_ENV_TYPE <br>
 *      AISDK_CONFIG_AUDIO_FORMAT <br>
 *      AISDK_CONFIG_REQ_TIMEOUT <br>
 *      AISDK_CONFIG_VAD_RATION <br>
 *      AISDK_CONFIG_LOG_LEVEL <br>
 *      AISDK_CONFIG_VOICE_ENGINE <br>
 *      AISDK_CONFIG_TTS_ENGINE <br>
 *      等等以AISDK_CONFIG_*开头的常量定义
 */
AISDK_API_EXPORTS void aisdkSetConfig(int key, const char* value);
/**
 * @brief 获得相应配置项的值
 * @param in key 配置项关键字
 * @return 配置项的值
 */
AISDK_API_EXPORTS const char* aisdkGetConfig(int key);

/**
* @brief 重置状态，释放资源
* @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
*/
AISDK_API_EXPORTS int aisdkRelease();
/**
 * @brief 获得SDK版本号
 * @return 版本号
 */
AISDK_API_EXPORTS const char * aisdkGetVersion();

#ifdef __cplusplus
}
#endif

#endif //PACKAGE_TMS_AISDK_AISDK_COMMON_API_H
