/**
 * @file
 * @author kangrong
 * @date 2017/8/28
 * @brief 示例代码：语音识别
 * @version 0.1.0
 * @note
 */


#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <pthread.h>

#include "aisdk_common_api.h"
#include "aisdk_wakeup.h"
#include "aisdk_voice_online.h"
#include "aisdk_one_shot.h"

using namespace std;

char* wakeupVoiceFile;
char* onlineVoiceFile;

bool stopOfflineReco = false;
bool stopOnlineReco = false;

void sendAudioData() {
    std::ifstream dataFile;

    //输入唤醒识别音频
    cout << "input wakeup reco audio data..." << endl;
    dataFile.open(wakeupVoiceFile, std::ios::binary);
    dataFile.seekg (44, std::ios::beg);
    int size = 4096;
    int count = 0;
    int res = 0;
    while(!stopOnlineReco && dataFile.eof() == 0) {
        char* pcm_buf = new char[size];
        dataFile.read(pcm_buf, size);
        size = dataFile.gcount();
        count++;
        usleep(100000);
        res = aisdkInputOneShotAudioData(pcm_buf, size);
        //TODO handle res not zero, send data again

        std::cout << "ivaSetWakeupRecord, res:" << res << " count "<<count<<std::endl;
    }
    dataFile.close();

    //输入语音识别音频
    cout << "input online reco audio data..." << endl;
    dataFile.open(onlineVoiceFile, std::ios::binary);
    dataFile.seekg (44, std::ios::beg);
    size = 4096;
    count = 0;
    while(!stopOnlineReco && dataFile.eof() == 0) {
        char* pcm_buf = new char[size];
        dataFile.read(pcm_buf, size);
        size = dataFile.gcount();
        count++;
		usleep(100000);
        res = aisdkInputOneShotAudioData(pcm_buf, size);
        //TODO handle res not zero, send data again

        std::cout << "ivaSetOnlineRecord, res:" << res << " count "<<count<<std::endl;
    }
    dataFile.close();
    sleep(3);
}

void callback(int cmd, char* data, int dataLen, void* userData, int userDataLen, void *extra, int extraLen)
{
    // 任何情况下，不要阻塞回调线程。
    string result(data, dataLen);
    cout << "callback cmd: " << cmd  << endl;

    switch(cmd) {
        case AISDK_CMD_WAKEUP_RECO_START: {
            std::cout << "启动唤醒识别" << result<<std::endl;
            stopOfflineReco = false;
            //不能阻塞回调线程
            pthread_t t1;
            pthread_create(&t1,NULL,sendAudioData,NULL);

            break;
        }
        case AISDK_CMD_WAKEUP_RECO_RESULT: {
            std::cout << "唤醒识别结束, result: " << result << std::endl;
            stopOfflineReco = true;
            break;
        }
        case AISDK_CMD_WAKEUP_RECO_ERROR:{
            std::cout << "唤醒识别发生错误,  停止输入音频。" << std::endl;
            stopOfflineReco = true;
            break;
        }
        case AISDK_CMD_WAKEUP_RECO_CANCELED:{
            std::cout << "唤醒识别已经取消。" << std::endl;
            stopOfflineReco = true;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_START: {
            std::cout << "启动语音识别，可以输入语音流." << std::endl;

            stopOnlineReco = false;
            std::cout << "开始测试在线识别" << std::endl;

            break;
        }
        case AISDK_CMD_ONLINE_RECO_SPEECH_END: {
            std::cout << "语音识别结束, result: " << result << std::endl;
            stopOnlineReco = true;
            break;
        }

        case AISDK_CMD_ONLINE_RECO_RESULT: {
            std::cout << "语音识别返回结果, result: " << result << std::endl;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_SPEECH_START:{
            std::cout << "在线vad检测开始, result: " << result << std::endl;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_INTERMEDIATE_RESULT:{
            std::cout << "中间结果, result: " << result << std::endl;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_DATA_VOLUME:{
            std::cout << "音量值, result: " << result << std::endl;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_ERROR:{
            std::cout << "发生错误, 停止输入: " << result << std::endl;
            stopOnlineReco = true;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_TIMEOUT:{
            std::cout << "在线识别超时（没有在规定时间内检测到语音输入）: " << result << std::endl;
            stopOnlineReco = true;
            break;
        }
        case AISDK_CMD_ONLINE_RECO_CANCELED:{
            std::cout << "用户取消，停止输入: " << result << std::endl;
            stopOnlineReco = true;
            break;
        }


        default:
            break;
    }

}
/**
 * 程序后面跟一个参数，指定读取的录音文件。
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    if(argc < 3) {
        std::cerr << "usage:\n tsdk_test wakeup.wav online.wav(16khz 16bit single channel wav file)" << std::endl;
        return -1;
    }

    wakeupVoiceFile = argv[1];  // 输入的测试唤醒识别音频文件
    onlineVoiceFile = argv[2];  // 输入的测试语音识别音频文件

    //设置回调函数
    aisdkSetCallback(callback);
    //初始化SDK
    int res = aisdkInit(".", "your_app_key", "your_access_token", "your_dsn");
    if(res != 0) {
        std::cerr << "init iva fail, err:" << res << std::endl;
        return -2;
    }
    //设置返回音量
    aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ENABLE_CALCULATE_VOLUME,AISDK_CONFIG_VALUE_ENABLE);
//    aisdkSetConfig(AISDK_CONFIG_VOICE_ONLINE_ENABLE_CLOUDVAD,AISDK_CONFIG_VALUE_DISABLE);

    // 初始化模型
    res = aisdkInitOneShot("vad", "keywords_model");
    if (res != 0) {
        std::cerr << "init oneshot fail, err: " << res << std::endl;
        return -2;
    }

    std::string cmd;
    while(true) {
        std::cout << "cmd>>> 1:测试OneShot;2:退出" << std::endl;
        std::cin >> cmd;
        int ran_num = rand() % 4;
        std::cout << "cmd:" << cmd << std::endl;
        if (cmd == "1")   {
            std::cout << "开始测试OneShot" << std::endl;
            aisdkStartOneShot(NULL, 0, 0);

        } else if (cmd == "2") {
            std::cout << "退出测试程序" << std::endl;
            aisdkStopOneShot();
            break;
        } else {
            std::cerr << "cmd:" << cmd << ", not match 1/2" << std::endl;
        }
        // 由于异步操作，主线程等待5s
        sleep(5);
    }
}
