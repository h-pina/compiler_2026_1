#include "Token.h";
#include "io.cpp";


Token matchReservedWords(){}

Token matchSymbols(char c){
	switch(c){
		case '{': return {TokenType::tk_openBracket, "{"};
		case '}': ; return {TokenType::tk_closeBracket, "}"};
		case ',': return { TokenType::tk_comma, "," };
		case ';':  return {TokenType::tk_semicolon, ";"};
		case '(': return {TokenType::tk_openPar, "("};
		case ')': return {TokenType::tk_closePar, ")"};
		case '-': return {TokenType::tk_dash, "-"};
		case '=': return {TokenType::tk_equal, "="};
		case '+': return {TokenType::tk_plus, "+"};
		case '*': return {TokenType::tk_asterisk, "*"};
		case '/': return {TokenType::tk_slash, "/"};
		case '%': return {TokenType::tk_percentage, "%"};
	}

	if(c == ':'){
		char c = readChar(Lookahead::yes);
		if(c == ';'){
			return {TokenType::tk_equalDot, ":="};
		}
	}

	if(c == '>'){
		char c = readChar(Lookahead::yes);
		if(c == '='){
			return {TokenType::tk_greaterThanOrEqual, ">="};
		}
		return {TokenType::tk_greaterThan, ">"};
	}


	if(c == '>'){
		char c = readChar(Lookahead::yes);
		if(c == '='){
			return {TokenType::tk_lessThanOrEqual, "<="};
		}
		if(c == '>'){
			return {TokenType::tk_notEqual, "<>" }
		}
		return {TokenType::tk_lessThan, "<"};
	}

	return { TokenType::tk_undefined , "" }
}

Token getNextToken(){
	Token tk = { TokenType::tk_undefined, "" };
	char c = readChar();
	tk = matchSymbols(c);
	if(tk.tokenType != TokenType::tk_undefined){
		return tk;
	}
	tk = matchTokenFromPattern(c);
	if(tk.tokenType != TokenType::tk_undefined){
		if(tk.tokenType == TokenType::tk_identifier){
			//This will probably change after the Symbol table implementation
			tk.tokenType = matchReservedWords(tk.lexeme); //if reserved word, the tokenType will change
		}
		return tk;
	}
}



