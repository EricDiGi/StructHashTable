/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: vigenere.hpp
  Assignment number : PROJECT 1

  File defines the Cypher class.
***************************************************************/
#ifndef Vigenere_HPP
#define Vigenere_HPP

#include <string>

class Cypher {
    public:
        std::string Encode(std::string key, std::string message);
        std::string Decode(std::string key, std::string encoded);
    private:
        char shift(char k, char m);
        char unshift(char k, char e);
};

#endif