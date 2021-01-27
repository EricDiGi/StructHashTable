/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testFileRaw.cpp
  Assignment number : PROJECT 1

  Ensure File operations work as expected.
***************************************************************/
#include <iostream>
#include "FileHandler.hpp"

using namespace std;

int main(){
    Handle f;
    bool ready = f.ready(1);
    bool set = f.set(1);
    if((ready == true) && set){
        f.go(1);
    }
    ready = f.ready(2);
    set = f.set(2);
    if((ready == true) && set){
        f.go(2);
    }
    cout << "DONE" << endl;
    cout << f.numBuckets() << endl;
}