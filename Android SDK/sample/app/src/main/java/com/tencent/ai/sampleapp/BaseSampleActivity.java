package com.tencent.ai.sampleapp;

import android.app.Activity;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.widget.ScrollView;
import android.widget.TextView;

/**
 * SampleActivity基类
 *
 * Created by cassliu on 2017/10/7.
 */
public class BaseSampleActivity extends Activity implements Handler.Callback{

    private static final String TAG = "BaseSampleActivity";

    /** 界面打印信息区域 */
    private TextView mLogTv;
    private ScrollView mLogScrollView;
    private Handler mHandler;
    private static final int MSG_PRINT_LOG = 9527;

    @Override
    protected void onDestroy() {
        super.onDestroy();

        mHandler.removeMessages(MSG_PRINT_LOG);
        mHandler = null;
        mLogTv = null;
        mLogScrollView = null;
    }

    protected void initView() {
        mLogTv = (TextView) findViewById(R.id.log_tv);
        mLogScrollView = (ScrollView)findViewById(R.id.log_scroller);

        mHandler = new Handler(Looper.getMainLooper(), this);
    }

    protected void printLog(String log) {
        if (null == mLogTv) {
            Log.e(TAG, "initView should be invoked first!");
            return;
        }

        if (TextUtils.isEmpty(log)) {
            Log.e(TAG, "log is empty!");
            return;
        }

        if (null != mHandler) {
            Message message = mHandler.obtainMessage(MSG_PRINT_LOG);
            message.obj = log;
            mHandler.sendMessage(message);
        }
    }

    @Override
    public boolean handleMessage(Message msg) {
        switch (msg.what) {
            case MSG_PRINT_LOG:
                /** 需要打印的信息 */
                String printLog = (String)msg.obj;
                if (null != mLogTv) {
                    mLogTv.append(printLog + "\n");
                    mLogScrollView.fullScroll(ScrollView.FOCUS_DOWN);
                }
                break;
        }

        return true;
    }
}
