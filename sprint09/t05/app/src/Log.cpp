#include "Log.h"
#include "LoggerWorker.h"

Log::~Log() {
    LoggerWorker& worker = LoggerWorker::getLogger();
    std::istreambuf_iterator<char> eos;
    std::string message(std::istreambuf_iterator<char>(m_inputStream), eos);
    worker.log(m_logLevel, message);
}

Log Log::createLog(Log::LogLevel level) {
    return Log(level);
}

Log::Log(Log::LogLevel level) : m_logLevel(level) {}
