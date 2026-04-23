#include "LexerException.h"

LexerException::LexerException(const std::string& msg)
    : message(msg) {}

const char* LexerException::what() const noexcept {
    return message.c_str();
}
