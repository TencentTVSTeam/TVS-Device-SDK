package com.tencent.ai.sampleapp.util;

import android.content.Context;
import android.os.Environment;
import android.text.TextUtils;
import android.util.Log;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.RandomAccessFile;
import java.io.UnsupportedEncodingException;

/**
 * Created by cassliu on 2017/10/7.
 */
public class FileUtil {
    private static final String TAG = "FileUtil";

    /**
     * 检查目录是否为空
     *
     * @param folder
     * @return
     */
    public static boolean isDirectoryEmpty(File folder) {
        return !folder.exists() || !folder.isDirectory() || folder.list().length <= 0;
    }


    public static void copyModelFiles(Context inContext) {
        if (isModelFileExist(inContext)) {
            return;
        }
        // 拷贝sdk配置文件到sd卡
        String packagePath = getModelFilePath(inContext);
        // 拷贝唤醒模型，先清除原来有的目录
        String sKeywordsPath = packagePath + "/keywords_model";
        File mFile = new File(sKeywordsPath);
        FileUtil.delete(mFile);
        //创建目录
        if (!mFile.exists()) {
            mFile.mkdirs();
        }
        //进行文件拷贝的操作
        AssetsCopyer.releaseAssets(inContext, "keywords_model", packagePath);
        Log.i(TAG, "TVS keywords model config file path: " + sKeywordsPath);


        // 拷贝自定义唤醒模型，先清除原来有的目录
        String sVoiceOfflineModelPath = packagePath + "/mdl_vtt";
        File voiceOfflineModelFile = new File(sVoiceOfflineModelPath);
        FileUtil.delete(voiceOfflineModelFile);
        //创建目录
        if (!voiceOfflineModelFile.exists()) {
            voiceOfflineModelFile.mkdirs();
        }
        //进行文件拷贝的操作
        AssetsCopyer.releaseAssets(inContext, "mdl_vtt", packagePath);
        Log.i(TAG, "TVS voiceOffline model config file path: " + sVoiceOfflineModelPath);

        // 拷贝本地VAD模型，先清除原来有的目录
        String sVadModelPath = packagePath + "/vad";
        File vadModelFile = new File(sVadModelPath);
        FileUtil.delete(vadModelFile);
        //创建目录
        if (!vadModelFile.exists()) {
            vadModelFile.mkdirs();
        }
        //进行文件拷贝的操作
        AssetsCopyer.releaseAssets(inContext, "vad", packagePath);
        Log.i(TAG, "TVS vad model config file path: " + sVadModelPath);

        // 拷贝本地VAD模型，先清除原来有的目录
        String sOfflineSemanticModelPath = packagePath + "/data";
        File offlineSemanticModelFile = new File(sOfflineSemanticModelPath);
        FileUtil.delete(offlineSemanticModelFile);
        //创建目录
        if (!offlineSemanticModelFile.exists()) {
            offlineSemanticModelFile.mkdirs();
        }
        //进行文件拷贝的操作
        AssetsCopyer.releaseAssets(inContext, "data", packagePath);
        Log.i(TAG, "TVS vad model config file path: " + sOfflineSemanticModelPath);
    }

    /**
     * 递归删除文件及文件夹
     *
     * @param file
     */
    public static void delete(File file) {
        if (file.isFile()) {
            file.delete();
            return;
        }

        if (file.isDirectory()) {
            File[] childFiles = file.listFiles();
            if (childFiles == null || childFiles.length == 0) {
                file.delete();
                return;
            }

            for (int i = 0; i < childFiles.length; i++) {
                delete(childFiles[i]);
            }
            file.delete();
        }
    }

    public static String getModelFilePath(Context context) {
        String packagePath = Environment.getExternalStorageDirectory().getAbsolutePath() + "/Android/data/" + context.getPackageName() + "/files";
        return packagePath;
    }

    private static boolean isModelFileExist(Context context) {
        String sFilePath = getModelFilePath(context) + "/vad";
        boolean isExist = false;
        File mFile = new File(sFilePath);
        Log.d(TAG, "Model File Path=" + sFilePath);
        if (mFile.exists()) {
            isExist = true;
        }

        return isExist;
    }

    public static String getWakeupBufferFilePath(Context context) {
        String path = context.getApplicationContext().getExternalCacheDir().getAbsolutePath() + File.separator + "files/wakeup_buffer";
        File f = new File(path);
        if (f.exists() && f.isDirectory()) {
        } else {
            if (!f.isDirectory()) {
                //Nothing
                f.delete();
            }
            f.mkdirs();
        }
        return path;
    }
	
	    public static String getLibFilePath(Context context) {
        String packagePath = "/data/data/" + context.getPackageName();
        return packagePath;
    }

    private static boolean isLibFileExist(Context context) {
        String sFilePath = getExtendLib(context)  + "/libtvad.so";
        boolean isExist = false;
        File mFile = new File(sFilePath);
        Log.d(TAG, "Model File Path=" + sFilePath);
        if (mFile.exists()) {
            isExist = true;
        }

        return isExist;
    }

    public static String getExtendLib(Context context) {
        String sLibPath = getLibFilePath(context) + "/lib";
        return sLibPath;
    }

    public static boolean isExternalStorageAvailable() {
        try {
            return TextUtils.equals("mounted", Environment.getExternalStorageState());
        } catch (Exception var1) {
            return false;
        }
    }

    public static File getExternalFilesDir(Context context, String type) {
        File file = null;

        try {
            file = context.getExternalFilesDir(type);
        } catch (Exception var4) {
            ;
        }

        if (file == null) {
            if (type == null) {
                file = new File(getExternalStorageDirectory().getAbsolutePath() + "/Android/data/" + context.getPackageName() + "/files");
            } else {
                file = new File(getExternalStorageDirectory().getAbsolutePath() + "/Android/data/" + context.getPackageName() + "/files/" + type);
            }

            if (!file.exists()) {
                file.mkdirs();
            }
        }

        return file;
    }

    public static File getExternalStorageDirectory() {
        return Environment.getExternalStorageDirectory();
    }

    public static void doWriteLogcat(Context context){

        if (!FileUtil.isExternalStorageAvailable()) {
            Log.d(TAG,"SD卡不存在，请检查SD卡...");
        }

        String ownPackageName = context.getPackageName();

        // 创建本次目录
        Log.d(TAG,"开始创建本次的工作目录...");
        File workDir = FileUtil.getExternalFilesDir(context, "debug");
        Log.d(TAG,workDir.getAbsolutePath());


        // 导出手机的logcat日志
        Log.d(TAG,"导出logcat日志...");
        String logcatPath = workDir.getAbsoluteFile() + "/logcat.txt";
        File logcatFile = new File(logcatPath);
        BufferedReader bufferedReader = null;
        OutputStreamWriter bufferedWriter = null;
        try {
            if (logcatFile.exists()) {
                logcatFile.delete();
            }
            logcatFile.getParentFile().mkdirs();
            logcatFile.createNewFile();

            String[] argsStrings = new String[]{
                    "logcat", "-d", "-v", "time"
            };
            java.lang.Process mProcess = Runtime.getRuntime().exec(argsStrings);

            PrintStream outputStream = new PrintStream(new BufferedOutputStream(
                    mProcess.getOutputStream(), 128));
            outputStream.flush();
            outputStream.close();

            bufferedReader = new BufferedReader(new InputStreamReader(
                    mProcess.getInputStream()));
            bufferedWriter = new OutputStreamWriter(new FileOutputStream(logcatFile,
                    false));

            String line;
            while ((line = bufferedReader.readLine()) != null) {
                bufferedWriter.write(line + "\n");
            }

        } catch (IOException e) {
            Log.d(TAG,"导出过程中出现问题：" + e.getMessage());
        } finally {
            if (null != bufferedReader) {
                try {
                    bufferedReader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            if (null != bufferedWriter) {
                try {
                    bufferedWriter.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static String getJson(String fileName, Context context){
        StringBuilder stringBuilder = new StringBuilder();
        try {
            InputStream is = context.getAssets().open(fileName);
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(is));
            String line;
            while ((line=bufferedReader.readLine()) != null){
                stringBuilder.append(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return stringBuilder.toString();
    }

    public static String getStringWithFile(String fileName) {
        try {
            File file = new File(fileName);
            InputStream is = new FileInputStream(file);
            return getString(is);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static String getString(InputStream inputStream) {
        InputStreamReader inputStreamReader = null;
        try {
            inputStreamReader = new InputStreamReader(inputStream, "utf-8");
        } catch (UnsupportedEncodingException e1) {
            e1.printStackTrace();
        }
        BufferedReader reader = new BufferedReader(inputStreamReader);
        StringBuilder sb = new StringBuilder("");
        String line;
        try {
            while ((line = reader.readLine()) != null) {
                sb.append(line);
                sb.append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return sb.toString();
    }

    // 将字符串写入到文本文件中
    public static void writeTxtToFile(String strcontent, String filePath, String fileName) {
        //生成文件夹之后，再生成文件，不然会出错
        makeFilePath(filePath, fileName);

        String strFilePath = filePath + fileName;
        // 每次写入时，都换行写
        String strContent = strcontent + "\r\n";
        try {
            File file = new File(strFilePath);
            if (!file.exists()) {
                Log.d("TestFile", "Create the file:" + strFilePath);
                file.getParentFile().mkdirs();
                file.createNewFile();
            }
            RandomAccessFile raf = new RandomAccessFile(file, "rwd");
            raf.seek(file.length());
            raf.write(strContent.getBytes());
            raf.close();
        } catch (Exception e) {
            Log.e("TestFile", "Error on write File:" + e);
        }
    }

    //生成文件
    public static File makeFilePath(String filePath, String fileName) {
        File file = null;
        makeRootDirectory(filePath);
        try {
            file = new File(filePath + fileName);
            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return file;
    }

    //生成文件夹
    public static void makeRootDirectory(String filePath) {
        File file = null;
        try {
            file = new File(filePath);
            if (!file.exists()) {
                file.mkdir();
            }
        } catch (Exception e) {
            Log.i("error:", e + "");
        }
    }

    //读取指定目录下的所有TXT文件的文件内容
    public static String getFileContent(File file) {
        String content = "";
        if (!file.isDirectory()) { //检查此路径名的文件是否是一个目录(文件夹)
            if (file.getName().endsWith("txt")) {//文件格式为""文件
                try {
                    InputStream instream = new FileInputStream(file);
                    if (instream != null) {
                        InputStreamReader inputreader
                                = new InputStreamReader(instream, "UTF-8");
                        BufferedReader buffreader = new BufferedReader(inputreader);
                        String line = "";
                        //分行读取
                        while ((line = buffreader.readLine()) != null) {
                            content += line + "\n";
                        }
                        instream.close();//关闭输入流
                    }
                } catch (java.io.FileNotFoundException e) {
                    Log.d("TestFile", "The File doesn't not exist.");
                } catch (IOException e) {
                    Log.d("TestFile", e.getMessage());
                }
            }
        }
        return content;
    }
}
