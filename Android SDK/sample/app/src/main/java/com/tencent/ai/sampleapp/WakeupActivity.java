package com.tencent.ai.sampleapp;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.tencent.ai.sampleapp.record.PcmRecorder;
import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sdk.atw.AtwSession;
import com.tencent.ai.sdk.atw.IAtwListener;
import com.tencent.ai.sdk.utils.ISSErrors;
import com.tencent.ai.sdk.atw.WakeupRsp;

import java.io.File;

/**
 * 离线唤醒
 */
public class WakeupActivity extends BaseSampleActivity implements View.OnClickListener, PcmRecorder.RecordListener {

    private static final String TAG = "WakeupActivity";

    /** 录音线程 */
    private PcmRecorder mPcmRecorder;

    /** SDK唤醒模块Session */
    private AtwSession mAtwSession = null;
    /** 是否延迟开启唤醒流程，一般在初始化时候设置 */
    private boolean mPendingStartWakeup = false;

    /** 唤醒本地模型文件，保证跟识别模型 */
    private static final String RES_PATH = Environment.getExternalStorageDirectory().getAbsolutePath()
            + "/tencent/dingdang/res/tsr";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_wakeup);

        // 初始化View
        super.initView();
        findViewById(R.id.wakeup_btn).setOnClickListener(this);
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

                mAtwSession = new AtwSession(this, RES_PATH, mvwListener);

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

    @Override
    public void onRecord(byte[] buffer, int bufferSize) {
        printLog("录音中..." + bufferSize);
        if (null != mAtwSession) {
            mAtwSession.appendAudioData(buffer, bufferSize);
        }
    }

    private IAtwListener mvwListener = new IAtwListener() {
		
        @Override
        public void onAtwWakeup(WakeupRsp rsp) {
            Log.d(TAG, "wake up : " + rsp.iEndTimeMs);

            printLog("唤醒成功，你好语音助理, wakeup_time:" + rsp.iEndTimeMs);

            stopRecord();
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
}
