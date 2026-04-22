#include "lexer.h"
#include "Token.h"
#include "logger.h"
#include <cctype>
#include <cinttypes>
#include <unordered_map>

int Lexer::lineCount = 1;

Lexer::Lexer(CharStream& cs)
    : m_cs(cs), 
			m_logger(LogLevel::Debug, LogType::Lexer, true)
{}

void Lexer::skip() {
    while (true) {
        // Skip whitespace first 
        while (std::isspace(m_cs.peek())) {
						if(m_cs.peek() == '\n') lineCount++;
            m_cs.get();
        }

        // Check for single line comments
        if (m_cs.peek() == '/' && m_cs.peek(1) == '/') {
            while (m_cs.peek() != '\n' && m_cs.peek() != EOF) {
                m_cs.get();
            }
            continue;
        }

        // Check for block comments
        if (m_cs.peek() == '/' && m_cs.peek(1) == '*') {
            m_cs.get(); //get'/'
            m_cs.get(); //get'*'

            while (!(m_cs.peek() == '*' && m_cs.peek(1) == '/')) {
                if (m_cs.peek() == EOF) return;
                m_cs.get();
            }

            m_cs.get(); //get'*'
            m_cs.get(); //get'/'

            continue;
        }

        break; //if none is found, the skip() is done
    }
    
}

TokenType Lexer::getIdentifierType(const std::string& lexeme) {
    static const std::unordered_map<std::string, TokenType> keywords = {
        {"class", TokenType::tk_class},
        {"int", TokenType::tk_int},
        {"string", TokenType::tk_string},
        {"float", TokenType::tk_float},
        {"if", TokenType::tk_if},
        {"else", TokenType::tk_else},
        {"do", TokenType::tk_do},
        {"while", TokenType::tk_while},
        {"repeat", TokenType::tk_repeat},
        {"until", TokenType::tk_until},
        {"read", TokenType::tk_read},
        {"write", TokenType::tk_write},
        {"not", TokenType::tk_not},
        {"or", TokenType::tk_or},
        {"and", TokenType::tk_and},
    };

    auto it = keywords.find(lexeme);
    if (it != keywords.end()) {
        return it->second;
    }

    return TokenType::tk_identifier;
}

Token Lexer::matchSymbols(char c) {
    switch(c) {
        case '{': return {TokenType::tk_openBracket, "{"};
        case '}': return {TokenType::tk_closeBracket, "}"};
        case ',': return {TokenType::tk_comma, ","};
        case ';': return {TokenType::tk_semicolon, ";"};
        case '(': return {TokenType::tk_openPar, "("};
        case ')': return {TokenType::tk_closePar, ")"};
        case '-': return {TokenType::tk_dash, "-"};
        case '=': return {TokenType::tk_equal, "="};
        case '+': return {TokenType::tk_plus, "+"};
        case '*': return {TokenType::tk_asterisk, "*"};
        case '/': return {TokenType::tk_slash, "/"};
        case '%': return {TokenType::tk_percentage, "%"};
    }

    if (c == ':') {
        if (m_cs.peek() == '=') {
            m_cs.get();
            return {TokenType::tk_equalDot, ":="};
        }
    }

    if (c == '>') {
        if (m_cs.peek() == '=') {
            m_cs.get();
            return {TokenType::tk_greaterThanOrEqual, ">="};
        }
        
        return {TokenType::tk_greaterThan, ">"};
    }

    if (c == '<') {
        if (m_cs.peek() == '=') {
            m_cs.get();
            return {TokenType::tk_lessThanOrEqual, "<="};
        }

        if (m_cs.peek() == '>') {
            m_cs.get();
            return {TokenType::tk_notEqual, "<>"};
        }
        
        return {TokenType::tk_lessThan, "<"};
    }

    
    return {TokenType::tk_undefined, ""};
}

Token Lexer::matchTokenFromPattern(char c) {
    
    // Identifier
    if (std::isalpha(c)) {
        std::string lexeme;
        lexeme.push_back(c);

        while (std::isalnum(m_cs.peek())) {
            lexeme.push_back(m_cs.get());
        }
        
        auto type = getIdentifierType(lexeme);
        return {type, lexeme};
    }

    //Numbers
    if (std::isdigit(c)) {
				TokenType tkType = TokenType::tk_integerConst;
        std::string lexeme;
        lexeme.push_back(c);

				if(c != '0'){
					while (std::isdigit(m_cs.peek())) {
						lexeme.push_back(m_cs.get());
					}
				}

				if(m_cs.peek() == '.'){
					lexeme.push_back(m_cs.get());
					while (std::isdigit(m_cs.peek())) {
							lexeme.push_back(m_cs.get());
							tkType = TokenType::tk_float;
					}
				}
        
        return {tkType, lexeme};
    }

    //literals
    if (c == '"') {
        std::string lexeme;

        while (m_cs.peek() != '"') {
						if(m_cs.peek() == EOF){
							return {TokenType::tk_eof, ""};
						}
            lexeme.push_back(m_cs.get());
        }

        if (m_cs.peek() == '"') {
            m_cs.get(); // ignore closing quote
            return {TokenType::tk_literal, lexeme};
        }
        
        return {TokenType::tk_undefined, lexeme};
    }
    
    return {TokenType::tk_undefined, ""};
}

Token Lexer::getNextToken() {
    skip();

    int c = m_cs.get();

    if (c == EOF) {
        return {TokenType::tk_eof, ""};
    }

    Token tk = matchSymbols(c);
    if (tk.tokenType != TokenType::tk_undefined) {
        return tk;
    }

    tk = matchTokenFromPattern(c);
    if (tk.tokenType != TokenType::tk_undefined) {
        return tk;
    }

    return {TokenType::tk_undefined, std::string(1, (char)c)};
}
