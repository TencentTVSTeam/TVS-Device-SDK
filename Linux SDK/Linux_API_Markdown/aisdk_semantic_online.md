# aisdk_semantic_online

### 回调命令定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_SEMANTIC_RESULT |2000 |语义返回的回调 |
|AISDK_CMD_MEDIA_SEMANTIC_RESULT |2001 |独立请求媒体的接口结果返回 |
|AISDK_CMD_SEMANTIC_ERROR |2002 |语义返回出错 |
|AISDK_CMD_MEDIA_SEMANTIC_ERROR |2003 |独立请求媒体出错 |
|AISDK_CMD_COMPLEX_SEMANTIC_RESULT |2004 |明确语义的接口结果返回 |
|AISDK_CMD_COMPLEX_SEMANTIC_ERROR |2005 |明确语义请求出错 |
|AISDK_CMD_RESOUCES_RESULT |2006 |请求资源URl接口结果返回 |
|AISDK_CMD_RESOUCES_ERROR |2007 |请求资源URl接口结果返回出错 |
|AISDK_CMD_ONLINE_RECO_UPLOAD_SEMANTIC |2008 |上传语法到语义服务器成功 |
|AISDK_CMD_ONLINE_RECO_UPLOAD_SEMANTIC_ERROR |2009 |上传语法到语义服务器失败 |
|AISDK_CMD_EX_SEMANTIC_RESULT |2010 |明确语义扩展版本语义返回 |
|AISDK_CMD_EX_SEMANTIC_ERROR |2011 |明确语义扩展版本语义返回出错 |

----------

### 配置项键值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CONFIG_SEMANTIC_ENV_TYPE |2001 |配置语义服务的环境，默认正式环境 |

----------

### cancel方法的请求类型定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_SEMANTIC_REQ_TYPE_TEXT |1 |文本请求 |
|AISDK_SEMANTIC_REQ_TYPE_SEMANTIC |2 |媒体请求 |
|AISDK_SEMANTIC_REQ_TYPE_COMPLEX_SEMANTIC |3 |明确语义请求 |
|AISDK_SEMANTIC_REQ_TYPE_RESOURCE_URL |4 |资源URL请求 |
|AISDK_SEMANTIC_REQ_TYPE_TEXT_EX |5 |增强版文本请求 |

----------

### 请求方法flags取值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION |0x01 |清空上一次请求的上下文 |
|AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION |0x02 |退出当前请求的上下文 |
|AISDK_FLAG_SEMANTIC_NOT_ASR |0x04 |标记当前语义请求的文本不是语音识别结果 |
|AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION |0x08 |强制清除后台保存的所有上下文信息 |
|AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION |0x10 |让后台不把当前请求保存到session里 |

</br>
----------
## 文本转语义

  <pre><code>int aisdkOnlineText2Semantic(const char* text, int textLen, void* userData, int len, int flags);</code></pre>
	
<p>在线语义识别接口， 结果通过回调异步回调返回。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  text | char* | 以utf8格式编码的文本串，以'\0'结尾 |
|  textLen | int | 文本串长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |
|  flags | int |控制标志，参考AISDK_FLAG_SEMANTIC_*常量定义，支持多flag或运算。默认设置为0即可 |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 明确语义获取服务数据

  <pre><code>int aisdkComplexSemantic2Semantic(const char* semanticJson, int len, void *userData, int userDataLen, int flags);</code></pre>
	
<p>特殊功能性接口。传入明确语义JSON请求服务数据，用于非用户语音交互来的请求，例如自动播放下一首。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  semanticJson | char* | 语义JSON |
|  textLen | int | 语义JSON长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |
|  flags | int |控制标志，参考AISDK_FLAG_SEMANTIC_*常量定义，支持多flag或运算。默认设置为0即可 |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 请求单首音乐的详细信息（已过时，请勿调用）

  <pre><code>int aisdkReqMusic(const char* mediaId, int mediaIdLength, void* userData, int len);</code></pre>
	
<p>请求单首音乐的详细信息，传入媒体ID，请求服务返回对应的播放url。如果本地缓存了播放列表播放音乐时，音乐的地址可能会有变化，播放前应该用音乐的ID请求一次新的url。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | char* | 音乐ID |
|  mediaIdLength | int | 音乐ID长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 请求单个FM的详细信息（已过时，请勿调用）

  <pre><code>int aisdkReqFM(const char* showId, int showIdLength, int showType, void* userData, int len);  </code></pre>
	
<p>请求单个FM的详细信息，传入媒体ID，请求服务返回对应的播放url。如果本地缓存了播放列表播放FM时，FM的地址可能会有变化，播放前应该用FM的ID请求一次新的url。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  showId | char* | FM节目ID |
|  showIdLength | int | FM节目乐ID长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 请求资源地址

  <pre><code>int aisdkReqResouceUrl(const char* resoucesIdsJson,int len, void* userData, int userDataLen);</code></pre>
	
<p>请求单个媒体的详细信息，传入媒体ID，请求服务返回对应的播放url。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  resoucesIdsJson | char* | json字符串，字符串格式：["id1","id2"]|
|  len | int | json字符串长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 取消全部语义请求

  <pre><code>int aisdkCancelText2Semantic();</code></pre>
	
<p>取消全部语义请求。</p>

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 取消特定语义请求

  <pre><code>int aisdkCancelSemanticByUserData(void* userData);</code></pre>
	
<p>根据外部传入数据，取消特定语义请求。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userData | void* | 自定义数据指针 |

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 取消特定类型的语义请求

  <pre><code>int aisdkCancelSemanticByType(int iReqType);</code></pre>
	
<p>根据请求类型，取消特定语义请求，请求类型见AISDK_SEMANTIC_REQ_TYPE_*常量。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  iReqType | int | 请求类型 |

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 明确语义获取服务数据扩展版本

  <pre><code>int aisdkOnlineText2SemanticEx(const char* text, int textLen,
        const char* semanticJson, int semanticLen,
        const struct AISDKExtContent* contents, int contentsLen,
        void* userData, int userDataLen, int flags);</code></pre>

	
<p>在线语义识别接口。扩展接口，支持明确意图、普通文本请求、带额外数据请求。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  text | char* | 以utf8格式编码的文本串，以'\0'结尾|
|  textLen | int | 文本串长度 |
|  semanticJson | char* | 语义JSON |
|  semanticLen | int | 语义JSON长度 |
|  contents | AISDKExtContent* | AISDKExtContent结构体指针 |
|  contentsLen | int | AISDKExtContent结构体长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |
