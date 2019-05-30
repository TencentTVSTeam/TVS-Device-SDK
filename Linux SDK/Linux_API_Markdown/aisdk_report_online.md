# aisdk_report_online

### �ص������
| ����     | ȡֵ       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
|AISDK_CMD_REPORT_MEDIA_STARTED_SUCCESS |10000 |ý�岥�ſ�ʼ״̬�ϱ��ɹ� |
|AISDK_CMD_REPORT_MEDIA_STARTED_ERROR |10001 |ý�岥�ſ�ʼ״̬�ϱ�ʧ�� |
|AISDK_CMD_REPORT_MEDIA_STOPPED_SUCCESS |10002 |ý�岥�ű��л�״̬�ϱ��ɹ� |
|AISDK_CMD_REPORT_MEDIA_STOPPED_ERROR |10003 |ý�岥�ű��л�״̬�ϱ�ʧ�� |
|AISDK_CMD_REPORT_MEDIA_FINISHED_SUCCESS |10004 |ý�岥�Ž���״̬�ϱ��ɹ� |
|AISDK_CMD_REPORT_MEDIA_FINISHED_ERROR |10005 |ý�岥�Ž���״̬�ϱ�ʧ�� |
|AISDK_CMD_REPORT_CLIENT_STATE_SUCCESS |10006 |ͨ���ն�״̬�ϱ��ɹ� |
|AISDK_CMD_REPORT_CLIENT_STATE_ERROR |10007 |ͨ���ն�״̬�ϱ�ʧ�� |

</br>
----------
### ͳ��ý�岥�ſ�ʼ

<pre><code>void aisdkReportMediaStarted(const char* mediaId);</code></pre>
  
<p>ͳ��ý�岥�ſ�ʼ��</p>

### ����
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | const char* | ý���id���ɷ������·� |

### ����ֵ
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | �ɹ� |
| AISDK_ERROR_* | int | ���������붨���AISDK_ERROR_*����  |

</br>
----------
### ͳ��ý�屻�л�

<pre><code>void aisdkReportMediaStopped(const char* mediaId, long long duration);</code></pre>
  
<p>ͳ��ý�屻�л���</p>

### ����
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | const char* | ý���id���ɷ������·� |
| duration | long long | ý�岥���˶೤ʱ�䣨���룩 |

### ����ֵ
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | �ɹ� |
| AISDK_ERROR_* | int | ���������붨���AISDK_ERROR_*����  |

</br>
----------
### ͳ��ý�岥�Ž���

<pre><code>void aisdkReportMediaFinished(const char* mediaId, long long duration);</code></pre>
  
<p>ͳ��ý�岥�Ž�����</p>

### ����
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | const char* | ý���id���ɷ������·� |
| duration | long long | ý�岥���˶೤ʱ�䣨���룩 |

### ����ֵ
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | �ɹ� |
| AISDK_ERROR_* | int | ���������붨���AISDK_ERROR_*����  |

</br>
----------
### ͨ��״̬�ϱ��ӿ�

<pre><code>void aisdkReportClientState(const char* sJsonData, void* userData, int userDataLen);</code></pre>
  
<p>ͨ��״̬�ϱ��ӿڡ�</p>

### ����
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
|  sJsonData | const char* | JSON��ʽ���ϱ����ݣ��������Ͳ�ͬ����Ҳ������ͬ��������ο��ĵ� |
|  userData | void* | �Զ�������ָ�롣callbackʱ���� |
|  len | int | �Զ������ݳ��� |

### ����ֵ
| ����     | ����       | ˵��                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OK | int | �ɹ� |
| AISDK_ERROR_* | int | ���������붨���AISDK_ERROR_*����  |



