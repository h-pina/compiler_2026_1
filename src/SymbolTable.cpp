/*
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include "Lexer.h"
#include "SymbolTable.h"


void SymbolTable::add(std::string lexeme, std::string type = "None", float value = 0.0){
	st_item newItem = {lexeme, type, value};
	const std::pair< std::unordered_map<std::string, 
									st_item>::iterator, bool > result =  symbolTable.insert({lexeme, newItem});
	if(!result.second){
		st_item existingItem = result.first->second;
		if(existingItem.type != type || existingItem.value != value){
			std::string erromsg = "Error in line " + std::to_string(Lexer::lineCount) + 
													"The symbol already has a entry for " + 
													lexeme + " which differs from the values you are trying to add";
			throw std::invalid_argument(erromsg);
		}
	}
}

void SymbolTable::update(std::string lexeme, std::string type = "None", float value = 0.0){
	st_item newItem = {lexeme, type, value};
	std::unordered_map<std::string, st_item>::iterator search = symbolTable.find(lexeme);
	if(search != symbolTable.end()){
		search->second = newItem;
		return;
	}

	std::string errormsg =  "Error in line " + std::to_string(Lexer::lineCount) + 
													"The lexeme" + lexeme +
													"does not exist on the symbol table. Could not update";
	throw std::invalid_argument(errormsg);
}

st_item SymbolTable::get(std::string lexeme){
	std::unordered_map<std::string, st_item>::iterator search = symbolTable.find(lexeme);
	if(search !=	symbolTable.end()){
		return search->second;
	}
	return entryNotFound;
}

void SymbolTable::print(){
	std::cout << padTo(std::string("Lexeme"),15)<< "|"\
						<< padTo(std::string("type"),15)<< "|"\
						<< padTo(std::string("value"),15) << std::endl;


	for(auto const& [key, value] : symbolTable){
		std::cout << padTo(value.lexeme, 15);
		std::cout << "|" <<padTo(value.type, 15);
		std::cout << "|" <<padTo(std::to_string(value.value), 19);
		std::cout << std::endl;
	}

}
*/