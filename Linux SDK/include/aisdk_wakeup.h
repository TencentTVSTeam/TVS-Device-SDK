/**
 * @file
 * @author shengyujin
 * @date 2017/8/1
 * @brief 唤醒相关接口
 * @note
 * @copyright © 2017 TENCENT. All rights reserved.
 */


#ifndef PACKAGE_TMS_AISDK_AISDK_WAKEUP_H
#define PACKAGE_TMS_AISDK_AISDK_WAKEUP_H


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
 * 回调接口命令定义
 */
/**
 * @brief 回调接口命令定义，唤醒识别开始，接受录音数据
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_WAKEUP_RECO_START = 7000;

/**
 *
 * @brief 回调接口命令定义，唤醒检测完成，可以停止输入录音数据，返回唤醒识别结果
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_WAKEUP_RECO_RESULT = AISDK_CMD_WAKEUP_RECO_START + 1;

/**
 *
 * @brief 回调接口命令定义，唤醒识别出错
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_WAKEUP_RECO_ERROR = AISDK_CMD_WAKEUP_RECO_START + 2;

/**
 * @brief 回调接口命令定义，已取消唤醒识别
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_WAKEUP_RECO_CANCELED = AISDK_CMD_WAKEUP_RECO_START + 3;
/*************************************************************
 * START:配置项key定义
 * ***********************************************************/
// 配置项，key的起始值
const int AISDK_CONFIG_WAKEUP_BEGIN = 7000;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置唤醒识别超时时间（已废弃）
 *
 * 配置项关键字
 * ## 功能
 * 配置唤醒识别超时时间，已废弃，请勿使用
 */
const int AISDK_CONFIG_WAKEUP_TIMEOUT = AISDK_CONFIG_WAKEUP_BEGIN + 1;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否保存录音，所有输入音频都保存在一个文件中，默认关闭
 *
 * 配置项关键字
 * ## 功能
 * 配置是否保存录音
 * ## 值
 * ## 示例
 * ```
 * //保存录音
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_SAVE_SPEECH,"1")
 * //不保存录音
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_SAVE_SPEECH,"0")
 * ```
 */
const int AISDK_CONFIG_WAKEUP_SAVE_SPEECH = AISDK_CONFIG_WAKEUP_BEGIN + 2;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置是否保存每一次唤醒识别的录音，每次唤醒保存一个文件，默认关闭
 *
 * 配置项关键字
 * ## 功能
 * 配置是否保存每一次唤醒识别的录音
 * ## 值
 * ## 示例
 * ```
 * //保存录音
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED,"1")
 * //不保存录音
 * aisdkSetConfig(AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED,"0")
 * ```
 */
const int AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED = AISDK_CONFIG_WAKEUP_BEGIN + 3;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置保存录音的路径，默认是保存在工作目录下的wakeup文件夹
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
const int AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH = AISDK_CONFIG_WAKEUP_BEGIN + 4;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 配置保存文件的最大数量，默认20个录音文件
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
const int AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE = AISDK_CONFIG_WAKEUP_BEGIN + 5;

/**
 *
 * @see aisdkSetConfig()
 *
 * @brief 唤醒录音文件控制命令，内部使用
 *
 * 配置项关键字
 * ## 功能
 * 唤醒录音文件控制命令
 * ## 值
 */
const int AISDK_CONFIG_WAKEUP_BUFFER_CONTROL = AISDK_CONFIG_WAKEUP_BEGIN + 6;

/**
 *
 * @see aisdkGetConfig()
 *
 * @brief 获取唤醒模型的MD5，仅支持获取，不支持设置
 *
 * 配置项关键字
 * ## 功能
 * 获取唤醒模型的MD5
 * ## 值
 */
const int AISDK_CONFIG_WAKEUP_MODEL_MD5 = AISDK_CONFIG_WAKEUP_BEGIN + 7;

// 配置项，key的结束值
const int AISDK_CONFIG_WAKEUP_END = 7999;

/*************************************************************
 * END：配置项key定义
 * ***********************************************************/

/*************************************************************
 * START:错误码定义
 * ***********************************************************/
/**
 * @brief 错误码定义：模块还未初始化
 */
const int AISDK_ERROR_WAKEUP_RECO_FAILED = 7000;

/**
 * @brief 错误码定义：未开始识别就输入语音
 */
const int AISDK_ERROR_WAKEUP_RECO_NOT_STARTED = AISDK_ERROR_WAKEUP_RECO_FAILED + 1;  //7001

/**
 * @brief 错误码定义：创建离线唤醒识别模块失败
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED = AISDK_ERROR_WAKEUP_RECO_FAILED + 2;  //7002

/**
 * @brief 错误码定义：SDK没有包含唤醒模块
 */
const int AISDK_ERROR_WAKEUP_RECO_MODULE_UNAVAILABLE = AISDK_ERROR_WAKEUP_RECO_FAILED + 3;

/**
 * @brief 错误码定义：此错误码不返回，见其他DETAIL错误
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL = AISDK_ERROR_WAKEUP_RECO_FAILED + 4;

/**
 * @brief 错误码定义：创建模块失败，其他原因
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_OTHER = AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL + 1;

/**
 * @brief 错误码定义：创建模块失败，MD5不匹配
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_MISMATCH_MODEL_MD5 = AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL + 2;

/**
 * @brief 错误码定义：创建模块失败，读取模型失败
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_READ_MODEL_FAIL = AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL + 3;

/**
 * @brief 错误码定义：创建模块失败，配置文件不存
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_MODEL_OR_CONFIG_FILE_NOT_EXIST = AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL + 4;

/**
 * @brief 错误码定义：创建模块失败，不支持的PCM格式
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_UNSUPPORTED_PCM_FORMAT = AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL + 5;

/**
 * @brief 错误码定义：创建模块失败，创建解码器失败
 */
const int AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_FAIL_CREATE_DECODER = AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL + 6;

/**
 * @brief 错误码定义：唤醒识别过程出错无法完成识别，例如解码音频错误
 */
const int AISDK_ERROR_WAKEUP_RECO_FATAL = AISDK_ERROR_WAKEUP_RECO_FAILED + 11;
/*************************************************************
 * END:错误码定义
 * ***********************************************************/

/*************************************************************
 * START:返回的json数据中的code定义
 * ***********************************************************/
/**
 * @brief json code定义：唤醒成功
 */
const int AISDK_RESULT_CODE_WAKEUP_OK = 0;
/*************************************************************
 * END:返回的json数据中的code定义
 * ***********************************************************/

/**
 * @brief 唤醒初始化，只需要初始化一次。
 * @param modelPath 唤醒词模型路径
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkInitOfflineWakeup(const char * modelPath);

/**
 * @brief 切换唤醒模型, 切换成功后，需要重新start，如果切换识别则需要重新init。
 * @param modelPath 唤醒词模型路径
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkSwitchModelWakeup(const char * modelPath);

/**
 * @brief 开始一次唤醒识别，唤醒识别开启一次即可，不需要在识别到唤醒词后重新启动。
 * @param userData 用户自定义数据， callback时将会原样带回。
 * @param len 用户自定义数据长度
 * @param flags 控制标志，保留未来使用，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkStartOfflineWakeup(void* userData, int len, int flags);

/**
* @brief 输入录音数据
* @param data 录音数据存储区域
* @param dataLen 录音数据长度
* @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
* @warning 建议每次调用输入的录音数据长度为4096字节。
*
*/
AISDK_API_EXPORTS int aisdkInputOfflineWakeupAudioData(char* data, int dataLen);

/**
* @brief 取消本次语音唤醒识别流程。
* @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
*/
AISDK_API_EXPORTS int aisdkCancelOfflineWakeup();

/**
 * @brief 获取唤醒库和模型版本号
 * @return 版本号字符串
 */
AISDK_API_EXPORTS const char* aisdkGetWakeupVersion();

/**
 * @brief 获取当前唤醒模型的灵敏度
 * @return 灵敏度，取值范围：0.0~1.0
 */
AISDK_API_EXPORTS float aisdkGetWakeupSensitive();

/**
 * @brief 设置当前唤醒模型的灵敏度
 * @param 灵敏度，取值范围：0.5~0.99
 * @return 0：ok，other：fail。
 */
AISDK_API_EXPORTS int aisdkSetWakeupSensitive(float sensitive);

/**
 * @brief 获取上一次唤醒的置信度
 * @return 置信度，取值范围：0.0~1.0
 */
AISDK_API_EXPORTS float aisdkGetWakeupScore();

#ifdef __cplusplus
}
#endif

#endif //PACKAGE_TMS_AISDK_AISDK_WAKEUP_H
