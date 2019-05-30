/**
 * @file
 * @author kangrong
 * @date 2017/8/28
 * @brief 示例代码：tts
 * @version 0.1.0
 * @note
 */

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include "aisdk_common_api.h"
#include "aisdk_tts_online.h"
using namespace std;

string ttsCache;

int getCode(string data){

    size_t  location=data.find("\"code\"");
    if(location!=string::npos){
        cout<<"code location"<<location<<endl;
        string rcStr=data.substr(location+7,1);
        return rcStr[0]-'0';

    }
    cerr<<" 没有找到code"<<endl;
    return -1;
}

int getRc(string data){

    size_t  location=data.find("\"rc\"");
    if(location!=string::npos){
        cout<<"rc location"<<location<<endl;
        string rcStr=data.substr(location+5,1);
        return rcStr[0]-'0';

    }
    cerr<<" 没有找到rc"<<endl;
    return -1;
}
void callback(int cmd, char* data, int dataLen, void* userData, int userDataLen, void *extra, int extraLen)
{
    // 任何情况下，不要阻塞回调线程。
    string result(data, dataLen);
    cout << "callback cmd: " << cmd <<" userDataLen:"<<userDataLen <<" extraLen:"<<extraLen << endl;

    switch(cmd) {
        case AISDK_CMD_TTS_RESULT: {// TTS数据返回
            if(dataLen == 0) {
                std::cerr << "tts data receive fail." << std::endl;
                return;
            }
            int rc=getRc(result);
            if (rc == 0) {
                std::cout << "TTS数据返回数据包." << std::endl;
                //取得code
                int code = getCode(result);
                //tts数据片段。tts语音数据从extra返回。
                string ttsSeg((char *)extra,extraLen);
                if (code == AISDK_RESULT_CODE_TTS_DATA) {
                    std::cout << "TTS数据返回一个中间数据包." << std::endl;
                    ttsCache.append(ttsSeg);
                } else if (code == AISDK_RESULT_CODE_TTS_LAST_DATA) {
                    std::cout << "TTS数据返回最后一个数据包." << std::endl;
                    ttsCache.append(ttsSeg);
                    std::cout << "TTS总的数据包大小： " << ttsCache.size() << std::endl;
                    std::ofstream ttsFile;
                    ttsFile.open("tts.pcm", std::ios::binary);
                    ttsFile.write(ttsCache.c_str(),ttsCache.size());
                    ttsFile.close();
                    ttsCache.clear();
                }else{
                    std::cout << "something error." << std::endl;
                }
            }

            break;
        }
        case AISDK_CMD_TTS_ERROR:{
            std::cerr << "tts返回失败." << std::endl;
            break;
        }
        default:
            break;
    }

}

int main(int argc, char *argv[])
{

    //设置回调函数
    aisdkSetCallback(callback);
    //初始化
    int res = aisdkInit(".", "your_app_key", "your_access_token", "your_dsn");
    aisdkSetConfig(AISDK_CONFIG_ENV_TYPE,AISDK_CONFIG_VALUE_ENV_TYPE_FORMAL);
    aisdkSetConfig(AISDK_CONFIG_TTS_TYPE,AISDK_CONFIG_VALUE_TTS_TYPE_WAV);
    //可以设置TTS引擎。
    //aisdkSetConfig(AISDK_CONFIG_TTS_ENGINE,"2");
    std::string cmd;
    while(true) {
        std::cout << "cmd>>> 1:TTS 2:退出" << std::endl;
        std::cin >> cmd;
        int ran_num = rand() % 4;
        std::cout << "cmd:" << cmd << std::endl;
        if (cmd == "1"){
            std::cout << "开始测试TTS" << std::endl;
            // test tts
            std::string text = "水满田畴稻叶齐，日光穿树晓烟低，";
            void* ttsData;
            aisdkText2Speech(text.c_str(), text.size(), ttsData, 3); // 文字转语音

        } else if (cmd == "2") {
            std::cout << "退出测试程序" << std::endl;
            break;
        } else {
            std::cerr << "cmd:" << cmd << ", not match 1/2/3/4/5" << std::endl;
        }

        sleep(5);   // 由于异步操作，主线程等待5s
    }
}