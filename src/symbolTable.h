#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <unordered_map>
#include <string>
#include "Token.h"

struct StEntry{
		std::string lexeme;
		TokenType tokenType;
};

class SymbolTable{
		private:
				std::unordered_map<std::string, StEntry> symbolTable;

		public:
				void insert(StEntry entry);
				void get(std::string lexeme);
};


#endif
