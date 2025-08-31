#pragma once
#include <filesystem>
#include <fstream>
#include <string>

#include "common.h"

namespace fs = std::filesystem;

namespace Imprint {
    enum class LogLevel {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };
    
    class Logger {
    public:
        Logger(std::string moduleName, LogLevel level = LogLevel::INFO, bool writeToFile = true);

        ~Logger() {
            if (fileStream.is_open()) {
                fileStream.close();
            }
        }

        void DEBUG(const std::string &msg);
        void INFO(const std::string &msg);
        void WARN(const std::string& msg);
        void ERROR(const std::string& msg);
        void FATEL(const std::string& msg);

    private:
        void log(LogLevel level, const std::string &msg);

        inline std::string levelToString(LogLevel level) {
            switch (level) {
                case LogLevel::DEBUG: return "DEBUG";
                case LogLevel::INFO: return "INFO";
                case LogLevel::WARN: return "WARN";
                case LogLevel::ERROR: return "ERROR";
                case LogLevel::FATAL: return "FATAL";
            }
            return "UNKNOWN";
        }

        inline std::string levelToColor(LogLevel level) {
            switch (level) {
                case LogLevel::DEBUG: return "\033[36m"; // 青色
                case LogLevel::INFO: return "\033[37m";  // 白色
                case LogLevel::WARN: return "\033[33m";  // 黄色
                case LogLevel::ERROR: return "\033[31m"; // 红色
                case LogLevel::FATAL: return "\033[1;31m"; // 亮红
            }
            return "\033[0m";
        }

        std::string moduleName_;
        LogLevel minLevel_ = LogLevel::INFO;
        fs::path logFilePath_;
        static std::ofstream fileStream;
    };
} // namespace Imprint