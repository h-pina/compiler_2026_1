#include <iostream>
#include <queue>
#include <vector>

//lookahead 
std::queue<char> lookAheadQueue;
enum class Lookahead { yes, no};

char readChar(Lookahead l = Lookahead::no){
	char c;
	if(l == Lookahead::yes){
		lookAheadQueue.push(c);
		return c;
	}

	//if there is something in the lookaheadQueue, return it, else read it
	return c;
}


//Just some sketching
void readFileContents(const char* path){}
