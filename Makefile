CXX = g++
CXXFLAGS = -Wall -Wextra

SRC = $(wildcard src/*.cpp)

TARGET = lexer 

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	./lexer

clean:
	rm -f $(TARGET)
