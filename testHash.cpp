/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testHash.cpp
  Assignment number : PROJECT 1

  File is used as a test bench for the Hash class and its
  constituents.
***************************************************************/
#include "HashTable.hpp"
#include <iostream>

using namespace std;

int main(){
    HashTable tab;
    tab.build(3,"abc");
    tab.insertEntry("alfred", "aaaaaa");
    tab.insertEntry("ajax", "AAAAAA");
    tab.insertEntry("batman", "bbbbbb");
    tab.insertEntry("carr", "cccccc");
    cout << tab;
}