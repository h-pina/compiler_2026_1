#include "logger.h"

Logger::Logger(LogLevel level, LogType type, bool enabled) : level(level), type(type), enabled(enabled) {}

void Logger::info(const std::string& message) const {
    if (!enabled || level < LogLevel::Info) return;
    log(LogLevel::Info, message);
}
void Logger::warn(const std::string& message) const {
    if (!enabled || level <  LogLevel::Warning) return;
    log(LogLevel::Warning, message);
}
void Logger::err(const std::string& message) const {
    if (!enabled || level < LogLevel::Error) return;
    log(LogLevel::Error, message);
}
void Logger::debug(const std::string& message) const {
    if (!enabled || level < LogLevel::Debug) return;
    log(LogLevel::Debug, message);
}

void Logger::log(LogLevel level, const std::string& message) const {
    std::cout << "[" << logLevelToString(level) << "] [" << logTypeToString(type) << "] " << message << std::endl;
}

std::string Logger::logLevelToString(LogLevel level) const {
    switch(level) {
        case LogLevel::Info: return "Info";
        case LogLevel::Warning: return "Warning";
        case LogLevel::Error: return "Error";
        case LogLevel::Debug: return "Debug";
        default: return "Unknown";
    }
}

std::string Logger::logTypeToString(LogType type) const {
    switch(type) {
        case LogType::Lexer: return "Lexer";
        default: return "Unknown";
    }
}
