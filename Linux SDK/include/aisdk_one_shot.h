/**
 * @file
 * @author shengyujin
 * @date 2018/12/21
 * @brief 通用语音识别相关接口，只有一路音频输入的情况使用这个接口即可完成唤醒识别和语音识别流程
 * @note
 * @copyright © 2018 TENCENT. All rights reserved.
 */

#ifndef TVS_BASE_AISDK_ONE_SHOT_H
#define TVS_BASE_AISDK_ONE_SHOT_H
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
 * @brief ONESHORT模式已启动
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONE_SHOT_START = 13000;
/**
 * @brief ONESHORT模式已结束
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ONE_SHOT_STOP = AISDK_CMD_ONE_SHOT_START + 1;

/**
 * @brief OneShot初始化，只需要初始化一次。
 * @param voicePath 本地VAD模型所在路径，如果不需要本地VAD可以传NULL
 * @param modelPath 唤醒词模型所在路径，如果不需要唤醒识别可以传NULL
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkInitOneShot(const char* voicePath, const char* wakeupPath);

/**
 * @brief 开始OneShot流程，启动一次即可一直输入音频，不需要反复启动，SDK内部会在唤醒识别和语音识别之间切换
 * @param userData 自定义数据指针。callback时带回。
 * @param len 自定义数据长度。
 * @param flags 控制标志，参考AISDK_FLAG_ONLINE_RECO_*常量定义，支持多flag或运算。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkStartOneShot(void* userData, int len, int flags);

/**
 * @brief 输入音频数据，在OneShot流程中全程需要输入
 * @param data 录音数据存储区域。建议长度为4096.
 * @param dataLen 录音数据长度。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 * @warning:
 *      上层应用应当把实时录音数据通过该接口输入到SDK（建议每次输入4096字节长度的音频）。
 *   在启动OneShot流程后全程需要通过此接口输入音频。
 */
AISDK_API_EXPORTS int aisdkInputOneShotAudioData(char* data, int dataLen);

/**
 * @brief 开始一次语音识别，用于手动启动语音识别
 * @param userData 自定义数据指针。callback时带回。
 * @param len 自定义数据长度。
 * @param flags 控制标志，参考AISDK_FLAG_ONLINE_RECO_*常量定义，支持多flag或运算。如果不设置，传0即可。
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkStartOneShotOnlineVoice2Text(void* userData, int len, int flags);

/**
 * @brief 取消当前正在进行的语音识别，不影响唤醒识别
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkCancelOneShotOnlineVoice2Text();

/**
 * @brief 停止当前正在进行的语音识别并获取结果，用于手动停止语音识别的场景，不影响唤醒识别
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
 */
AISDK_API_EXPORTS int aisdkStopOneShotOnlineVoice2Text();

/**
 * @brief 停止OneShot流程，会停掉正在进行中的唤醒和语音识别
 * @return 0：ok，other：fail。 错误码定义见AISDK_ERROR_*常量
*/
AISDK_API_EXPORTS int aisdkStopOneShot();

#ifdef __cplusplus
}
#endif

#endif //TVS_BASE_AISDK_ONE_SHOT_H
