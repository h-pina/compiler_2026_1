#ifndef LEXER_H
#define LEXER_H

#include "CharStream.h"
#include "Token.h"
#include "Logger.h"

class Lexer {
private:
    CharStream& m_cs;
    Logger m_logger;

    void skip();
    Token matchSymbols(char c);
    Token matchTokenFromPattern(char c);
    TokenType getIdentifierType(const std::string& lexeme);

public:
    static int lineCount;
    
    Lexer(CharStream& cs);
    Token getNextToken();
};

#endif