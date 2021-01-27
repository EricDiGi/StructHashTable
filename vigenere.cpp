/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: vigenere.cpp
  Assignment number : PROJECT 1

  File defines the Cypher class. Cypher is an abstract class 
  used to run encoding and decoding operations on strings.
***************************************************************/
#include <iostream>
#include <string>
#include "vigenere.hpp"

using namespace std;

string Cypher::Encode(string key, string message){
    string encode = "";
    for(int i = 0; i < (int)message.length(); i++){
        encode += shift(key.at(i%(int)key.length()),message.at(i)); 
        //keys are often shorter than messages// use i%key_len to role back
    }
    return encode;
}

string Cypher::Decode(string key, string encoded){
    string decode = "";
    for(int i = 0; i < (int)encoded.length(); i++){
        decode += unshift(key.at(i%(int)key.length()), encoded.at(i)); 
        //keys are often shorter than messages// use i%key_len to role back
    }
    //cout << key << "\t" << decode << "\t" << encoded << endl;
    return decode;
}

char Cypher::shift(char k, char m){
    int K = (int) k - 97;
    int M = (int) m - 97;
    int C = ((M + K) % 26) + 97;
    return C;
}

char Cypher::unshift(char k, char e){
    int K = (int) k - 97;
    int E = (int) e - 97;
    int M = ((E - K + 26) % 26) + 97;
    return M;
}