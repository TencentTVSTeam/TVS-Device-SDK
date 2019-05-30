/**
 * @file
 * @author kangrong
 * @date 2018/1/24
 * @brief 账户相关接口
 * @note 用来设置和管理账户信息。
 * @copyright © 2017 TENCENT. All rights reserved.
 */
#ifndef PACKAGE_TMS_AISDK_AISDK_ACCOUNT_H
#define PACKAGE_TMS_AISDK_AISDK_ACCOUNT_H

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
 * @brief  回调接口命令定义,上报QBGuid成功
 * @note 上报QBGuid成功
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ACCOUNT_REPORT_RELATION_SUCCESS = 8000;

/**
 * @brief  回调接口命令定义,上报QBGuid失败
 * @note 上报QBGuid失败
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ACCOUNT_REPORT_RELATION_FAIL = AISDK_CMD_ACCOUNT_REPORT_RELATION_SUCCESS + 1;

/**
 * @brief  回调接口命令定义,上报刷票失败
 * @note 上报刷票失败
 * @see AISDK_CALLBACK
 */
const int AISDK_CMD_ACCOUNT_REFRESH_TOKEN_FAIL = AISDK_CMD_ACCOUNT_REPORT_RELATION_SUCCESS + 2;

typedef struct{
    char* appId;
    char* openId;
    char* refreshToken;
    char* accessToken;
    char* qbId;
    int expireTime;
    int accountType;
    int isNeedRefresh;
} AISDKAccount;
/**
 * 设置账户
 * @param accountType 账号类型
 * accountType|说明
 * --|--
 * 1|IDCENTER_ID_QQ
 * 2|IDCENTER_ID_WX
 * 3|IDCENTER_ID_DV
 * 4|IDCENTER_ID_QQOPEN
 * @param appId 应用appId
 * @param openId 账户openId
 * @param refreshToken 账户refreshToken
 * @param accessToken  账户accessToken
 * @param qbId 账户qbId，没有的话传空串即可
 * @param expireTime 账户失效时间，微信账户需要填写
 * @param isNeedRefresh 是否需要SDK刷新token，微信账户需要填写， 0:不需要，1:需要。
 * @return 0
 */
AISDK_API_EXPORTS int aisdkSetAccount(int accountType,
                                       const char* appId,
                                       const char* openId,
                                       const char* refreshToken,
                                       const char* accessToken,
                                       const char* qbId,
                                       long long expireTime,
                                       int isNeedRefresh);

/**
 * @brief 获得当前账号信息
 * @param account 返回的账户信息
 * @return 0:表示有账号，其他:表示没有账号
 */
AISDK_API_EXPORTS int aisdkGetAccount(AISDKAccount* account);

/**
 * 设置clientId形式的账户信息
 * @param clientId 通过叮当手机端SDK登陆后获取的账号信息
 * @param isNeedRefresh 是否需要SDK刷新token，微信账户需要填写， 0:不需要，1:需要。
 * @return 0
 */
AISDK_API_EXPORTS int aisdkSetAccountByClientId(const char* clientId, int isNeedRefresh);

/**
 * @brief 获得clientId形式的账号信息
 * @param client ，传出clientId，SDK内部分配内存，请传入一个空指针，并在使用完后释放内存
 * @return 0:表示成功返回clientId，其他表示没有账户信息
 */
AISDK_API_EXPORTS int aisdkGetAccountClientId(char** client);

/**
 * @brief 清空账号信息
 */
AISDK_API_EXPORTS void aisdkClearAccount();

/**
 * @brief 上报账号的关系（内部使用，请勿调用）
 */
AISDK_API_EXPORTS int aisdkReportRelation(const char* qbGuid, void* userData, int len);

#ifdef __cplusplus
}
#endif

#endif //PACKAGE_TMS_AISDK_AISDK_ACCOUNT_H
