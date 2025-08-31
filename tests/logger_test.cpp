#include "logger.h"
#include <iostream>

int main() {
    // 创建 Logger 实例
    Imprint::Logger logger("LoggerTest", Imprint::LogLevel::DEBUG);

    // 测试各种日志级别
    logger.DEBUG("This is a debug message");
    logger.INFO("This is an info message");
    logger.WARN("This is a warning message");
    logger.ERROR("This is an error message");
    logger.FATEL("This is a fatal message");

    std::cout << "Logger test completed. Check console output and log files." << std::endl;
    
    return 0;
}