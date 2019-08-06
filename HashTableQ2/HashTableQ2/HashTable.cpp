//
//  HashTable.cpp
//  HashTableQ2
//
//  Created by Camila Barros on 2019-07-23.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "HashTable.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

hashClass::hashClass(int classSize): classTable(new student [classSize]){
    tableSize = classSize;
    for(int i = 0; i < tableSize; i++){
        classTable[i].name = "empty";
        classTable[i].studentID = NULL;
        classTable[i].marks_oop345 = NULL;
    }
};

int hashClass::HashKey(string key){
    int index, hash = 0;
    for(auto c : key)
        hash = hash + (int)c;
    index = (hash * 31) % tableSize;
    return index;
}

void hashClass::AddStudent(string na, int id, float mark){
    int ind = HashKey(na);
    while(classTable[ind].name != "empty")
        ind++;
    classTable[ind].name = na;
    classTable[ind].studentID = id;
    classTable[ind].marks_oop345 = mark;
}

void::hashClass::PrintTable(){
    for(int i = 0; i < tableSize; i++){
        cout << "Index: " << i << endl;
        cout << "<------------------>" << endl;
        cout << "Student name: " << classTable[i].name << endl;
        cout << "Student ID: " << classTable[i].studentID << endl;
        cout << "Student OOP345 mark: " << classTable[i].marks_oop345 << endl;
        cout << "<------------------>" << endl;
    }
}

int hashClass::NumberOfStudents(){
    int counter{};
    for (int i = 0; i < tableSize; i++){
        if(classTable[i].name != "empty")
            counter++;
    }
    return counter;
}

int hashClass::FindStudent(string na){
    for(int i = 0; i < tableSize; i++){
        if(classTable[i].name == na){
            cout << "Student found in index " << i << endl;
            cout << "Student name: " << classTable[i].name << endl;
            cout << "Student ID: " << classTable[i].studentID << endl;
            cout << "Student OOP345 mark: " << classTable[i].marks_oop345 << endl;
            return i;
        }
    }
    return -1;
}

void hashClass::DeleteStudent(string na){
    int s = FindStudent(na);
    classTable[s].name = "empty";
    classTable[s].studentID = NULL;
    classTable[s].marks_oop345 = NULL;
    cout << na << " was deleted!" << endl;
}
