#ifndef CHARSTREAM_H
#define CHARSTREAM_H

#include <fstream>
#include <deque>

class CharStream {
private:
    std::ifstream file;
    std::deque<char> buffered;

public:
    CharStream(const char* path);

    int peek(size_t offset = 0);
    int get();
};

#endif
