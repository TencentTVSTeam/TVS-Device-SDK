/*!
 @header SemanticSession.h
 @brief 语义识别能力提供者，该类封装了语义能力的所有接口
 @author zacardfang
 @copyright © 2017 TENCENT. All rights reserved.
*/

#import <Foundation/Foundation.h>
#import "SpeechEngine.h"

/*!
 * @brief 语义识别回调接口，在SemanticSession对象中注入
 */
@protocol SemanticSessionDelegate <NSObject>

/*!
 * @brief 语义识别正常返回
 * @param cmd 返回结果命令字，参照K_AISDK_CMD_xx来处理具体业务
 * @param code 返回的json数据错误码，参照语义说明文档解析
 * @param data 返回的json数据，参照语义说明文档解析
 * @param userData 调用语义识别时传入的自定义参数
 */
-(void)onOnlineSemanticCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData;

/*!
 * @brief 语义识别错误返回
 * @param cmd 返回结果命令字，参照K_AISDK_CMD_xx_ERROR来处理异常返回
 * @param code 返回的json数据错误码，参照语义说明文档解析
 * @param message 错误信息
 * @param userData 调用语义识别时传入的自定义参数
 */
-(void)onOnlineSemanticError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData;

@end

@interface SemanticSession : NSObject<SessionDelegate>

@property(nonatomic, weak)id<SemanticSessionDelegate> delegate;
@property(nonatomic, strong)dispatch_queue_t semanticQueue;

/*!
 * @brief 在线二次识别接口，结果通过回调异步回调返回
 * @param text 以utf8格式编码的文本串，以'\0'结尾
 * @param userdata 自定义数据
 * @param flags 控制标志，参考K_AISDK_FLAG_SEMANTIC_*常量定义。默认设置为0即可
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int) text2semantic:(NSString *)text userData:(id)userdata flags:(NSInteger)flags;

/*!
 * @brief 特殊功能性接口，复合语义
 * @param semanticJson 语义JSON
 * @param userdata 自定义数据，callback时带回
 * @param flags 控制标志，参考AISDK_FLAG_SEMANTIC_*常量定义，支持多flag或运算。默认设置为0即可。
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int) complexSemantic2Semantic:(NSString *)semanticJson userData:(id)userdata semanticFlags:(int)flags ;

/*!
 * @brief 请求单首音乐的详细信息，播放音乐时，音乐的地址可能会有变化，播放前应该用音乐的ID请求一次新的url
 * @param mediaId 媒体Id
 * @param extraMsg 扩展字段
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int) reqMusic:(NSString *)mediaId extraMsg:(NSString *)extraMsg;

/*!
 * @brief 请求单个FM的详细信息，播放FM时，FM的地址可能会有变化，播放前应该用FM的ID请求一次新的url
 * @param showId 媒体Id
 * @param showType 类型
 * @param extraMsg 扩展字段
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int) reqFM:(NSString *)showId showType:(NSInteger)showType extraMsg:(NSString *)extraMsg;

/*!
 * @brief 取消本次语义请求
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int) cancelText2Semantic;

/*!
 * @brief 根据外部传入数据，取消特定语义请求
 * @param userdata 传入的自定义数据
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int) cancelSemanticByUserData:(id)userdata;

/*!
 * @brief 根据请求类型，取消特定语义请求
 * @param iReqType 请求类型见AISDK_SEMANTIC_REQ_TYPE_*常量
 * @return 0:ok, other：fail。 错误码定义见K_AISDK_ERROR_*常量
 */
- (int)cancelSemanticByType:(NSInteger)iReqType;

@end


//常量定义

/*----------semantic------*/

/*!
 * @brief  回调接口命令定义,语义返回的回调
 * @note 返回语义识别结果
 * @see SemanticSessionDelegate
 */
extern const int K_AISDK_CMD_SEMANTIC_RESULT;

/*!
 * @brief 回调接口命令定义,独立请求媒体的接口结果返回
 * @note aisdkReqMusic 和aisdkReqFM函数请求的音乐/fm信息语义回调
 * @see SemanticSessionDelegate
 */
extern const int K_AISDK_CMD_MEDIA_SEMANTIC_RESULT;
/*!
 * @brief  回调接口命令定义,语义返回出错
 * @note 返回语义识别结果
 * @see SemanticSessionDelegate
 */
extern const int K_AISDK_CMD_SEMANTIC_ERROR; // 语义识别出错
/*!
 * @brief 回调接口命令定义,独立请求媒体出错
 * @note aisdkReqMusic 和aisdkReqFM函数请求的音乐/fm信息语义回调
 * @see SemanticSessionDelegate
 */
extern const int K_AISDK_CMD_MEDIA_SEMANTIC_ERROR; // 独立请求媒体的接口出错

/*!
 * @brief 回调接口命令定义,复合语义的接口结果返回
 * @note aisdkReqMusic 和aisdkReqFM函数请求的音乐/fm信息语义回调
 * @see SemanticSessionDelegate
 */
extern const int K_AISDK_CMD_COMPLEX_SEMANTIC_RESULT;
/*!
 * @brief 回调接口命令定义,复合语义请求出错
 * @see SemanticSessionDelegate
 */
extern const int K_AISDK_CMD_COMPLEX_SEMANTIC_ERROR;

// 配置项，key的起始值
extern const int K_AISDK_CONFIG_SEMANTIC_ONLINE_BEGIN;

/*!
 * @brief 配置语义服务的环境
 * @note 设置语义服务环境为正式环境 aisdkSetConfig(AISDK_CONFIG_SEMANTIC_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)
 * @see aisdkSetConfig()
 */
extern const int K_AISDK_CONFIG_SEMANTIC_ENV_TYPE;

// 配置项，key的结束值
extern const int K_AISDK_CONFIG_SEMANTIC_ONLINE_END;

/*!
 * @brief 请求类型：文本请求
 * @note 用于cancel(int)参数
 */
extern const int K_AISDK_SEMANTIC_REQ_TYPE_TEXT;
/*!
 * @brief 请求类型：复合语义请求
 * @note 用于cancel(int)参数
 */
extern const int K_AISDK_SEMANTIC_REQ_TYPE_SEMANTIC;
/*!
 * @brief 请求类型：复合语义请求
 * @note 用于cancel(int)参数
 */
extern const int K_AISDK_SEMANTIC_REQ_TYPE_COMPLEX_SEMANTIC;

/*!
 * @brief调用flags标志取值定义
 * 清空上一次请求的上下文
 */
extern const int K_AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION;

/*!
 * @brief退出当前请求的上下文
 */
extern const int K_AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION;

/*!
 * 标记当前语义请求的文本不是语音识别结果。
 */
extern const int K_AISDK_FLAG_SEMANTIC_NOT_ASR; // = 0x04;


/*!
 * 强制清除后台保存的所有上下文信息
 */
extern const int K_AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION; // = 0x08;

/*!
 * 让后台不把当前请求保存到session里
 */
extern const int K_AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION; // = 0x10;


