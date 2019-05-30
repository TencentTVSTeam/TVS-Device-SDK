package com.tencent.ai.sampleapp;

import android.media.AudioManager;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;

import com.tencent.ai.sampleapp.record.PcmRecorder;
import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sdk.atw.AtwSession;
import com.tencent.ai.sdk.atw.IAtwListener;
import com.tencent.ai.sdk.atw.WakeupError;
import com.tencent.ai.sdk.atw.WakeupRsp;
import com.tencent.ai.sdk.tr.ITrListener;
import com.tencent.ai.sdk.tr.TrParameters;
import com.tencent.ai.sdk.tr.TrSession;
import com.tencent.ai.sdk.tts.ITtsInitListener;
import com.tencent.ai.sdk.tts.ITtsListener;
import com.tencent.ai.sdk.tts.TtsSession;
import com.tencent.ai.sdk.utils.ISSErrors;

import org.json.JSONObject;

import java.io.File;

public class WakeupRecognizeActivity extends BaseSampleActivity implements View.OnClickListener, PcmRecorder.RecordListener {

    private static final String TAG = "WakeupRecognizeActivity";


    /** 录音线程 */
    private PcmRecorder mPcmRecorder;

    /** SDK唤醒模块Session */
    private AtwSession mAtwSession = null;
    /** 是否延迟开启唤醒流程，一般在初始化时候设置 */
    private boolean mPendingStartWakeup = false;

    private TrSession mTrSession;

    /** 唤醒本地模型文件，本Sample必须放在这个目录，否则唤醒无法运行 */
    private String RES_PATH = "";

    /** SDK TtsSession */
    private TtsSession mTTSSession;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_wakeup);
        // 初始化View
        super.initView();
        findViewById(R.id.wakeup_btn).setOnClickListener(this);
        RES_PATH = FileUtil.getModelFilePath(this);

        // 初始化在线识别Session
        TrParameters params = new TrParameters();
        params.setOnlineVoiceResDir(RES_PATH, false);
        params.setWakeupResDir(RES_PATH,false);
        params.setMixModeConfigDir(RES_PATH);
        mTrSession = TrSession.getInstance(this, params);
        mTrSession.init(mTrListener);

        // 初始化Session
        mTTSSession = new TtsSession(this, mTTSInitListener, "");

        // 选择识别类型, 默认语音转文字
        onRecognizeTypeSet(TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_ALL);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        if(mPcmRecorder!=null) {
            mPcmRecorder.stopThread();
        }

        if (null != mAtwSession) {
            mAtwSession.release();
            mAtwSession = null;
        }

        if (null != mTrSession) {
            mTrSession.release();
            mTrSession = null;
        }

        // 销毁Session
        if(null != mTTSSession)
        {
            mTTSSession.stopSpeak();
            mTTSSession.release();
            mTTSSession = null;
        }
    }

    /**
     * 选择识别类型
     *
     * @param type
     */
    private void onRecognizeTypeSet(String type) {
        if (null == mTrSession) {
            return;
        }

        mTrSession.setParam(TrSession.ISS_TR_PARAM_VOICE_TYPE, type);
        if (type == TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_ALL) {
            printLog("\n当前识别类型：语音 -> 语义，下次开启语音识别生效");
        } else if (type == TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_VOICE) {
            printLog("\n当前识别类型：语音 -> 文本，下次开启语音识别生效");
        } else {
            printLog("\n未知类型");
        }
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.wakeup_btn) {
            File resFolder = new File(RES_PATH);
            if (FileUtil.isDirectoryEmpty(resFolder)) {
                printLog(RES_PATH + " 目录为空，请将唤醒模型文件置于该目录下");
                return;
            }

            if (mPendingStartWakeup) {
                printLog("正在初始化中，请稍后再试");
                return;
            }

            if (null == mAtwSession) {
                mPendingStartWakeup = true;

                mAtwSession = AtwSession.getInstance(this, RES_PATH, false);
                mAtwSession.init(mvwListener);

                printLog("初始化唤醒Session中");

                return;
            }

            // 开启唤醒
            startWakeup();
        }
    }

    /**
     * 开启唤醒
     */
    private void startWakeup() {
        // 停止上次录音
        mAtwSession.stop();
        stopRecord();

        String message = null;
        int id = mAtwSession.start();
        if (id != ISSErrors.ISS_SUCCESS) {
            message = "Wakeup SessionStart error,id = " + id;
            Log.e(TAG, message);
        } else {
            message = "Wakeup SessionStart succ";
            Log.d(TAG, message);

            // 开始录音
            mPcmRecorder = new PcmRecorder(this);
            mPcmRecorder.start();

            printLog("\n开始唤醒流程：\n");
        }
        printLog(message);
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

    /**
     * 开启语音识别
     */
    private void startRecognize() {
        // 停止上次录音
//        mTrSession.stop();

        String message = null;
        int id = mTrSession.start(TrSession.ISS_TR_MODE_CLOUD_REC, false);
        if (id != ISSErrors.ISS_SUCCESS) {
            message = "Tr SessionStart error,id = " + id;
            Log.e(TAG, message);
            printLog(message);
        } else {
            // 开始录音
//            mPcmRecorder = new PcmRecorder(this);
//            mPcmRecorder.start();

            printLog("\n开始语音识别流程：");
            printLog("开始录音");
        }
    }

    private void spreakTts(String lParam) {
        try {
            JSONObject object = new JSONObject(lParam);
            String text = object.optString("noscreen_answer");
            String tips = object.optString("tips");
            if (TextUtils.isEmpty(text)) {
                text = tips;
            }

            // 请求语义
            if(null != mTTSSession) {
                mTTSSession.stopSpeak();
                // 设置是否需要播放
                mTTSSession.setParam(TtsSession.TYPE_TTS_PLAYING, TtsSession.TTS_PLAYING);
                int ret = mTTSSession.startSpeak(text, mTTSListener);
                if (ret == ISSErrors.TTS_PLAYER_SUCCESS) {
                }

                printLog("\n请求开始：\n" + text);
            }
        } catch (Exception e) {

        }
    }

    @Override
    public void onRecord(byte[] buffer, int bufferSize) {
//        printLog("录音中..." + bufferSize);
        if (null != mAtwSession) {
            mAtwSession.appendAudioData(buffer, bufferSize);
        }

        if (null != mTrSession) {
            mTrSession.appendAudioData(buffer, bufferSize);
        }
    }

    private IAtwListener mvwListener = new IAtwListener() {

        @Override
        public void onAtwWakeup(WakeupRsp rsp) {
            Log.d(TAG, "wake up : " + rsp.iEndTimeMs);
            printLog("唤醒成功，你好语音助理, wakeup_time:" + rsp.iEndTimeMs + ",text=" + rsp.sText);
            if (null != mTTSSession) {
                mTTSSession.stopSpeak();
            }
            startRecognize();
//            stopRecord();
        }

        @Override
        public void onAtwError(WakeupError error) {

        }

        @Override
        public void onAtwInited(boolean state, int errId) {
            if (state) {
                printLog("初始化成功");

                // 初始化以后，延迟开启唤醒Session
                if (mPendingStartWakeup) {
                    startWakeup();
                }
            } else {
                printLog("初始化失败，errId ：" + errId);

                mAtwSession = null;
            }

            mPendingStartWakeup = false;
        }
    };

    private ITrListener mTrListener = new ITrListener() {
        @Override
        public void onTrInited(boolean state, int errId) {
            String msg = "onTrInited - state : " + state + ", errId : " + errId;
            Log.i(TAG, "onTrInited - state : " + state + ", errId : " + errId);
            if (state) {
            } else {
                printLog("TrSession init失败, errId : " + errId);
            }
        }

        @Override
        public void onTrVoiceMsgProc(long trMsgCode, long cmd, String voiceResult, Object extraData) {
            String msg = null;
            Log.i(TAG, "onTrVoiceMsgProc - uMsg : " + trMsgCode + ", wParam : " + cmd + ", lParam : " + voiceResult);
            if (trMsgCode == TrSession.ISS_TR_MSG_SpeechStart) {
                msg = "检测到说话开始";
            } else if (trMsgCode == TrSession.ISS_TR_MSG_SpeechEnd) {
                msg = "检测到说话结束";
            } else if (trMsgCode == TrSession.ISS_TR_MSG_VoiceResult) {
                msg = "语音 -> 文本 结束，结果为：" + voiceResult;
                //stopRecord();
            }

            if (!TextUtils.isEmpty(msg)) {
                printLog(msg);
            }
        }

        @Override
        public void onTrSemanticMsgProc(long trMsgCode, long errCode, int cmd, String semanticResult, Object extraMsg) {
            Log.i(TAG, "onTrSemanticMsgProc - uMsg : " + trMsgCode + ", wParam : " + errCode + ", lParam : " + semanticResult + ", extraMsg : " + extraMsg);
            printLog("语音 -> 语义 结束，结果为 ：");
            printLog(semanticResult);
            spreakTts(semanticResult);
//            stopRecord();
        }

        @Override
        public void onTrVoiceErrMsgProc(long trMsgCode, long errCode, String trErrorMsg, Object extraData) {
            Log.i(TAG, "onTrVoiceErrMsgProc - uMsg : " + trMsgCode + ", errCode : " + errCode + ", lParam : " + trErrorMsg);
            printLog("语音 -> 文本 出现错误，errCode ：" + errCode + ", msg : " + trErrorMsg);
//            stopRecord();
        }

        @Override
        public void onTrSemanticErrMsgProc(long trMsgCode, long errCode, int cmd, String trErrorMsg, Object extraMsg) {
            Log.i(TAG, "onTrSemanticErrMsgProc - uMsg : " + trMsgCode + ", errCode : " + errCode + ", cmd : " + cmd
                    + ", lParam : " + trErrorMsg + ", extraMsg : " + extraMsg);
            printLog("语音 -> 语义 出现错误，errCode ：" + errCode + ", cmd : " + cmd +", msg : " + trErrorMsg);
//            stopRecord();
        }
    };

    private ITtsInitListener mTTSInitListener = new ITtsInitListener() {
        @Override
        public void onTtsInited(boolean state, int errId) {
            String msg = "";
            if (state) {
                msg = "初始化成功";

                mTTSSession.sessionStart(AudioManager.STREAM_NOTIFICATION);
            } else {
                msg = "初始化失败，errId ：" + errId;
            }

            Log.d(TAG, msg);
            printLog(msg);
        }
    };

    private ITtsListener mTTSListener = new ITtsListener() {
        @Override
        public void onPlayCompleted() {
            String msg = "播放结束：onPlayCompleted";
            Log.i(TAG, msg);
            printLog(msg);
        }

        @Override
        public void onPlayBegin() {
            String msg = "播放开始：onPlayBegin";
            Log.i(TAG, msg);
            printLog(msg);
        }

        @Override
        public void onPlayInterrupted() {
            String msg = "播放被中断：onPlayInterrupted";
            Log.i(TAG, msg);
            printLog(msg);
        }

        @Override
        public void onProgressReturn(int textindex, int textlen) {
//            String msg;
//            if (TextUtils.isEmpty(curText)) {
//                msg = "播放进度 - textindex ：" +  textindex + ", textlen : " + textlen;
//            } else {
//                msg = "播放进度 - textindex ：" +  textindex + ", textlen : " + textlen + "\n" + curText.substring(textindex,
//                        textindex + textlen);
//            }
//            Log.i(TAG, msg);
//            printLog(msg);
        }

        @Override
        public void onProgressRuturnData(byte[] data, boolean end) {
            String msg = "音频流返回 - data size : " + data.length + ", isEnd : " + end;
            Log.i(TAG, msg);
            printLog(msg);
        }

        @Override
        public void onError(int i, String s) {

        }
    };
}
