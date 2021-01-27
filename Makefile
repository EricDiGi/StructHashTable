CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: UserID testCypher testHash testFileRaw testFoundation testAll

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o core main

testCypher: $(OBJECTS) testBench.cpp vigenere.cpp vigenere.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

testHash: $(OBJECTS) testHash.cpp HashTable.cpp HashTable.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

testFileRaw: $(OBJECTS) testFileRaw.cpp FileHandler.cpp FileHandler.hpp vigenere.cpp vigenere.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

testFoundation: $(OBJECTS) testFoundation.cpp Foundation.cpp Foundation.hpp HashTable.cpp HashTable.hpp FileHandler.cpp FileHandler.hpp vigenere.cpp vigenere.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

testAll: $(OBJECTS) UserId.cpp Foundation.cpp Foundation.hpp HashTable.cpp HashTable.hpp FileHandler.cpp FileHandler.hpp vigenere.cpp vigenere.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

UserID: $(OBJECTS) UserId.cpp Foundation.cpp Foundation.hpp HashTable.cpp HashTable.hpp FileHandler.cpp FileHandler.hpp vigenere.cpp vigenere.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^