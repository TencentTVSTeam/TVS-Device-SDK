# SemanticSession

</br>
----------
### 根据请求类型，取消特定语义请求  

  
  <pre><code>- (int)cancelSemanticByType:(NSInteger)iReqType </code></pre>
  
<p>根据请求类型，取消特定语义请求</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  iReqType | NSInteger | <p>请求类型见AISDK\_SEMANTIC\_REQ\_TYPE\_*常量</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|


</br>
----------
### 根据外部传入数据，取消特定语义请求  

  
  <pre><code>- (int)cancelSemanticByUserData:(id)userdata </code></pre>
  
<p>根据外部传入数据，取消特定语义请求</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  userdata | id | <p>传入的自定义数据</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|


</br>
----------
### 取消本次语义请求  

  
  <pre><code>- (int)cancelText2Semantic </code></pre>
  
<p>取消本次语义请求</p>


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|

</br>
----------
### 特殊功能性接口，复合语义  

  
  <pre><code>- (int)complexSemantic2Semantic:(NSString *)semanticJson userData:(id)userdata semanticFlags:(int)flags </code></pre>
  
<p>特殊功能性接口，复合语义</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  semanticJson | NSString | <p>语义JSON</p>|
|  userdata | id | <p>自定义数据，callback时带回</p>|
|  flags | int | <p>控制标志，参考AISDK\_FLAG\_SEMANTIC\_*常量定义，支持多flag或运算。默认设置为0即可。</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|


</br>
----------
### 请求单个FM的详细信息

  
  <pre><code>- (int)reqFM:(NSString *)showId showType:(NSInteger)showType extraMsg:(NSString *)extraMsg </code></pre>
  
<p>请求单个FM的详细信息，播放FM时，FM的地址可能会有变化，播放前应该用FM的ID请求一次新的url</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  showId | NSString | <p>媒体Id</p>|
|  showType | NSInteger | <p>类型</p>|
|  extraMsg | NSString | <p>扩展字段</p>|

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|


</br>
----------
### 请求单首音乐的详细信息

  
  <pre><code>- (int)reqMusic:(NSString *)mediaId extraMsg:(NSString *)extraMsg </code></pre>
  
<p>请求单首音乐的详细信息，播放音乐时，音乐的地址可能会有变化，播放前应该用音乐的ID请求一次新的url</p>

### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  mediaId | NSString | <p>媒体Id</p>|
|  extraMsg | NSString | <p>扩展字段</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|


</br>
----------
### 在线二次识别接口，结果通过回调异步回调返回  

  
  <pre><code>- (int)text2semantic:(NSString *)text userData:(id)userdata flags:(NSInteger)flags </code></pre>
  
<p>在线二次识别接口，结果通过回调异步回调返回</p>






### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  text | NSString | <p>以utf8格式编码的文本串，以'\0'结尾</p>|
|  userdata | id | <p>自定义数据</p>|
|  flags | NSInteger | <p>控制标志，参考K\_AISDK\_FLAG\_SEMANTIC\_*常量定义。默认设置为0即可</p>|



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | int | <p>0:ok, other：fail。 错误码定义见K\_AISDK\_ERROR\_*常量</p>|