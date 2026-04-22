#include "charStream.h"

CharStream::CharStream(const char* path) {
    file.open(path);
}

//Look what {position} characters ahead
int CharStream::getChar(){
    char c;
    if (!file.get(c)) {
        return EOF;
    }
		return c;
}

int CharStream::peek(size_t position) {
    while (buffered.size() <= position) {
        int c = getChar();
        buffered.push_back(c);
    }

    return buffered[position];
}

int CharStream::get() {
    if (!buffered.empty()) {
        int c = buffered.front();
        buffered.pop_front();
        return c;
    }

		int c = getChar();

    return c;
}
