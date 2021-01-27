/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testFoundation.cpp
  Assignment number : PROJECT 1

  Used as a test bench for the Platform class. 
***************************************************************/
#include "Foundation.hpp"
#include <iostream>

using namespace std;

int main(){
    Platform p;
    p.LoadFileData();
    p.buildHashTable();
    cout << p.tab << endl;
}