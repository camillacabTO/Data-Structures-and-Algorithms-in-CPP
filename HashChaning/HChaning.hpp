//
//  HChaning.hpp
//  HashChaning
//
//  Created by Camila Barros on 2019-07-30.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef HChaning_hpp
#define HChaning_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Person {
public:
    int ID;
    string name;
    Person(int, string);
    Person() = default;
    Person* next;
};

class HashItem{
public:
    static const int tableSize = 5;
    Person* HashTable[tableSize];
    HashItem();
    
    int HashKey(string key);
    void InsertHashi(int id, string name);
    int FindHashi(string name);
    void PrintTable();
    void PrintTableBasic();
    void DeleteHashi(string name);
};



#endif /* HChaning_hpp */
