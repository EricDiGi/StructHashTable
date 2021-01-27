/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: HashTable.hpp
  Assignment number : PROJECT 1

  File defines two classes, HashTable and LinkedLists.
  Also defines Node as a struct.
***************************************************************/
#ifndef HashTable_HPP
#define HashTable_HPP

#include <string>
#include <iostream>

struct Node{
    std::string uid;
    std::string pword;
    Node* next;    
};

class LinkedList{
    private:
        Node* head;
    public:
        std::string bucketId;
        LinkedList();
        LinkedList(std::string id, Node* n);
        ~LinkedList();
        void push(std::string UID, std::string pword);
        std::string find(std::string uid);

    friend std::ostream &operator<< (std::ostream &out, const LinkedList &l){
        Node* list = l.head;
        while(list != NULL){
            out << list->uid << "\t\t" << list->pword << std::endl;
            list = list->next;
        }
        out << std::endl;
        return out;
    }
};

class HashTable{
    private:
        int buckets;
        LinkedList* table;
    public:
        HashTable();
        ~HashTable();
        void build(int numBuckets, std::string buckets);
        std::string extract(std::string key);
        void insertEntry(std::string uid, std::string pword);
    
    friend std::ostream &operator<< (std::ostream &out, const HashTable &t){
        out << "\t buckets: " << t.buckets << std::endl;
        for(int i = 0; i < t.buckets; i++){
            out << "THIS IS LETTER : " << t.table[i].bucketId << std::endl;
            out << t.table[i];
        }
        return out;
    }
};
#endif