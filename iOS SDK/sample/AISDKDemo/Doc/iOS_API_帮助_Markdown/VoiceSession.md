# VoiceSession

</br>
----------
### 取消本次语音识别  

  
  <pre><code>-(int)cancelVoice2Text </code></pre>
  
<p>取消本次语音识别</p>


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 输入录音数据  

  
  <pre><code>-(int)inputVoice2TextAudioData:(NSData *)audioBuffer </code></pre>
  
<p>输入录音数据<br>
上层应用应当把实时录音数据通过该接口输入到SDK（建议每次输入4096字节长度的音频)。<br>   
在调用此接口过程中，会有VAD检测到开始、VAD检测到结束、实时音量、语音识别到结果等 状态的回调。 <br>           
遇到AISDK_CMD_ONLINE_RECO_CANCELED/AISDK_CMD_ONLINE_RECO_TIME OUT/AISDK_CMD_ONLINE_RECO_ERROR/AISDK_CMD_ONLINE_RECO_RESULT时，停止调用 该函数。</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  audioBuffer | NSData | <p>上传音频数据</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 开始一次语音识别流程  

  
  <pre><code>-(int)startVoice2text:(NSInteger)mode </code></pre>
  
<p>开始一次语音识别流程</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  mode | NSInteger | <p>控制标志，参考K\_AISDK\_FLAG\_ONLINE\_RECO\_*常量定义。如果不设置，传0即可。</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 开始一次语音识别流程扩展  

  
  <pre><code>-(int)startVoice2text:(NSInteger)mode userData:(id)userdata </code></pre>
  
<p>开始一次语音识别流程扩展</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userdata | id | <p>自定义数据指针。callback时带回。</p>|
|  mode | NSInteger | <p>控制标志，参考K\_AISDK\_FLAG\_ONLINE\_RECO\_*常量定义。如果不设置，传0即可。</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 停止本次语音识别，获取语音识别结果  

  
  <pre><code>-(int)stopVoice2Text </code></pre>
  
<p>停止本次语音识别，获取语音识别结果<br> 停止后，不会中断语音识别，SDK会将现在已经接收到的音频发送到后台请求语音识别结果。</p>


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 初始化语音识别功能 

  
  <pre><code>-(int)initOnlineVoice2TextWithPath:(const char *)modelPath </code></pre>
  
<p>初始化语音识别功能 <br> 如果没有接入新版vad，不需要调用此方法。</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  resDir | const\_char\_ptr | <p>const char\*类型，VAD模型所在的根目录。</p>|

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|
