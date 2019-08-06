//
//  Containers.hpp
//  Test 3
//
//  Created by Camila Barros on 2019-07-24.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

//1.    Add a menu in the main function that asks for following options
//i.    Insert Record
//ii.    Search Node
//iii.    Display Record (For tree use in-order traversal method)
//iv.    Delete
//v.    Searching Cost
//vi.    Exit


#ifndef Containers_hpp
#define Containers_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    int ID;
    string name;
    Person(int, string);
    Person() = default;
    bool operator<(const Person &rhs) const {
        return this->ID < rhs.ID;
    }
    bool operator==(const Person &rhs) const {
        return (this->ID == rhs.ID);
    }
    
};

class BSTitem{
public:
    Person p;
    BSTitem* left;
    BSTitem* right;
    BSTitem() = default;
};

class HashItem{
public:
    static const int tableSize = 10;
    Person* HashTable;
    HashItem();
    
    int HashKey(string key);
    void InsertHashi(int id, string name);
    int FindHashi(string name);
    void PrintTable();
    void DeleteHashi(string name);
};


BSTitem* CreateBSTi(int id, string name);
BSTitem* InsertBSTi(BSTitem* root,int id, string name);
bool SearchBSTi(BSTitem* root,string name);
void PrintBSTi(BSTitem* root);
BSTitem* FindMin(BSTitem* root);
BSTitem* DeleteBSTi(BSTitem* root, int id);

void SearchPinVec(vector<Person> vec, int id);
void DisplayVector(vector<Person> &vec);
void DeletePinVec(vector<Person> &vec, int id);


#endif /* Containers_hpp */
