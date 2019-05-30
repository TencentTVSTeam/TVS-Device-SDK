# OneshotSession

</br>
----------
### OneShot初始化，只需要初始化一次  

  
  <pre><code>-(instancetype)init:(NSString\*)voiceModelPath wakeupModelPath:(NSString\*)wakeupModelPath </code></pre>
  
<p>OneShot初始化，只需要初始化一次</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  voiceModelPath | NSString | <p>本地VAD模型所在路径，如果不需要本地VAD可以传NULL</p>|
|  wakeupModelPath | NSString | <p>唤醒词模型所在路径，必传，否则无法唤醒</p>|


</br>
----------
### 开始通用语音识别流程

  
  <pre><code>-(int)start:(void*)userData voiceType:(NSInteger)flags </code></pre>
  
<p>开始通用语音识别流程，启动一次即可一直输入语音，不需要反复启动，SDK内部会在唤醒识别和语音识别之间切换</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userData | void\_ptr | <p>void\*类型，自定义数据指针，callback时带回。</p>|
|  flags | NSInteger | <p>控制标志，参考AISDK\_FLAG\_ONLINE\_RECO\_\*常量定义，支持多flag或运算。如果不设置，传0即可。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 开始一次语音识别，用于直接唤醒开始交互  

  
  <pre><code>-(int)startOneShotOnlineVoice2Text:(void*)userData voiceType:(NSInteger)flags </code></pre>
  
<p>开始一次语音识别，用于直接唤醒开始交互。</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userData | void\_ptr | <p>void\*类型，自定义数据指针，callback时带回。</p>|
|  flags | NSInteger | <p>控制标志，参考AISDK\_FLAG\_ONLINE\_RECO\_\*常量定义，支持多flag或运算。如果不设置，传0即可。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 取消通用语音识别流程

  
  <pre><code>-(int)stopOneShot </code></pre>
  
<p>取消通用语音识别流程，会停掉正在进行中的唤醒和者语音识别</p>


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 停止本次语音识别并获取结果 

  
  <pre><code>-(int)stopOneShotOnlineVoice2Text </code></pre>
  
<p>停止本次语音识别并获取结果，用于长按开启语音识别的场景。</p>


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 取消本次语音识别 

  
  <pre><code>-(int)cancelOneShotOnlineVoice2Text </code></pre>
  
<p>取消本次语音识别。</p>

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|


</br>
----------
### 输入音频数据，在OneShot流程中全程需要输入  

  
  <pre><code>-(int)inputVoice2TextAudioData:(NSData *)audioBuffer </code></pre>
  
<p>输入音频数据，在OneShot流程中全程需要输入。</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  audioBuffer | NSData | <p>录音数据存储区域。建议长度为4096。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|