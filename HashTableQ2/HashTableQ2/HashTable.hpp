//
//  HashTable.hpp
//  HashTableQ2
//
//  Created by Camila Barros on 2019-07-23.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

//Question 2
//Create a student hash table that contains information, studentID (int), name (string), marks_oop345 (float). The size of hash table is equal to the number of students in the class. Use linear probing in case of collisions.
//Perform insertion, deletion, display and search operations.

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef HashTable_hpp
#define HashTable_hpp

int static tableSize = 0;

class hashClass{
private:
    int tableSize;
    struct student {
        int studentID;
        string name;
        float marks_oop345;
    };
    
    student* classTable;
  
public:
    hashClass(int classSize);
    int HashKey(string key);
    void AddStudent(string na, int id, float mark);
    void PrintTable();
    int NumberOfStudents();
    int FindStudent(string na);
    void DeleteStudent(string na);
    
    
};

#endif /* HashTable_hpp */
