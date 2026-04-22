#include "charStream.h"
#include "lexer.h"
#include "logger.h"

int main() {
		CharStream cs("./tests/test.txt");
		Lexer lexer(cs);
		
		Token tk = lexer.getNextToken();
		while (tk.tokenType != TokenType::tk_eof){
				Logger::printToken(tk);
    }
    return 0;
}
