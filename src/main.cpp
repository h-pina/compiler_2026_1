#include "charStream.h"
#include "lexer.h"
#include "debugUtils.h"

int main() {
		CharStream cs("./tests/test4.txt");
		Lexer lexer(cs);
		
		Token tk = lexer.getNextToken();
		while (tk.tokenType != TokenType::tk_eof){
				DebugUtils::printToken(tk);
				tk = lexer.getNextToken();
		}
    return 0;
}
