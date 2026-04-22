#include "charStream.h"

CharStream::CharStream(const char* path) {
    file.open(path);

    // TODO: throw exception if file can't open
}

int CharStream::peek(size_t offset) {
    while (buffered.size() <= offset) {
        char c;
        if (!file.get(c)) {
            return EOF;
        }
        buffered.push_back(c);
    }

    return buffered[offset];
}

int CharStream::get() {
    if (!buffered.empty()) {
        char c = buffered.front();
        buffered.pop_front();
        return c;
    }

    char c;
    if (!file.get(c)) {
        return EOF;
    }

    return c;
}
