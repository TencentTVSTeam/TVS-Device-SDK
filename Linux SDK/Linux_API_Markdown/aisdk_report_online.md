# aisdk_report_online

### 回调命令定义
| 名称     | 取值       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_REPORT_MEDIA_STARTED_SUCCESS |10000 |媒体播放开始状态上报成功 |
|AISDK_CMD_REPORT_MEDIA_STARTED_ERROR |10001 |媒体播放开始状态上报失败 |
|AISDK_CMD_REPORT_MEDIA_STOPPED_SUCCESS |10002 |媒体播放被切换状态上报成功 |
|AISDK_CMD_REPORT_MEDIA_STOPPED_ERROR |10003 |媒体播放被切换状态上报失败 |
|AISDK_CMD_REPORT_MEDIA_FINISHED_SUCCESS |10004 |媒体播放结束状态上报成功 |
|AISDK_CMD_REPORT_MEDIA_FINISHED_ERROR |10005 |媒体播放结束状态上报失败 |
|AISDK_CMD_REPORT_CLIENT_STATE_SUCCESS |10006 |通用终端状态上报成功 |
|AISDK_CMD_REPORT_CLIENT_STATE_ERROR |10007 |通用终端状态上报失败 |

</br>
----------
### 统计媒体播放开始

<pre><code>void aisdkReportMediaStarted(const char* mediaId);</code></pre>
  
<p>统计媒体播放开始。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | const char* | 媒体的id，由服务器下发 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 统计媒体被切换

<pre><code>void aisdkReportMediaStopped(const char* mediaId, long long duration);</code></pre>
  
<p>统计媒体被切换。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | const char* | 媒体的id，由服务器下发 |
| duration | long long | 媒体播放了多长时间（毫秒） |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 统计媒体播放结束

<pre><code>void aisdkReportMediaFinished(const char* mediaId, long long duration);</code></pre>
  
<p>统计媒体播放结束。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | const char* | 媒体的id，由服务器下发 |
| duration | long long | 媒体播放了多长时间（毫秒） |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |

</br>
----------
### 通用状态上报接口

<pre><code>void aisdkReportClientState(const char* sJsonData, void* userData, int userDataLen);</code></pre>
  
<p>通用状态上报接口。</p>

### 参数
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  sJsonData | const char* | JSON格式的上报数据，根据类型不同数据也有所不同，具体请参考文档 |
|  userData | void* | 自定义数据指针。callback时带回 |
|  len | int | 自定义数据长度 |

### 返回值
| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | 成功 |
| AISDK_ERROR_* | int | 出错，错误码定义见AISDK_ERROR_*常量  |



