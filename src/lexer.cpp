#include "lexer.h"
#include <cctype>

Lexer::Lexer(CharStream& cs)
    : m_cs(cs)
{}


void Lexer::skip() {
    while (true) {
        // Skip whitespace
        while (std::isspace(m_cs.peek())) {
            m_cs.get();
        }

        // Skip line comments: //
        if (m_cs.peek() == '/' && m_cs.peek(1) == '/') {
            while (m_cs.peek() != '\n' && m_cs.peek() != EOF) {
                m_cs.get();
            }
            continue;
        }

        // Skip block comments: /* ... */
        if (m_cs.peek() == '/' && m_cs.peek(1) == '*') {
            m_cs.get(); // consume '/'
            m_cs.get(); // consume '*'

            while (!(m_cs.peek() == '*' && m_cs.peek(1) == '/')) {
                if (m_cs.peek() == EOF) {
                    // Unterminated block comment
                    return;
                }
                m_cs.get();
            }

            m_cs.get(); // consume '*'
            m_cs.get(); // consume '/'

            continue;
        }

        break;
    }
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
    if (std::isalpha(c) || c == '_') {
        std::string lexeme;
        lexeme.push_back(c);

        while (std::isalnum(m_cs.peek()) || m_cs.peek() == '_') {
            lexeme.push_back(m_cs.get());
        }

        return {TokenType::tk_identifier, lexeme};
    }

    // Number
    if (std::isdigit(c)) {
        std::string lexeme;
        lexeme.push_back(c);

        while (std::isdigit(m_cs.peek())) {
            lexeme.push_back(m_cs.get());
        }

        return {TokenType::tk_integerConst, lexeme};
    }

    // String literal
    if (c == '"') {
        std::string lexeme;

        while (m_cs.peek() != '"' && m_cs.peek() != EOF) {
            lexeme.push_back(m_cs.get());
        }

        if (m_cs.peek() == '"') {
            m_cs.get(); // consume closing quote
            return {TokenType::tk_literal, lexeme};
        }

        // Unterminated string
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

    return {TokenType::tk_undefined, std::string(1, c)};
}
