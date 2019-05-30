# aisdk_tts_online

### 回调命令定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_TTS_RESULT |4000 |当TTS返回结果时发出 |
|AISDK_CMD_TTS_ERROR |4001 |当TTS返回出错时发出 |

----------

### 配置项键值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CONFIG_TTS_VOLUME |4001 |配置TTS的音量大小，默认值50 |
|AISDK_CONFIG_TTS_ENV_TYPE |4002 |配置TTS的环境，默认正式环境 |
|AISDK_CONFIG_TTS_ROLE |4003 |配置TTS的角色，默认值0，有服务端选择 |

----------

### 回调数据json中的code定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_RESULT_CODE_TTS_DATA |0 |标识中间语音数据包 |
|AISDK_RESULT_CODE_TTS_LAST_DATA |1 |标识最后一个语音数据包 |

</br>
----------
## TTS合成

<pre><code>int aisdkText2Speech(const char* text, int textLen, void* userData, int len);</code></pre>
	
<p>TTS合成接口，TTS结果通过回调异步回调返回。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  text | char* | 需要转语音的文本，以utf8格式编码的文本串，以'\0'结尾 |
|  textLen | int | 文本长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 指定语言TTS合成

<pre><code>int aisdkText2SpeechEx(int languageType, const char* text, int textLen, void* userData, int len);</code></pre>
	
<p>TTS转换接口，TTS结果通过回调异步回调返回，支持选择语言。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  languageType | int |  语言类型，0：默认，1：中文，2：英文 |
|  text | char* | 需要转语音的文本，以utf8格式编码的文本串，以'\0'结尾 |
|  textLen | int | 文本长度 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 取消所有的TTS请求

<pre><code>int aisdkCancelText2Speech();</code></pre>
	
<p>取消所有的TTS请求。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 取消特定TTS请求

<pre><code>int aisdkCancelText2SpeechByUserData(void* userData);</code></pre>
	
<p>根据外部传入数据，取消特定TTS请求。取消后，这一次的tts请求结果不再返回。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userData | void* | 自定义数据指针 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |
