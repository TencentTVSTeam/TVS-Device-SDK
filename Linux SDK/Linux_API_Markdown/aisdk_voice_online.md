# aisdk_voice_online

### 回调命令定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_ONLINE_RECO_START |6000 |在线识别开始，接受录音数据 |
|AISDK_CMD_ONLINE_RECO_SPEECH_START |6001 |在线语音VAD检测到开始 | 
|AISDK_CMD_ONLINE_RECO_SPEECH_END |6002 |在线语音vad检测完成，可以停止输入录音数据 |
|AISDK_CMD_ONLINE_RECO_RESULT |6003 |返回在线识别结果 |
|AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT |6004 |上报在线识别的中间结果 |
|AISDK_CMD_ONLINE_RECO_DATA_VOLUME |6005 |上报输入音频数据的音量值 |
|AISDK_CMD_ONLINE_RECO_CANCELED |6006 |已取消在线识别 |
|AISDK_CMD_ONLINE_RECO_TIMEOUT |6007 |在线识别超时，没有识别到有效输入 |
|AISDK_CMD_ONLINE_RECO_ERROR |6008 |在线识别出错，返回错误信息 |
|AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT |6009 |在线识别云端长时间结束不了导致超时 |
|AISDK_CMD_ONLINE_RECO_FULL_MODE_FINISHED |6010 |完整模式的在线识别流程结束（以FULL_MODE启动时才会回调） |
|AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT |6011 |本地VAD检测静音超时 |
|AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_SUCCESS |6012 |获取语音识别Session成功，标识云端已为始语音识别做好准备 |
|AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_FAILURE |6013 |获取语音识别Session失败，本次语音识别还未开始就结束了 |
|AISDK_CMD_ONLINE_RECO_ONESHOT_SHORT_MODE_TIMEOUT |6014 |oneshot短模式检测vad开始静音超时 |

----------

### 接口方法返回错误码定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_ERROR_ONLINE_RECO_NOT_STARTED |6000 |模块还没有初始化 |
|AISDK_ERROR_ONLINE_RECO_CREATE_HANDLE_FAILED |6001 |创建在线识别模块失败 |
|AISDK_ERROR_ONLINE_RECO_ALREADY_STARTED |6002 |语音识别已经启动，不需要重复启动 |

----------

### 配置项键值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CONFIG_VOICE_ONLINE_TIMEOUT |6001 |配置在线语音超时时间，默认10s |
|AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD |6003 |配置是否开启云端VAD，默认开启 |
|AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME |6004 |配置是否开启计算音量，默认关闭 |
|AISDK_CONFIG_VOICE_VAD_SILENT_MAX |6005 |配置oneshot短模式检测vad开始静音超时时间，默认500ms |
|AISDK_CONFIG_VOICE_ONLINE_LANGUAGE_TYPE |6006 |设置语音识别的语言类型 |
|AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH |6007 |配置是否保存录音，默认关闭 |
|AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT |6008 |设置语音识别的静音超时时间，默认10s |
|AISDK_CONFIG_VOICE_ONLINE_SIL_TIME |6009 | 设置语音识别的尾部静音结束时间，默认500ms |
|AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD |6010 |是否使用本地vad结束，默认开启 |
|AISDK_CONFIG_VOICE_ONLINE_AUDIO_PACKET_SIZE |6011 |在线识别发送的语音数据包大小，默认3200字节 |
|AISDK_CONFIG_VOICE_ENV_TYPE |6012 |配置语音识别环境，默认正式环境 |
|AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO |6013 |忽略在语音识别中的唤醒（已废弃） |
|AISDK_CONFIG_VOICE_ONLINE_INPUT_ENCODED_DATA |6014 |配置输入音频是否已编码，默认关闭 |
|AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD |6015 |配置是否只识别VAD，默认关闭 |

----------

### start方法flags取值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_FLAG_ONLINE_RECO_FULL_MODE |0x01 |语音识别改为完整模式，一个接口完成语音、语义、TTS流程 |
|AISDK_FLAG_ONLINE_RECO_MANUAL_MODE |0x02 |语音识别改为手动模式 |
|AISDK_FLAG_ONLINE_SEMANTIC_CLEAR_PREV_SESSION |0x04 |清空上一次请求的上下文 |
|AISDK_FLAG_ONLINE_SEMANTIC_EXIT_CUR_SESSION |0x08 |退出当前请求的上下文 |
----------

### 回调数据json中的code定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_RESULT_CODE_ONLINE_OK |0 |成功 |
|AISDK_RESULT_CODE_ONLINE_CANCELED_BY_WAKEUP |1 |语音识别被唤醒打断 |

</br>
----------
### 初始化语音识别模型  

<pre><code>int aisdkInitOnlineVoice2Text(const char* modelPath);</code></pre>
  
<p>初始化语音识别功能，如果没有接入新版vad，不需要调用此方法。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  modelPath | const char* | VAD模型所在的根目录 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 开始一次语音识别流程  

<pre><code>int aisdkStartOnlineVoice2Text(void* userData, int len, int flags);</code></pre>
  
<p>开始一次语音识别流程，传入自定义数据，会在回调中带回给接入方，传入识别的模式标志flags选择识别的模式。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |
|  flags | int | 控制标志，参考AISDK_FLAG_ONLINE_RECO_*常量定义，支持多flag或运算。如果不设置，传0即 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 输入在线录音数据  

<pre><code>int aisdkInputOnlineVoice2TextAudioData(char* data, int dataLen); </code></pre>
  
<p>输入在线录音数据，上层应用应当把实时录音数据通过该接口输入到SDK（建议每次输入4096字节长度的音频）。在调用此接口过程中，会有VAD检测到开始、VAD检测到结束、实时音量、语音识别到结果等状态的回调。遇到AISDK_CMD_ONLINE_RECO_CANCELED、AISDK_CMD_ONLINE_RECO_TIMEOUT、AISDK_CMD_ONLINE_RECO_ERROR、AISDK_CMD_ONLINE_RECO_RESULT时，停止调用该函数。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  data | void* | 录音数据存储区域。建议长度为4096|
|  len | int | 录音数据长度|

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 取消本次语音识别  
  
<pre><code>int aisdkCancelOnlineVoice2Text(); </code></pre>
  
<p>取消本次语音识别。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 停止本次语音识别  
  
<pre><code>int aisdkStopOnlineVoice2Text();</code></pre>
  
<p>停止本次语音识别，获取语音识别结果。停止后，不会中断语音识别，SDK会将现在已经接收到的音频发送到后台请求语音识别结果，此接口适用于手动停止识别的场景。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 获取VAD模型的版本 
  
<pre><code>const char* aisdkGetVadVersion();</code></pre>
  
<p>获取正在使用的VAD模型的版本，只有使用了本地VAD模型才会有返回值。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| 版本号 | const char* | 版本号字符串 |


