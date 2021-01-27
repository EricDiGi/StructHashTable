/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: FileHandler.hpp
  Assignment number : PROJECT 1

  File defines the Handle class.
***************************************************************/
#ifndef FileHandler_HPP
#define FileHandler_HPP


#include <string>
#include <fstream>

class Handle{
    public:
        std::string buckets;
        std::ifstream infile;
        std::ofstream ofile;
        ~Handle();
        bool ready(int opt);
        bool set(int opt);
        void go(int opt);
        void close();
        std::string makePass();
        std::string toLower(std::string in);
        bool in(std::string c);
        int numBuckets();
};

#endif