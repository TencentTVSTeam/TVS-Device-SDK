package com.tencent.ai.sampleapp;

import android.os.Bundle;
import android.preference.EditTextPreference;
import android.preference.ListPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceManager;
import android.preference.SwitchPreference;
import android.text.TextUtils;
import android.widget.Toast;

import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sdk.control.SpeechManager;
import com.tencent.ai.sdk.settings.CommonConfig;
import com.tencent.ai.sdk.settings.VoiceConfig;
import com.tencent.ai.sdk.settings.WakeupConfig;

public class SettingsActivity extends PreferenceActivity implements Preference.OnPreferenceChangeListener {
    PreferenceManager mPreferenceManager;
    ListPreference mEnvListPreference;
    SwitchPreference mSanboxSwitchPreference;
    SwitchPreference mSaveRecognizeSwitchPreference;
    SwitchPreference mSaveWakeupPreference;
    SwitchPreference mSaveWakeupReportPreference;
    SwitchPreference mVadCloudPreference;
    SwitchPreference mVadLocalPreference;
    SwitchPreference mVadOnlyDetectPreference;
    SwitchPreference mIgnoreWakeupPreference;
    ListPreference mWakeupReportNetworkPreference;
    Preference mWakeupReportSavePathPreference;
    EditTextPreference mWakeupReportSaveSizePreference;
    EditTextPreference mOnlineAudioPeerSizePreference;
    EditTextPreference mOnlineSilTimeoutPreference;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.settings);
        mPreferenceManager = getPreferenceManager();
        mEnvListPreference = (ListPreference) mPreferenceManager.findPreference("env_switch");
        mSanboxSwitchPreference = (SwitchPreference) mPreferenceManager.findPreference("sanbox");
        mSaveRecognizeSwitchPreference = (SwitchPreference) mPreferenceManager.findPreference("save_recognize");
        mSaveWakeupPreference = (SwitchPreference) mPreferenceManager.findPreference("save_wakeup");
        mSaveWakeupReportPreference = (SwitchPreference) mPreferenceManager.findPreference("save_wakeup_report");
        mVadCloudPreference = (SwitchPreference) mPreferenceManager.findPreference("vad_cloud");
        mVadLocalPreference = (SwitchPreference) mPreferenceManager.findPreference("vad_local");
        mVadOnlyDetectPreference = (SwitchPreference) mPreferenceManager.findPreference("vad_only_detect");
        mIgnoreWakeupPreference = (SwitchPreference) mPreferenceManager.findPreference("ignore_wakeup");
        mWakeupReportNetworkPreference = (ListPreference) mPreferenceManager.findPreference("wakeup_report_network_type");
        mWakeupReportSavePathPreference =  mPreferenceManager.findPreference("wakeup_report_save_path");
        mWakeupReportSaveSizePreference = (EditTextPreference) mPreferenceManager.findPreference("wakeup_report_save_size");
        mOnlineAudioPeerSizePreference = (EditTextPreference) mPreferenceManager.findPreference("audio_peer_size");
        mOnlineSilTimeoutPreference = (EditTextPreference) mPreferenceManager.findPreference("online_sil_timeout");

        setDefaultValue();

//        mEnvListPreference.setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
//            @Override
//            public boolean onPreferenceChange(Preference preference, Object newValue) {
//                String value = String.valueOf(newValue);
//                String summary = "";
//                if (TextUtils.equals(value, "0")) {
//                    summary = getResources().getString(R.string.env_normal);
//                    SpeechManager.getInstance().setEnvironment(CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL);
//                } else if (TextUtils.equals(value, "1")) {
//                    summary = getResources().getString(R.string.env_test);
//                    SpeechManager.getInstance().setEnvironment(CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_TEST);
//                } else if (TextUtils.equals(value, "2")) {
//                    summary = getResources().getString(R.string.env_exp);
//                    SpeechManager.getInstance().setEnvironment(CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_EXP);
//                }
//                mEnvListPreference.setSummary(summary);
//                Toast.makeText(SettingsActivity.this, "环境已设置为：" + summary, Toast.LENGTH_SHORT).show();
//                return true;
//            }
//        });
//
//
//        mSanboxSwitchPreference.setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
//            @Override
//            public boolean onPreferenceChange(Preference preference, Object newValue) {
//                SpeechManager.getInstance().setSandBox((Boolean) newValue);
//                return true;
//            }
//        });
        mEnvListPreference.setOnPreferenceChangeListener(this);
        mSanboxSwitchPreference.setOnPreferenceChangeListener(this);
        mSaveRecognizeSwitchPreference.setOnPreferenceChangeListener(this);
        mSaveWakeupPreference.setOnPreferenceChangeListener(this);
        mSaveWakeupReportPreference.setOnPreferenceChangeListener(this);
        mVadCloudPreference.setOnPreferenceChangeListener(this);
        mVadLocalPreference.setOnPreferenceChangeListener(this);
        mVadOnlyDetectPreference.setOnPreferenceChangeListener(this);
        mWakeupReportNetworkPreference.setOnPreferenceChangeListener(this);
        mWakeupReportSavePathPreference.setOnPreferenceChangeListener(this);
        mWakeupReportSaveSizePreference.setOnPreferenceChangeListener(this);
        mIgnoreWakeupPreference.setOnPreferenceChangeListener(this);
        mOnlineAudioPeerSizePreference.setOnPreferenceChangeListener(this);
        mOnlineSilTimeoutPreference.setOnPreferenceChangeListener(this);
    }


    private void setDefaultValue() {
        if (mEnvListPreference != null) {
            String envType = SpeechManager.getInstance().aisdkGetConfig(CommonConfig.AISDK_CONFIG_ENV_TYPE);
            String summary = "";
            int valueIndex = 0;
            if (TextUtils.equals(envType, CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL)) {
                summary = getResources().getString(R.string.env_normal);
                valueIndex = 0;
            } else if (TextUtils.equals(envType, CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_TEST)) {
                summary = getResources().getString(R.string.env_test);
                valueIndex = 1;
            } else if (TextUtils.equals(envType, CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_EXP)) {
                summary = getResources().getString(R.string.env_exp);
                valueIndex = 2;
            }
            mEnvListPreference.setValueIndex(valueIndex);
            mEnvListPreference.setSummary(summary);
        }
        if (mSanboxSwitchPreference != null) {
            String sanbox = SpeechManager.getInstance().aisdkGetConfig(CommonConfig.AISDK_CONFIG_OPEN_SANDBOX);
            if (TextUtils.equals("1", sanbox)) {
                mSanboxSwitchPreference.setChecked(true);
            } else {
                mSanboxSwitchPreference.setChecked(false);
            }
        }
        if (mSaveRecognizeSwitchPreference != null) {
            String saveSpeech = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH);
            if (TextUtils.equals("1", saveSpeech)) {
                mSaveRecognizeSwitchPreference.setChecked(true);
            } else {
                mSaveRecognizeSwitchPreference.setChecked(false);
            }
        }
        if (mSaveWakeupPreference != null) {
            String saveWakeup = SpeechManager.getInstance().aisdkGetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_SAVE_SPEECH);
            if (TextUtils.equals("1", saveWakeup)) {
                mSaveWakeupPreference.setChecked(true);
            } else {
                mSaveWakeupPreference.setChecked(false);
            }
        }
        if (mSaveWakeupReportPreference != null) {
            String saveWakeupReport = SpeechManager.getInstance().aisdkGetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED);
            if (TextUtils.equals("1", saveWakeupReport)) {
                mSaveWakeupReportPreference.setChecked(true);
                refreshWakeupReportState(true);
            } else {
                mSaveWakeupReportPreference.setChecked(false);
                refreshWakeupReportState(false);
            }
        }
        if (mVadCloudPreference != null) {
            String vadCloud = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD);
            if (TextUtils.equals("1", vadCloud)) {
                mVadCloudPreference.setChecked(true);
            } else {
                mVadCloudPreference.setChecked(false);
            }
        }
        if (mVadLocalPreference != null) {
            String vadLocal = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD);
            if (TextUtils.equals("1", vadLocal)) {
                mVadLocalPreference.setChecked(true);
            } else {
                mVadLocalPreference.setChecked(false);
            }
        }
        if (mVadOnlyDetectPreference != null) {
            String vadOnlyDetect = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD);
            if (TextUtils.equals("1", vadOnlyDetect)) {
                mVadOnlyDetectPreference.setChecked(true);
            } else {
                mVadOnlyDetectPreference.setChecked(false);
            }
        }
        if (mWakeupReportNetworkPreference != null) {
            String wakeupNetworkType = SpeechManager.getInstance().aisdkGetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE);
            String summary = "";
            int valueIndex = 0;
            if (TextUtils.equals(wakeupNetworkType, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_NO_UPLOADING)) {
                summary = getResources().getString(R.string.wakeup_network_none);
                valueIndex = 0;
            } else if (TextUtils.equals(wakeupNetworkType, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_ONLY_WIFI)) {
                summary = getResources().getString(R.string.wakeup_network_wifi);
                valueIndex = 1;
            } else if (TextUtils.equals(wakeupNetworkType, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_ONLY_4G)) {
                summary = getResources().getString(R.string.wakeup_network_4g);
                valueIndex = 2;
            } else if (TextUtils.equals(wakeupNetworkType, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_BOTH_WIFI_AND_4G)) {
                summary = getResources().getString(R.string.wakeup_network_both);
                valueIndex = 3;
            }
            mWakeupReportNetworkPreference.setValueIndex(valueIndex);
            mWakeupReportNetworkPreference.setSummary(summary);
        }
        if (mWakeupReportSavePathPreference != null) {
            String wakeupReportSavePath = SpeechManager.getInstance().aisdkGetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH);
            mWakeupReportSavePathPreference.setSummary(wakeupReportSavePath);
        }
        if (mWakeupReportSaveSizePreference != null) {
            String wakeupReportSaveSize = SpeechManager.getInstance().aisdkGetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE);
            mWakeupReportSaveSizePreference.setSummary(wakeupReportSaveSize);
        }
        if (mIgnoreWakeupPreference != null) {
            String ignoreWakeup = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO);
            if (TextUtils.equals("1", ignoreWakeup)) {
                mIgnoreWakeupPreference.setChecked(true);
            } else {
                mIgnoreWakeupPreference.setChecked(false);
            }
        }
        if (mOnlineAudioPeerSizePreference != null) {
            String peerSize = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE);
            mOnlineAudioPeerSizePreference.setSummary(peerSize);
        }
        if (mOnlineSilTimeoutPreference != null) {
            String timeout = SpeechManager.getInstance().aisdkGetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT);
            mOnlineSilTimeoutPreference.setSummary(timeout);
        }
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
        if (preference == mEnvListPreference) {
            String value = String.valueOf(newValue);
            String summary = "";
            if (TextUtils.equals(value, "0")) {
                summary = getResources().getString(R.string.env_normal);
                SpeechManager.getInstance().setEnvironment(CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL);
            } else if (TextUtils.equals(value, "1")) {
                summary = getResources().getString(R.string.env_test);
                SpeechManager.getInstance().setEnvironment(CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_TEST);
            } else if (TextUtils.equals(value, "2")) {
                summary = getResources().getString(R.string.env_exp);
                SpeechManager.getInstance().setEnvironment(CommonConfig.AISDK_CONFIG_VALUE_ENV_TYPE_EXP);
            }
            mEnvListPreference.setSummary(summary);
            Toast.makeText(SettingsActivity.this, "环境已设置为：" + summary, Toast.LENGTH_SHORT).show();
        } else if (preference == mSanboxSwitchPreference) {
            SpeechManager.getInstance().setSandBox((Boolean) newValue);
        } else if (preference == mSaveRecognizeSwitchPreference) {
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_SAVE_SPEECH, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
        } else if (preference == mSaveWakeupPreference) {
            SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_SAVE_SPEECH, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
        } else if (preference == mSaveWakeupReportPreference) {
            SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_SAVING_ENABLED, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
            refreshWakeupReportState((boolean) newValue);
            //如果关闭上传，需要手动置空path
            //再次打开，需要重新设置音频保存位置
            if ((boolean) newValue) {
                String path = FileUtil.getWakeupBufferFilePath(this);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH, path);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE, "20");
            } else {
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH, CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE, CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
            }
        } else if (preference == mVadCloudPreference) {
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
        } else if (preference == mVadLocalPreference) {
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_USER_LOCAL_VAD, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
        } else if (preference == mVadOnlyDetectPreference) {
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_ONLY_DETECT_VAD, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
        } else if (preference == mWakeupReportNetworkPreference) {
            String value = String.valueOf(newValue);
            String summary = "";
            if (TextUtils.equals(value, "0")) {
                summary = getResources().getString(R.string.wakeup_network_none);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_NO_UPLOADING);
            } else if (TextUtils.equals(value, "1")) {
                summary = getResources().getString(R.string.wakeup_network_wifi);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_ONLY_WIFI);
            } else if (TextUtils.equals(value, "2")) {
                summary = getResources().getString(R.string.wakeup_network_4g);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_ONLY_4G);
            } else if (TextUtils.equals(value, "3")) {
                summary = getResources().getString(R.string.wakeup_network_both);
                SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_UPLOAD_NETWORK_TYPE, WakeupConfig.AISDK_CONFIG_VALUE_WAKEUP_BUFFER_NETWORK_BOTH_WIFI_AND_4G);
            }
            mWakeupReportNetworkPreference.setSummary(summary);
        } else if (preference == mWakeupReportSavePathPreference) {
            SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_SAVING_PATH, (String) newValue);
        } else if (preference == mWakeupReportSaveSizePreference) {
            SpeechManager.getInstance().aisdkSetConfig(WakeupConfig.AISDK_CONFIG_WAKEUP_BUFFER_MAX_FILE_SIZE, (String) newValue);
            mWakeupReportSaveSizePreference.setSummary((String) newValue);
        } else if (preference == mIgnoreWakeupPreference) {
//            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_IGNORE_WAKEUP_WHEN_RECO, (boolean) newValue ? CommonConfig.AISDK_CONFIG_VALUE_ENABLE : CommonConfig.AISDK_CONFIG_VALUE_DISABLE);
            SpeechManager.getInstance().setIfIgnoreWakeupWhenReco((boolean) newValue);
        } else if (preference == mOnlineAudioPeerSizePreference) {
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_AUDIO_PEER_SIZE, (String) newValue);
            mOnlineAudioPeerSizePreference.setSummary((String) newValue);
        } else if (preference == mOnlineSilTimeoutPreference) {
            SpeechManager.getInstance().aisdkSetConfig(VoiceConfig.AISDK_CONFIG_VOICE_ONLINE_SIL_TIMEOUT, (String) newValue);
            mOnlineSilTimeoutPreference.setSummary((String) newValue);
        }

        return true;
    }

    private void refreshWakeupReportState(boolean isChecked) {
        if (mWakeupReportNetworkPreference != null) {
            mWakeupReportNetworkPreference.setEnabled(isChecked);
        }
        if (mWakeupReportSavePathPreference != null) {
            mWakeupReportSavePathPreference.setEnabled(isChecked);
        }
        if (mWakeupReportSaveSizePreference != null) {
            mWakeupReportSaveSizePreference.setEnabled(isChecked);

        }
    }
}
