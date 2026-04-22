#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
	//reserved words
	tk_class,
	tk_int,
	tk_string,
	tk_float,
	tk_if,
	tk_else,
	tk_do,
	tk_while,
	tk_repeat,
	tk_until,
	tk_read,
	tk_write,
	tk_not,
	tk_or,
	tk_and,

	//symbols 
	tk_openBracket,
	tk_closeBracket,
	tk_comma,
	tk_semicolon,
	tk_equalDot,
	tk_openPar,
	tk_closePar,
	tk_dash,
	tk_greaterThan,
	tk_greaterThanOrEqual,
	tk_lessThan,
	tk_lessThanOrEqual,
	tk_notEqual,
	tk_equal,
	tk_plus,
	tk_minus, //TODO: minus and dash are the same?
	tk_asterisk,
	tk_slash,
	tk_percentage,

	//other
	tk_integerConst,
	tk_realConst,
	tk_literal,
	tk_identifier,

	//invalid 
	tk_undefined,
	tk_eof,
};

struct Token{
	TokenType tokenType;
	std::string lexeme;
};

#endif
