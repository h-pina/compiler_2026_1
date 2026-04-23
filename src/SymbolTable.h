#pragma once

#include <string>
#include <unordered_map>
#include <vector>

typedef struct st_item{
	std::string lexeme;
	std::string type;
	float value;
}st_item;

class SymbolTable {
	public:
		SymbolTable() = default;
		void add(std::string lexeme, std::string type, float value);
		void update(std::string lexeme, std::string type, float value);
		st_item get(std::string lexeme);
		void print(); //Function used for debbuging
		
	private:
		std::unordered_map<std::string,st_item> symbolTable;
		st_item entryNotFound = {"","",-1};
};