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