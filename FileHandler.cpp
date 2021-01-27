/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: FileHandler.cpp
  Assignment number : PROJECT 1

  File defines the Handle class. Handle class is used to read
  and manipulate text file data. Also aids in defining the 
  dimensions of the Hash Table.
***************************************************************/
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "FileHandler.hpp"
#include "vigenere.hpp"

using namespace std;

//Check the any files are closed
Handle::~Handle(){
    if(this->infile.is_open())
        this->infile.close();
    if(this->ofile.is_open())
        this->ofile.close();
}

void Handle::close(){
    if(this->infile.is_open())
        this->infile.close();
    if(this->ofile.is_open())
        this->ofile.close();
}

//open required file for reading
bool Handle::ready(int opt){
    if(opt <= 1){
        this->infile.open("lastNames.txt", ios::in);
        return this->infile.is_open();
    }
    if(opt >= 2){
        this->infile.open("raw.txt", ios::in);
        return this->infile.is_open();
    }
    return false;
}

//open required file for writing
bool Handle::set(int opt){
    if(opt <= 1){
        this->ofile.open("raw.txt", ios::out);
        return this->ofile.is_open();
    }
    if(opt >= 2){
        this->ofile.open("encrypted.txt", ios::out);
        return this->ofile.is_open();
    }
    return false;
}

//create password
string Handle::makePass(){
    string pass = "";
    for(int i = 0 ; i < 9; i++){
        pass += (char)(rand()%26 + 97);
    }
    return pass;
}

//convert strings to lowercase
string Handle::toLower(string in){
    string NEW = "";
    for(int i = 0; i < (int)in.length(); i++){
        if((char)in.at(i) < 97){
            NEW += (char)in.at(i) + ('z' - 'Z');
        }
        else{
            NEW += in.at(i);
        }
    }
    return NEW;
}

//process data into proper format and write to file
void Handle::go(int opt){
    if(opt <= 1){
        this->buckets = "";
        string lname; double a; int  b;
        string llname;
        while(!this->infile.eof()){
            infile >> lname >> a >> a >> b;
            llname = toLower(lname);
            if(!in(llname)){
                this->buckets += llname.at(0);
            }
            ofile << llname << "\t" << makePass() << "\n";
        }
        close();
    }
    if(opt >= 2){
        Cypher v;
        string lname; string pword; string enc;
        while(!this->infile.eof()){
            infile >> lname >> pword;
            enc = v.Encode(lname, pword);
            ofile << lname << "\t" << enc << "\n";
        }
        close();
    }
    close();
}

//identify bucket for data entry, see if we recorded it yet.
bool Handle::in(string c){
    if(this->buckets.find(c.at(0)) == std::string::npos){
        return false;
    }
    return true;
}
/* THIS SOLVES HAVING TOO MANY OR TOO FEW BUCKETS */

int Handle::numBuckets(){
    return (int)this->buckets.length();
}