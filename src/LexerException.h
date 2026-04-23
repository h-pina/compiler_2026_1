#ifndef LEXER_EXCEPTION_H
#define LEXER_EXCEPTION_H

#include <exception>
#include <string>

class LexerException : public std::exception {
private:
    std::string message;

public:
    explicit LexerException(const std::string& msg);

    const char* what() const noexcept override;
};

#endif
