/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: UserId.cpp
  Assignment number : PROJECT 1

  Implements the code necessary to run the operations described
  in the project description.
  Outputs the first 5 lines of the lastNames.txt with matching
  passwords and again with passwords with 1 char changed.
***************************************************************/
#include "Foundation.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

string alterPass(string pass){
    char o = (pass.at(8) - 96)%26 + 97;
    pass.at(8) = o;
    return pass;
}

string swapBool(bool v){
    if(v)
        return "MATCH";
    return "XXXXX";
}

int main(){
    Platform p;
    p.LoadFileData();
    p.buildHashTable();

    cout << "LEGAL PAIRS:\nUserId\t\tPassword\tResult\n";
    //Load valid pairs from raw file
    int iter = 0;
    ifstream raw;
    raw.open("raw.txt", ios::in);
    string uid; string pass;
    while(iter <= 4){
        raw >> uid >> pass;
        cout << uid << "\t\t" << pass << "\t" << swapBool(p.testPass(uid,pass)) << "\n";
        iter++;
    }
    raw.close();

    //Test invalid pairs i made up
    cout << "\nILLEGAL PAIRS:\nUserId\t\tPassword\tResult\n";
    raw.open("raw.txt", ios::in);
    iter = 0;
    while(iter <= 4){
        raw >> uid >> pass;
        pass = alterPass(pass);
        cout << uid << "\t\t" << pass << "\t" << swapBool(p.testPass(uid,pass)) << "\n";
        iter++;
    }
    raw.close();
}