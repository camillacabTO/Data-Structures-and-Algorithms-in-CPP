//
//  HChaning.cpp
//  HashChaning
//
//  Created by Camila Barros on 2019-07-30.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "HChaning.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Person::Person(int id, string na)
:ID(id),name(na),next(NULL){}


HashItem::HashItem():HashTable(){
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new Person;
        HashTable[i]->ID = NULL;
        HashTable[i]->name = "empty";
        HashTable[i]->next = NULL;
    }
};

int HashItem::HashKey(string key){
    int index, hash = 0;
    for (auto c : key)
        hash = hash + (int)c;
    index = (hash * 31) % HashItem::tableSize;
    return index;
}

void HashItem::InsertHashi(int id, string name){
    int ind = HashKey(name);
    if(HashTable[ind]->name == "empty"){
        HashTable[ind]->name = name;
        HashTable[ind]->ID = id;
    } else {
        Person* temp = HashTable[ind];
        Person* newP = new Person(id,name);
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newP;
    }
}

int HashItem::FindHashi(string name){
    for(int i = 0; i < tableSize; i++){
        if(HashTable[i]->name == name){
            cout << "The Person found in the HashTable index # " << i << endl;
            cout << "Person's name: " << HashTable[i]->name << endl;
            cout << "Person's ID: " << HashTable[i]->ID << endl;
            return i;
        } else {
            Person* temp = HashTable[i];
            while(temp->name != name && temp->next != NULL)
                temp = temp->next;
            if(temp->name == name)
                return i;
        }
    }
    return -1;
}
    
//
void HashItem::PrintTable(){
    for(int i = 0; i < tableSize; i++){
        cout << "Index: " << i << endl;
        cout << "<------------------>" << endl;
        cout << "Person's name: " << HashTable[i]->name << endl;
        cout << "Person's ID: " << HashTable[i]->ID << endl;
        cout << "<------------------>" << endl;
        Person* temp = HashTable[i];
        while(temp->next != NULL){
            temp = temp->next;
            cout << "Person's name: " << temp->name << endl;
            cout << "Person's ID: " << temp->ID << endl;
            cout << "<................>" << endl;
        }
    }
}
//
//void HashItem::PrintTableBasic(){
//    for(int i = 0; i < tableSize; i++){
//        cout << "Index: " << i << endl;
//        cout << "<------------------>" << endl;
//        cout << "Person's name: " << HashTable[i]->name << endl;
//        cout << "Person's ID: " << HashTable[i]->ID << endl;
//        cout << "<------------------>" << endl;
//    }
//}

void HashItem::DeleteHashi(string name){
    int s = HashKey(name);
    if(HashTable[s]->name == "empty"){
        cout << name << " not found" << endl;
    } else if(HashTable[s]->next == NULL && HashTable[s]->name == name){
        HashTable[s]->ID = NULL;
        HashTable[s]->name = "empty";
    } else if (HashTable[s]->name == name){
        Person* del = HashTable[s];
        HashTable[s] = HashTable[s]->next;
        delete del;
    } else {
        Person* ptr1 = HashTable[s];
        Person* temp = ptr1;
        while(ptr1->name != name && ptr1->next != NULL){
            temp = ptr1;
            ptr1 = ptr1->next;
        }
        if(ptr1->next == NULL){
            cout << name << " not found" << endl;
        } else {
            temp->next = ptr1->next;
            delete ptr1;
        }
    }
}


