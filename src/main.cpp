#include "CharStream.h"
#include "Lexer.h"
#include "DebugUtils.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    CharStream cs(argv[1]);
    Lexer lexer(cs);

    Token tk = lexer.getNextToken();
    while (tk.tokenType != TokenType::tk_eof) {
        DebugUtils::printToken(tk);
        tk = lexer.getNextToken();
    }
    return 0;
}
