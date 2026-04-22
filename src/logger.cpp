#include "logger.h"

std::string Logger::getTokenType(TokenType tkType){
	switch(tkType){
			case TokenType::tk_int: return "tk_int";
			case TokenType::tk_string: return "tk_string";
			case TokenType::tk_float: return "tk_float";
			case TokenType::tk_if: return "tk_if";
			case TokenType::tk_else: return "tk_else";
			case TokenType::tk_do: return "tk_do";
			case TokenType::tk_while: return "tk_while";
			case TokenType::tk_repeat: return "tk_repeat";
			case TokenType::tk_until: return "tk_until";
			case TokenType::tk_read: return "tk_read";
			case TokenType::tk_write: return "tk_write";
			case TokenType::tk_not: return "tk_not";
			case TokenType::tk_or: return "tk_or";
			case TokenType::tk_and: return "tk_and";
			case TokenType::tk_openBracket: return "tk_openBracket";
			case TokenType::tk_closeBracket: return "tk_closeBracket";
			case TokenType::tk_comma: return "tk_comma";
			case TokenType::tk_semicolon: return "tk_semicolon";
			case TokenType::tk_equalDot: return "tk_equalDot";
			case TokenType::tk_openPar: return "tk_openPar";
			case TokenType::tk_closePar: return "tk_closePar";
			case TokenType::tk_dash: return "tk_dash";
			case TokenType::tk_greaterThan: return "tk_greaterThan";
			case TokenType::tk_greaterThanOrEqual: return "tk_greaterThanOrEqual";
			case TokenType::tk_lessThan: return "tk_lessThan";
			case TokenType::tk_lessThanOrEqual: return "tk_lessThanOrEqual";
			case TokenType::tk_notEqual: return "tk_notEqual";
			case TokenType::tk_equal: return "tk_equal";
			case TokenType::tk_plus: return "tk_plus";
			case TokenType::tk_minus: return "tk_minus" ;
			case TokenType::tk_asterisk: return "tk_asterisk";
			case TokenType::tk_slash: return "tk_slash";
			case TokenType::tk_percentage: return "tk_percentage";
			case TokenType::tk_integerConst: return "tk_integerConst";
			case TokenType::tk_realConst: return "tk_realConst";
			case TokenType::tk_literal: return "tk_literal";
			case TokenType::tk_identifier: return "tk_identifier";
			default: return "tk_undefined";
	}
}

void Logger::printToken(Token tk){
	std::cout << "Token<" << getTokenType(tk.tokenType) << ", " << tk.lexeme << ">\n";
}
