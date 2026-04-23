#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H

#include "Token.h"
#include <string>
#include <iostream>

namespace DebugUtils {
    std::string getTokenType(TokenType tkType);
    void printToken(const Token& tk);
}

#endif