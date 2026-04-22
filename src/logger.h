#ifndef LOGGER_H
#define LOGGER_H

#include "Token.h"
#include <iostream>
#include <string>

enum class LogLevel {
    Error,
    Warning,
    Info,
    Debug
};
enum class LogType {
    Lexer,
};

class Logger {
    public:
        explicit Logger(LogLevel level, LogType type, bool enabled);
        void info(const std::string& message) const;
        void warn(const std::string& message) const;
        void err(const std::string& message) const;
        void debug(const std::string& message) const;
    private:
        LogLevel level;
        LogType type;
        bool enabled;
        void log(LogLevel level, const std::string& message) const;
        std::string logLevelToString(LogLevel level) const;
        std::string logTypeToString(LogType type) const;
};

#endif
