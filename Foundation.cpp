/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: Foundation.cpp
  Assignment number : PROJECT 1

  File defines the Platform class. The Platform class is used
  to stitch system together allowing objects to communicate.
***************************************************************/
#include "Foundation.hpp"
#include "FileHandler.hpp"
#include "vigenere.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* PURPOSE : to handle and implement all necessary classes*/

void Platform::buildHashTable(){
    this->tab.build((int)this->buckets.length(), this->buckets);

    ifstream infile; string name; string epw;
    infile.open("encrypted.txt", ios::in);

    while(!infile.eof()){
        infile >> name >> epw;
        this->tab.insertEntry(name, epw);
    }
    if(infile.is_open())
        infile.close();
}

int Platform::LoadFileData(){
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
    this->buckets = f.buckets;
    return f.numBuckets(); 
}

//tests passsword equality
bool Platform::testPass(string uid, string pass){
    string relpass = this->tab.extract(uid);
    Cypher v;
    string unenc = v.Decode(uid, relpass);
    return (pass == unenc);
}