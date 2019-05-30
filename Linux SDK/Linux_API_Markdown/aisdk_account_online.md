# aisdk_account_online

### 回调命令定义

| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_ACCOUNT_REPORT_RELATION_SUCCESS |8000 |上报QBGuid成功（内部使用） |
|AISDK_CMD_ACCOUNT_REPORT_RELATION_FAIL |8001 |上报QBGuid失败（内部使用） | 
|AISDK_CMD_ACCOUNT_REFRESH_TOKEN_FAIL |8002 |上报刷票失败，需要重新授权 |

----------

### 账号数据结构定义
<pre><code>	
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
</code></pre>

</br>
----------
### 设置账户信息  
  
<pre><code>	int aisdkSetAccount(int accountType,
                       const char* appId,
                       const char* openId,
                       const char* refreshToken,
                       const char* accessToken,
                       const char* qbId,
                       long long expireTime,
                       int isNeedRefresh);</code></pre>
  
<p>设置用户的账户信息。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  accountType | int | 账号类型 <p>1: IDCENTER_ID_QQ</p>  <p>2: IDCENTER_ID_WX</p> <p>3: IDCENTER_ID_DV</p> <p>4: IDCENTER_ID_QQOPEN</p> |
|  appId | char * | 应用appId |
|  openId | char * | 账户openId |
|  refreshToken | char * | 账户refreshToken |
|  accessToken | char * | 账户refreshToken |
|  qbId | char * | 账户qbId（若没有可不填） |
|  expireTime | int | 账户失效时间，微信账户需要填写 |
|  isNeedRefresh | int | 是否需要SDK刷新token，微信账户需要填写， 0:不需要，1:需要。 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 设置账户信息字符串  
  
<pre><code>int aisdkSetAccountByClientId(const char* clientId, int isNeedRefresh); </code></pre>
  
<p>设置cliendId形式的账户信息。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  clientId | char * | 账户cliendId |
|  isNeedRefresh | int | 是否需要SDK刷新token，微信账户需要填写， 0:不需要，1:需要。 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 获得当前账户信息  
  
<pre><code>int aisdkGetAccount(AISDKAccount* account);</code></pre>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  account | AISDKAccount* | 返回的账户信息，AISDKAccount结构体定义参见头文件 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 获得clientId形式的账户信息  

<pre><code>int aisdkGetAccountClientId(char** client);</code></pre>
  
<p>获得clientId形式的账户信息。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  client | char** | 返回的账户信息，接入方使用完需要释放内存 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 清空账号信息 

<pre><code>void aisdkClearAccount();</code></pre>
  
<p>清空账号信息。</p>

</br>
----------
### 上报账号的关系  

<pre><code>int aisdkReportRelation(const char* qbGuid, void* userData, int len);</code></pre>
  
<p>上报账号的关系，此方法供内部使用，请勿调用。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  qbGuid | char* | QQ浏览器的GUID |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |
