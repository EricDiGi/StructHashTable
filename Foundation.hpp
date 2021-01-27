/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: Foundation.hpp
  Assignment number : PROJECT 1

  File defines the Platform class.
***************************************************************/
#ifndef Foundation_HPP
#define Foundation_HPP

#include <string>
#include <fstream>
#include "HashTable.hpp"

class Platform{
    public:
        std::string buckets;
        HashTable tab;
        int LoadFileData();
        void buildHashTable();
        bool testPass(std::string uid, std::string pass);
};

#endif