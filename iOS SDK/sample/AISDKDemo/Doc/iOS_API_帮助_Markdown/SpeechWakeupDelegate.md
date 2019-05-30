# SpeechWakeupDelegate


</br>
----------
### 唤醒识别回调  

  
  <pre><code>-(void)onSpeechWakeupCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData </code></pre>
  
<p>唤醒识别回调</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明,K\_AISDK\_CMD\_WAKEUP\_RECO\_xx</p>|
|  code | NSInteger | <p>通常返回0</p>|
|  data | NSString | <p>识别结果</p>|
|  userData | id | <p>自定义数据</p>|




</br>
----------
### 唤醒识别异常回调  
  
  <pre><code>-(void)onSpeechWakeupError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData </code></pre>
  
<p>唤醒识别异常回调</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明, K\_AISDK\_ERROR\_WAKEUP\_RECO\_xx</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  message | NSString | <p>错误信息</p>|
|  userData | id | <p>自定义数据</p>|


