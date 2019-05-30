package com.tencent.ai.sampleapp;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.tencent.ai.sampleapp.util.FileUtil;
import com.tencent.ai.sampleapp.util.PermissionUtils;
import com.tencent.ai.sdk.control.SpeechManager;

import java.util.ArrayList;
import java.util.List;

/**
 * Sample主入口
 */
public class MainActivity extends Activity implements AdapterView.OnItemClickListener, PermissionUtils.PermissionGrant {

    private boolean mDebug = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        requestPermission();

        // 填充Sample ListView
        String[] sampleItems = getResources().getStringArray(R.array.sample_list);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, sampleItems);
        ListView sampleListView = (ListView) findViewById(R.id.sample_listView);
        sampleListView.setAdapter(adapter);
        sampleListView.setOnItemClickListener(this);

        // 版本信息
        ((TextView) findViewById(R.id.version_tv)).setText(com.tencent.ai.sdk.utils.BuildConfig.getVersion());
        if (mDebug) {
            TextView guidTv = (TextView) findViewById(R.id.guid_tv);
            guidTv.setVisibility(View.VISIBLE);
            guidTv.setText("GUID:" + SpeechManager.getInstance().getGuidStr());
        }

    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Class sampleClass = null;
        switch (position) {
            case 0:
                sampleClass = SpeechRecognizeActivity.class;
                break;
            case 1:
                sampleClass = Text2SemanticActivity.class;
                break;
            case 2:
                sampleClass = TTSActivity.class;
                break;
            case 3:
                sampleClass = WakeupActivity.class;
                break;
            case 4:
                sampleClass = OneShotActivity.class;
                break;
            case 5:
                sampleClass = CustomWakeupActivity.class;
                break;
            case 6:
                sampleClass = WakeupRecognizeActivity.class;
                break;
        }

        if (null != sampleClass) {
            Intent intent = new Intent(this, sampleClass);
            startActivity(intent);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        menu.add(0, 1, 0, "设置").setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onMenuItemSelected(int featureId, MenuItem item) {
        int id = item.getItemId();
        if (id == 1) {
            startActivity(new Intent(MainActivity.this, SettingsActivity.class));
        }
        return super.onMenuItemSelected(featureId, item);
    }

    private void requestPermission() {
        List<String> permissions = new ArrayList<>();
        permissions.add(PermissionUtils.PERMISSION_WRITE_EXTERNAL_STORAGE);
        permissions.add(PermissionUtils.PERMISSION_READ_PHONE_STATE);
        permissions.add(PermissionUtils.PERMISSION_RECORD_AUDIO);
        PermissionUtils.requestMultiPermissions(this, permissions, this);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        PermissionUtils.requestPermissionsResult(this, requestCode, permissions, grantResults, this);
    }

    @Override
    public void onPermissionGranted(int requestCode) {
        switch (requestCode) {
            case PermissionUtils.CODE_MULTI_PERMISSION:
                FileUtil.copyModelFiles(this);
            break;
        }
    }

    @Override
    public void onPermissionDenied(int requestCode) {

    }
}
