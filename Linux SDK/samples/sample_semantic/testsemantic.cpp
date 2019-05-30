/**
 * @file
 * @author kangrong
 * @date 2017/8/28
 * @brief 示例代码：语义
 * @version 0.1.0
 * @note
 */

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sstream>

#include "aisdk_common_api.h"
#include "aisdk_semantic_online.h"

using namespace std;

char* onlineVoiceFile;
char* offlineVoiceFile;
string ttsCache;
bool stopOnlineReco = false;
bool stopOfflineReco = false;
void callback(int cmd, char* data, int dataLen, void* userData, int userDataLen, void *extra, int extraLen)
{
    // 任何情况下，不要阻塞回调线程。
    string result(data, dataLen);
    cout << "callback cmd: " << cmd  << endl;

    switch(cmd) {

        case AISDK_CMD_SEMANTIC_RESULT: {
            std::cout << "语义识别返回结果, result: " << result << std::endl;
            break;
        }
        case AISDK_CMD_SEMANTIC_ERROR:{
            std::cout << "语义识别出错 "  << std::endl;
            break;
        }

        case AISDK_CMD_COMPLEX_SEMANTIC_RESULT:{
            std::cout << "复合语义返回结果 "  <<result<< std::endl;
            break;
        }
        case AISDK_CMD_COMPLEX_SEMANTIC_ERROR:{
            std::cout << "复合语义返回错误 "  << std::endl;
            break;
        }
        case AISDK_CMD_MEDIA_SEMANTIC_RESULT:{
            std::cout << "媒体语义返回结果 "<<result  << std::endl;
            break;
        }
        case AISDK_CMD_MEDIA_SEMANTIC_ERROR:{
            std::cout << "媒体语义返回错误 "  << std::endl;
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
    //初始化SDK
    int res = aisdkInit(".", "your_app_key", "your_access_token", "your_dsn");
    if(res != 0) {
        std::cerr << "init iva fail, err:" << res << std::endl;
        return -2;
    }


    std::string cmd;
    while(true) {
        std::cout << "cmd>>> 1:在线语义；2:在线语义(清除上一次请求上下文)；3:退出" << std::endl;
        std::cin >> cmd;
        std::cout << "cmd:" << cmd << std::endl;
        if(cmd == "1") {
            std::cout << "开始测试语义" << std::endl;

            std::string text("上一首\0");
            void* onlineTextData;

            aisdkOnlineText2Semantic(text.c_str(), text.size(), onlineTextData, 3,0);

        } else if(cmd == "2") {
            std::cout << "开始测试语义(清除上一次请求上下文)" << std::endl;

            std::string text("上一首\0");
            void* onlineTextData;

            aisdkOnlineText2Semantic(text.c_str(), text.size(), onlineTextData, 3,AISDK_FLAG_SEMANTIC_CLEAR_PREV_SESSION);

        }else if (cmd == "3") {
            std::cout << "退出测试程序" << std::endl;
            break;
        } else {
            std::cerr << "cmd:" << cmd << ", not match 1/2" << std::endl;
        }

        sleep(5);   // 由于异步操作，主线程等待5s
    }
}