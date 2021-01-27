/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testBench.cpp
  Assignment number : PROJECT 1

  Test that Cypher is encoding and decoding correctly.
***************************************************************/
#include <iostream>
#include <string>
#include "vigenere.hpp"

using namespace std;

int main(){
    cout << "OUTPUT:\n";
    Cypher c;
    cout << c.Encode("jones", "data") << endl;
    cout << c.Decode("jones", "moge") << endl;
}