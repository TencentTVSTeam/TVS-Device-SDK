# SpeechEngine



</br>
----------
### 获取SpeechEngine实例  

  
  <pre><code>+(id)sharedInstance:(NSString \*)app_key acess_token:(NSString \*)acess_token withDsn:(NSString \*)dsn </code></pre>
  
<p>获取SpeechEngine实例</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  app_key | NSString | <p>申请的appkey</p>|
|  acess_token | NSString | <p>申请的acesstoken</p>|
|  dsn | NSString | <p>uuid 手机的唯一标示</p>|


</br>
----------
### 获取已经初始化的SpeechEngine实例  

  
  <pre><code>+(id)getInitedInstance </code></pre>
  
<p>获取已经初始化的SpeechEngine实例</p>   


</br>
----------
### 设置QUA  

  
  <pre><code>-(void)setQUA:(NSString\*)vendor product:(NSString \*)product version:(NSString \*)version versionNum:(NSString \*)versionNum package:(NSString \*)package device:(NSString \*)device </code></pre>
  
<p>设置QUA</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  vendor | NSString | <p>厂商</p>|
|  product | NSString | <p>产品名称</p>|
|  version | NSString | <p>版本名称</p>|
|  versionNum | NSString | <p>版本序列号</p>|
|  package | NSString | <p>bundlerId</p>|
|  device | NSString | <p>设备类型</p>|




</br>
----------
### 注册session  

  
  <pre><code>-(void)addSession:(id<SessionDelegate>)delegate </code></pre>
  
<p>注册session</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  delegate | id | <p>id<SessionDelegate>的类型，根据需要传入VoiceSession、SemanticSession、TtsSession实例</p>|


</br>
----------
### 注销session  

  
  <pre><code>-(void)removeSDelegate:(NSString *)key </code></pre>
  
<p>注销session</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  key | NSString | <p>session对象的key</p>|


</br>
----------
### 设置配置项  

  
  <pre><code>-(void)setConfig:(int)key value:(const char *)value </code></pre>
  
<p>设置配置项 <br> 参看以K_AISDK_CONFIG_*开头的常量定义</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  key | int | <p>配置项关键字 ，见K_AISDK_CONFIG_开头的常量</p>|
|  value | const\_char\_ptr | <p>const char*类型配置项的值，见K\_AISDK\_CONFIG\_VALUE\_开头的常量</p>|



</br>
----------
### 获得相应配置项的值  

  
  <pre><code>-(NSString *)getConfig:(NSInteger)key </code></pre>
  
<p>获得相应配置项的值</p>


### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  key | NSInteger | <p>配置项关键字</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | NSString | <p>配置项的值</p>|



</br>
----------
### 获取版本信息  

  
  <pre><code>-(NSString *)getSDKVersion </code></pre>
  
<p>获取版本信息</p>



### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | NSString | <p>返回版本号，平台sdkversion-基础sdkversion</p>|


</br>
----------
### 重置状态，释放资源  

  
  <pre><code>-(NSInteger)releaseSDK </code></pre>
  
<p>重置状态，释放资源</p>

### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
|  ret | NSInteger | <p>0：ok，other：fail。 错误码定义见AISDK\_ERROR\_*常量</p>|





