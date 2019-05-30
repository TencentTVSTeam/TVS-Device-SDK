package com.tencent.ai.sampleapp;

import android.os.Bundle;
import android.os.Environment;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sampleapp.util.JSONTool;
import com.tencent.ai.sdk.tr.ITrListener;
import com.tencent.ai.sdk.tr.TrParameters;
import com.tencent.ai.sdk.tr.TrSession;

/**
 * 文字转语义
 */
public class Text2SemanticActivity extends BaseSampleActivity implements View.OnClickListener{

    private static final String TAG = "Text2SemanticActivity";

    /** 文字转语义 按钮 */
    private EditText mText2SemanticEdit;
    /** SDK TrSession实例 */
    private TrSession mTrSession;

    private String res = Environment.getExternalStorageDirectory().getAbsolutePath()
            + "/tencent/dingdang/res/tsr/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_text_2_semantic);

        // 初始化View
        super.initView();
        mText2SemanticEdit = (EditText)findViewById(R.id.text_2_semantic_edit);
        Button text2SemanticBtn = (Button)findViewById(R.id.text_2_semantic_btn);
        text2SemanticBtn.setOnClickListener(this);

        // 初始化Session
        TrParameters params = new TrParameters();
        res = FileUtil.getModelFilePath(this);
        params.setOfflineSemanticResDir(res, false);
        params.setOfflineVoiceResDir(res, false);
        params.setOnlineVoiceResDir(res, false);
        params.setWakeupResDir(res,false);
        params.setMixModeConfigDir(res);
        mTrSession = TrSession.getInstance(this, params);
        mTrSession.init(mTrListener);

//        mTrSession = new TrSession(this, mTrListener, "", "");
//        mTrSession = TrSession.getInstance(this, mTrListener, 0, "","");
//        mTrSession = TrSession.getInstance(this,mTrListener, 0, res, "", "");

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        // 销毁Session
        if(null != mTrSession)
        {
            mTrSession.release();
            mTrSession = null;
        }
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.text_2_semantic_btn) {
            String text = mText2SemanticEdit.getText().toString();
            // 非空判断
            if (TextUtils.isEmpty(text)) {
                String error = "输入文字为空！";
                Log.e(TAG, error);
                printLog(error);
            }

            // 请求语义
            if(null != mTrSession) {
                mTrSession.stop();
                mTrSession.appendTextString(text, true, "test_text_2_semantic");

                printLog("\n请求开始：\n" + text);
            }
        }
    }

    private ITrListener mTrListener = new ITrListener() {
        @Override
        public void onTrInited(boolean state, int errId) {
            String msg = "onTrInited - state : " + state + ", errId : " + errId;
            Log.i(TAG, "onTrInited - state : " + state + ", errId : " + errId);
            if (state) {
                printLog("TrSession init成功");
            } else {
                printLog("TrSession init失败, errId : " + errId);
            }
        }

        @Override
        public void onTrVoiceMsgProc(long trMsgCode, long cmd, String voiceResult, Object o) {
            Log.i(TAG, "onTrVoiceMsgProc - trMsgCode : " + trMsgCode + ", cmd : " + cmd + ", voiceResult : " + voiceResult);
        }

        @Override
        public void onTrSemanticMsgProc(long trMsgCode, long errCode, int cmd, String semanticResult, Object extraMsg) {
            Log.i(TAG, "onTrSemanticMsgProc - trMsgCode : " + trMsgCode + ", errCode : " + errCode + ", semanticResult : " + semanticResult + ", extraMsg : " + extraMsg);
            printLog("文本 -> 语义 结束，结果为 ：");
            String result = JSONTool.stringToJSON(semanticResult);
            printLog(result);

        }

        @Override
        public void onTrVoiceErrMsgProc(long trMsgCode, long errCode, String trErrorMsg, Object o) {
            Log.e(TAG, "onTrVoiceErrMsgProc - uMsg : " + trMsgCode + ", errCode : " + errCode + ", lParam : " + trErrorMsg);
        }

        @Override
        public void onTrSemanticErrMsgProc(long trMsgCode, long errCode, int cmd, String trErrorMsg, Object extraMsg) {
            Log.i(TAG, "onTrSemanticErrMsgProc - trMsgCode : " + trMsgCode + ", errCode : " + errCode + ", cmd : " + cmd
                    + ", trErrorMsg : " + trErrorMsg + ", extraMsg : " + extraMsg);
            printLog("文本 -> 语义 出现错误，errCode ：" + errCode + ", cmd : " + cmd +", msg : " + trErrorMsg);
        }
    };
}
