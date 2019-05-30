# OneShotSessionDelegate



</br>
----------
### OneShot模式开启完成  

  
  <pre><code>-(void)onOneShotStart:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData </code></pre>
  
<p>OneShot模式开启完成</p>



### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明,K\_AISDK\_CMD\_xx</p>|
|  code | NSInteger | <p>通常返回0</p>|
|  data | NSString | <p>识别结果</p>|
|  userData | UserData | <p>自定义数据</p>|


</br>
----------
### OneShot模式结束  

  
  <pre><code>-(void)onOneShotStop:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData </code></pre>
  
<p>OneShot模式结束</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明, K\_AISDK\_ERROR\_xx</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  message | NSString | <p>错误信息</p>|
|  userData | UserData | <p>自定义数据</p>|


</br>
----------
### OneShot唤醒识别回调  

  
  <pre><code>-(void)onOneShotWakeupCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData </code></pre>
  
<p>OneShot唤醒识别回调</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明,K\_AISDK\_CMD\_WAKEUP\_RECO\_xx</p>|
|  code | NSInteger | <p>通常返回0</p>|
|  data | NSString | <p>识别结果</p>|
|  userData | UserData | <p>自定义数据</p>|


</br>
----------
### OneShot唤醒识别异常回调  

  
  <pre><code>-(void)onOneShotWakeupError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData </code></pre>
  
<p>OneShot唤醒识别异常回调</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明,K\_AISDK\_CMD\_WAKEUP\_RECO\_xx</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  message | NSString | <p>错误信息</p>|
|  userData | UserData | <p>自定义数据</p>|


</br>
----------
### OneShot语音识别回调  

  
  <pre><code>-(void)onOneShotVocieCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData </code></pre>
  
<p>OneShot语音识别回调</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明,K\_AISDK\_CMD\_ONLINE\_RECO\_xx</p>|
|  code | NSInteger | <p>通常返回0</p>|
|  data | NSString | <p>识别结果</p>|
|  userData | UserData | <p>自定义数据</p>|


</br>
----------
### OneShot语音识别异常回调  

  
  <pre><code>-(void)onOneShotVocieError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData </code></pre>
  
<p>OneShot语音识别异常回调</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>参照cmd说明,K\_AISDK\_CMD\_ONLINE\_RECO\_xx</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  message | NSString | <p>错误信息</p>|
|  userData | UserData | <p>自定义数据</p>|