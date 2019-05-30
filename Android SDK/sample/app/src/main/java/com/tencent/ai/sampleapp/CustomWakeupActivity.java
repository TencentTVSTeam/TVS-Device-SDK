package com.tencent.ai.sampleapp;

import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.RadioButton;

import com.tencent.ai.sampleapp.record.PcmRecorder;
import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sdk.tvw.ITvwListener;
import com.tencent.ai.sdk.tvw.TvwSession;
import com.tencent.ai.sdk.utils.ISSErrors;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class CustomWakeupActivity extends BaseSampleActivity implements PcmRecorder.RecordListener, View.OnClickListener {

    private static final String TAG = "CustomWakeupActivity";

    /**
     * 唤醒触发按钮
     */
    private ImageButton mWakeupBtn;
    private RadioButton mGlobalScene;
    private RadioButton mConfirmScene;
    private RadioButton mSelectScene;
    private RadioButton mAnswerCallScene;
    private EditText mCustomKeyword;
    private Button mSetCustomWakeup;
    private Button mRestoreWakeup;

    /**
     * SDK语音&语义识别的Session
     */
    private TvwSession mTvwSession;


    /**
     * 录音线程
     */
    private PcmRecorder mPcmRecorder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_custom_wakeup);

        // 初始化View
        initView();

        String voiceOfflineModePath = FileUtil.getModelFilePath(this) + "/mdl_vtt";
        String vadModePath = FileUtil.getModelFilePath(this) + "/vad";
        mTvwSession = TvwSession.getInstance(this, mvwListener, voiceOfflineModePath, vadModePath);
        mTvwSession.initService();
    }

    @Override
    protected void initView() {
        super.initView();
        mWakeupBtn = findViewById(R.id.wakeup_btn);
        mWakeupBtn.setOnClickListener(this);
        mGlobalScene = findViewById(R.id.scene_global);
        mConfirmScene = findViewById(R.id.scene_confirm);
        mSelectScene = findViewById(R.id.scene_select);
        mAnswerCallScene = findViewById(R.id.scene_answer_call);
        mGlobalScene.setChecked(true);
        mCustomKeyword = findViewById(R.id.custom_keyword_edit);
        mSetCustomWakeup = findViewById(R.id.set_custom_wakeup);
        mRestoreWakeup = findViewById(R.id.restore_custom_wakeup);
        mSetCustomWakeup.setOnClickListener(this);
        mRestoreWakeup.setOnClickListener(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        if (mPcmRecorder != null) {
            mPcmRecorder.stopThread();
        }

        if (null != mTvwSession) {
            mTvwSession.release();
            mTvwSession = null;
        }
    }

    @Override
    public void onRecord(byte[] buffer, int bufferSize) {
//        printLog("录音中..." + bufferSize);
        // 收到录音数据
        if (null != mTvwSession) {
            mTvwSession.appendAudioData(buffer, bufferSize);
        }
    }

    /**
     * 开启语音识别
     */
    private void startWakeup() {
        // 停止上次录音
        mTvwSession.stop();
        stopRecord();

        String message = null;
        //启动唤醒识别，目前传入参数仅预留，不做场景区分。只要设置进去的唤醒词，都可被唤醒成功
        int id = mTvwSession.start(getSelectScene());
        if (id != ISSErrors.ISS_SUCCESS) {
            message = "Tvw SessionStart error,id = " + id;
            Log.e(TAG, message);
            printLog(message);
        } else {
            // 开始录音
            mPcmRecorder = new PcmRecorder(this);
            mPcmRecorder.start();

            printLog("\n开始唤醒流程：");
            printLog("开始录音");
        }
    }

    /**
     * 停止录音
     */
    private void stopRecord() {
        if (null != mPcmRecorder) {
            if (mPcmRecorder.stopThread()) {
                printLog("停止录音");
            }
        }
    }

    private ITvwListener mvwListener = new ITvwListener() {

        @Override
        public void onTvwInited(boolean state, int errId) {
            if (!state) {
                if (errId == ISSErrors.REMOTE_EXCEPTION) {
                    mTvwSession.initService();
                }
            }
        }

        @Override
        public void onTvwWakeup(int nMvwScene, int nMvwId, int nMvwScore, String lParam) {
            //SDK中会响应所有设置进去的唤醒词，用户需要自行根据返回值中的nMvwScene值来区分是设置到哪个场景的唤醒词
            StringBuffer logMsg = new StringBuffer("\n唤醒成功，场景：");
            logMsg.append(getSelectSceneMSG(nMvwScene));
            logMsg.append("\n唤醒词id：");
            logMsg.append(nMvwId);
            logMsg.append("\n唤醒词详情：" + lParam);
            printLog(logMsg.toString());
        }

        @Override
        public void onSetKeywordCallback(long stateCode, String stateMsg) {
            if (stateCode == TvwSession.ISS_TVW_MSG_SetKeywordsSuccess) {
                String msg = "设置成功，" + stateMsg;
                printLog(msg);
                printLog(getAllCustomKeywords());
                Log.d(TAG, msg);
            } else if (stateCode == TvwSession.ISS_TVW_MSG_SetKeywordsFailed) {
                String errorMsg = "设置失败，" + stateMsg;
                printLog(errorMsg);
                Log.d(TAG, errorMsg);
            }
        }
    };

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.wakeup_btn:
                startWakeup();
                break;
            case R.id.set_custom_wakeup:
                String keyword = mCustomKeyword.getText().toString();
                if (TextUtils.isEmpty(keyword)) {
                    printLog("请填自定义唤醒词");
                } else {
                    setCustomWakeupWord(getSelectScene(), keyword);
                }
                startWakeup();
                break;
            case R.id.restore_custom_wakeup:
                restoreWakeupWord(getSelectScene());
                printLog(getAllCustomKeywords());
                startWakeup();
                break;
        }
    }

    private void setCustomWakeupWord(int scene, String wakeupWord) {
        JSONObject objRoot = new JSONObject();
        JSONArray objArr = new JSONArray();
        String[] strWords = wakeupWord.split(",");

        StringBuffer logMsg = new StringBuffer();

        for (int nIndex = 0; nIndex != strWords.length; nIndex++) {
            JSONObject objWord = new JSONObject();
            try {
                objWord.put("KeyWordId", nIndex);          //唤醒词id
                objWord.put("KeyWord", strWords[nIndex]);  //唤醒词
                objWord.put("DefaultThreshold40", 0);//灵敏度
                objArr.put(objWord);
                logMsg.append("\n唤醒词:" + nIndex + ":" + strWords[nIndex] + ",");
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        try {
            objRoot.put("Keywords", objArr);
            Log.d(TAG, "setCustomWakeupWord: " + logMsg.toString());

            //设置自定义唤醒词，此方式是覆盖的，会将之前设置的相同的唤醒词覆盖
            int ret = mTvwSession.setTvwCoverKeyWords(scene, objRoot.toString());

            //设置自定义唤醒词，此方式仅在后续追加的形式，会出现存在同样唤醒词的情况，尽量减少使用
            //int ret = mTvwSession.setTvwKeyWords(scene, objRoot.toString());


            if (ret == ISSErrors.ISS_SUCCESS) {
                logMsg.append("已应用到 " + getSelectSceneMSG(getSelectScene()));
                printLog(logMsg.toString());
            } else {
                printLog("设置失败");
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    private void restoreWakeupWord(int scene) {
        int ret = -1;
        if (mTvwSession != null) {
            ret = mTvwSession.setTvwDefaultKeyWords(scene);
        }
        if (ret == ISSErrors.ISS_SUCCESS) {
            printLog("已重置" + getSelectSceneMSG(scene) + "下的自定义唤醒词");
        } else {
            printLog("重置" + getSelectSceneMSG(scene) + "的自定义唤醒词失败");
        }
    }

    private int getSelectScene() {
        if (mAnswerCallScene == null || mConfirmScene == null
                || mGlobalScene == null || mSelectScene == null) {
            return TvwSession.ISS_TVW_SCENE_GLOBAL;
        }
        int scene = TvwSession.ISS_TVW_SCENE_GLOBAL;
        if (mGlobalScene.isChecked()) {
            scene = TvwSession.ISS_TVW_SCENE_GLOBAL;
        } else if (mConfirmScene.isChecked()) {
            scene =  TvwSession.ISS_TVW_SCENE_CONFIRM;
        } else if (mSelectScene.isChecked()) {
            scene =  TvwSession.ISS_TVW_SCENE_SELECT;
        } else if (mAnswerCallScene.isChecked()) {
            scene =  TvwSession.ISS_TVW_SCENE_ANSWER_CALL;
        }
        return scene;
    }

    /**
     * 获取对应场景描述
     * @param scene 场景
     * @return
     */
    private String getSelectSceneMSG(int scene) {
        String msg = "通用场景";
        switch (scene){
            case TvwSession.ISS_TVW_SCENE_GLOBAL:
                msg = "通用场景";
                break;
            case TvwSession.ISS_TVW_SCENE_CONFIRM:
                msg = "确定/取消场景";
                break;
            case TvwSession.ISS_TVW_SCENE_SELECT:
                msg = "选择场景";
                break;
            case TvwSession.ISS_TVW_SCENE_ANSWER_CALL:
                msg = "电话场景";
                break;
        }
        return msg;
    }

    /**
     * 获取对应场景已保存的自定义唤醒词
     * @param scene 场景
     * @return
     */
    private String getSelectSceneKeywords(int scene) {
        String keywords = "\n"+getSelectSceneMSG(scene) + ":";
        if (mTvwSession != null) {
            keywords += mTvwSession.getSceneContent(scene);
            return keywords;
        }
        return keywords + "空";
    }

    private String getAllCustomKeywords() {
        StringBuffer allKeywords = new StringBuffer("所有已设置的唤醒词:");
        allKeywords.append(getSelectSceneKeywords(TvwSession.ISS_TVW_SCENE_GLOBAL));
        allKeywords.append(getSelectSceneKeywords(TvwSession.ISS_TVW_SCENE_CONFIRM));
        allKeywords.append(getSelectSceneKeywords(TvwSession.ISS_TVW_SCENE_SELECT));
        allKeywords.append(getSelectSceneKeywords(TvwSession.ISS_TVW_SCENE_ANSWER_CALL));
        return allKeywords.toString();
    }
}
