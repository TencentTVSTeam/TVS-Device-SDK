# TtsSessionDelegate

</br>
----------
### 文本转语音回调  

  
  <pre><code>-(void)onOnlineTtsCallback:(NSInteger)cmd code:(NSInteger)code pcm:(NSData *)pcm userData:(id)userData </code></pre>
  
<p>文本转语音回调</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  pcm | NSData | <p>音频数据，pcm格式</p>|
|  userData | id | <p>自定义数据</p>|




</br>
----------
### 异常回调  

  
  <pre><code>-(void)onOnlineTtsError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData </code></pre>
  
<p>异常回调</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照K\_AISDK\_CMD\_TTS\_ERROR说明</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  message | NSString | <p>错误信息</p>|
|  userData | id | <p>自定义数据</p>|
