package com.tencent.ai.sampleapp.record;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.util.Log;

import java.util.concurrent.locks.ReentrantLock;

public class PcmRecorder extends Thread {

	private static final String TAG = "PcmRecorder";

	private AudioRecord mRecorder = null;

	private int buffersize = -1;
	private byte[] buffer = null;
	private boolean isRunning = false;
	private ReentrantLock lock = new ReentrantLock();

	private int setTrack = 64;
	private int SET_CHANNELS = AudioFormat.CHANNEL_IN_MONO;
	private static final int DEFAULT_SAMPLE_RATE = 16 * 1000;
	private static final short DEFAULT_AUDIO_FORMAT = AudioFormat.ENCODING_PCM_16BIT;

	private RecordListener mRecordListener;

	public PcmRecorder(RecordListener listener) {
		super("PcmRecorder");
		mRecordListener = listener;
	}

	public boolean isPlainAudio = true;

	@Override
	public synchronized void start() {
		super.start();

		isRunning = true;
	}

	/**
	 * 停止线程
	 */
	public synchronized boolean stopThread() {
		if (!isRunning()) {
			return false;
		}

		isRunning = false;
		try {
			join();
		} catch (InterruptedException e) {
			e.printStackTrace();
			Log.e(TAG, "stopThread : " + e.getMessage());
		}

		return true;
	}

	@Override
	public void run() {
		lock.lock();
		try {
			buffersize = AudioRecord.getMinBufferSize(DEFAULT_SAMPLE_RATE,
					SET_CHANNELS, DEFAULT_AUDIO_FORMAT);

			Log.d(TAG, "buffersize=" + String.valueOf(buffersize));
			if (buffersize < 0) {
                return;
            } else if (mRecorder == null) {
                if(buffersize < 4096) {
                	buffersize = 4096;
                }
				buffer = new byte[buffersize];
                mRecorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
    					DEFAULT_SAMPLE_RATE, SET_CHANNELS, DEFAULT_AUDIO_FORMAT,
    					buffersize);
            }
			if (mRecorder.getState() == AudioRecord.STATE_UNINITIALIZED) {
				Log.e(TAG, "Error: AudioRecord state == STATE_UNINITIALIZED");
				return;
			}
			mRecorder.startRecording();
		} finally {
			lock.unlock();
		}

		while (isRunning) {
			try {
				int count = mRecorder.read(buffer, 0, buffersize);
				if (count > 0 && null != mRecordListener) {
					mRecordListener.onRecord(buffer, count);
				}
			} catch (Exception e) {
				e.printStackTrace();
			}
			try {
				Thread.sleep(buffersize / setTrack);
			} catch (InterruptedException e) {
				e.printStackTrace();

				Log.e(TAG, "InterruptedException: " + e.getMessage());
			}
		}
		if (mRecorder != null) {
			mRecorder.stop();
			mRecorder.release();
		}
	}

	public boolean isRunning() {
		return isRunning;
	}

	public interface RecordListener {
		public void onRecord(byte[] buffer, int bufferSize);
	}
}
