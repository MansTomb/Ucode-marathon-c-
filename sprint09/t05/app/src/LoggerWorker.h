#pragma once

#include <queue>
#include <fstream>

#include "Log.h"
#include "Worker.h"

class LoggerWorker final : public Worker {
 public:
    ~LoggerWorker() override;
    static LoggerWorker & getLogger();
    void log(Log::LogLevel level, const std::string& logMessage);
 private:
    struct LogMessage{
        std::string message;
        Log::LogLevel logLevel;
    };
    static std::string getTimeInLog();
    static std::string getTimeFileName();
    static std::string getLogLevel(Log::LogLevel level);
    LoggerWorker();
    void run() override;
    std::mutex m_runMutex;
    std::condition_variable m_condVar;
    std::ofstream m_logFileStream;
    std::queue<LogMessage> m_logQueue;
    inline static std::shared_ptr<LoggerWorker> m_logger{nullptr};
};
