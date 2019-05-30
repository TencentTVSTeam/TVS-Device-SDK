package com.tencent.ai.sampleapp;

import android.app.Application;
import android.util.Log;

import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sdk.control.SpeechManager;
import com.tencent.ai.sdk.jni.LoadingCallback;
import com.tencent.ai.sdk.settings.CommonConfig;
import com.tencent.ai.sdk.settings.VoiceConfig;
import com.tencent.ai.sdk.settings.WakeupConfig;

import org.json.JSONObject;

public class SpeechApplication extends Application {
    private static SpeechApplication sInstance;
    public static boolean sLoaded = false;

    @Override
    public void onCreate() {
        super.onCreate();
        sInstance = this;
//		new Thread(startup).start();
        SpeechManager.getInstance().startUp(sInstance, getAppInfo(), new LoadingCallback() {
            @Override
            public void onLoadFinished(boolean success) {
                if (success) {
                    SpeechManager.getInstance().setDisplayLog(true);
                    // 设置开启离线语音日志输出
                    SpeechManager.getInstance().setOfflineLogLevel(SpeechManager.VOICE_OFFLINE_LOG_LEVEL_DEBUG, SpeechManager.VOICE_OFFLINE_TIME_FOMAT_NOMAL);
                    SpeechManager.getInstance().setForceLog(true);
                    sLoaded = true;


                }
            }
        });
        FileUtil.copyModelFiles(this);
    }

    /**
     * Json字符串中，新增deviceSerialNum字段，必须传入，否则会初始化失败
     */
	private String getAppInfo() {
		String result = "";
		try {
			final JSONObject info = new JSONObject();
			info.put("appkey", ""); //填入应用的appkey
			info.put("token", ""); //填入应用的access token
			/**
			 * 如果产品是车机，填入CAR
			 * 如果产品是电视，填入TV
			 * 如果产品是音箱，填入SPEAKER
			 * 如果产品是手机，填入PHONE
			 */
			info.put("deviceName", ""); //固定，填入CAR或者TV或者SPEAKER或者PHONE
			info.put("productName", ""); //产品名称，不要有特殊字符和空格
			info.put("vendor",""); //厂商英文名,不要有特殊字符和空格
            info.put("deviceSerialNum", "359906070210625"); //设备唯一标识码，唯一设备ID

			final JSONObject json = new JSONObject();
			json.put("info", info);

			result = json.toString();
		} catch (Exception e) {
			// do nothing
		}
		Log.d("SpeechApplication", "info = " + result);
		return result;
	}
	
	public static SpeechApplication getInstance() {
		return sInstance;
	}
}
