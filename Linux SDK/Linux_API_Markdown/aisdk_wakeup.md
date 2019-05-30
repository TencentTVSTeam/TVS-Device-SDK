# aisdk_wakeup

### 回调命令定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_WAKEUP_RECO_START |7000 |唤醒识别开始，接受录音数据 |
|AISDK_CMD_WAKEUP_RECO_RESULT |7001 |唤醒vad检测完成，可以停止输入录音数据，返回唤醒识别结果 |
|AISDK_CMD_WAKEUP_RECO_ERROR |7002 |唤醒识别出错 |
|AISDK_CMD_WAKEUP_RECO_CANCELED |7003 |已取消唤醒识别 |

----------

### 接口方法返回错误码定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_ERROR_WAKEUP_RECO_FAILED |7000 |模块还未初始化 |
|AISDK_ERROR_WAKEUP_RECO_NOT_STARTED |7001 |未开始识别就输入语音 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED |7002 |创建离线唤醒识别模块失败 |
|AISDK_ERROR_WAKEUP_RECO_MODULE_UNAVAILABLE |7003 |SDK没有包含唤醒模块（加载唤醒库失败） |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL |7004 |此错误码不返回，见其他DETAIL错误 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_OTHER |7005 |创建模块失败：其他原因 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_MISMATCH_MODEL_MD5 |7006 |创建模块失败：MD5不匹配 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_READ_MODEL_FAIL |7007 |创建模块失败：读取模型失败 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_MODEL_OR_CONFIG_FILE_NOT_EXIST |7008 |创建模块失败：配置文件不存在 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_UNSUPPORTED_PCM_FORMAT |7009 |创建模块失败：不支持的PCM格式 |
|AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_FAIL_CREATE_DECODER |7010 |创建模块失败：创建解码器失败 |
|AISDK_ERROR_WAKEUP_RECO_FATAL |7011 |唤醒识别过程出错无法完成识别，例如解码音频错误 |

----------

### 配置项键值定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CONFIG_WAKEUP_TIMEOUT |7001 |已废弃，请勿使用 |
|AISDK_CONFIG_WAKEUP_SAVE_SPEECH |7002 |配置是否保存录音，所有输入音频都保存在一个文件中，默认关闭 |
|AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED |7003 |配置是否保存每一次唤醒识别的录音，每次唤醒保存一个文件，默认关闭 |
|AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH |7004 |配置保存录音的路径，默认是保存在工作目录下的 |
|AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE |7005 |配置保存文件的最大数量，默认20个录音文件 |
|AISDK_CONFIG_WAKEUP_BUFFER_CONTROL |7006 |唤醒录音文件控制命令，内部使用 |
|AISDK_CONFIG_WAKEUP_MODEL_MD5 |7007 |获取唤醒模型的MD5，仅支持获取，不支持设置 |

----------

### 回调数据json中的code定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_RESULT_CODE_WAKEUP_OK |0 |成功 |

</br>
----------
### 唤醒初始化

<pre><code>int aisdkInitOfflineWakeup(const char * modelPath);</code></pre>
  
<p>唤醒初始化，只需要初始化一次。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  modelPath | const char* | 唤醒模型路径 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 切换唤醒模型

<pre><code>int aisdkSwitchModelWakeup(const char * modelPath);</code></pre>
  
<p>切换唤醒模型, 切换成功后，需要重新start，如果切换失败则需要重新init。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  modelPath | const char* | 唤醒模型路径 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 开始一次唤醒识别流程  

<pre><code>int aisdkStartOfflineWakeup(void* userData, int len, int flags);</code></pre>
  
<p>开始一次唤醒识别流程，传入的自定义数据，会在回调中带回给接入方，传入识别的模式标志flags选择识别的模式。唤醒识别开启一次即可，不需要在识别到唤醒词后重新启动。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userData | void* | 用户自定义数据，callback时将会原样带回 |
|  len | int | 自定义数据长度 |
|  flags | int | 控制标志，保留未来使用，传0即可 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 输入录音数据  

<pre><code>int aisdkInputOfflineWakeupAudioData(char* data, int dataLen); </code></pre>
  
<p>输入录音数据，上层应用应当把实时录音数据通过该接口输入到SDK（建议每次输入4096字节长度的音频）。在调用此接口后，如果识别到唤醒词，会通过回调通知上层应用。</p>

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
### 取消本次唤醒识别  
  
<pre><code>int aisdkCancelOfflineWakeup(); </code></pre>
  
<p>取消本次唤醒识别。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 获取唤醒库和模型版本号  
  
<pre><code>const char* aisdkGetWakeupVersion();</code></pre>
  
<p> 获取唤醒库和模型版本号。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| 版本号 | const char* | 版本号字符串 |

</br>
----------
### 获取当前唤醒模型的灵敏度 
  
<pre><code>float aisdkGetWakeupSensitive();</code></pre>
  
<p>获取当前唤醒模型的灵敏度。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| 灵敏度 | float | 灵敏度，取值范围：0.0~1.0 |

</br>
----------
### 设置当前唤醒模型的灵敏度 
  
<pre><code>int aisdkSetWakeupSensitive(float sensitive);</code></pre>
  
<p>设置当前唤醒模型的灵敏度。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  sensitive | float |灵敏度，取值范围：0.0~1.0 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 获取上一次唤醒的置信度 
  
<pre><code>float aisdkGetWakeupScore();</code></pre>
  
<p>获取上一次唤醒的置信度。</p>

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| 置信度 | float | 置信度，取值范围：0.0~1.0 |

