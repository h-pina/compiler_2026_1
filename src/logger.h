#ifndef LOGGER_H
#define LOGGER_H

#include "Token.h"
#include <iostream>
#include <string>

namespace Logger{
		std::string getTokenType(TokenType tkType);
		void printToken(Token tk);
}

#endif 
