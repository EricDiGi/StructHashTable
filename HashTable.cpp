#include <iostream>
#include <string>

#include "HashTable.hpp"

using namespace std;


HashTable::HashTable(){
    this->buckets = 0;
    this->table = new LinkedList[0];
}

HashTable::~HashTable(){
    delete[] this->table;
}

void HashTable::build(int num, string buckets){
    this->buckets = num;
    this->table = new LinkedList[num];
    for(int i = 0; i < num; i++){
        this->table[i].bucketId = buckets[i];
    }
}

string HashTable::extract(string key){
    for(int i = 0; i < this->buckets; i++){
        if(this->table[i].bucketId.at(0) == key.at(0)){
            return this->table[i].find(key);
        }
    }
    return "NULL";
}

void HashTable::insertEntry(string uid, string pword){
        for(int i = 0; i < this->buckets; i++){
            if(uid.at(0) == this->table[i].bucketId.at(0)){
                this->table[i].push(uid, pword);
            }
        }
}

LinkedList::LinkedList(){
    this->head = NULL;
    this->bucketId = "0";
}

LinkedList::LinkedList(string id, Node* n){
    this->head = n;
    this->bucketId = id;
}

LinkedList::~LinkedList(){
    delete this->head;
}


void LinkedList::push(std::string UID, std::string pword){
    struct Node* n = new Node{UID, pword};

    if(this->head == NULL){
        this->head = n;
        return;
    }

    Node* temp = this->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

string LinkedList::find(string uid){
    Node* temp = this->head;
    while(temp != NULL){
        if(temp->uid == uid){
            return temp->pword;
        }
        temp = temp->next;
    }
    return "NULL";
}
