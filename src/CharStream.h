#ifndef CHARSTREAM_H
#define CHARSTREAM_H

#include <fstream>
#include <deque>

class CharStream {
private:
		//dequeue allows for acess by index, which is important
		//for multiple buffered chars
    std::deque<int> buffered; 
    std::ifstream file;

		int getChar();

public:
    CharStream(const char* path);

    int peek(size_t position = 0);
    int get();
};

#endif
