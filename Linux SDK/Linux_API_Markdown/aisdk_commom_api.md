# aisdk_common_api

### 回调命令定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_COMMON_PUSH_MSG |1 |收到服务端的push消息 |

----------

### 接口方法返回错误码定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_RESULT_OK |0 |成功 |
|AISDK_ERROR_COMMON_UNKNOWN_ERROR |1 |未知错误 |
|AISDK_ERROR_COMMON_NOT_INITIALIZED |2 |SDK未初始化 |
|AISDK_ERROR_COMMON_INTERNAL_ERROR |3 |内部错误 |
|AISDK_ERROR_COMMON_NETWORK_FAIL |5 |网络请求发送失败 |
|AISDK_ERROR_COMMON_NETWORK_RESPONSE_FAIL |6 |网络请求回包失败 |
|AISDK_ERROR_COMMON_NETWORK_TIMEOUT |7 |网络请求超时 |
|AISDK_ERROR_COMMON_PARAM_INVALID |9 |传入参数错误或不合法 |
|AISDK_ERROR_COMMON_SERVICE_RESP |10 |服务返回异常 |
|AISDK_ERROR_COMMON_BAD_PERFORMANCE |11 |运行不佳 |
|AISDK_ERROR_COMMON_APPKEY_NOT_SET|12 |初始化时未设置Appkey和AccessToken |

----------

### 配置项键值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CONFIG_ENV_TYPE |1 |配置网络环境，默认正式环境 |
|AISDK_CONFIG_TTS_TYPE |2 |配置TTS返回音频格式，默认WAV（PCM）格式 |
|AISDK_CONFIG_AUDIO_FORMAT |3 |配置语音识别请求的音频格式，默认SPEEX格式 |
|AISDK_CONFIG_REQ_TIMEOUT |4 |配置网络请求超时时间，默认5s |
|AISDK_CONFIG_VAD_RATION |5 |配置VAD灵敏度 |
|AISDK_CONFIG_LOG_LEVEL |6 |配置LOG打印级别，默认DEBUG级别 |
|AISDK_CONFIG_VOICE_ENGINE |7 |配置语音识别引擎，默认值0，由服务端选择引擎 |
|AISDK_CONFIG_TTS_ENGINE |8 |配置TTS引擎，默认值0，由云端选择引擎 |
|AISDK_CONFIG_LBS_DATA |9 |配置位置信息，配置后SDK会在后续的请求中带上位置信息 |
|AISDK_CONFIG_ASR_DOMAIN |10 |配置语音识别模型，默认值10 |
|AISDK_CONFIG_CHAT_BOT |11 |配置聊天机器人 |
|AISDK_CONFIG_APP_KEY_AND_TOKEN |12 |单独配置app key和access token |
|AISDK_CONFIG_LOG_SYNC |14 |配置LOG是否同步打印 |
|AISDK_CONFIG_GUID |15 |获得设备当前GUID，不支持设置 |
|AISDK_CONFIG_QUA |16 |获得设备当前QUA，不支持设置，设置请使用aisdkSetQUA接口 |
|AISDK_CONFIG_LOG_TIME_FORMAT |17 |配置LOG打印的时间格式，默认值1 |
|AISDK_CONFIG_NETWORK_TYPE |18 |配置当前网络类型 |
|AISDK_CONFIG_NETWORK_STATUS |19 |配置当前网络状态 |
|AISDK_CONFIG_CHANNEL_ID |20 |配置渠道号 |
|AISDK_CONFIG_RSP_VERSION |21 |配置回复语规范 |
|AISDK_CONFIG_LOG_MAX_SIZE |22 |配置日志文件大小 |
|AISDK_CONFIG_APP_VERSION_NUM |23 |配置APP版本号，内部使用 |
|AISDK_CONFIG_OPEN_SANDBOX |24 |配置是否开启沙箱环境，默认关闭 |

</br>
----------
### 初始化函数  
  
<pre><code>int aisdkInit(const char* folderPath, const char* appKey, const char* accessToken, const char* dsn); </code></pre>
  
<p>初始化SDK，传入SDK的工作目录（必须可读写），接入方在叮当平台上申请的appkey和accessToken，设备的唯一序列号（DeviceSerialNumber）。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  folderPath | char * | <p>SDK的工作目录</p>|
|  appKey | char * | <p>应用的appkey，需要从平台申请，接入方必传</p>|
|  accessToken | char * | <p>应用的access token，需要从平台申请，接入方必传</p>|
|  dsn | char * | <p>设备的序列号（DSN），终端的唯一标识，接入方必传</p>|

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 扩展初始化函数  
  
<pre><code>int aisdkFullInit(const char* folderPath, const char* sharedFilePath, const char* appKey, const char* accessToken, const char* dsn); </code></pre>
  
<p>初始化SDK，传入SDK的工作目录（必须可读写）、共享工作目录（必须可读写）、接入方在叮当平台上申请的appkey和accessToken，设备的唯一序列号（DeviceSerialNumber）。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  folderPath | char * | <p>SDK的工作目录</p>|
|  sharedFilePath | char * | <p>共享工作目录，可在进程间共享数据（Android平台）</p>|
|  appKey | char * | <p>应用的appkey，需要从平台申请，接入方必传</p>|
|  accessToken | char * | <p>应用的access token，需要从平台申请，接入方必传</p>|
|  dsn | char * | <p>设备的序列号（DSN），终端的唯一标识，接入方必传</p>|

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 设置回调函数  
  
<pre><code>void  aisdkSetCallback(AISDK_CALLBACK callbackPtr); </code></pre>
  
<p>注册一个回调函数指针，后续SDK的事件通知都通过这个函数指针回调给接入方</p><p>回调函数原型：</p>

<pre><code>typedef void (AISDK_CALL_CONV *AISDK_CALLBACK)(int cmd, char* data, int dataLen, void* userData, int userDataLen, void *extraData, int extraDataLen);</code></pre>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  callbackPtr | AISDK_CALLBACK | <p>回调函数指针</p>|

</br>
----------
### 设置QUA  

<pre><code>void aisdkSetQUA(const char* platform, const char* vendor, const char* product, const char* versionNum, const char* package, const char* device); </code></pre>
  
<p>QUA是设备的描述信息，通过这个接口设置给SDK后，SDK的每次请求都会带上QUA，服务端可以用于识别发送请求的设备。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  platform | char * | <p>系统平台（LINUX/ANDROID/IOS）</p>|
|  vendor | char * | <p>厂商的名字，接入方自定义</p>|
|  product | char * | <p>产品的名字，接入方自定义</p>|
|  versionNum | char * | <p>软件版本号，接入方自定义（1.0.0.0000）</p>|
|  package | char * | <p>软件包名，接入方自定义</p>|
|  device | char * | <p>设备类型（SPEAKER）</p>|

</br>
----------
### 设置配置项  

<pre><code>void aisdkSetConfig(int key, const char* value); </code></pre>
  
<p>这个接口可以设置SDK所有的配置，接入方可以在运行时更改SDK的配置。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  key | int | <p>配置项的常量，参考AISDK_CONFIG_*常量定义</p>|
|  value | char * | <p>配置对应的值</p>|

</br>
----------
### 获取配置项  
  
<pre><code>const char* aisdkGetConfig(int key); </code></pre>
  
<p>获得相应配置项的值。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  key | int | <p>配置项的常量，参考AISDK_CONFIG_*常量定义</p>|

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  value | char * | <p>配置对应的值</p>|

</br>
----------
### 释放SDK的资源  

<pre><code>int aisdkRelease(); </code></pre>
  
<p>释放SDK的资源，重置状态。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
## 获取SDK版本号

<pre><code>char* aisdkGetVersion()</code></pre>
	
<p>获取具体配置项的值</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|   | char * | SDK版本号 |