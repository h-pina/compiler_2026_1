#ifndef LEXER_H
#define LEXER_H

#include "charStream.h"
#include "Token.h"

class Lexer {
private:
    CharStream& m_cs;

    void skip();
    Token matchSymbols(char c);
    Token matchTokenFromPattern(char c);

public:
    Lexer(CharStream& cs);
    Token getNextToken();
};

#endif
