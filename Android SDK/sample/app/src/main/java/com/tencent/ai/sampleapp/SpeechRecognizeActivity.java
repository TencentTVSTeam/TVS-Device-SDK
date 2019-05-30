package com.tencent.ai.sampleapp;

import android.annotation.TargetApi;
import android.app.Dialog;
import android.content.Context;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.util.Log;
import android.view.Gravity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;

import com.tencent.ai.sampleapp.record.LocalPcmReader;
import com.tencent.ai.sampleapp.record.PcmRecorder;
import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sampleapp.util.JSONTool;
import com.tencent.ai.sdk.control.SpeechManager;
import com.tencent.ai.sdk.tr.ITrListener;
import com.tencent.ai.sdk.tr.TrParameters;
import com.tencent.ai.sdk.tr.TrSession;
import com.tencent.ai.sdk.tr.VoiceConst;
import com.tencent.ai.sdk.utils.ISSErrors;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * 语音语义识别
 * <br/>
 * 通过语音直接请求语义，包括自动检测说话停止、按住发言两种方式
 */
public class SpeechRecognizeActivity extends BaseSampleActivity implements PcmRecorder.RecordListener, View.OnClickListener{

    private static final String TAG = "SpeechRecognizeActivity";
    private static final String TEST_TAG = "TENCENT_TEST";

    /** 语音识别触发按钮 */
    private ImageButton mSpeechRecognizeBtn;
    /** 用于切换按钮的事件，手动和自动录音模式 */
    private AutoModeClickListener mAutoModeClickListener;
    private ManualModeTouchListener mManualModeTouchListener;
    private Button mSpeechUploadBtn;

    /** SDK语音&语义识别的Session */
    private TrSession mTrSession;

    /** 录音线程 */
    private PcmRecorder mPcmRecorder;
    private Button mVoiceContextBtn;
    private EditText mVoiceType;
    private EditText mVoiceContext;

    private String res = "";
    private boolean mTestMode = false;
    private List<String> mResultRecord;
    private Handler mHandler = new Handler();
    private int mHasResult = 0;
    private static SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd-HH:mm:ss.SSS");

    private Runnable mResultTimeoutChecker = new Runnable() {
        @Override
        public void run() {
            printLog("Result timeout!!");
            stopRecord();
            if (mTestMode) {
                mResultRecord.add("ERROR: NO RESPONSE"+", time:"+sdf.format(new Date()));
                Log.d(TEST_TAG, "Will start to test");
                mHandler.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        startRecognize();
                    }
                }, 300);
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_speech_recognize);

        // 初始化View
        initView();
        mSpeechRecognizeBtn = (ImageButton)findViewById(R.id.speech_recognize_btn);
        mSpeechUploadBtn = findViewById(R.id.speech_upload_dict);
        mVoiceContextBtn = findViewById(R.id.set_voice_context);
        mVoiceType = findViewById(R.id.edit_type);
        mVoiceContext = findViewById(R.id.voice_context);
        mVoiceContextBtn.setOnClickListener(this);
        mSpeechUploadBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                File contactFile = new File(res+ "/contact.json");
                if (contactFile.exists()) {
                    String contactString = FileUtil.getStringWithFile(res+ "/contact.json");
                    int ret = mTrSession.uploadDict(contactString, TrSession.ISS_TR_MSG_UpLoadDictToLocalStatus);
                    if (ret == 0) {
                        printLog("上传联系人成功");
                    }
                    printLog("请在检查文件是否存在:" + res+ "/contact.json");
                }
            }
        });

        // 选择录音模式：默认为自动检测说话结束
        mAutoModeClickListener = new AutoModeClickListener();
        mManualModeTouchListener = new ManualModeTouchListener();
        onManualModeSet(false);
//        onFullModeSet(false);

        // 初始化Session
//        mTrSession = TrSession.getInstance(this, mTrListener, 0, "", "");
//        mTrSession.init(mTrListener);
        res = FileUtil.getModelFilePath(this);
        TrParameters params = new TrParameters();
        params.setOnlineVoiceResDir(res, false);
        params.setOfflineVoiceResDir(res, false);
        params.setWakeupResDir(res,false);
        params.setMixModeConfigDir(res);
        mTrSession = TrSession.getInstance(this, params);
        mTrSession.init(mTrListener);

        // 选择识别类型, 默认语音转文字
        if (mTestMode) {
            mSpeechRecognizeBtn.setEnabled(false);
            LocalPcmReader.initLocalFiles();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        if(mPcmRecorder!=null) {
            mPcmRecorder.stopThread();
        }

        if (null != mTrSession) {
            mTrSession.release();
            mTrSession = null;
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.speech_recognize_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        boolean checked = item.isChecked();
        // 自动结束录音模式
        if (id == R.id.auto_mode) {
            if (!checked) {
                item.setChecked(true);
                onManualModeSet(false);
            }
            // 手动结束录音模式
        } else if (id == R.id.manual_mode) {
            if (!checked) {
                item.setChecked(true);
                onManualModeSet(true);
            }
            // 测试模式
        }else if (id == R.id.test_mode) {
            if (!checked) {
                item.setChecked(true);
                onTestModeSet(true);
            }
        } else if (id == R.id.normal_mode) {
            if (!checked) {
                item.setChecked(true);
                onTestModeSet(false);
            }
            // 识别类型：语音转文字
        } else if (id == R.id.speech_2_txt) {
            if (!checked) {
                item.setChecked(true);
                onRecognizeTypeSet(TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_VOICE);
            }
            // 识别类型：语音转语义
        } else if (id == R.id.speech_2_semantic) {
            if (!checked) {
                item.setChecked(true);
                onRecognizeTypeSet(TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_ALL);
            }
        } else if (id == R.id.speech_2_timeout) {
            new ResetDialog(this).showView();
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.set_voice_context:
                if (mTrSession != null) {
                    if (mVoiceType != null && mVoiceContext != null) {
                        int voiceType = 0;
                        if (!TextUtils.isEmpty(mVoiceType.getText().toString())) {
                            voiceType = Integer.valueOf(mVoiceType.getText().toString());
                        }
                        String voiceContext = "";
                        if (!TextUtils.isEmpty(mVoiceContext.getText().toString())) {
                            voiceContext = mVoiceContext.getText().toString();
                    }
                        int ret = mTrSession.setOnlineVoiceContext(voiceType, voiceContext);
                        if (ret == 0) {
                            printLog("设置上下文内容成功,type:" + voiceType + ",context=" + voiceContext);
                        }
                    }
                }
                break;
        }
    }

    class ResetDialog extends Dialog {
        private EditText mEditText;
        private Button mButton;
        public ResetDialog(Context context) {
            super(context, R.style.WeLauncherDialogStyle);
            setContentView(R.layout.reset_dialog_layout);
            Window window = getWindow();
            if (window != null) {
                WindowManager.LayoutParams params = window.getAttributes();
                params.gravity = Gravity.CENTER;
                window.setAttributes(params);
            }
            setCanceledOnTouchOutside(false);
            mEditText = (EditText) findViewById(R.id.editView);
            mButton = (Button) findViewById(R.id.button);
            mButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    try {
                        int timeout = Integer.parseInt(mEditText.getText().toString().toString());
                        SpeechRecognizeActivity.this.mTrSession.setSlientTimeout(timeout);
                    } catch (Exception e) {

                    }
                    dissmissView();
                }
            });
        }

        public void showView() {
            try {
                show();
            } catch (Exception e) {
                // do nothing
            }
        }

        private void dissmissView() {
            try {
                dismiss();
            } catch (Exception e) {
                // do nothing
            }
        }
    }

    @Override
    public void onRecord(byte[] buffer, int bufferSize) {
//        printLog("录音中..." + bufferSize);
        // 收到录音数据
        if (null != mTrSession) {
            mTrSession.appendAudioData(buffer, bufferSize);
        }
    }

    /**
     * 选择测试模式
     *
     * @param test true为测试模式，批量导入音频
     */
    private void onTestModeSet(boolean test) {
        // 按键发言
        if (test) {
            printLog("\n当前为测试模式");
            mTestMode = true;
            // 选择识别类型, 默认语音转文字
            mSpeechRecognizeBtn.setEnabled(false);
            LocalPcmReader.initLocalFiles();
            if (mResultRecord == null)
            mResultRecord = new ArrayList<>();
            mResultRecord.clear();
            mHandler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    Log.d(TAG, "Begin Test");
                    startRecognize();
                }
            }, 1000);
        } else {
            printLog("\n当前为普通模式");
            mHandler.removeCallbacks(mResultTimeoutChecker);
            stopRecord();
            mTrSession.stop();
            mResultRecord.add("end test"+ ", time:"+sdf.format(new Date()));
            mHandler.post(new Runnable() {
                @Override
                public void run() {
                    writeTestResult();
                }
            });
            mTestMode = false;
            mSpeechRecognizeBtn.setEnabled(true);
        }
    }

    /**
     * 选择录音模式
     *
     * @param manual true为手动压住发言，false为自动检测说话结束
     */
    private void onManualModeSet(boolean manual) {
        // 按键发言
        if (manual) {
            SpeechManager.getInstance().setManualMode(true);
            printLog("\n当前录音模式：按键发言，下次开启语音识别生效");
            mSpeechRecognizeBtn.setOnTouchListener(mManualModeTouchListener);
            mSpeechRecognizeBtn.setOnClickListener(null);
        } else {
            // 自动结束录音
            SpeechManager.getInstance().setManualMode(false);
            printLog("\n当前录音模式：自动检测说话结束，下次开启语音识别生效");
            mSpeechRecognizeBtn.setOnClickListener(mAutoModeClickListener);
            mSpeechRecognizeBtn.setOnTouchListener(null);
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

    /**
     * 开启语音识别
     */
    @TargetApi(19)
    private void startRecognize() {
        // 停止上次录音
        if (mTestMode) {
            if (LocalPcmReader.hasTestFile()) {
                Log.d(TEST_TAG, "Start one test");
            } else {
                writeTestResult();
                return;
            }
        }
        mTrSession.stop();
        stopRecord();

        String message = null;
        int id = mTrSession.start(TrSession.ISS_TR_MODE_CLOUD_REC, false);
        if (id != ISSErrors.ISS_SUCCESS) {
            message = "Tr SessionStart error,id = " + id;
            Log.e(TAG, message);
            printLog(message);
        } else {
            // 开始录音
            if (mTestMode) {
                mPcmRecorder = new LocalPcmReader(this);
            } else {
                mPcmRecorder = new PcmRecorder(this);
            }
            mPcmRecorder.start();

            printLog("\n开始语音识别流程：");
            printLog("开始录音");
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

    @TargetApi(Build.VERSION_CODES.KITKAT)
    private void writeTestResult(){
        Log.e(TEST_TAG, "writeTestResult mTestMode = "+mTestMode);
        //write results
        try {
            File writeName = new File("/sdcard/dingdang_test_result.txt");
            writeName.createNewFile(); // 创建新文件,有同名的文件的话直接覆盖
            try (FileWriter writer = new FileWriter(writeName);
                 BufferedWriter out = new BufferedWriter(writer)
            ) {
                Log.d(TEST_TAG, "HAVE " + mResultRecord.size() + " results");
                for (String s : mResultRecord) {
                    out.write(s);
                    out.write("\r\n");
                    out.flush();
                }
            }
        } catch (IOException e) {
            Log.e(TEST_TAG, "Cannot write result");
        }
        Log.d(TEST_TAG, "test over has result = " + mHasResult);
    }

    class AutoModeClickListener implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            if (v.getId() == R.id.speech_recognize_btn) {
                startRecognize();
            }
        }
    }

    class ManualModeTouchListener implements View.OnTouchListener {

        @Override
        public boolean onTouch(View v, MotionEvent event) {
            if (event.getAction() == MotionEvent.ACTION_DOWN) {
                startRecognize();
            } else if (event.getAction() == MotionEvent.ACTION_UP) {
                if (null != mTrSession) {
                    mTrSession.endAudioData();
                }
            }

            return false;
        }
    }

    private ITrListener mTrListener = new ITrListener() {
        @Override
        public void onTrInited(boolean state, int errId) {
            String msg = "onTrInited - state : " + state + ", errId : " + errId;
            Log.i(TAG, "onTrInited - state : " + state + ", errId : " + errId);
            if (state) {
                printLog("TrSession init成功");
                // 选择识别类型, 默认语音转文字
                onRecognizeTypeSet(TrSession.ISS_TR_PARAM_VOICE_TYPE_RSP_VOICE);
                if (mTestMode) {
                    mResultRecord = new ArrayList<>();
                    mHandler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            Log.d(TAG, "Begin Test");
                            startRecognize();
                        }
                    }, 1000);
                }
            } else {
                printLog("TrSession init失败, errId : " + errId);
            }
        }

        /**
         * @brief 语音识别回调。
         *
         * 根据trMsgCode区分不同类型回调。
         **
         * @param trMsgCode 消息状态码，对应TrSession中ISS_TR_MSG_*消息
         * |      trMsgCode                                 |说明                |cmd         |voiceResult           |
         * |-------------------------------------------|--------------------|---------------|----------------|
         * |{@link TrSession#ISS_TR_MSG_VolumeLevel}  |返回声音能量,0-25，可以用来展示声音效果|无       |          声音能量    |
         * |{@link TrSession#ISS_TR_MSG_ProcessResult}|返回流式识别中间结果|     无        | 结果字符串     |
         * |{@link TrSession#ISS_TR_MSG_VoiceResult}  |返回语音识别最终结果|         无    |  结果字符串    |
         * |{@link TrSession#ISS_TR_MSG_SpeechStart}  |返回状态：检测到语音开始点|   无    |     无         |
         * |{@link TrSession#ISS_TR_MSG_SpeechEnd}    |返回状态：检测到语音结束点|     无  |            无  |
         * @param errCode 回调状态码，正常返回为{@link com.tencent.ai.sdk.utils.ISSErrors#ISS_SUCCESS}，只需在回调错误的时候关注
         * @param voiceResult 语音识别的结果
         * @param extraData 终端调用start传入的自定义信息
         */
        @Override
        public void onTrVoiceMsgProc(long trMsgCode, long errCode, String voiceResult, Object extraData) {
            String msg = null;
            Log.i(TAG, "onTrVoiceMsgProc - trMsgCode : " + trMsgCode + ", errCode : " + errCode + ", voiceResult : " + voiceResult);
            if (trMsgCode == TrSession.ISS_TR_MSG_VoiceStart) {
                msg = "开始启动识别";
            } else if (trMsgCode == TrSession.ISS_TR_MSG_SpeechStart) {
                msg = "检测到说话开始";
            } else if (trMsgCode == TrSession.ISS_TR_MSG_SpeechEnd) {
                msg = "检测到说话结束";
                mHandler.removeCallbacks(mResultTimeoutChecker);
                //delay 15s to checkout timeout
                mHandler.postDelayed(mResultTimeoutChecker, 15000);
            } else if (trMsgCode == TrSession.ISS_TR_MSG_ProcessResult){
                msg = "语音识别中：" + voiceResult;
            } else if (trMsgCode == TrSession.ISS_TR_MSG_VoiceResult) {
                msg = "语音 -> 文本 结束，结果为：" + voiceResult;
                if (mTestMode) {
                    mResultRecord.add(voiceResult+", time:"+sdf.format(new Date()));
                    Log.d(TEST_TAG, "get result " + voiceResult);
                }
                stopRecord();
                if (mTestMode) {
                    mHasResult += 1;
                    mHandler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            startRecognize();
                        }
                    }, 300);
                }
                mHandler.removeCallbacks(mResultTimeoutChecker);
            } else if (trMsgCode == TrSession.ISS_TR_MSG_ProcessResult) {
                //中间结果
                mHandler.removeCallbacks(mResultTimeoutChecker);
                //delay 15s to checkout timeout
                mHandler.postDelayed(mResultTimeoutChecker, 15000);
            } else if (trMsgCode == TrSession.ISS_TR_MSG_InitStreamCloudSuccess) {
                msg = "获取语音识别Session成功";
            }

            if (!TextUtils.isEmpty(msg)) {
                printLog(msg);
            }
        }

        @Override
        public void onTrSemanticMsgProc(long trMsgCode, long errCode, int cmd, String semanticResult, Object extraMsg) {
            Log.i(TAG, "onTrSemanticMsgProc - trMsgCode : " + trMsgCode + ", errCode : " + errCode + ", semanticResult : " + semanticResult + ", extraMsg : " + extraMsg);
            printLog("语音 -> 语义 结束，结果为 ：");
            String result = JSONTool.stringToJSON(semanticResult);
            printLog(result);

            stopRecord();
        }

        /**
         * @brief 语音识别出现错误
         *
         * @param trMsgCode 消息错误码，对应TrSession#ISS_TR_MSG_*的定义
         * |      trMsgCode                          |说明                        |
         * |-------------------------------------|----------------------------|
         * |{@link TrSession#ISS_TR_MSG_Error}  |语音识别发生错误             |
         * |{@link TrSession#ISS_TR_MSG_SpeechTimeout}|在线识别超时，没有识别到有效输入|
         * |{@link TrSession#ISS_TR_MSG_InitStreamCloudFailure}|获取语音识别Session失败，本次语音识别还未开始就结束了|
         *
         * @param errCode 错误码，用于区分具体错误信息
         * |      errCode                          |说明                       |
         * |-------------------------------------|----------------------------|
         * | {@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_FAIL}         |网络请求发送失败     |
         * | {@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_RESPONSE_FAIL} |网络请求回包失败。  |
         * | {@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_NETWORK_TIMEOUT}       |网络请求超时。      |
         * | {@link com.tencent.ai.sdk.utils.ISSErrors#ISS_ERROR_SERVICE_ERROR}   |服务异常   |
         * @param trErrorMsg 错误信息描述
         * @param extraData 终端调用start传入的自定义信息
         *
         */
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
                }
            } else if (trMsgCode == TrSession.ISS_TR_MSG_InitStreamCloudFailure) {
                errMsg = "获取语音识别Session失败";
            }
            Log.i(TAG, "onTrVoiceErrMsgProc: " + errMsg);
            printLog("语音 -> 文本 出现错误，errCode ：" + errCode + ", errMsg : " + errMsg);

            mHandler.removeCallbacks(mResultTimeoutChecker);
            stopRecord();
            if (mTestMode) {
                mResultRecord.add("ERROR:"+errCode+", time:"+sdf.format(new Date()));
                Log.d(TEST_TAG, "Will start to test");
                mHandler.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        startRecognize();
                    }
                }, 300);
            }
        }

        @Override
        public void onTrSemanticErrMsgProc(long trMsgCode, long errCode, int cmd, String trErrorMsg, Object extraMsg) {
            Log.i(TAG, "onTrSemanticErrMsgProc - trMsgCode : " + trMsgCode + ", errCode : " + errCode + ", cmd : " + cmd
                    + ", trErrorMsg : " + trErrorMsg + ", extraMsg : " + extraMsg);
            printLog("语音 -> 语义 出现错误，errCode ：" + errCode + ", cmd : " + cmd +", msg : " + trErrorMsg);

            stopRecord();
        }
    };
}
