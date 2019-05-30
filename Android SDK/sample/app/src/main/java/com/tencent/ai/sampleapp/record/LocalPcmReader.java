package com.tencent.ai.sampleapp.record;

import android.annotation.TargetApi;
import android.os.Environment;
import android.util.Log;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Created by carmzhu on 2018/7/17.
 */

public class LocalPcmReader extends PcmRecorder {
    private PcmRecorder.RecordListener mRecordListener;
    private AtomicBoolean mValid = new AtomicBoolean(false);
    //private String PCM_PATH = Environment.getExternalStorageDirectory().getAbsolutePath() + "/speech/dingdang_2.pcm";
    private static String mPcmDir = Environment.getExternalStorageDirectory().getAbsolutePath() + "/tencent/test";
    static private List<String> mPcmFileNames = null;
    static private int mCurrentIndex = 0;
    private static final String TAG = "TENCENT_TEST";
    private static final String FILE_LISTS = "file_lists.txt";

    public LocalPcmReader(RecordListener listener) {
        super(null);
        mRecordListener = listener;
    }

    @TargetApi(19)
    public static void initLocalFiles() {
        File pcm_dir = new File(mPcmDir);
        if (!pcm_dir.exists()) {
            pcm_dir.mkdir();
        }

        if (!pcm_dir.isDirectory()) {
            pcm_dir.delete();
            pcm_dir.mkdir();
        }

        File file_lists = new File(mPcmDir + File.separator + FILE_LISTS);
        if (file_lists.exists()) {
            mPcmFileNames = new ArrayList<>();
            String pathname = mPcmDir + File.separator + FILE_LISTS;
            try (FileReader reader = new FileReader(pathname);
                 BufferedReader br = new BufferedReader(reader) // 建立一个对象，它把文件内容转成计算机能读懂的语言
            ) {
                String line;
                //网友推荐更加简洁的写法
                while ((line = br.readLine()) != null) {
                    String fn = mPcmDir+File.separator+line;
                    if (new File(fn).exists()) {
                        mPcmFileNames.add(fn);
                    }
                }
            } catch (IOException e) {
                Log.e(TAG, "cannot read file");
            }
            Log.d(TAG, "There are " + mPcmFileNames.size() + ", files");

        } else {

            File[] files = pcm_dir.listFiles();
            if (files != null) {
                mPcmFileNames = new ArrayList<>();
                for (File f : files) {
                    if (f.getAbsolutePath().endsWith("wav") || f.getAbsolutePath().endsWith("pcm")) {
                        mPcmFileNames.add(f.getAbsolutePath());
                    }
                }
            }
        }
        mCurrentIndex = 0;
        Log.d(TAG, "There are " + mPcmFileNames.size() + " audio files");
    }

    @Override
    public synchronized boolean stopThread() {
        mValid.compareAndSet(true, false);
        return true;
    }

    @Override
    public boolean isRunning() {
        return mValid.get();
    }

    @Override
    public void run() {
        mValid.compareAndSet(false, true);
        byte[] bytes = null;
        int pos = 0;
        int readLength = 4096;
        isPlainAudio = false;
        if (mPcmFileNames != null && mPcmFileNames.size() > 0) {
            try {
                if (mCurrentIndex >= mPcmFileNames.size()) {
                    mCurrentIndex = 0;
                }
                Log.d(TAG, "reading file " + mPcmFileNames.get(mCurrentIndex));
                FileInputStream fileInputStream = new FileInputStream(mPcmFileNames.get(mCurrentIndex));
                int length = fileInputStream.available();
                if (mPcmFileNames.get(mCurrentIndex).endsWith("wav")) {
                    fileInputStream.skip(64);
                    pos += 64;
                }
                while (pos < length && mValid.get()) {
                    if (pos + readLength > length) {
                        bytes = new byte[length - pos];
                    } else {
                        bytes = new byte[readLength];
                    }
                    fileInputStream.read(bytes, 0, bytes.length);
                    if (mRecordListener != null)
                        mRecordListener.onRecord(bytes, bytes.length);

                    pos += readLength;
                    try {
                        Thread.sleep(30);
                    } catch (InterruptedException e) {

                    }
                }
                Log.d(TAG, "close the stream file");
                fileInputStream.close();
            } catch (FileNotFoundException e) {
            } catch (IOException e) {
            }
            mCurrentIndex++;
            /*if (mCurrentIndex == mPcmFileNames.size()) {
                //reset to zero
                mCurrentIndex = 0;
            }*/
        }
        isPlainAudio = true;
        while (mValid.get()) {
            bytes = new byte[4960];
            if (mRecordListener != null) {
                mRecordListener.onRecord(bytes, 4960);
            }
            try {
                Thread.sleep(30);
            } catch (InterruptedException e) {

            }
        }

        mValid.compareAndSet(true, false);
        Log.d("prepro", "run finished");
    }

    public static boolean hasTestFile() {
        if (mPcmFileNames == null || mPcmFileNames.size() == 0) return false;
        if (mPcmFileNames.size() == mCurrentIndex) return false;
        return true;
    }

    public static int testFileCount() {
        if (mPcmFileNames == null) return 0;
        return mPcmFileNames.size();
    }

    @Override
    public synchronized void start() {
        super.start();
    }
}
