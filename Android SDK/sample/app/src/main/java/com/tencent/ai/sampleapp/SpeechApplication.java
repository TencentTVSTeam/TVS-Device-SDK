package com.tencent.ai.sampleapp;

import android.app.Application;
import android.util.Log;

import com.tencent.ai.sdk.control.SpeechManager;
import com.tencent.ai.sdk.utils.ISSErrors;

import org.json.JSONObject;

public class SpeechApplication extends Application {
	private static SpeechApplication sInstance;

	@Override
	public void onCreate() {
		super.onCreate();
		sInstance = this;
//		new Thread(startup).start();
		int ret = SpeechManager.getInstance().startUp(sInstance, getAppInfo());
		if (ret != ISSErrors.ISS_SUCCESS) {
			System.exit(0);
		}
	}
	
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
