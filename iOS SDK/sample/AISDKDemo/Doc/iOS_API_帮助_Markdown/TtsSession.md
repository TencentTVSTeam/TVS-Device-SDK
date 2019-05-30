# TtsSession

</br>
----------
### 取消此次的TTS请求  

  
  <pre><code>-(int)cancelText2Speech </code></pre>
  
<p>取消此次的TTS请求 <br> 取消后，这一次的tts请求结果不再返回。</p>







### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok other:fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|

</br>
----------
### TTS识别接口， TTS结果通过回调异步回调返回  

  
  <pre><code>-(int)text2Speech:(NSString *)text userData:(id)userdata </code></pre>
  
<p>TTS识别接口， TTS结果通过回调异步回调返回</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  text | NSString | <p>需要转语音的文本，以utf8格式编码的文本串，以'\0'结尾</p>|
|  userdata | id | <p>自定义数据</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|

</br>
----------
### TTS转换接口扩展， TTS结果通过回调异步回调返回  

  
  <pre><code>-(int)text2SpeechEx:(int)languageType text:(NSString *)text userData:(id)userdata </code></pre>
  
<p>TTS转换接口扩展， TTS结果通过回调异步回调返回</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  languageType | int | <p>语言类型，0：默认，1：中文，2：英文</p>|
|  text | NSString | <p>需要转语音的文本，以utf8格式编码的文本串，以'\0'结尾</p>|
|  userdata | id | <p>自定义数据</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|


