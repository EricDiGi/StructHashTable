  
CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: testHash

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o Hash core main

testHash: $(OBJECTS) testHash.cpp HashTable.cpp HashTable.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^
