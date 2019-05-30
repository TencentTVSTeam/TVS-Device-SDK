package com.tencent.ai.sampleapp;

import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.tencent.ai.sampleapp.record.PcmRecorder;
import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sampleapp.util.JSONTool;
import com.tencent.ai.sdk.atw.IAtwListener;
import com.tencent.ai.sdk.atw.WakeupError;
import com.tencent.ai.sdk.atw.WakeupRsp;
import com.tencent.ai.sdk.control.SpeechManager;
import com.tencent.ai.sdk.oneshot.IOneShotListener;
import com.tencent.ai.sdk.oneshot.OneShotListeners;
import com.tencent.ai.sdk.oneshot.OneShotSession;
import com.tencent.ai.sdk.settings.VoiceConfig;
import com.tencent.ai.sdk.tr.ITrListener;
import com.tencent.ai.sdk.tr.TrParameters;
import com.tencent.ai.sdk.tr.TrSession;
import com.tencent.ai.sdk.tr.VoiceConst;
import com.tencent.ai.sdk.tts.ITtsListener;
import com.tencent.ai.sdk.utils.ISSErrors;

import java.io.File;

/**
 * OneShot模式
 */
public class OneShotActivity extends BaseSampleActivity implements View.OnClickListener, PcmRecorder.RecordListener {

    private static final String TAG = "OneShotActivity";

    /** 录音线程 */
    private PcmRecorder mPcmRecorder;

    /** SDK OneShot模块Session */
    private OneShotSession mOneShotSession = null;

    /** 唤醒本地模型文件 */
    private String mResPath = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_oneshot);

        // 初始化View
        super.initView();
        findViewById(R.id.oneshot_btn).setOnClickListener(this);
        initOneShot();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        if(mPcmRecorder!=null) {
            mPcmRecorder.stopThread();
        }

        if (null != mOneShotSession) {
            mOneShotSession.release();
            mOneShotSession = null;
        }
    }

    private void initOneShot(){
        mResPath = FileUtil.getModelFilePath(this);
        File resFolder = new File(mResPath);
        if (FileUtil.isDirectoryEmpty(resFolder)) {
            printLog(mResPath + " 目录为空，请将唤醒与vad模型文件置于该目录下");
            return;
        }

        if (null == mOneShotSession) {
            TrParameters parameters = new TrParameters();
            parameters.setWakeupResDir(mResPath, false);
            parameters.setOnlineVoiceResDir(mResPath, false);

            OneShotListeners oneShotListeners = new OneShotListeners();
            oneShotListeners.setOneShotListener(mOneShotListener);
            oneShotListeners.setAtwListener(mAtwListener);
            oneShotListeners.setTrListener(mTrListener);
            oneShotListeners.setTtsListener(mTtsListener);

            mOneShotSession = new OneShotSession(this, parameters, oneShotListeners);

            //设置静音超时时间为2s
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_VAD_SILENT_MAX, "2000");

            printLog("正在初始化OneShotSession.");

            return;
        }

        startOneShot();
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.oneshot_btn) {
            startVoice2Text();
        }
    }

    private void startOneShot(){
        mOneShotSession.cancelOnlineVoice2Text();
        stopRecord();
        String message = null;
        int id = mOneShotSession.start();
        if (id != ISSErrors.ISS_SUCCESS) {
            message = "OneShot SessionStart error,id = " + id;
            Log.e(TAG, message);
        } else {
            StringBuilder initMsg = new StringBuilder();
            initMsg.append("OneShot SessionStart success.");

            // 开始录音
            mPcmRecorder = new PcmRecorder(this);
            mPcmRecorder.start();

            boolean isFullMode = SpeechManager.getInstance().getIsFullMode();
            if (isFullMode) {
                initMsg.append("\n当前处于全流程模式，语音->文本->语义.\n");
            } else {
                initMsg.append("\n当前处于单流程模式，仅语音->文本结果.\n");
            }
            initMsg.append("\n已开启OneShot流程，等待唤醒：\n");
            initMsg.append("\n也可点击语音按钮直接进行语音识别.");

            printLog(initMsg.toString());
        }
        printLog(message);
    }

    private void startVoice2Text(){
        if (mOneShotSession != null) {
            mOneShotSession.startOnlineVoice2Text();
            printLog("\n正在语音识别，录音中...");
        }
    }

    /**
     * 停止录音
     */
    private void stopRecord() {
        if(null != mPcmRecorder) {
            if (mPcmRecorder.stopThread()) {
                printLog("停止录音");
            }
        }
    }

    @Override
    public void onRecord(byte[] buffer, int bufferSize) {
//        printLog("录音中..." + bufferSize);
        if (null != mOneShotSession) {
            mOneShotSession.appendAudioData(buffer, bufferSize);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.oneshot_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        boolean checked = item.isChecked();
        if (id == R.id.full_mode) {
            item.setChecked(!checked);
            onFullModeSet(!checked);
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        boolean isFullMode = SpeechManager.getInstance().getIsFullMode();
        menu.findItem(R.id.full_mode).setChecked(isFullMode);
        return super.onPrepareOptionsMenu(menu);
    }

    /**
     * 选择流程模式
     *
     * @param enable true为全流程模式，false为单语音是别模式
     */
    private void onFullModeSet(boolean enable) {
        if (enable) {
            SpeechManager.getInstance().setFullMode(true);
            printLog("\n当前流程模式：全流程模式，OneShot识别需退出本页面重新进入,语音识别生效。点击按钮识别可直接生效");
        } else {
            // 自动结束录音
            SpeechManager.getInstance().setFullMode(false);
            printLog("\n当前流程模式：单语音识别模式，OneShot识别需退出本页面重新进入,语音识别生效。点击按钮识别可直接生效");
        }
    }

    private IOneShotListener mOneShotListener = new IOneShotListener() {
        @Override
        public void onOneShotInited(boolean state, int errId) {
            if (state) {
                printLog("初始化成功.");

                startOneShot();
            } else {
                printLog("初始化失败，errId ：" + errId);
                mOneShotSession = null;
            }
        }
    };

    private IAtwListener mAtwListener = new IAtwListener() {
        @Override
        public void onAtwInited(boolean state, int errId) {

        }

        @Override
        public void onAtwWakeup(WakeupRsp rsp) {
            printLog("唤醒成功，你好语音助理, 唤醒词:" + rsp.sText);
        }

        @Override
        public void onAtwError(WakeupError error) {

        }
    };

    private ITrListener mTrListener = new ITrListener() {
        @Override
        public void onTrInited(boolean state, int errId) {
            String msg = "onTrInited - state : " + state + ", errId : " + errId;
            Log.i(TAG, "onTrInited - state : " + state + ", errId : " + errId);
        }

        @Override
        public void onTrVoiceMsgProc(long trMsgCode, long cmd, String voiceResult, Object extraData) {
            String msg = null;
            Log.i(TAG, "onTrVoiceMsgProc - uMsg : " + trMsgCode + ", wParam : " + cmd + ", lParam : " + voiceResult);
            if (trMsgCode == TrSession.ISS_TR_MSG_InitStatus) {
                msg = "唤醒成功，正在录音";
            }else if (trMsgCode == TrSession.ISS_TR_MSG_SpeechStart) {
                msg = "检测到说话开始";
            } else if (trMsgCode == TrSession.ISS_TR_MSG_SpeechEnd) {
                msg = "检测到说话结束";
            } else if(trMsgCode == TrSession.ISS_TR_MSG_ProcessResult) {
                msg = "语音识别中：" + voiceResult;
            }else if (trMsgCode == TrSession.ISS_TR_MSG_VoiceResult) {
                msg = "语音 -> 文本 结束，结果为：" + voiceResult;
            }

            if (!TextUtils.isEmpty(msg)) {
                printLog(msg);
            }
        }

        @Override
        public void onTrSemanticMsgProc(long trMsgCode, long errCode, int cmd, String semanticResult, Object extraMsg) {
            Log.i(TAG, "onTrSemanticMsgProc - uMsg : " + trMsgCode + ", wParam : " + errCode + ", lParam : " + semanticResult + ", extraMsg : " + extraMsg);
            printLog("语音 -> 语义 结束，结果为 ：");
            String result = JSONTool.stringToJSON(semanticResult);
            printLog(result);
        }

        @Override
        public void onTrVoiceErrMsgProc(long trMsgCode, long errCode, String trErrorMsg, Object extraData) {
            Log.i(TAG, "onTrVoiceErrMsgProc - uMsg : " + trMsgCode + ", errCode : " + errCode + ", lParam : " + trErrorMsg);
            String errMsg = "";
            if (trMsgCode == TrSession.ISS_TR_MSG_Error) {
                errMsg = "语音识别错误";
            } else if (trMsgCode == TrSession.ISS_TR_MSG_SpeechTimeout) {
                if (errCode == VoiceConst.AISDK_CMD_ONLINE_RECO_TIMEOUT) {
                    errMsg = "在线识别超时，没有识别到有效输入";
                } else if (errCode == VoiceConst.AISDK_CMD_ONLINE_RECO_LOCAL_SIL_TIMEOUT) {
                    errMsg = "本地VAD检测静音超时";
                } else if (errCode == VoiceConst.AISDK_CMD_ONLINE_RECO_SPEECH_TIMEOUT) {
                    errMsg = "在线识别云端长时间结束不了导致问题";
                } else if (errCode == VoiceConst.AISDK_CMD_ONLINE_RECO_ONESHOT_SHORT_MODE_TIMEOUT) {
                    errMsg = "oneshot短模式检测vad开始静音超时";
                }
            } else if (trMsgCode == TrSession.ISS_TR_MSG_InitStreamCloudFailure) {
                errMsg = "创建云端识别session失败";
            }
            Log.i(TAG, "onTrVoiceErrMsgProc: " + errMsg);
            printLog("语音 -> 文本 出现错误，errCode ：" + errCode + ", errMsg : " + errMsg);
        }

        @Override
        public void onTrSemanticErrMsgProc(long trMsgCode, long errCode, int cmd, String trErrorMsg, Object extraMsg) {
            Log.i(TAG, "onTrSemanticErrMsgProc - uMsg : " + trMsgCode + ", errCode : " + errCode + ", cmd : " + cmd
                    + ", lParam : " + trErrorMsg + ", extraMsg : " + extraMsg);
            printLog("语音 -> 语义 出现错误，errCode ：" + errCode + ", cmd : " + cmd +", msg : " + trErrorMsg);
        }
    };

    private ITtsListener mTtsListener = new ITtsListener() {
        @Override
        public void onPlayBegin() {

        }

        @Override
        public void onPlayCompleted() {

        }

        @Override
        public void onPlayInterrupted() {

        }

        @Override
        public void onProgressReturn(int textindex, int textlen) {

        }

        @Override
        public void onError(int errorCode, String msg) {
            Log.i(TAG, "Tts 合成错误: errorCode=" + errorCode + ",errorMsg=" + msg);
            printLog("Tts 合成错误: errorCode ：" + errorCode + ", errorMsg : " + msg);
        }

        @Override
        public void onProgressRuturnData(byte[] data, boolean end) {
            Log.i(TAG, "Tts 合成音频完成: data=" + data.length + ",是否已结束=" + end);
            printLog("TTS合成音频完成，数据包大小 ：" + data.length + ", 是否最后一条音频数据 : " + end);
        }
    };

}
