# SemanticSessionDelegate

</br>
----------
### 语义识别正常返回  

  
  <pre><code>-(void)onOnlineSemanticCallback:(NSInteger)cmd code:(NSInteger)code data:(NSString *)data userData:(id)userData </code></pre>
  
<p>语义识别正常返回</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>返回结果命令字，参照K\_AISDK\_CMD\_xx来处理具体业务</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  data | NSString | <p>返回的json数据，参照语义说明文档解析</p>|
|  userData | id | <p>调用语义识别时传入的自定义参数</p>|




</br>
----------
### 语义识别错误返回  

  
  <pre><code>-(void)onOnlineSemanticError:(NSInteger)cmd code:(NSInteger)code message:(NSString *)message userData:(id)userData </code></pre>
  
<p>语义识别错误返回</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  cmd | NSInteger | <p>返回结果命令字，参照K\_AISDK\_CMD\_xx\_ERROR来处理异常返回</p>|
|  code | NSInteger | <p>返回的json数据错误码，参照语义说明文档解析</p>|
|  message | NSString | <p>错误信息</p>|
|  userData | id | <p>调用语义识别时传入的自定义参数</p>|

