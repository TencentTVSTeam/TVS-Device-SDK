<a name="top"></a><span id="top"></span>
#  v2.3.190530



- [AISDKAccount](#aisdkaccount)
	- [账户信息](#账户信息)
	
- [AccountManager](#accountmanager)
	- [账户信息管理工具](#账户信息管理工具)
	- [清理帐号信息](#清理帐号信息)
	- [获取帐号信息](#获取帐号信息)
	- [设置帐号信息](#设置帐号信息)
	- [设置帐号ID](#设置帐号id)
	
- [AtwSession](#atwsession)
	- [输入录音数据](#输入录音数据)
	- [构造函数](#构造函数)
	- [获取唤醒单例](#获取唤醒单例)
	- [获取唤醒的置信度](#获取唤醒的置信度)
	- [获取唤醒灵敏度](#获取唤醒灵敏度)
	- [初始化唤醒回调](#初始化唤醒回调)
	- [初始化服务](#初始化服务)
	- [销毁唤醒引擎](#销毁唤醒引擎)
	- [设置语音唤醒的参数](#设置语音唤醒的参数)
	- [设置唤醒灵敏度](#设置唤醒灵敏度)
	- [启动语音唤醒](#启动语音唤醒)
	- [停止本次唤醒会话](#停止本次唤醒会话)
	- [停止本次语音唤醒识别](#停止本次语音唤醒识别)
	
- [CommonConfig](#commonconfig)
	- [通用配置](#通用配置)
	
- [ESpeaker](#espeaker)
	- [离线TTS的设置项](#离线tts的设置项)
	
- [IAtwListener](#iatwlistener)
	- [语音唤醒回调](#语音唤醒回调)
	- [语音唤醒错误回调](#语音唤醒错误回调)
	- [语音唤醒模块初始化结果](#语音唤醒模块初始化结果)
	- [语音唤醒结果回调](#语音唤醒结果回调)
	
- [IOneShotListener](#ioneshotlistener)
	- [OneShot模块初始化结果](#oneshot模块初始化结果)
	
- [ISSErrors](#isserrors)
	- [常量类](#常量类)
	
- [ITrListener](#itrlistener)
	- [语音、语义识别回调](#语音、语义识别回调)
	- [TrSession会话初始化结果](#trsession会话初始化结果)
	- [语义识别出现错误](#语义识别出现错误)
	- [语义识别回调](#语义识别回调)
	- [语音识别出现错误](#语音识别出现错误)
	- [语音识别回调](#语音识别回调)
	
- [ITtsInitListener](#ittsinitlistener)
	- [TTS播报状态回调](#tts播报状态回调)
	- [语音合成出现错误](#语音合成出现错误)
	- [TTS播报开始](#tts播报开始)
	- [TTS播报完成](#tts播报完成)
	- [TTS播报中断](#tts播报中断)
	- [播报进度](#播报进度)
	- [返回流式音频语音流](#返回流式音频语音流)
	- [TTS会话初始化结果](#tts会话初始化结果)
	
- [ITvwListener](#itvwlistener)
	- [自定义唤醒回调接口](#自定义唤醒回调接口)
	- [语音唤醒模块初始化结果](#语音唤醒模块初始化结果)
	- [设置唤醒词状态回调](#设置唤醒词状态回调)
	- [语音唤醒结果回调](#语音唤醒结果回调)
	
- [OneShotListeners](#oneshotlisteners)
	- [设置唤醒回调接口](#设置唤醒回调接口)
	- [设置oneshot初始化回调](#设置oneshot初始化回调)
	- [设置语音/语义识别回调](#设置语音/语义识别回调)
	- [设置TTS语音合成回调](#设置tts语音合成回调)
	
- [OneShotSession](#oneshotsession)
	- [构造函数](#构造函数)
	- [输入音频数据](#输入音频数据)
	- [取消当前正在进行的语音识别](#取消当前正在进行的语音识别)
	- [停止OneShot流程](#停止oneshot流程)
	- [开始OneShot流程](#开始oneshot流程)
	- [开始一次语音识别](#开始一次语音识别)
	- [停止当前正在进行的语音识别并获取结果](#停止当前正在进行的语音识别并获取结果)
	
- [SemanticConfig](#semanticconfig)
	- [语义识别请求flag](#语义识别请求flag)
	
- [SemanticConst](#semanticconst)
	- [语义识别的常量类](#语义识别的常量类)
	
- [SpeechManager](#speechmanager)
	- [SDK管理类](#sdk管理类)
	- [获取SDK各项参数](#获取sdk各项参数)
	- [设置SDK各项参数](#设置sdk各项参数)
	- [获取SDK的GUID](#获取sdk的guid)
	- [获取SpeechManager实例](#获取speechmanager实例)
	- [获取SDK的Qua](#获取sdk的qua)
	- [设置QUA](#设置qua)
	- [设置appkey和token](#设置appkey和token)
	- [设置偏向领域](#设置偏向领域)
	- [设置地理位置](#设置地理位置)
	- [用来设置网络环境](#用来设置网络环境)
	- [控制语音识别流程](#控制语音识别流程)
	- [设置离线语音识别log开关](#设置离线语音识别log开关)
	- [设置网络超时时间](#设置网络超时时间)
	- [用来设置沙箱环境](#用来设置沙箱环境)
	- [设置静音结束时长](#设置静音结束时长)
	- [设置静音超时时长](#设置静音超时时长)
	- [用来设置测试环境](#用来设置测试环境)
	- [初始化SDK](#初始化sdk)
	
- [TrParameters](#trparameters)
	- [设置离线语义模型路径](#设置离线语义模型路径)
	- [设置离线语音模型路径](#设置离线语音模型路径)
	- [设置vad模型路径](#设置vad模型路径)
	- [设置离线唤醒模型路径](#设置离线唤醒模型路径)
	
- [TrSession](#trsession)
	- [开始一次语音/语义识别流程](#开始一次语音/语义识别流程)
	- [开始一次语音/语义识别流程](#开始一次语音/语义识别流程)
	- [语义识别](#语义识别)
	- [构造函数](#构造函数)
	- [构造函数](#构造函数)
	- [输入录音数据方法](#输入录音数据方法)
	- [直接用文本请求语义](#直接用文本请求语义)
	- [直接用文本请求语义](#直接用文本请求语义)
	- [直接用文本请求语义](#直接用文本请求语义)
	- [直接用文本请求语义](#直接用文本请求语义)
	- [停止传送录音](#停止传送录音)
	- [获得TrSession对象](#获得trsession对象)
	- [获得TrSession对象](#获得trsession对象)
	- [获得TrSession对象](#获得trsession对象)
	- [获得TrSession对象](#获得trsession对象)
	- [初始化vad模型](#初始化vad模型)
	- [销毁TrSession会话](#销毁trsession会话)
	- [请求FM数据](#请求fm数据)
	- [请求FM数据](#请求fm数据)
	- [根据音乐ID请求音乐信息](#根据音乐id请求音乐信息)
	- [根据音乐ID请求音乐信息](#根据音乐id请求音乐信息)
	- [根据音乐ID请求音乐信息](#根据音乐id请求音乐信息)
	- [使用明确语义发送请求](#使用明确语义发送请求)
	- [使用明确语义发送请求](#使用明确语义发送请求)
	- [使用明确语义发送请求](#使用明确语义发送请求)
	- [使用明确语义发送请求](#使用明确语义发送请求)
	- [使用明确语义发送请求](#使用明确语义发送请求)
	- [使用明确语义发送请求](#使用明确语义发送请求)
	- [设定识别参数](#设定识别参数)
	- [设置语义识别环境](#设置语义识别环境)
	- [设置静音超时时间](#设置静音超时时间)
	- [设置语音识别环境](#设置语音识别环境)
	- [开始一次语音/语义识别流程](#开始一次语音/语义识别流程)
	- [开始一次语音/语义识别流程](#开始一次语音/语义识别流程)
	- [开始一次语音/语义识别流程](#开始一次语音/语义识别流程)
	- [强制停止TrSession的语义语音识别流程](#强制停止trsession的语义语音识别流程)
	- [上传字典](#上传字典)
	
- [TtsConfig](#ttsconfig)
	- [TTS的设置项](#tts的设置项)
	
- [TtsConst](#ttsconst)
	- [回调接口命令](#回调接口命令)
	- [TTS的语音包状态code](#tts的语音包状态code)
	
- [TtsParams](#ttsparams)
	- [TTS参数](#tts参数)
	
- [TtsSession](#ttssession)
	- [TTS功能类](#tts功能类)
	- [取消TTS播报](#取消tts播报)
	- [初始化方法](#初始化方法)
	- [暂停TTS播报](#暂停tts播报)
	- [恢复TTS播报](#恢复tts播报)
	- [一次TTS会话的初始化工作](#一次tts会话的初始化工作)
	- [终止此次合成会话](#终止此次合成会话)
	- [设置音频播放焦点类型](#设置音频播放焦点类型)
	- [设置参数](#设置参数)
	- [设置参数](#设置参数)
	- [设置stream type](#设置stream-type)
	- [构造函数](#构造函数)
	- [设置语音识别环境](#设置语音识别环境)
	- [开始语音合成](#开始语音合成)
	- [停止TTS播报](#停止tts播报)
	
- [TvwSession](#tvwsession)
	- [自定义唤醒工具类](#自定义唤醒工具类)
	- [输入录音数据](#输入录音数据)
	- [输入录音数据](#输入录音数据)
	- [获取唤醒单例](#获取唤醒单例)
	- [获取对应场景的所有唤醒词](#获取对应场景的所有唤醒词)
	- [销毁唤醒引擎](#销毁唤醒引擎)
	- [覆盖当前场景的唤醒词](#覆盖当前场景的唤醒词)
	- [恢复默认唤醒词](#恢复默认唤醒词)
	- [设置唤醒词](#设置唤醒词)
	- [启动自定义唤醒](#启动自定义唤醒)
	- [停止本次唤醒会话](#停止本次唤醒会话)
	
- [VoiceConfig](#voiceconfig)
	- [语音识别的设置项](#语音识别的设置项)
	
- [VoiceConst](#voiceconst)
	- [语音识别常量](#语音识别常量)
	
- [WakeupConfig](#wakeupconfig)
	- [唤醒的设置项](#唤醒的设置项)
	
- [WakeupConst](#wakeupconst)
	- [回调接口命令](#回调接口命令)
	- [唤醒错误码](#唤醒错误码)
	
- [WakeupError](#wakeuperror)
	- [唤醒错误信息](#唤醒错误信息)
	
- [WakeupRsp](#wakeuprsp)
	- [唤醒返回参数](#唤醒返回参数)
	


# AISDKAccount




<br>
[#Top](#top)
## 账户信息

<p>账户信息存放类</p>

```java
public class AISDKAccount
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| IDCENTER_ID_QQ | int | <p>QQ账户登录类型</p>|
| IDCENTER_ID_WX | int | <p>微信账户登录类型</p>|
| IDCENTER_ID_DV | int | <p>设备唯一ID，目前用于iOS设备游客模式</p>|
| IDCENTER_ID_QQOPEN | int | <p>qq物联开放平台</p>|
| accountType | int | <p>qq物联开放平台</p>|
| appId | String | <p>appId</p>|
| openId | String | <p>openId</p>|
| refreshToken | String | <p>refreshToken</p>|
| accessToken | String | <p>accessToken</p>|
| qbId | String | <p>qbId</p>|
| expireTime | long | <p>微信的有效时间，其他类型传0即可</p>|
| isNeedRefresh | int | <p>是否需要SDK进行账户票据的刷新</p>|



# AccountManager




<br>
[#Top](#top)
## 账户信息管理工具

<p>账户信息管理工具,主要用于设置账户信息以及获取账户信息接口</p>

```java
public class AccountManager
```






<br>
[#Top](#top)
## 清理帐号信息

<p>清理账户信息接口，账户退出后调用</p>

```java
public void aisdkClearAccount()
```






<br>
[#Top](#top)
## 获取帐号信息

<p>获取账户信息,当使用SDK自主刷新后，请求相关信息之前需要重新获取账户信息</p>

```java
public AISDKAccount aisdkGetAccount()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDKAccount | AISDKAccount | <p>帐号信息</p>|


<br>
[#Top](#top)
## 设置帐号信息

<p>上传账户信息,当设备账户登录后，需要把账户信息设置进来</p>

```java
public int aisdkSetAccount(AISDKAccount account)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| account | AISDKAccount | <p>帐号信息存放类</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置帐号ID

<p>设置ID接口,方便dm sdk的参数传入，dm sdk返回的账号是字符串，字符串里面用,分割。</p>

```java
public int aisdkSetAccountByClientId(String clientId, int isNeedRefresh)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| clientId | String | <p>DM SDK登录后返回的账号信息</p>|
| isNeedRefresh | boolean | <p>是否需要SDK内部刷票</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|

# AtwSession




<br>
[#Top](#top)
## 输入录音数据

<p>输入录音数据，输入实时的录音数据,支持输入16K采样率、S16-LE、单声道的PCM录音,只能在一个线程中调用此接口</p>

```java
public synchronized int appendAudioData(byte[] audioBuffer, int bufferLength)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| audioBuffer | byte[] | <p>录音缓存数组，建议每次输入4096字节。</p>|
| bufferLength | int | <p>录音缓存数组长度</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 构造函数

<p>构造AtwSession，需要传三个非空参数,否则会取到null</p>

```java
public AtwSession(Context context, String resDir, IAtwListener mvwListener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>建议Context.getApplicationContext()</p>|
| resDir | String | <p>资源路径。该目录下应该有keywords_model文件夹。</p>|
| atwListener | IAtwListener | <p>唤醒回调</p>|




<br>
[#Top](#top)
## 获取唤醒单例

<p>取得语音唤醒实例，需要传三个非空参数,否则会取到null</p>

```java
public static AtwSession getInstance(Context context, String resDir, boolean withModelDir)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>建议Context.getApplicationContext()</p>|
| resDir | String | <p>资源目录</p>|
| withModelDir | boolean | <p>如果指定为true,则资源目录直接为resDir, 否则，将在resDir后面自动加上keywords_model</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AtwSession | AtwSession | <p>AtwSession实例</p>|


<br>
[#Top](#top)
## 获取唤醒的置信度

<p>获取上一次成功唤醒的置信度</p>

```java
public float getScore()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| score | float | <p>上一次成功唤醒的置信度</p>|


<br>
[#Top](#top)
## 获取唤醒灵敏度

<p>获取唤醒灵敏度</p>

```java
public float getSensitive()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| sensitive | float | <p>当前设置的唤醒灵敏度</p>|


<br>
[#Top](#top)
## 初始化唤醒回调

<p>如果使用getInstance(context, resDir, withModelDir)进行初始化，则需主动调用此方法初始化回调</p>

```java
public void init(IAtwListener listener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| listener | IAtwListener | <p>唤醒回调</p>|




<br>
[#Top](#top)
## 初始化服务

<p>连接服务,创建session时默认连接一次</p>

```java
public void initService()
```






<br>
[#Top](#top)
## 销毁唤醒引擎

<p>销毁唤醒引擎。此方法调用后， AtwSession将不可用。</p>

```java
public int release()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置语音唤醒的参数

<p>设置语音唤醒的参数。</p>

```java
public synchronized int setParam(String szParam, String szParamValue)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| szParam | String | <p>参数项</p>|
| szParamValue | String | <p>参数值</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置唤醒灵敏度

<p>设置唤醒灵敏度</p>

```java
public void setSensitive(float sensitive)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| sensitive | float | <p>取值范围是0.5~0.99之间，数值越大灵敏度越高</p>|




<br>
[#Top](#top)
## 启动语音唤醒

<p>启动语音唤醒。接口是同步的</p>

```java
public synchronized int start()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 停止本次唤醒会话

<p>停止唤醒会话。停止唤醒会话后，不要调用appendAudioData()输入唤醒语音流。</p>

```java
public int stop()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 停止本次语音唤醒识别

<p>停止本次语音唤醒识别。</p>

```java
public int stopScene()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|

# CommonConfig




<br>
[#Top](#top)
## 通用配置

<p>通用配置</p>

```java
public class CommonConfig
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CONFIG_ENV_TYPE | int | <p>1,网络环境：0-正式环境；1-测试环境</p>|
| AISDK_CONFIG_TTS_TYPE | int | <p>2,TTS格式：0-MP3；1-WAV;2-AMR</p>|
| AISDK_CONFIG_AUDIO_FORMAT | int | <p>3,请求语音格式，1:PCM 2:WAV 4:SPEEX 5:AMR 6:WX_SPEEX 7:OPUS 8:MP3</p>|
| AISDK_CONFIG_REQ_TIMEOUT | int | <p>4,配置网络请求超时时间，单位ms,例：设置请求超时时长为5s,aisdkSetConfig(AISDK_CONFIG_REQ_TIMEOUT,&quot;5000&quot;)</p>|
| AISDK_CONFIG_VAD_RATION | int | <p>5,配置VAD灵敏度，配置VAD灵敏度，值越大，灵敏度越低，建议使用1.1</p>|
| AISDK_CONFIG_LOG_LEVEL | int | <p>6,配置LOG打印级别</p>|
| AISDK_CONFIG_VOICE_ENGINE | int | <p>7,语音识别引擎：0:NONE;1:baidu;2:WX;3:IFLY;4:YIYA;5:BETA</p>|
| AISDK_CONFIG_TTS_ENGINE | int | <p>8,TTS引擎：0:NONE;1:baidu;2:WX;3:IFLY;4:YIYA;5:BETA</p>|
| AISDK_CONFIG_LBS_DATA | int | <p>9,位置信息，格式：经度|纬度，例如：&quot;113.930770|22.543501&quot;</p>|
| AISDK_CONFIG_ASR_DOMAIN | int | <p>10,配置语音识别模型;例如：10：通用模型，80：音箱模型，90：车机模型</p>|
| AISDK_CONFIG_CHAT_BOT | int | <p>11,配置聊天机器人</p>|
| AISDK_CONFIG_APP_KEY_AND_TOKEN | int | <p>12,单独配置app key和access token，包括appkey和access token，以&quot;|&quot;隔开</p>|
| AISDK_CONFIG_LOG_SYNC | int | <p>14,配置LOG是否同步打印.AISDK_CONFIG_VALUE_ENABLE|开启同步打印日志。AISDK_CONFIG_VALUE_DISABLE|异步打印日志。</p>|
| AISDK_CONFIG_GUID | int | <p>15,获得设备当前GUID</p>|
| AISDK_CONFIG_QUA | int | <p>16,获得设备当前QUA</p>|
| AISDK_CONFIG_LOG_TIME_FORMAT | int | <p>17,配置LOG打印的时间格式</p>|
| AISDK_CONFIG_NETWORK_TYPE | int | <p>18,配置当前网络类型</p>|
| AISDK_CONFIG_NETWORK_STATUS | int | <p>19,配置当前网络状态，&quot;1&quot;:有网，&quot;0&quot;:无网</p>|
| AISDK_CONFIG_CHANNEL_ID | int | <p>20,配置渠道号</p>|
| AISDK_CONFIG_RSP_VERSION | int | <p>21,配置回复语规范，取值范围：1，2</p>|
| AISDK_CONFIG_LOG_MAX_SIZE | int | <p>22,配置配置日志文件大小，单位MB，此配置只能在init方法调用之前设置</p>|
| AISDK_CONFIG_APP_VERSION_NUM | int | <p>23,配置APP版本号</p>|
| AISDK_CONFIG_OPEN_SANDBOX | int | <p>24,配置是否开启沙箱环境</p>|
| AISDK_CONFIG_VALUE_ENABLE | String | <p>1,开启</p>|
| AISDK_CONFIG_VALUE_DISABLE | String | <p>0,禁用</p>|
| AISDK_CONFIG_VALUE_ENV_TYPE_NORMAL | String | <p>0,正式环境</p>|
| AISDK_CONFIG_VALUE_ENV_TYPE_TEST | String | <p>1,测试环境</p>|
| AISDK_CONFIG_VALUE_ENV_TYPE_EXP | String | <p>2,体验环境</p>|
| AISDK_CONFIG_VALUE_TTS_TYPE_MP3 | String | <p>0,TTS格式：MP3</p>|
| AISDK_CONFIG_VALUE_TTS_TYPE_WAV | String | <p>1,TTS格式：WAV</p>|
| AISDK_CONFIG_VALUE_TTS_TYPE_AMR | String | <p>2,TTS格式：AMR</p>|
| AISDK_CONFIG_VALUE_WIFI | String | <p>0,APN类型：WIFI</p>|
| AISDK_CONFIG_VALUE_APN_CMWAP | String | <p>1,APN类型：CMWAP</p>|
| AISDK_CONFIG_VALUE_APN_CMNET | String | <p>2,APN类型：CMNET</p>|
| AISDK_CONFIG_VALUE_APN_UNWAP | String | <p>3,APN类型：UNWAP</p>|
| AISDK_CONFIG_VALUE_APN_UNNET | String | <p>4,APN类型：UNNET</p>|
| AISDK_CONFIG_VALUE_APN_CTWAP | String | <p>5,APN类型：CTWAP</p>|
| AISDK_CONFIG_VALUE_APN_CTNET | String | <p>6,APN类型：CTNET</p>|
| AISDK_CONFIG_VALUE_APN_3GWAP | String | <p>7,APN类型：3GWAP</p>|
| AISDK_CONFIG_VALUE_APN_3GNET | String | <p>8,APN类型：3GNET</p>|



# ESpeaker




<br>
[#Top](#top)
## 离线TTS的设置项

<p>离线TTS的设置项</p>

```java
public class ESpeaker
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISS_TTS_PARAM_SPEAKER | int | <p>1280,设置发声人的key</p>|
| Y_SPEACHER_ID | int | <p>0,设置发声人的value，Y老师</p>|
| LIBAI_SPEAKER_ID | int | <p>1,设置发声人的value，李白</p>|
| DAJI_SPEAKER_ID | int | <p>2,设置发声人的value，妲己</p>|



# IAtwListener




<br>
[#Top](#top)
## 语音唤醒回调

<p>语音唤醒回调</p>

```java
public interface IAtwListener
```






<br>
[#Top](#top)
## 语音唤醒错误回调

<p>语音唤醒错误回调</p>

```java
void onAtwError(WakeupError error)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| error | WakeupError | <p>错误信息</p>|




<br>
[#Top](#top)
## 语音唤醒模块初始化结果

<p>语音唤醒模块初始化结果</p>

```java
void onAtwInited(boolean state, int errId)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| state | boolean | <p>初始化结果 true:成功 false:失败</p>|
| errId | int | <p>错误码,当state==true时，errId可忽略</p>|




<br>
[#Top](#top)
## 语音唤醒结果回调

<p>语音唤醒结果回调</p>

```java
void onAtwWakeup(WakeupRsp rsp)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| rsp | WakeupRsp | <p>唤醒返回结果</p>|



# IOneShotListener




<br>
[#Top](#top)
## OneShot模块初始化结果

<p>OneShot模块初始化结果</p>

```java
void onOneShotInited(boolean state, int errId)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| state | boolean | <p>初始化结果 true:成功 false:失败</p>|
| errId | int | <p>错误码,当state==true时，errId可忽略。ISSErrors.ISS_SUCCESS ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|



# ISSErrors




<br>
[#Top](#top)
## 常量类

<p>方法返回码常量定义</p>

```java
public interface ISSErrors
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| INVALID_SESSION | 20000 | <p>授权失败,可能是识别会话还没有创建完成，或者是会话已过期</p>|
| REMOTE_EXCEPTION | 20001 | <p>远程服务异常</p>|
| BIND_FAILED | 20002 | <p>绑定服务失败</p>|
| TTS_PLAYER_SUCCESS | 21000 | <p>TTS播报成功</p>|
| TTS_PLAYER_UNINIT | 21004 | <p>TTS未init</p>|
| TTS_PLAYER_INITED_NOTSTART | 21005 | <p>TTS初始化完成</p>|
| ISS_SUCCESS | 0 | <p>成功</p>|
| ISS_ERROR_FAIL | -1 | <p>失败</p>|
| ISS_ERROR_EXCEPTION | -2 | <p>异常</p>|
| ISS_ERROR_INVALID_CALL | 10000 | <p>无效的调用。可能调用create后未等待初始化完成就直接调用sessionStart</p>|
| ISS_ERROR_INVALID_JSON_FMT | 10001 | <p>输入的Json格式有问题</p>|
| ISS_ERROR_INVALID_JSON_INFO | 10002 | <p>没有从Json输入中提取到必要的语法信息</p>|
| ISS_ERROR_OUT_OF_MEMORY | 10101 | <p>OOM</p>|
| ISS_ERROR_FILE_NOT_FOUND | 10102 | <p>文件未找到</p>|
| ISS_ERROR_INIT_SDCARD_UNAVAILABLE | 10103 | <p>sdcard错误</p>|
| ISS_ERROR_ACCESS | 10105 | |
| ISS_ERROR_INVALID_PARA | 10106 | <p>无效的参数值,输入了错误的场景或识别模式</p>|
| ISS_ERROR_NOT_INIT | 10111 | <p>未初始化</p>|
| ISS_ERROR_ALREADY_EXIST | 10121 | |
| ISS_ERROR_MSG_PARAM_ERROR | 10303 | |
| ISS_ERROR_UNKNOWN_ERROR | 1 | <p>未知错误</p>|
| ISS_ERROR_NOT_INITIALIZED | 2 | <p>SDK未初始化</p>|
| ISS_ERROR_INTERNAL_ERROR | 3 | <p>内部错误</p>|
| ISS_ERROR_VOICE_TIMEOUT | 4 | <p>语音超时</p>|
| ISS_ERROR_NETWORK_FAIL | 5 | <p>网络请求发送失败</p>|
| ISS_ERROR_NETWORK_RESPONSE_FAIL | 6 | <p>网络请求发送失败</p>|
| ISS_ERROR_NETWORK_TIMEOUT | 7 | <p>网络请求超时</p>|
| ISS_ERROR_COMMON_PARAM_INVALID | 9 | <p>传入参数错误或不合法</p>|
| ISS_ERROR_COMMOM_SERVICE_RESP | 10 | <p>服务返回异常</p>|
| ISS_ERROR_COMMON_BAD_PERFORMANCE | 11 | <p>运行不佳</p>|
| ISS_ERROR_COMMON_APPKEY_NOT_SET | 12 | <p>初始化时未设置Appkey和AccessToken</p>|
| ISS_ERROR_SERVICE_ERROR | 10304 | <p>后台服务异常</p>|



# ITrListener




<br>
[#Top](#top)
## 语音、语义识别回调

<p>语音、语义识别回调。</p>

```java
public interface ITrListener
```






<br>
[#Top](#top)
## TrSession会话初始化结果

<p>TrSession会话初始化结果</p>

```java
void onTrInited(boolean state, int errId)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| state | boolean | <p>初始化结果 true:成功 false:失败</p>|
| errId | int | <p>错误码,当state==true时，errId可忽略。ISSErrors.ISS_SUCCESS ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|




<br>
[#Top](#top)
## 语义识别出现错误

<p>语义识别出现错误</p>

```java
void onTrSemanticErrMsgProc(long trMsgCode, long errCode, int cmd, String trErrorMsg, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| trMsgCode | long | <p>消息错误码，对应TrSession#ISS_TR_MSG_*的定义<br></p> <table> <thead> <tr> <th>trMsgCode</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link TrSession#ISS_TR_MSG_Error}</td> <td>请求语义错误</td> </tr> <tr> <td>{@link TrSession#ISS_TR_MSG_SpeechTimeout}</td> <td>当语音识别结果为空时</td> </tr> </tbody> </table>|
| errCode | long | <p>错误码，用于区分具体错误信息<br></p> <table> <thead> <tr> <th>errCode</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_FAIL}</td> <td>网络请求发送失败</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_RESPONSE_FAIL}</td> <td>网络请求回包失败。</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_TIMEOUT}</td> <td>网络请求超时。</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_SERVICE_ERROR}</td> <td>服务异常</td> </tr> </tbody> </table>|
| cmd | int | <p>语义回调状态码，对应SemanticConst中的AISDK_CMD*</p>|
| trErrorMsg | String | <p>错误信息</p>|
| extraMsg | Object | <p>自定义信息。</p>|




<br>
[#Top](#top)
## 语义识别回调

<p>语义识别回调</p>

```java
void onTrSemanticMsgProc(long trMsgCode, long errCode, int cmd, String semanticResult, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| trMsgCode | long | <p>消息状态码，对应TrSession中ISS_TR_MSG_*消息<br> 根据trMsgCode区分不同类型回调<br></p> <table> <thead> <tr> <th>trMsgCode</th> <th>说明</th> <th>errCode</th> <th>cmd</th> <th>semanticResult</th> </tr> </thead> <tbody> <tr> <td>{@link TrSession#ISS_TR_MSG_Result}</td> <td>语义结果返回，语义类型看cmd</td> <td>无</td> <td>见TrSession.ISS_TR_CMD_*常量</td> <td>无</td> </tr> </tbody> </table>|
| errCode | long | <p>消息标示符</p>|
| cmd | int | <p>回调状态码，对应SemanticConst中的AISDK_CMD*</p>|
| semanticResult | String | <p>语义识别的结果</p>|
| extraMsg | Object | <p>终端调用start传入的自定义信息</p>|




<br>
[#Top](#top)
## 语音识别出现错误

<p>语音识别出现错误</p>

```java
void onTrVoiceErrMsgProc(long trMsgCode, long errCode, String trErrorMsg, Object extraData)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| trMsgCode | long | <p>消息错误码，对应TrSession#ISS_TR_MSG_*的定义<br></p> <table> <thead> <tr> <th>trMsgCode</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link TrSession#ISS_TR_MSG_Error}</td> <td>语音识别发生错误</td> </tr> <tr> <td>{@link TrSession#ISS_TR_MSG_SpeechTimeout}</td> <td>在线识别超时，没有识别到有效输入</td> </tr> </tbody> </table>|
| errCode | long | <p>错误码，用于区分具体错误信息<br></p> <table> <thead> <tr> <th>errCode</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_FAIL}</td> <td>网络请求发送失败</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_RESPONSE_FAIL}</td> <td>网络请求回包失败。</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_TIMEOUT}</td> <td>网络请求超时。</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_SERVICE_ERROR}</td> <td>服务异常</td> </tr> </tbody> </table>|
| trErrorMsg | String | <p>错误信息描述</p>|
| extraData | Object | <p>终端调用start传入的自定义信息</p>|




<br>
[#Top](#top)
## 语音识别回调

<p>语音识别回调。</p>

```java
void onTrVoiceMsgProc(long trMsgCode, long errCode, String voiceResult, Object extraData)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| trMsgCode | long | <p>消息状态码，对应TrSession中ISS_TR_MSG_*消息<br> 根据trMsgCode区分不同类型回调。<br></p> <table> <thead> <tr> <th>trMsgCode</th> <th>说明</th> <th>errCode</th> <th>voiceResult</th> </tr> </thead> <tbody> <tr> <td>{@link TrSession#ISS_TR_MSG_VolumeLevel}</td> <td>返回声音能量,0-25，可以用来展示声音效果</td> <td>无</td> <td>声音能量</td> </tr> <tr> <td>{@link TrSession#ISS_TR_MSG_ProcessResult}</td> <td>返回流式识别中间结果</td> <td>无</td> <td>结果字符串</td> </tr> <tr> <td>{@link TrSession#ISS_TR_MSG_VoiceResult}</td> <td>返回语音识别最终结果</td> <td>无</td> <td>结果字符串</td> </tr> <tr> <td>{@link TrSession#ISS_TR_MSG_SpeechStart}</td> <td>返回状态：检测到语音开始点</td> <td>无</td> <td>无</td> </tr> <tr> <td>{@link TrSession#ISS_TR_MSG_SpeechEnd}</td> <td>返回状态：检测到语音结束点</td> <td>无</td> <td>无</td> </tr> </tbody> </table>|
|  |  | |
| voiceResult | String | <p>语音识别的结果</p>|
| extraData | Object | <p>终端调用start传入的自定义信息</p>|



# ITtsInitListener




<br>
[#Top](#top)
## TTS播报状态回调

<p>TTS播报状态回调</p>

```java
public interface ITtsListener
```






<br>
[#Top](#top)
## 语音合成出现错误

<p>语音合成出现错误。<br> 如果发生错误,不仅会调用onPlayInterrupted,也会调用onError</p>

```java
void onError(int errorCode, String msg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| errorCode | int | <p>错误码<br></p> <table> <thead> <tr> <th>errorCode</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_FAIL}</td> <td>网络请求发送失败</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_RESPONSE_FAIL}</td> <td>网络请求回包失败。</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_TIMEOUT}</td> <td>网络请求超时。</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#TTS_PLAYER_UNINIT}</td> <td>播放器未初始化成功</td> </tr> <tr> <td>{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_SERVICE_ERROR}</td> <td>TTS服务异常</td> </tr> </tbody> </table>|
| msg | String | <p>错误信息</p>|




<br>
[#Top](#top)
## TTS播报开始

<p>TTS播报开始</p>

```java
void onPlayBegin()
```






<br>
[#Top](#top)
## TTS播报完成

<p>TTS播报完成</p>

```java
void onPlayCompleted()
```






<br>
[#Top](#top)
## TTS播报中断

<p>TTS播报中断</p>

```java
void onPlayInterrupted()
```






<br>
[#Top](#top)
## 播报进度

<p>播报进度。返回单位为个数</p>

```java
void onProgressReturn(int textindex, int textlen)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| textindex | int | |
| textlen | int | |




<br>
[#Top](#top)
## 返回流式音频语音流

<p>返回流式音频语音流。 对于长文本，可能多次回调。</p>

```java
void onProgressRuturnData()
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| data | byte[] | <p>语音数据包</p>|
| end | boolean | <p>是否是最后一个语音数据包</p>|




<br>
[#Top](#top)
## TTS会话初始化结果

<p>TTS会话初始化结果<br> state=true时, errId可忽略<br> state=false时, errId为错误码，参考{@link com.tencent.ai.sdk.utils.ISSErrors}常量定义。<br> 建议在{@link TtsSession} 构造函数中直接传入Context.getApplicationContext()<br></p>

```java
void onTtsInited(boolean state, int errId)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| state | boolean | <p>初始化状态， true or false</p>|
| errId | int | <p>错误码</p>|



# ITvwListener




<br>
[#Top](#top)
## 自定义唤醒回调接口

<p>自定义唤醒回调接口</p>

```java
public interface ITvwListener
```






<br>
[#Top](#top)
## 语音唤醒模块初始化结果

<p>语音唤醒模块初始化结果</p>

```java
void onTvwInited(boolean state, int errId)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| state | boolean | <p>初始化结果 true:成功 false:失败</p>|
| errId | int | <p>错误码,仅当state值为false时，需要使用</p>|




<br>
[#Top](#top)
## 设置唤醒词状态回调

<p>设置唤醒词状态回调</p>

```java
void onSetKeywordCallback(long uMsg, String lParam)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| stateCode | long | <p>取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link TvwSession#ISS_TVW_MSG_SetKeywordsSuccess}</td> <td>设置唤醒词成功</td> </tr> <tr> <td>{@link TvwSession#ISS_TVW_MSG_SetKeywordsFailed}</td> <td>设置唤醒词失败</td> </tr> </tbody> </table>|
| stateMsg | String | <p>回调信息，如果返回设置错误，则返回错误信息</p>|




<br>
[#Top](#top)
## 语音唤醒结果回调

<p>语音唤醒结果回调</p>

```java
void onTvwWakeup(int nMvwScene, int nMvwId, int nMvwScore, String lParam)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nMvwScene | int | <p>场景类型，对应:<br> {@link TvwSession#ISS_TVW_SCENE_GLOBAL}       通用 场景<br> {@link TvwSession#ISS_TVW_SCENE_CONFIRM}      确认/取消 场景<br> {@link TvwSession#ISS_TVW_SCENE_SELECT}       选择 场景<br> {@link TvwSession#ISS_TVW_SCENE_ANSWER_CALL}  电话 场景<br></p>|
| nMvwId | int | <p>唤醒词id</p>|
| nMvwScore | int | <p>唤醒词置信度，预留字段，暂不使用</p>|
| lParam | String | <p>当前唤醒词详细信息，用户设置进去的唤醒词json</p>|



# OneShotListeners




<br>
[#Top](#top)
## 设置唤醒回调接口

<p>设置唤醒回调接口</p>

```java
public void setAtwListener(IAtwListener atwListener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| atwListener | IAtwListener | <p>唤醒回调，与AtwSession一致</p>|




<br>
[#Top](#top)
## 设置oneshot初始化回调

<p>设置oneshot初始化回调</p>

```java
public void setOneShotListener(IOneShotListener oneShotListener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| oneShotListener | IOneShotListener | <p>oneshot初始化回调</p>|




<br>
[#Top](#top)
## 设置语音/语义识别回调

<p>设置语音/语义识别回调</p>

```java
public void setTrListener(ITrListener trListener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| trListener | ITrListener | <p>语音/语义识别回调，与TrSession中使用方式一致</p>|




<br>
[#Top](#top)
## 设置TTS语音合成回调

<p>设置TTS语音合成回调</p>

```java
public void setTtsListener(ITtsListener ttsListener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ttsListener | ITtsListener | <p>TTS语音合成回调，只回调onProgressRuturnData和onError，返回音频流数据，不做播放操作</p>|



# OneShotSession




<br>
[#Top](#top)
## 构造函数

<p>构造OneShotSession，需要传三个非空参数,否则会取到null</p>

```java
public OneShotSession(Context context, TrParameters trParameters, OneShotListeners oneShotListeners)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>Context，建议Context.getApplicationContext()</p>|
| trParameters | TrParameters | <p>资源参数，必须设置唤醒模型路径(setWakeupResDir)，可设置vad模型路径(setOnlineVoiceResDir)</p>|
| oneShotListeners | OneShotListeners | <p>oneshot回调集合，内部包含四个回调接口，可选择设置。 setAtwListener --- 语音唤醒回调 setTrListener  --- 语音/语义识别回调 setTtsListener --- TTS合成音频流回调 setOneShotListener - oneshot初始化回调</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| OneShotSession | OneShotSession | <p>OneShotSession实例</p>|


<br>
[#Top](#top)
## 输入音频数据

<p>输入录音数据，输入实时的录音数据,支持输入16K采样率、S16-LE、单声道的PCM录音,只能在一个线程中调用此接口</p>

```java
public synchronized int appendAudioData(byte[] audioBuffer, int bufferLength)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| audioBuffer | byte[] | <p>录音缓存数组，建议每次输入4096字节。</p>|
| bufferLength | int | <p>录音缓存数组长度</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 取消当前正在进行的语音识别

<p>取消当前正在进行的语音识别，不影响唤醒识别</p>

```java
public int cancelOnlineVoice2Text()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 停止OneShot流程

<p>停止OneShot流程，会停掉正在进行中的唤醒和语音识别</p>

```java
public int release()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始OneShot流程

<p>开始OneShot流程，启动一次即可一直输入音频，不需要反复启动，SDK内部会在唤醒识别和语音识别之间切换</p>

```java
public synchronized int start()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始一次语音识别

<p>开始一次语音识别，用于手动启动语音识别</p>

```java
public synchronized int startOnlineVoice2Text()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 停止当前正在进行的语音识别并获取结果

<p>停止当前正在进行的语音识别并获取结果，用于手动停止语音识别的场景，不影响唤醒识别</p>

```java
public int stopOnlineVoice2Text()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|

# SemanticConfig




<br>
[#Top](#top)
## 语义识别请求flag

<p>语义识别请求flag</p>

```java
public class SemanticConfig
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION | int | <p>清空上一次请求的上下文</p>|
| AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION | int | <p>退出当前请求的上下文</p>|
| AISDK_FLAG_SEMANTIC_NOT_ASR | int | <p>标记当前语义请求的文本不是语音识别结果</p>|
| AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION | int | <p>强制清除后台保存的所有上下文信息</p>|
| AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION | int | <p>让后台不把当前请求保存到session里</p>|



# SemanticConst




<br>
[#Top](#top)
## 语义识别的常量类

<p>语义识别的常量类</p>

```java
public class SemanticConst
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CMD_SEMANTIC_OFFLINE_RESULT | int | <p>1000,返回离线语义识别结果</p>|
| AISDK_CMD_SEMANTIC_OFFLINE_ERROR | int | <p>1001,返回离线语义识别错误</p>|
| AISDK_CMD_SEMANTIC_RESULT | int | <p>2000,语义返回的回调</p>|
| AISDK_CMD_MEDIA_SEMANTIC_RESULT | int | <p>2001,独立请求媒体的接口结果返回,请求的音乐/fm信息语义回调</p>|
| AISDK_CMD_SEMANTIC_ERROR | int | <p>2002,语义返回出错</p>|
| AISDK_CMD_MEDIA_SEMANTIC_ERROR | int | <p>2003,独立请求媒体出错,请求的音乐/fm信息语义回调</p>|
| AISDK_CMD_COMPLEX_SEMANTIC_RESULT | int | <p>2004,明确语义的接口结果返回</p>|
| AISDK_CMD_COMPLEX_SEMANTIC_ERROR | int | <p>2005,明确语义请求出错</p>|
| AISDK_CMD_RESOUCES_RESULT | int | <p>2006,请求资源URl接口结果返回</p>|
| AISDK_CMD_RESOUCES_ERROR | int | <p>2007,请求资源URl接口结果返回出错</p>|
| AISDK_CMD_ONLINE_RECO_UPLOAD_SEMANTIC | int | <p>2008,上传语法到语义服务器成功</p>|
| AISDK_CMD_ONLINE_RECO_UPLOAD_SEMANTIC_ERROR | int | <p>2009,上传语法到语义服务器失败</p>|
| AISDK_CMD_EX_SEMANTIC_RESULT | int | <p>2010,明确语义扩展版本语义返回</p>|
| AISDK_CMD_EX_SEMANTIC_ERROR | int | <p>2011,明确语义扩展版本语义返回出错</p>|



# SpeechManager




<br>
[#Top](#top)
## SDK管理类

<p>SDK通用接口，包括初始化、设置</p>

```java
public class SpeechManager
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| VOICE_OFFLINE_LOG_LEVEL_NONE | int | <p>不打印日志</p>|
| VOICE_OFFLINE_LOG_LEVEL_ERROR | int | <p>只打印error级别以上日志</p>|
| VOICE_OFFLINE_LOG_LEVEL_WARN | int | <p>只打印warn级别以上日志</p>|
| VOICE_OFFLINE_LOG_LEVEL_INFO | int | <p>只打印info级别以上日志</p>|
| VOICE_OFFLINE_LOG_LEVEL_DEBUG | int | <p>只打印debug级别以上日志</p>|
| VOICE_OFFLINE_TIME_FOMAT_NOMAL | int | <p>打印日志的时间戳为秒级别</p>|
| VOICE_OFFLINE_TIME_FOMAT_MM | int | <p>打印日志的时间戳为毫秒级别，慎用，有性能损耗</p>|




<br>
[#Top](#top)
## 获取SDK各项参数

<p>获取SDK各项参数</p>

```java
public String aisdkGetConfig(int key)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| key | int | <p>对应CommonConfig/VoiceConfig/SemanticConfig/TtsConfig类中的AISDK_CONFIG_*字段</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| value | String | <p>一般为CommonConfig.AISDK_CONFIG_VALUE_ENABLE开启，CommonConfig.AISDK_CONFIG_VALUE_DISABLE关闭</p>|


<br>
[#Top](#top)
## 设置SDK各项参数

<p>设置接口。设置SDK各项参数。</p>

```java
public int aisdkSetConfig(int key, String value)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| key | int | <p>对应CommonConfig/VoiceConfig/SemanticConfig/TtsConfig类中的AISDK_CONFIG_*字段</p>|
| value | String | <p>一般为CommonConfig.AISDK_CONFIG_VALUE_ENABLE:开启，CommonConfig.AISDK_CONFIG_VALUE_DISABLE:关闭</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 获取SDK的GUID

<p>获取SDK GUID接口</p>

```java
public String getGuidStr()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| guid | String | <p>GUID</p>|


<br>
[#Top](#top)
## 获取SpeechManager实例

<p>获取SpeechManager实例。SpeechManager在整个应用中，只存在单例。代表了SDK。</p>

```java
public static SpeechManager getInstance()
```






<br>
[#Top](#top)
## 获取SDK的Qua

<p>获取SDK Qua接口</p>

```java
public String getQua()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| qua | String | <p>QUA</p>|


<br>
[#Top](#top)
## 设置QUA

<p>设置QUA</p>

```java
public int setAiQua(String vendor, String productName, String deviceName)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| vendor | String | <p>厂商名字</p>|
| productName | String | <p>产品名字</p>|
| deviceName | String | <p>设备类型</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置appkey和token

<p>设置appkey和token。</p>

```java
public int setAppKeyAndAccessToken(String appkey, String accessToken)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| appkey | String | |
| accessToken | String | |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置偏向领域

<p>设置偏向领域接口。</p>

```java
public int setAsrDomain(int asrDomain)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| asrDomain | int | <p>偏向领域值说明<br></p> <table> <thead> <tr> <th>asrDomain</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{TrSession.ASR_GENERNAL_DOMAIN 10}</td> <td>通用模型</td> </tr> <tr> <td>{TrSession.ASR_SPEAKER_DOMAIN 80}</td> <td>音箱，远场模型</td> </tr> <tr> <td>{TrSession.ASR_CAR_DOMAIN 90}</td> <td>车机</td> </tr> </tbody> </table>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置地理位置

<p>设置地理位置<br>在用户地理位置变化时，开发者应调用该方法更新位置，以获得更好的体验。</p>

```java
public void setCurrentLocation(Location location)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| location | Location | <p>用户当前位置</p>|




<br>
[#Top](#top)
## 用来设置网络环境

<p>用来设置网络环境<br>正式环境、测试环境、体验环境：在腾讯云端，正式环境是给一般用户使用的后台服务集群。 腾讯会保障正式环境的服务稳定性。测试环境是给用于开发者测试那些未在正式环境上线的新功能使用的环境，一般可靠性极差。 SDK默认使用正式环境。只有特殊情况下才可以设置为测试环境和体验环境</p>

```java
public void setEnvironment(String envType)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| envType | String | <p>网络环境<br>CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_NORMAL是正式环境<br> CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_TEST为测试环境<br>CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_EXP是体验环境</p>|




<br>
[#Top](#top)
## 控制语音识别流程

<p>设置是否手动控制语音识别流程。<br>默认情况下， SDK语音识别模块自动识别语音结束，并返回识别结果。当开发者希望能自己控制语音的结束的时候，可以调用此接口设置手动模式。</p>

```java
public void setManualMode(boolean isManualMode)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| isManualMode | boolean | <p>true: 手动模式<br>false:自动模式</p>|




<br>
[#Top](#top)
## 设置离线语音识别log开关

<p>设置离线语音识别log开关</p>

```java
public int setOfflineLogLevel(int level, int value)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| level | int | <p>日志级别<br></p> <table> <thead> <tr> <th>level</th> <th>描述</th> </tr> </thead> <tbody> <tr> <td>VOICE_OFFLINE_LOG_LEVEL_DEBUG</td> <td>只打印Debug级别以上日志</td> </tr> <tr> <td>VOICE_OFFLINE_LOG_LEVEL_INFO</td> <td>只打印Info级别以上日志</td> </tr> <tr> <td>VOICE_OFFLINE_LOG_LEVEL_WARN</td> <td>只打印Warn级别以上日志</td> </tr> <tr> <td>VOICE_OFFLINE_LOG_LEVEL_ERROR</td> <td>只打印Error级别以上日志</td> </tr> <tr> <td>VOICE_OFFLINE_LOG_LEVEL_NONE</td> <td>不打印日志</td> </tr> </tbody> </table>|
| value | int | <p>日志打印间隔<br></p> <table> <thead> <tr> <th>value</th> <th>描述</th> </tr> </thead> <tbody> <tr> <td>VOICE_OFFLINE_TIME_FOMAT_NOMAL</td> <td>打印日志的时间戳为秒级别</td> </tr> <tr> <td>VOICE_OFFLINE_TIME_FOMAT_MM</td> <td>打印日志的时间戳为毫秒级别，慎用，有性能损耗</td> </tr> </tbody> </table>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置网络超时时间

<p>设置网络超时时间,默认情况是10s超时时间</p>

```java
public int setReqTimeout(int timeout)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| timeout | int | <p>单位毫秒（ms）</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 用来设置沙箱环境

<p>用来设置沙箱网络环境</p>

```java
public void setSandBox(boolean isSandBox)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| isSandBox | boolean | <p>沙箱网络环境，true为设置为沙箱环境</p>|




<br>
[#Top](#top)
## 设置静音结束时长

<p>设置静音结束时长,默认情况是10s超时时间</p>

```java
public void setSilenceTime(int silTime)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| timeout | int | <p>单位毫秒（ms）</p>|




<br>
[#Top](#top)
## 设置静音超时时长

<p>设置静音超时时长,默认情况是10s超时时间</p>

```java
public void setSilenceTimeout(int silTimeout)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| timeout | int | <p>单位毫秒（ms）</p>|




<br>
[#Top](#top)
## 用来设置测试环境

<p>用来设置测试网络环境<br>正式环境、测试环境：在腾讯云端，正式环境是给一般用户使用的后台服务集群。 腾讯会保障正式环境的服务稳定性。测试环境是给用于开发者测试那些未在正式环境上线的新功能使用的环境，一般可靠性极差。 SDK默认使用正式环境。只有特殊情况下才可以设置为测试环境。</p>

```java
public void setTestEnvironment(boolean isTestEnvironment)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| isTestEnvironment | boolean | <p>是否是测试环境。true是测试环境。 false为正式环境。</p>|




<br>
[#Top](#top)
## 初始化SDK

<p>初始化SDK,info中新增deviceSerialNum设备唯一标识码，必填，否则会初始化失败 配置信息的JSON格式如下：</p> <pre><code> {      "info":      {            "appkey":"填入在平台申请的appkey，必填",            "token":"填入在平台申请的access token，必填",            "deviceName":"CAR或者TV或者PHONE或者SPEAKER",            "productName":"产品名，全字母/下划线形式"            "vendor":"公司英文名，全字母/下划线"            "deviceSerialNum":"唯一设备标识码，必填"            "CHID":渠道号      } } </code></pre> <p>deviceName填写规范<br></p> <table> <thead> <tr> <th>设备类型</th> <th>deviceName</th> </tr> </thead> <tbody> <tr> <td>音箱</td> <td>SPEAKER</td> </tr> <tr> <td>车机</td> <td>CAR</td> </tr> <tr> <td>音箱</td> <td>PHONE</td> </tr> <tr> <td>电视</td> <td>TV</td> </tr> </tbody> </table>

```java
public void startUp(final Context context, final String info, final LoadingCallback callback)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>建议Context.getApplicationContext()</p>|
| info | String | <p>Json格式的配置信息</p>|
| callback | LoadingCallback | <p>初始化成功回调</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|

# TrParameters




<br>
[#Top](#top)
## 设置离线语义模型路径

<p>设置离线语义模型路径</p>

```java
public void setOfflineSemanticResDir(@NonNull String dir, boolean withModelDir)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| dir | String | <p>离线语音模型路径，当withModelDir为false时，会自动在dir后面添加/data</p>|
| withModelDir | boolean | <p>当withModelDir为true时，dir目录下必须有模型文件而非data文件夹</p>|




<br>
[#Top](#top)
## 设置离线语音模型路径

<p>设置离线语音模型路径</p>

```java
public void setOfflineVoiceResDir(@NonNull String dir, boolean withModelDir)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| dir | String | <p>离线语音模型路径，当withModelDir为false时，会自动在dir后面添加/mdl_vtt</p>|
| withModelDir | boolean | <p>当withModelDir为true时，dir目录下必须有模型文件而非mdl_vtt文件夹</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置vad模型路径

<p>设置本地vad模型路径</p>

```java
public void setOnlineVoiceResDir(@NonNull String dir, boolean withModelDir)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| dir | String | <p>本地vad模型路径，当withModelDir为false时，会自动在dir后面添加/vad</p>|
| withModelDir | boolean | <p>当withModelDir为true时，dir目录下必须有模型文件而非vad文件夹</p>|




<br>
[#Top](#top)
## 设置离线唤醒模型路径

<p>设置离线唤醒模型路径</p>

```java
public void setWakeupResDir(@NonNull String dir, boolean withModelDir)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| dir | String | <p>离线语音模型路径，当withModelDir为false时，会自动在dir后面添加/keywords_model</p>|
| withModelDir | boolean | <p>当withModelDir为true时，dir目录下必须有模型文件而非keywords_model文件夹</p>|



# TrSession




<br>
[#Top](#top)
## 开始一次语音/语义识别流程

<p>开始一次语音/语义识别流程。开始一次语音识别,如果已经处于识别状态,会停止之前的识别,重新开始这次新的识别</p>

```java
public synchronized int start(int iMode, boolean record, Object extraData, int iSemanticCmd)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>语音识别模式<br> iMode取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>纯在线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>纯离线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>在线离线混合识别</td> </tr> </tbody> </table>|
| record | boolean | <p>是否需要SDK录音，false:SDK不进行录音，需要上层进行录音。 true:SDK会自动进行录音。</p>|
| extraData | Object | <p>用户传入自定义信息，会在语音callback返回</p>|
| iSemanticCmd | int | <p>语义命令 iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始一次语音/语义识别流程

<p>开始一次语音/语义识别流程。开始一次语音识别,如果已经处于识别状态,会停止之前的识别,重新开始这次新的识别</p>

```java
public synchronized int start(int iMode, boolean record, Object extraData, int iSemanticCmd, boolean forceNetState)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>语音识别模式<br> iMode取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>纯在线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>纯离线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>在线离线混合识别</td> </tr> </tbody> </table>|
| record | boolean | <p>是否需要SDK录音，false:SDK不进行录音，需要上层进行录音。 true:SDK会自动进行录音。</p>|
| extraData | Object | <p>用户传入自定义信息，会在语音callback返回</p>|
| iSemanticCmd | int | <p>语义命令 iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| forceNetState | boolean | <p>是否强制启用离线识别，设置为false，则在线情况下也使用离线识别</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 语义识别

<p>语音、语义识别功能</p>

```java
public class TrSession implements VoiceRecordListener
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISS_TR_MODE_CLOUD_REC | int | <p>sessionStart函数的参数, 纯在线识别</p>|
| ISS_TR_MODE_LOCAL_REC | int | <p>sessionStart函数的参数, 纯离线识别</p>|
| ISS_TR_MODE_MIX_REC | int | <p>sessionStart函数的参数, 在线离线识别混合</p>|
| VOICE_ONLINE_DEFAULT_TYPE | int | <p>默认类型（普通话）</p>|
| VOICE_ONLINE_MANDARIN_TYPE | int | <p>普通话</p>|
| VOICE_ONLINE_ENGLISH_TYPE | int | <p>英语</p>|
| AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION | int | <p>清空上一次请求的上下文</p>|
| AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION | int | <p>退出当前请求的上下文</p>|
| AISDK_FLAG_SEMANTIC_NOT_ASR | int | <p>标记当前语义请求的文本不是语音识别结果</p>|
| AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION | int | <p>强制清除后台保存的所有上下文信息</p>|
| AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION | int | <p>让后台不把当前请求保存到session里</p>|
| ISS_TR_MSG_InitStatus | int | <p>20000,初始化是否成功</p>|
| ISS_TR_MSG_UpLoadDictToLocalStatus | int | <p>20001,本地个性化数据上传是否成功</p>|
| ISS_TR_MSG_UpLoadDictToCloudStatus | int | <p>20002,云端个性化数据上传是否成功</p>|
| ISS_TR_MSG_VolumeLevel | int | <p>20003,返回声音能量,音量大小，最小为0，最大为25</p>|
| ISS_TR_MSG_ResponseTimeout | int | <p>20004,响应超时,没有在预定的时间内检测到语音 Others: 识别引擎已经停止,不需要再写入数据</p>|
| ISS_TR_MSG_SpeechStart | int | <p>20005,检测到语音开始点</p>|
| ISS_TR_MSG_SpeechTimeout | int | <p>20006,语音识别超时或者语义识别超时</p>|
| ISS_TR_MSG_SpeechEnd | int | <p>20007,检测到语音结束点，正在进行识别处理,不需要再写入数据</p>|
| ISS_TR_MSG_Error | int | <p>20008,语义识别错误或者语音识别错误</p>|
| ISS_TR_MSG_Result | int | <p>20009,返回带语义的识别结果</p>|
| ISS_TR_MSG_VoiceResult | int | <p>20012,语音识别返回结果</p>|
| ISS_TR_MSG_ProcessResult | int | <p>20013,返回流式语音结果进度</p>|
| ISS_TR_MSG_VoiceRecordStates | int | <p>20014,录音状态回调</p>|
| ISS_TR_MSG_VoiceStart | int | <p>20015,启动语音识别</p>|
| ISS_TR_MSG_InitStreamCloudSuccess | int | <p>20016,获取语音识别Session成功，标识云端已为始语音识别做好准备</p>|
| ISS_TR_MSG_InitStreamCloudFailure | int | <p>20017,获取语音识别Session失败，本次语音识别还未开始就结束了</p>|
| ISS_TR_CMD_SEMANTIC_RESULT | int | <p>2000,语义结果类型：普通语义返回</p>|
| ISS_TR_CMD_MEDIA_SEMANTIC_RESULT | int | <p>2001,语义结果类型：音乐/FM信息语义返回</p>|
| ISS_TR_CMD_COMPLEX_SEMANTIC_RESULT | int | <p>2004,语义结果类型：复合语义返回</p>|
| ISS_TR_PARAM_VOICE_TYPE | String | <p>设置项<br> 设置TrSession识别流程类型<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_PARAM_VOICE_TYPE_RSP_VOICE}</td> <td>仅返回语音识别结果</td> </tr> <tr> <td>{@link #ISS_TR_PARAM_VOICE_TYPE_RSP_ALL}</td> <td>返回语音识别+语义识别结果</td> </tr> </tbody> </table> <p>//仅返回语音识别结果。 setParam(TrSession.ISS_TR_PARAM_VOICE_TYPE, TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_VOICE) }</p>|
| ISS_TR_PARAM_VOICE_TYPE_RSP_VOICE | String | <p>设置项值：仅语音识别</p>|
| ISS_TR_PARAM_VOICE_TYPE_RSP_ALL | String | <p>设置项值：语音+语义识别</p>|
| AISDK_CONFIG_ASR_DOMAIN | String | <p>语音识别偏向领域</p>|
| ASR_GENERNAL_DOMAIN | String | <p>通用领域</p>|
| ASR_SPEAKER_DOMAIN | String | <p>音响领域</p>|
| ASR_CAR_DOMAIN | String | <p>车机领域</p>|
| AISDK_CONFIG_AUDIO_FORMAT | String | <p>请求语音格式，1:PCM 1:WAV 4:SPEEX 5:AMR</p>|
| AIAUDIOFORMATTYPE_PCM | String | <p>语音请求格式value:1</p>|
| AIAUDIOFORMATTYPE_WAV | String | <p>语音请求格式value:2</p>|
| AIAUDIOFORMATTYPE_SPEEX | String | <p>语音请求格式value:4</p>|
| AIAUDIOFORMATTYPE_AMR | String | <p>语音请求格式value:5</p>|
| AIAUDIOFORMATTYPE_WX_SPEEX | String | <p>语音请求格式value:6</p>|
| AIAUDIOFORMATTYPE_OPUS | String | <p>语音请求格式value:7</p>|
| AIAUDIOFORMATTYPE_MP3 | String | <p>语音请求格式value:8</p>|




<br>
[#Top](#top)
## 构造函数

<p>TrSession构造方法。</p>

```java
private TrSession(Context context, ITrListener nlpListener, int iAcousLang, String resDir, String imei)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nlpListener | ITrListener | <p>回调接口,不能为null</p>|
| iAcousLang | int | <p>语音语言，填0即可</p>|
| resDir | String | <p>离线资源的存储目录。如果没有离线资源，填&quot;&quot;，不可填null</p>|
| imei | String | <p>如果机器没有imei则要手动设置，如果机器有imei该参数传入&quot;&quot;即可</p>|




<br>
[#Top](#top)
## 构造函数



```java
private TrSession(Context mContext, ITrListener mSrListener, int iAcousLang, String resDir, String imei, String serialNumber)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| mContext | Context | <p>传入的Context对象，不能为null。建议Context.getApplicationContext()</p>|
| mSrListener | ITrListener | <p>回调接口,不能为null</p>|
| iAcousLang | int | <p>语音语言，填0即可</p>|
| resDir | String | <p>离线资源的存储目录。如果没有离线资源，填&quot;&quot;，不可填null</p>|
| imei | String | <p>如果机器没有imei则要手动设置，如果机器有imei该参数传入&quot;&quot;即可</p>|
| serialNumber | String | |




<br>
[#Top](#top)
## 输入录音数据方法

<p>输入录音数据方法。输入录音数据,支持输入16K采样率、S16-LE、单声道的PCM录音。建议每次输入4096字节数据。<br> 必须处于识别启动状态下才能输入音频数据。当写入音频数据过快时，会<Br> 返回ISS_ERROR_NO_ENOUGH_BUFFER错误码,在发生这种情况时，用户需要等一段时间再写入数据。<Br> (一般智能手机,车机处理器不会出现语音识别处理跟不上效率的情况,有可能一次写入的数据太大,<Br> 或者是写测试程序时).请注意有可能在写入数据期间,语音识别引擎回调识别函数.</p>

```java
public synchronized int appendAudioData(byte[] audioBuffer, int nBufferLength)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| audioBuffer | byte[] | <p>输入的音频buffer，建议每次输入4096字节数据。</p>|
| nBufferLength | int | <p>输入的音频数据长度</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 直接用文本请求语义

<p>直接用文本请求语义返回</p>

```java
public synchronized int appendTextString(String text, boolean online, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| text | String | <p>文本。如“我要听周杰伦的歌曲”</p>|
| online | boolean | <p>选择在线模式还是离线模式</p>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 直接用文本请求语义

<p>直接用文本请求语义返回</p>

```java
public synchronized int appendTextString(String text, boolean online, int iSemanticCmd, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| text | String | <p>文本。如“我要听周杰伦的歌曲”</p>|
| online | boolean | <p>选择在线模式还是离线模式</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 直接用文本请求语义

<p>直接用文本请求语义返回</p>

```java
public synchronized int appendTextString(int iMode, String text, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>云端请求模式</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>本地请求模式</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>云端/本地请求模式</td> </tr> </tbody> </table>|
| text | String | <p>文本。如“我要听周杰伦的歌曲”</p>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 直接用文本请求语义

<p>直接用文本请求语义返回</p>

```java
public synchronized int appendTextString(int iMode, String text, int iSemanticCmd, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>云端请求模式</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>本地请求模式</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>云端/本地请求模式</td> </tr> </tbody> </table>|
| text | String | <p>文本。如“我要听周杰伦的歌曲”</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 停止传送录音

<p>主动停止传送录音，不需要再写入数据。</p>

```java
public synchronized int endAudioData()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 获得TrSession对象

<p>获得TrSession对象。开发者应确保mContext和mSrListener以及resDir不为空。 另外注意监听ISRParams.ISS_SR_MSG_InitStatus消息，只有返回该消息才可以使用识别引擎的功能</p>

```java
public static TrSession getInstance(Context context, ITrListener nlpListener, int iAcousLang, String resDir, String imei)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>传入的Context对象，不能为null。建议Context.getApplicationContext()</p>|
| nlpListener | ITrListener | <p>SR回调接口,不能为null</p>|
| iAcousLang | int | <p>语种参数，填0即可</p>|
| resDir | String | <p>离线资源的存储目录。如果没有离线资源，填&quot;&quot;，不可填null</p>|
| imei | String | <p>如果机器没有imei则要手动设置，如果机器有imei该参数传入&quot;&quot;即可</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| TrSession | TrSession | <p>TrSession</p>|


<br>
[#Top](#top)
## 获得TrSession对象



```java
public static TrSession getInstance(Context context, ITrListener srListener, int iAcousLang, String resDir, String imei, String serialNumber)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>传入的Context对象，不能为null，建议Context.getApplicationContext()</p>|
| srListener | ITrListener | <p>SR回调接口,不能为null</p>|
| iAcousLang | int | <p>语种参数，填0即可</p>|
| resDir | String | <p>离线资源的存储目录。如果没有离线资源，填&quot;&quot;，不可填null</p>|
| imei | String | <p>如果机器没有imei则要手动设置，如果机器有imei该参数传入&quot;&quot;即可</p>|
| serialNumber | String | |


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| TrSession | TrSession | <p>TrSession</p>|


<br>
[#Top](#top)
## 获得TrSession对象



```java
private static TrSession getInstance(Context context, ITrListener nlpListener, String resDir, String imei)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>传入的Context对象，不能为null。建议Context.getApplicationContext()</p>|
| nlpListener | ITrListener | <p>回调接口,不能为null</p>|
| resDir | String | <p>离线资源的存储目录。如果没有离线资源，填&quot;&quot;，不可填null</p>|
| imei | String | <p>如果机器没有imei则要手动设置，如果机器有imei该参数传入&quot;&quot;即可</p>|




<br>
[#Top](#top)
## 获得TrSession对象



```java
public static TrSession getInstance(Context context, TrParameters params)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>传入的Context对象，不能为null，建议Context.getApplicationContext()</p>|
| params | TrParameters | <p>语音识别额外参数，包含模型路径等</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| TrSession | TrSession | <p>TrSession</p>|


<br>
[#Top](#top)
## 初始化vad模型

<p>如果没有接入新版vad，不需要调用此方法</p>

```java
public int initVadModel(String vadModelDir)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| vadModelDir | String | <p>VAD模型所在的根目录</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 销毁TrSession会话

<p>销毁TrSession会话。调用了此接口后，本对象将不再可用。</p>

```java
public synchronized int release()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 请求FM数据

<p>请求FM数据</p>

```java
public synchronized int reqFM(String showId, int showType, Object extraObj)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| showId | String | <p>FM的ID</p>|
| showType | int | |
| extraObj | Object | <p>自定义信息</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 请求FM数据

<p>请求FM数据</p>

```java
public synchronized int reqFM(String showId, int showType, String extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| showId | String | <p>FM的ID</p>|
| showType | int | |
| extraMsg | String | <p>自定义信息</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 根据音乐ID请求音乐信息

<p>根据音乐ID请求音乐信息接口。 本接口返回结果从语义回调返回。</p>

```java
public synchronized int reqMusic(String mediaId, String action,Object extraObj)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| mediaId | String | <p>音乐ID</p>|
| action | String | <p>意图</p>|
| extraObj | Object | <p>回调的时候带回</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 根据音乐ID请求音乐信息

<p>根据音乐ID请求音乐信息接口。 本接口返回结果从语义回调返回。</p>

```java
public synchronized int reqMusic(String mediaId, String action, int iSemanticCmd,Object extraObj)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| mediaId | String | <p>音乐ID</p>|
| action | String | <p>意图</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraObj | Object | <p>回调的时候带回</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 根据音乐ID请求音乐信息

<p>根据音乐ID请求音乐信息接口</p>

```java
public synchronized int reqMusic(String mediaId, String extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| mediaId | String | <p>音乐ID</p>|
| extraMsg | String | <p>自定义信息。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 使用明确语义发送请求

<p>使用明确语义请求语义数据</p>

```java
public synchronized int reqWithComplexSemantic(TrSemantic semantic, boolean online, int iSemanticCmd, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| semantic | TrSemantic | <p>文本。如“我要听周杰伦的歌曲”</p>|
| online | boolean | <p>传入true</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 使用明确语义发送请求

<p>使用明确语义请求语义数据。</p>

```java
public synchronized int reqWithComplexSemantic(String semantic, boolean online, int iSemanticCmd, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| semantic | String | <p>文本。json结构</p>|
| online | boolean | <p>传入true</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th style="text-align:left">说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td style="text-align:left">清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td style="text-align:left">退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td style="text-align:left">标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td style="text-align:left">强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td style="text-align:left">让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 使用明确语义发送请求

<p>使用明确语义请求语义数据。</p>

```java
public synchronized int reqWithComplexSemantic(TrSemantic semantic, boolean online, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| semantic | TrSemantic | <p>文本。如“我要听周杰伦的歌曲”</p>|
| online | boolean | <p>传入true</p>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 使用明确语义发送请求

<p>使用明确语义请求语义数据。</p>

```java
public synchronized int reqWithComplexSemantic(String semantic, boolean online, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| semantic | String | <p>文本。json结构</p>|
| online | boolean | <p>传入true</p>|
| extraMsg | Object | <p>用户自定义对象。当语义结果回调时，将会带回该对象。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 使用明确语义发送请求

<p>使用明确语义发送请求，带自定义参数接口</p>

```java
public synchronized int sendOnlineText2SemanticEx(String text, TrSemantic semantic, AISDKExtContent[] contents, int iSemanticCmd, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| text | String | <p>请求语义的文本</p>|
| semantic | TrSemantic | <p>文本。如“我要听周杰伦的歌曲”</p>|
| contents | AISDKExtContent[] | <p>自定义参数数据，详见AISDKExtContent</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraMsg | Object | <p>自定义参数，返回方法带回去</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| cmd | int | <p>cmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>SemanticOnlineInterface.AISDK_CMD_EX_SEMANTIC_RESULT}</td> <td>返回成功结果</td> </tr> <tr> <td>SemanticOnlineInterface.AISDK_CMD_EX_SEMANTIC_ERROR</td> <td>返回失败结果</td> </tr> </tbody> </table>|


<br>
[#Top](#top)
## 使用明确语义发送请求

<p>使用明确语义发送请求，带自定义参数接口</p>

```java
public synchronized int sendOnlineText2SemanticEx(String text, String semantic, AISDKExtContent[] contents, int iSemanticCmd, Object extraMsg)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| text | String | <p>请求语义的文本</p>|
| semantic | String | <p>文本。json结构</p>|
| contents | AISDKExtContent[] | <p>自定义参数数据，详见AISDKExtContent</p>|
| iSemanticCmd | int | <p>语义命令<br> iSemanticCmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION}</td> <td>清空上一次请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_EXIT_CUR_SESSION}</td> <td>退出当前请求的上下文</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_ASR}</td> <td>标记当前语义请求的文本不是语音识别结果</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_FORCE_CLEAR_SESSION}</td> <td>强制清除后台保存的所有上下文信息</td> </tr> <tr> <td>{@link #AISDK_FLAG_SEMANTIC_NOT_SAVE_CURRENT_SESSION}</td> <td>让后台不把当前请求保存到session里</td> </tr> </tbody> </table>|
| extraMsg | Object | <p>自定义参数，返回方法带回去</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| cmd | int | <p>cmd取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>SemanticOnlineInterface.AISDK_CMD_EX_SEMANTIC_RESULT}</td> <td>返回成功结果</td> </tr> <tr> <td>SemanticOnlineInterface.AISDK_CMD_EX_SEMANTIC_ERROR</td> <td>返回失败结果</td> </tr> </tbody> </table>|


<br>
[#Top](#top)
## 设定识别参数

<p>设定识别参数。设定成功后对以后通过sessionStart启动的识别会话都有效。</p>

```java
public synchronized int setParam(String szParam, String szParamValue)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| szParam | String | <p>参数类型<br> 参数类型列表：<br></p> <table> <thead> <tr> <th>参数类型</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_PARAM_VOICE_TYPE}</td> <td>设置TrSession工作模式</td> </tr> </tbody> </table>|
| szParamValue | String | <p>参数值</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置语义识别环境

<p>设置语义识别环境</p>

```java
public synchronized int setSemanticRecognitionEnv(boolean isTestEnv)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| isTestEnv | boolean | <p>true:测试环境；false：正式环境</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置静音超时时间

<p>设置静音超时时间</p>

```java
public synchronized int setSlientTimeout(int timeout)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| timeout | int | <p>默认情况是10s超时时间</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置语音识别环境

<p>设置语音识别环境</p>

```java
public synchronized int setVoiceRecognitionEnv(boolean isTestEnv)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| isTestEnv | boolean | <p>true:测试环境；false：正式环境</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始一次语音/语义识别流程

<p>开始一次语音/语义识别流程。开始一次语音识别,如果已经处于识别状态,会停止之前的识别,重新开始这次新的识别</p>

```java
public int start(int iMode, boolean record)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>语音识别模式<br> iMode取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>纯在线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>纯离线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>在线离线混合识别</td> </tr> </tbody> </table>|
| record |  | <p>是否需要SDK录音，false:SDK不进行录音，需要上层进行录音。 true:SDK会自动进行录音。</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始一次语音/语义识别流程

<p>开始一次语音/语义识别流程。开始一次语音识别,如果已经处于识别状态,会停止之前的识别,重新开始这次新的识别</p>

```java
public synchronized int start(int iMode, boolean record, Object extraData)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>语音识别模式<br> iMode取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>纯在线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>纯离线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>在线离线混合识别</td> </tr> </tbody> </table>|
| record | boolean | <p>是否需要SDK录音，false:SDK不进行录音，需要上层进行录音。 true:SDK会自动进行录音。</p>|
| extraData | Object | <p>用户传入自定义信息，会在语音callback返回</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始一次语音/语义识别流程

<p>开始一次语音/语义识别流程。开始一次语音识别,如果已经处于识别状态,会停止之前的识别,重新开始这次新的识别</p>

```java
public synchronized int start(int iMode, boolean record, Object extraData, boolean forceNetState)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iMode | int | <p>语音识别模式<br> iMode取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MODE_CLOUD_REC}</td> <td>纯在线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_LOCAL_REC}</td> <td>纯离线识别</td> </tr> <tr> <td>{@link #ISS_TR_MODE_MIX_REC}</td> <td>在线离线混合识别</td> </tr> </tbody> </table>|
| record | boolean | <p>是否需要SDK录音，false:SDK不进行录音，需要上层进行录音。 true:SDK会自动进行录音。</p>|
| extraData | Object | <p>用户传入自定义信息，会在语音callback返回</p>|
| forceNetState | boolean | <p>是否强制启用离线识别，设置为false，则在线情况下也使用离线识别</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 强制停止TrSession的语义语音识别流程

<p>强制停止TrSession的语义语音识别流程。调用后，不再有回调。</p>

```java
public synchronized int stop()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 上传字典

<p>上传在线/离线词典</p>

```java
public synchronized int uploadDict(String strJsonBlobInfo, int bOnlyUploadToCloud)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| strJsonBlobInfo | String | <pre><code> 语法示例: 在线: {  "contactList": [{  "name": "张三"  }, {  "name": "李四"  }],  "businessType": "E_REPORT_PHONE_UPLOAD" }   离线: {   "contacts_list": [{   "name": "XXX",   "phone": ["123", "456"]   }, {    "name": "李四",    "phone": ["123", "456"]    }, {    "name": "王五",    "phone": ["123", "456"]    }],    "music_list": [{    "name": "没有共产党就没有新中国",    "ablum": "def",    "singer": ["fgh", "aaa", "bbb"]    }, {     " name": "心甘情愿",    "ablum": "def",   "singer": ["fgh", "aaa", "bbb"]   }, {    "name": "abc",   "ablum": "def",    "singer": ["fgh", "aaa", "bbb"]   }] } </code></pre>|
| bOnlyUploadToCloud | int | <p>取值范围:<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #ISS_TR_MSG_UpLoadDictToCloudStatus}</td> <td>上传云端， 供在线识别使用</td> </tr> <tr> <td>{@link #ISS_TR_MSG_UpLoadDictToLocalStatus}</td> <td>上传本地，供离线识别使用</td> </tr> </tbody> </table>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| errid | int | <p>错误返回值取值<br></p> <table> <thead> <tr> <th>成功or失败</th> <th>回调方法</th> <th>uMsg值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>成功</td> <td>{@link ITrListener#onTrVoiceMsgProc}</td> <td>{@link #TrSession#ISS_TR_MSG_UpLoadDictToCloudStatus}</td> <td>云端上传成功</td> </tr> <tr> <td>失败</td> <td>{@link ITrListener#onTrVoiceErrMsgProc}</td> <td>{@link #TrSession#ISS_TR_MSG_UpLoadDictToCloudStatus}</td> <td>云端上传失败</td> </tr> <tr> <td>成功</td> <td>{@link ITrListener#onTrVoiceMsgProc}</td> <td>{@link #TrSession#ISS_TR_MSG_UpLoadDictToLocalStatus}</td> <td>本地上传成功</td> </tr> <tr> <td>失败</td> <td>{@link ITrListener#onTrVoiceErrMsgProc}</td> <td>{@link #TrSession#ISS_TR_MSG_UpLoadDictToLocalStatus}</td> <td>本地上传失败</td> </tr> </tbody> </table>|

# TtsConfig




<br>
[#Top](#top)
## TTS的设置项

<p>TTS的设置项</p>

```java
public class TtsConfig
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CONFIG_TTS_VOLUME | int | <p>4001,设置TTS播放声音大小</p>|
| AISDK_CONFIG_TTS_ENV_TYPE | int | <p>4002,设置TTS环境</p>|
| AISDK_CONFIG_TTS_ROLE | int | <p>4003,设置tts角色</p>|



# TtsConst




<br>
[#Top](#top)
## 回调接口命令

<p>回调接口命令定义</p>

```java
AISDK_CMD_TTS
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CMD_TTS_OFFLINE_RESULT | int | <p>3000,当离线TTS合成返回结果时发出</p>|
| AISDK_CMD_TTS_OFFLINE_ERROR | int | <p>3001,当离线TTS合成返回出错时发出</p>|
| AISDK_CMD_TTS_RESULT | int | <p>4000,当在线TTS合成返回结果时发出</p>|
| AISDK_CMD_TTS_ERROR | int | <p>4001,当在线TTS合成返回出错时发出</p>|




<br>
[#Top](#top)
## TTS的语音包状态code

<p>TTS的语音包状态code</p>

```java
AISDK_RESULT
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_RESULT_OFFLINE_CODE_TTS_BEGIN | int | <p>0,离线TTS开始识别</p>|
| AISDK_RESULT_OFFLINE_CODE_TTS_DATA | int | <p>1,离线TTS中间语音数据包</p>|
| AISDK_RESULT_OFFLINE_CODE_TTS_END | int | <p>2,离线TTS识别结束</p>|
| AISDK_RESULT_CODE_TTS_DATA | int | <p>0,在线TTS中间语音数据包</p>|
| AISDK_RESULT_CODE_TTS_LAST_DATA | int | <p>1,在线TTS最后一个语音数据包,与AISDK_RESULT_CODE_TTS_DATA的不同在于:当文本较短时，tts语音包较短，只会有AISDK_RESULT_CODE_TTS_LAST_DATA</p>|



# TtsParams




<br>
[#Top](#top)
## TTS参数

<p>TTS参数</p>

```java
public class TtsParams
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| KEY_ONLINE_SPEAKER | int | <p>设置在线TTS的发声人</p>|
| VALUE_ONLINE_SPEAKER_DEFAULT | String | <p>默认角色</p>|
| VALUE_ONLINE_SPEAKER_ZHOULONGFEI | String | <p>男:zhoulongfei发声人 。如要使用，需要申请</p>|
| VALUE_ONLINE_SPEAKER_CHENANQI | String | <p>女:chenanqi发声人 。如要使用，需要申请</p>|
| VALUE_ONLINE_SPEAKER_YEZI | String | <p>女:yezi发声人。</p>|
| VALUE_ONLINE_SPEAKER_YEWAN | String | <p>男:yewan发声人。</p>|
| VALUE_ONLINE_SPEAKER_DAJI | String | <p>女:daji发声人。如要使用，需要申请</p>|
| VALUE_ONLINE_SPEAKER_LIBAI | String | <p>男:libai发声人 。如要使用，需要申请</p>|
| VALUE_ONLINE_SPEAKER_NEZHA | String | <p>童:哪吒发声人。如要使用，需要申请</p>|



# TtsSession




<br>
[#Top](#top)
## TTS功能类

<p>TTS功能类</p>

```java
public class TtsSession
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| TTS_MODE_CLOUD | int | <p>startSpeak参数，纯网络端TTS</p>|
| TTS_MODE_LOCAL | int | <p>startSpeak参数，纯本地端TTS</p>|
| TTS_MODE_MIX | int | <p>云加端混合TTS，有网络时，使用网络端TTS，无网络时，采用本地端TTS</p>|
| CONFIG_VALUE_TTS_TYPE_MP3 | String | <p>TTS格式：MP3</p>|
| CONFIG_VALUE_TTS_TYPE_WAV | String | <p>TTS格式：WAV</p>|
| CONFIG_VALUE_TTS_TYPE_AMR | String | <p>TTS格式：AMR</p>|




<br>
[#Top](#top)
## 取消TTS播报

<p>取消TTS播报，停止当前TTS播报并取消流媒体传输</p>

```java
public synchronized int cancelSpeak()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 初始化方法

<p>TtsSession初始化方法<br> 一般不需要调用，但是当{@link ITtsInitListener#onTtsInited ITtsInitListener.onTtsInited} 返回初始化失败时，可以调用该方法重新初始化。</p>

```java
public synchronized void initService()
```






<br>
[#Top](#top)
## 暂停TTS播报

<p>暂停TTS播报</p>

```java
public synchronized int pauseSpeak()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 恢复TTS播报

<p>恢复TTS播报</p>

```java
public synchronized int resumeSpeak()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 一次TTS会话的初始化工作

<p>一次TTS会话的初始化工作, 一次TTS会话成功开始后再次调用不会产生任何效果,除非收到aidl服务连接断开消息.</p>

```java
public synchronized int sessionStart(int audioType)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| audioType | int | <p>tts播报的声音类型</p>|




<br>
[#Top](#top)
## 终止此次合成会话

<p>终止此次合成会话，如果此时正在播报TTS合成结果，会停止播报。调用了此接口后，本对象将不再可用。</p>

```java
public synchronized int sessionStop()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置音频播放焦点类型

<p>设置音频播放时获取焦点的类型。<br> 默认为{@link android.media.AudioManager#AUDIOFOCUS_GAIN} 支持以下两种： {@link android.media.AudioManager#AUDIOFOCUS_GAIN} 和{@link android.media.AudioManager#AUDIOFOCUS_GAIN_TRANSIENT_MAY_DUCK} <br>下一次TTS播报生效</p>

```java
public void  setAudioFocusType(int type)
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置参数

<p>设置参数<br> setParam与{@link #setParamEx}功能是一样的，只是value参数类型不一样。<br> setParam仅支持value为int的参数类型。<br> setParamEx仅支持value为String的的参数类型<br></p>

```java
public synchronized int setParam(int id, int value)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| id | int | <p>参数类型 <br> 参见{@link #TYPE_TTS_PLAYING},设置TTS是否自动播报，默认自动播报</p>|
| value | int | <p>参数值，类型为int<br> 值取值范围<br></p> <table> <thead> <tr> <th>值</th> <th>说明</th> </tr> </thead> <tbody> <tr> <td>{@link #TTS_NO_PLAYING}</td> <td>不自动播报</td> </tr> <tr> <td>{@link #TTS_PLAYING}</td> <td>自动播报</td> </tr> </tbody> </table>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置参数

<p>设置参数</p>

```java
public synchronized int setParamEx(int id, String strValue)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| id | int | <p>参数类型</p>|
| strValue | String | <p>参数值</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置stream type

<p>设置TTS播放时的stream type</p>

```java
public void  setStreamType(int type)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| type | int | |




<br>
[#Top](#top)
## 构造函数

<p>设置TTS音频流播放音量，暂时只支持在线合成，不支持离线合成</p>

```java
public synchronized int setTTSPlayVolum(int volum)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| volum | int | <p>音量大小</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置语音识别环境

<p>设置语音识别环境</p>

```java
public synchronized int setTTSSynthesisEnv(boolean isTestEnv)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| isTestEnv | boolean | <p>true:测试环境；false：正式环境</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 开始语音合成

<p>开始语音合成（以TTS_MODE_MIX模式）<br>合成指定文本,如果引擎已经在合成一段文本时，又调用ISSTTSStart去合成 另一段文本，之前一次的合成任务会直接丢掉.</p>

```java
public synchronized int startSpeak(String text, ITtsListener listener)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| text | String | <p>要合成的文本</p>|
| listener | ITtsListener | <p>TTS回调,{@link ITtsListener}对象</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 停止TTS播报

<p>停止TTS播报</p>

```java
public synchronized int stopSpeak()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|

# TvwSession




<br>
[#Top](#top)
## 自定义唤醒工具类

<p>自定义唤醒工具类</p>

```java
public class TvwSession
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISS_TVW_SCENE_GLOBAL | int | <p>自定义唤醒&quot;通用&quot;场景类型</p>|
| ISS_TVW_SCENE_CONFIRM | int | <p>自定义唤醒&quot;确定/取消&quot;场景类型</p>|
| ISS_TVW_SCENE_SELECT | int | <p>自定义唤醒&quot;选择&quot;场景类型</p>|
| ISS_TVW_SCENE_ANSWER_CALL | int | <p>自定义唤醒&quot;电话&quot;场景类型</p>|
| ISS_TVW_MSG_SetKeywordsFailed | int | <p>设置自定义唤醒失败回调命令</p>|
| ISS_TVW_MSG_SetKeywordsSuccess | int | <p>设置自定义唤醒成功回调命令</p>|




<br>
[#Top](#top)
## 输入录音数据

<p>输入录音数据，输入实时的录音数据,支持输入16K采样率、S16-LE、单声道的PCM录音,只能在一个线程中调用此接口</p>

```java
public synchronized int appendAudioData(byte[] audioBuffer, int bufferLength)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| audioBuffer | byte[] | <p>录音缓存数组，建议每次输入4096字节。</p>|
| bufferLength | int | <p>录音缓存数组长度</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 输入录音数据

<p>输入录音数据,支持输入16K采样率、S16-LE、单声道的PCM录音。支持AEC的调用接口</p>

```java
public synchronized int appendAudioDataByAec(byte[] audioBuffer,byte[] refBuffer,int nBufferLength)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| audioBuffer | byte[] | <p>输入数据</p>|
| refBuffer | byte[] | <p>参考信号数据</p>|
| nBufferLength | int | <p>输入数据的长度</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 获取唤醒单例

<p>取得自定义唤醒的实例</p>

```java
public static TvwSession getInstance(Context context, ITvwListener mvwListener, String customWakeupModePath, String vadPath)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| context | Context | <p>建议Context.getApplicationContext()</p>|
| mvwListener | ITvwListener | <p>唤醒回调</p>|
| customWakeupModePath | String | <p>离线语音模型目录</p>|
| vadPath | String | <p>vad模型目录</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| TvwSession | TvwSession | <p>TvwSession实例</p>|


<br>
[#Top](#top)
## 获取对应场景的所有唤醒词

<p>获取对应场景的所有唤醒词接口</p>

```java
public String getSceneContent(int nTvwScene)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nTvwScene | int | <p>场景id</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| keyWord | String | <p>唤醒词列表,json字符串</p>|


<br>
[#Top](#top)
## 销毁唤醒引擎

<p>销毁唤醒引擎。此方法调用后， TvwSession将不可用。</p>

```java
public int release()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 覆盖当前场景的唤醒词

<p>覆盖当前场景的唤醒词，唤醒词相同则覆盖。</p>

```java
public int setTvwCoverKeyWords(int nTvwScene, String szWords)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nTvwScene | int | <p>场景</p>|
| szWords | String | <p>设定的唤醒词，json类型的字符串，json格式如下：<br></p> <pre> {   "Keywords": [{   "KeyWordId": 0,   "DefaultThreshold40": 0,   "KeyWord": "你好语音助理" }, {   "KeyWordId": 1,   "DefaultThreshold40": 0,   "KeyWord": "叮当叮当"   }] } </pre>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 恢复默认唤醒词

<p>恢复默认唤醒词，将当前场景的唤醒词清空</p>

```java
public int setTvwDefaultKeyWords(int nTvwScene)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nTvwScene | int | <p>场景</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 设置唤醒词

<p>设置某场景的唤醒词，此设置方式仅在后面追加，不保证唤醒词唯一。</p>

```java
public int setTvwKeyWords(int nTvwScene, String szWords)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nTvwScene | int | <p>场景ID</p>|
| szWords | String | <p>设定的唤醒词，json类型的字符串，json格式如下：<br></p> <pre> {   "Keywords": [{   "KeyWordId": 0,   "DefaultThreshold40": 0,   "KeyWord": "你好语音助理" }, {   "KeyWordId": 1,   "DefaultThreshold40": 0,   "KeyWord": "叮当叮当"   }] } </pre>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|


<br>
[#Top](#top)
## 启动自定义唤醒

<p>启动自定义唤醒</p>

```java
public synchronized int start(int nTvwScene)
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| nTvwScene | int | <p>场景类型，预留参数，暂不按场景返回对应的自定义唤醒词</p>|


### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| errId | int | <p>错误码<br> 唤醒引擎返回的错误码<br> MVW_UNAUTHORIZED:未授权的sid， sid为空<br> ISSErrID 多语音唤醒引擎返回的错误码.<br> ISS_SUCCESS:成功启动多语音唤醒;<br> ISS_ERROR_INVALID_HANDLE:无效多语音唤醒句柄;<br> ISS_ERROR_INVALID_CALL:错误调用,唤醒已经开始;<br></p>|


<br>
[#Top](#top)
## 停止本次唤醒会话

<p>停止本次唤醒会话</p>

```java
public int stop()
```




### 返回值

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| ISSErrors.ISS_SUCCESS | int | <p>ISSErrors.ISS_SUCCESS:success，other:fail。错误码见ISSErrors内常量</p>|

# VoiceConfig




<br>
[#Top](#top)
## 语音识别的设置项

<p>语音识别的设置项</p>

```java
public class VoiceConfig
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CONFIG_VOICE_ONLINE_TIMEOUT | int | <p>6001,配置在线语音超时时间，默认10s</p>|
| AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD | int | <p>6003,配置是否开启云端VAD，默认开启</p>|
| AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME | int | <p>6004,配置是否开启计算音量，默认关闭</p>|
| AISDK_CONFIG_VOICE_VAD_SILENT_MAX | int | <p>6005,配置vad静音超时时间，默认500ms</p>|
| AISDK_CONFIG_VOICE_ONLINE_LANGUAGE_TYPE | int | <p>6006,设置语音识别的语言类型，默认0普通话</p>|
| AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH | int | <p>6007,配置是否保存录音，默认关闭</p>|
| AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT | int | <p>6008,设置语音识别的静音超时时间，默认10s</p>|
| AISDK_CONFIG_VOICE_ONLINE_SIL_TIME | int | <p>6009,设置语音识别的尾部静音结束时间，默认500ms</p>|
| AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD | int | <p>6010,是否使用本地vad结束，默认开启</p>|
| AISDK_CONFIG_VOICE_ONLINE_AUDIO_PACKET_SIZE | int | <p>6011,在线识别发送的语音数据包大小，默认3200字节</p>|
| AISDK_CONFIG_VOICE_ENV_TYPE | int | <p>6012,配置语音识别环境，默认正式环境</p>|
| AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO | int | <p>6013,忽略在语音识别中的唤醒，已废弃</p>|
| AISDK_CONFIG_VOICE_ONLINE_INPUT_ENCODED_DATA | int | <p>6014,配置语音识别的输入音频是否已编码，对输入已编码的音频SDK不会再做编码，默认输入未编码音频，默认关闭</p>|
| AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD | int | <p>6015,配置是否只识别VAD，配置后不会发起在线语音识别，只回调VAD的开始和结束，默认关闭</p>|



# VoiceConst




<br>
[#Top](#top)
## 语音识别常量

<p>语音识别常量类</p>

```java
public class VoiceConst
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CMD_OFFLINE_RECO_START | int | <p>5000,离线识别开始，接受录音数据</p>|
| AISDK_CMD_OFFLINE_RECO_SPEECH_START | int | <p>5001,离线语音VAD检测到开始</p>|
| AISDK_CMD_OFFLINE_RECO_SPEECH_END | int | <p>5002,离线语音vad检测完成，可以停止输入录音数据</p>|
| AISDK_CMD_OFFLINE_RECO_RESULT | int | <p>5003,返回离线识别结果</p>|
| AISDK_CMD_OFFLINE_RECO_INTERMEDIATE_RESULT | int | <p>5004,上报离线识别的中间结果</p>|
| AISDK_CMD_OFFLINE_RECO_DATA_VOLUME | int | <p>5005,上报输入音频数据的音量值</p>|
| AISDK_CMD_OFFLINE_RECO_CANCELED | int | <p>5006,已取消离线识别</p>|
| AISDK_CMD_OFFLINE_RECO_TIMEOUT | int | <p>5007,离线识别超时</p>|
| AISDK_CMD_OFFLINE_RECO_ERROR | int | <p>5008,离线识别出错</p>|
| AISDK_CMD_ONLINE_RECO_START | int | <p>6000,在线识别开始，接受录音数据</p>|
| AISDK_CMD_ONLINE_RECO_SPEECH_START | int | <p>6001,在线语音VAD检测到开始</p>|
| AISDK_CMD_ONLINE_RECO_SPEECH_END | int | <p>6002,在线语音vad检测完成，可以停止输入录音数据</p>|
| AISDK_CMD_ONLINE_RECO_RESULT | int | <p>6003,返回在线识别结果</p>|
| AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT | int | <p>6004,返回在线识别的中间结果</p>|
| AISDK_CMD_ONLINE_RECO_DATA_VOLUME | int | <p>6005,返回输入音频数据的音量值</p>|
| AISDK_CMD_ONLINE_RECO_CANCELED | int | <p>6006,已取消在线识别</p>|
| AISDK_CMD_ONLINE_RECO_TIMEOUT | int | <p>6007,在线识别超时，没有识别到有效输入</p>|
| AISDK_CMD_ONLINE_RECO_ERROR | int | <p>6008,在线识别出错，返回错误信息</p>|
| AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT | int | <p>6009,在线识别云端长时间没有识别到结果</p>|
| AISDK_CMD_ONLINE_RECO_FULL_MODE_FINISHED | int | <p>6010,完整模式的在线识别流程结束（以FULL_MODE启动时才会回调）</p>|
| AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT | int | <p>6011,本地VAD检测静音超时</p>|
| AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_SUCCESS | int | <p>6012,获取语音识别Session成功，标识云端已为始语音识别做好准备</p>|
| AISDK_CMD_ONLINE_RECO_INIT_CLOUD_STREAM_FAILURE | int | <p>6013,获取语音识别Session失败，本次语音识别还未开始就结束了</p>|
| AISDK_CMD_ONLINE_RECO_ONESHOT_SHORT_MODE_TIMEOUT | int | <p>6014,oneshot短模式检测vad开始静音超时</p>|



# WakeupConfig




<br>
[#Top](#top)
## 唤醒的设置项

<p>唤醒的设置项</p>

```java
public class WakeupConfig
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CONFIG_WAKEUP_TIMEOUT | int | <p>7001,配置唤醒识别超时时间（已废弃）</p>|
| AISDK_CONFIG_WAKEUP_SAVE_SPEECH | int | <p>7002,配置是否保存录音，所有输入音频都保存在一个文件中，默认关闭</p>|
| AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED | int | <p>7003,配置是否保存每一次唤醒识别的录音，每次唤醒保存一个文件，默认关闭</p>|
| AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH | int | <p>7004,配置保存录音的路径，默认为&quot;&quot;</p>|
| AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE | int | <p>7005,配置保存文件的最大数量，默认20个录音文件</p>|
| AISDK_CONFIG_WAKEUP_MODEL_MD5 | int | <p>7007,获取唤醒模型的MD5，仅支持获取，不支持设置</p>|
| AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE | int | <p>7008,用于判断处于何种网络条件下，需上传唤醒音频</p>|
| AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_NO_UPLOADING | int | <p>0,配置上传唤醒音频的允许网络类型,不允许上传</p>|
| AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_ONLY_WIFI | int | <p>1,配置上传唤醒音频的允许网络类型,仅在wifi下上传</p>|
| AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_ONLY_4G | int | <p>2,配置上传唤醒音频的允许网络类型,仅在4G/3G网络上传</p>|
| AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_BOTH_WIFI_AND_4G | int | <p>3,配置上传唤醒音频的允许网络类型,同时在WIFI/4G/3G网络下上传</p>|



# WakeupConst




<br>
[#Top](#top)
## 回调接口命令

<p>回调接口命令定义</p>

```java
AISDK_CMD_WAKEUP_RECO
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_CMD_WAKEUP_RECO_START | int | <p>7000,唤醒识别开始，接受录音数据</p>|
| AISDK_CMD_WAKEUP_RECO_RESULT | int | <p>7001,唤醒vad检测完成，可以停止输入录音数据，返回唤醒识别结果</p>|
| AISDK_CMD_WAKEUP_RECO_ERROR | int | <p>7002,唤醒识别出错</p>|
| AISDK_CMD_WAKEUP_RECO_CANCELED | int | <p>7003,已取消唤醒识别</p>|




<br>
[#Top](#top)
## 唤醒错误码

<p>唤醒错误码定义</p>

```java
AISDK_ERROR_WAKEUP_RECO
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| AISDK_ERROR_WAKEUP_RECO_FAILED | int | <p>7000,模块还未初始化</p>|
| AISDK_ERROR_WAKEUP_RECO_NOT_STARTED | int | <p>7001,未初始化唤醒模块就输入语音</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED | int | <p>7002,创建离线唤醒识别模块失败</p>|
| AISDK_ERROR_WAKEUP_RECO_MODULE_UNAVAILABLE | int | <p>7003,SDK没有包含唤醒模块</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL | int | <p>7004,此错误码不返回，见其他DETAIL错误</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_OTHER | int | <p>7005,创建模块失败，其他原因</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_MISMATCH_MODEL_MD5 | int | <p>7006,创建模块失败，MD5不匹配</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_READ_MODEL_FAIL | int | <p>7007,创建模块失败，读取模型失败</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_MODEL_OR_CONFIG_FILE_NOT_EXIST | int | <p>7008,创建模块失败，配置文件不存</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_UNSUPPORTED_PCM_FORMAT | int | <p>7009,创建模块失败，不支持的PCM格式</p>|
| AISDK_ERROR_WAKEUP_RECO_CREATE_HANDLE_FAILED_DETAIL_FAIL_CREATE_DECODER | int | <p>7010,创建模块失败，创建解码器失败</p>|
| AISDK_ERROR_WAKEUP_RECO_FATAL | int | <p>7011,唤醒识别过程出错无法完成识别，例如解码音频错误</p>|



# WakeupError




<br>
[#Top](#top)
## 唤醒错误信息

<p>唤醒错误信息</p>

```java
public class WakeupError
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| errorCode | int | <p>唤醒错误码,错误码详见WakeupConst中AISDK_ERROR_WAKEUP_*相关说明</p>|
| errMsg | String | <p>唤醒错误详情</p>|



# WakeupRsp




<br>
[#Top](#top)
## 唤醒返回参数

<p>唤醒返回参数</p>

```java
public class WakeupRsp
```




### 参数

| 名称     | 类型       | 说明                           |
|:---------|:-----------|:--------------------------------------|
| iBeginTimeMs | int | <p>唤醒开始时间, 从调用start开始计时</p>|
| iEndTimeMs | int | <p>唤醒结束时间, 从调用start开始计时</p>|
| sText | String | <p>唤醒词</p>|
| isLikelyAWakeup | boolean | <p>是否疑似唤醒</p>|



