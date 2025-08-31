#include <chrono>
#include <iostream>

#include "logger.h"

namespace Imprint {
    std::ofstream Logger::fileStream;

    Logger::Logger(std::string moduleName, LogLevel level, bool writeToFile)
        : moduleName_(moduleName), minLevel_(level) {
        
        if (!writeToFile || fileStream.is_open()) {
            return;
        }

        fs::path logFileDir = Common::GetAppDir() / "logs";
        if (!fs::exists(logFileDir)) {
            fs::create_directories(logFileDir);
        }

        auto now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        std::stringstream timeSs;
        timeSs << "log_" << std::put_time(std::localtime(&tt), "%Y%m%d_%H%M%S") << ".log";

        logFilePath_ = logFileDir / timeSs.str();
        fileStream.open(logFilePath_);
        if (!fileStream.is_open()) {
            std::cerr << "Failed to open log file: " << logFilePath_ << std::endl;
        }
    }

    void Logger::DEBUG(const std::string& msg) { 
        log(LogLevel::DEBUG, msg); 
    }

    void Logger::INFO(const std::string& msg) { 
        log(LogLevel::INFO, msg); 
    }

    void Logger::WARN(const std::string& msg) { 
        log(LogLevel::WARN, msg); 
    }

    void Logger::ERROR(const std::string& msg) { 
        log(LogLevel::ERROR, msg); 
    }

    void Logger::FATEL(const std::string& msg) {
        log(LogLevel::FATAL, msg); 
    }

    void Logger::log(LogLevel level, const std::string& msg) {
        if (level < minLevel_) {
            return;
        }

        std::string levelStr = levelToString(level);
        std::string color    = levelToColor(level);

        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);

        std::stringstream timeSs;
        timeSs << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");

        std::string logLine = "[" + timeSs.str() + "] | [" + moduleName_ + "] | [" + levelStr + "] | " + msg;

        // 控制台输出（带颜色）
        std::cout << color << logLine << "\033[0m" << std::endl;

        // 写文件（无颜色）
        fileStream << logLine << std::endl;
    }
} // namespace Imprint