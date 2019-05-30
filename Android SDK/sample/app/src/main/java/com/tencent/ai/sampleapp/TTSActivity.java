package com.tencent.ai.sampleapp;

import android.media.AudioManager;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import com.tencent.ai.sdk.tts.ITtsInitListener;
import com.tencent.ai.sdk.tts.ITtsListener;
import com.tencent.ai.sdk.tts.TtsSession;
import com.tencent.ai.sdk.utils.ISSErrors;

/**
 * 文字转语音
 */
public class TTSActivity extends BaseSampleActivity implements View.OnClickListener{

    private static final String TAG = "Text2SemanticActivity";

    /** TTS 按钮 */
    private EditText mTTSEdit;
    /** SDK TtsSession */
    private TtsSession mTTSSession;
    private String curText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_tts);

        // 初始化View
        super.initView();
        mTTSEdit = (EditText)findViewById(R.id.tts_edit);
        findViewById(R.id.tts_btn).setOnClickListener(this);

        // 初始化Session
        mTTSSession = new TtsSession(this, mTTSInitListener, "");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        // 销毁Session
        if(null != mTTSSession)
        {
            mTTSSession.stopSpeak();
            mTTSSession.release();
            mTTSSession = null;
        }
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.tts_btn) {
            String text = mTTSEdit.getText().toString();
            // 非空判断
            if (TextUtils.isEmpty(text)) {
                String error = "输入文字为空！";
                Log.e(TAG, error);
                printLog(error);
            }

            // 请求语义
            if(null != mTTSSession) {
                mTTSSession.stopSpeak();
                // 设置是否需要播放
                mTTSSession.setParam(TtsSession.TYPE_TTS_PLAYING, TtsSession.TTS_PLAYING);
                int ret = mTTSSession.startSpeak(text, mTTSListener);
                if (ret == ISSErrors.TTS_PLAYER_SUCCESS) {
                    curText = text;
                }

                printLog("\n请求开始：\n" + text);
            }
        }
    }

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
            String msg;
            if (TextUtils.isEmpty(curText)) {
                msg = "播放进度 - textindex ：" +  textindex + ", textlen : " + textlen;
            } else {
                msg = "播放进度 - textindex ：" +  textindex + ", textlen : " + textlen + "\n" + curText.substring(textindex,
                        textindex + textlen);
            }
            Log.i(TAG, msg);
            printLog(msg);
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
