//
//  Containers.cpp
//  Test 3
//
//  Created by Camila Barros on 2019-07-24.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "Containers.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>


Person::Person(int id, string na)
    :ID(id),name(na){}


BSTitem* CreateBSTi(int id, string name){
    Person newP(id,name);
    BSTitem* newItem = new BSTitem();
    newItem->p = newP;
    newItem->left = newItem->right = NULL;
    return newItem;
}
    
BSTitem* InsertBSTi(BSTitem* root,int id, string name){
    if(root == NULL){
        root = CreateBSTi(id, name);
    } else if (id < root->p.ID){
        root->left = InsertBSTi(root->left,id, name);
    } else {
        root->right = InsertBSTi(root->right,id, name);
    }
    return root;
}

bool SearchBSTi(BSTitem* root,string name){
    if(root == NULL)
        return false;
    if(root->p.name == name){
        return true;
    }
    bool leftSide = SearchBSTi(root->left, name);
    bool rightSide = SearchBSTi(root->right, name);
    return leftSide || rightSide;
}

void PrintBSTi(BSTitem* root){
    if(root == NULL) return;
    PrintBSTi(root->left);
    cout << "___________________" << endl;
    cout << root->p.ID << endl;
    cout << root->p.name << endl;
    cout << "___________________" << endl;
    PrintBSTi(root->right);
}

BSTitem* FindMin(BSTitem* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

BSTitem* DeleteBSTi(BSTitem* root, int id){
    if(root == NULL) return root;
    else if(id < root->p.ID)
        root->left = DeleteBSTi(root->left,id);
    else if(id > root->p.ID)
        root->right = DeleteBSTi(root->right,id);
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if(root->left == NULL){
            BSTitem* temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL){
            BSTitem* temp = root;
            root = root->left;
            delete temp;
        } else {
            BSTitem* temp = FindMin(root->right);
            root->p.ID = temp->p.ID;
            root->p.name = temp->p.name;
            root->right = DeleteBSTi(root->right, temp->p.ID);
        }
    }
    return root;
}

HashItem::HashItem(): HashTable(new Person [tableSize]){
    for(int i = 0; i < tableSize; i++){
        HashTable[i].ID = NULL;
        HashTable[i].name = "empty";
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
    Person newP(id,name);
    while(HashTable[ind].name != "empty")
        ind++;
    HashTable[ind].name = name;
    HashTable[ind].ID = id;
}

int HashItem::FindHashi(string name){
    for(int i = 0; i < tableSize; i++){
        if(HashTable[i].name == name){
            cout << "The Person found in the HashTable index # " << i << endl;
            cout << "Person's name: " << HashTable[i].name << endl;
            cout << "Person's ID: " << HashTable[i].ID << endl;
            return i;
        }
    }
    return -1;
}

void HashItem::PrintTable(){
    for(int i = 0; i < tableSize; i++){
        cout << "Index: " << i << endl;
        cout << "<------------------>" << endl;
        cout << "Person's name: " << HashTable[i].name << endl;
        cout << "Person's ID: " << HashTable[i].ID << endl;
        cout << "<------------------>" << endl;
    }
}

void HashItem::DeleteHashi(string name){
    int s = FindHashi(name);
    HashTable[s].name = "empty";
    HashTable[s].ID = NULL;
    cout << name << " was deleted!" << endl;
}

void SearchPinVec(vector<Person> vec, int id){
    Person temp(id,"empty");
    auto it = find(vec.begin(), vec.end(), temp);
    if (it != vec.end()) {
        cout << "Someone with this ID was found in the vector" << endl;
    } else {
        cout << "Sorry, not found in the vector" << endl;
    }
}

ostream &operator<<(ostream &os, const Person &p){
    os << p.name << ":" << p.ID;
    return os;
}

void DisplayVector(vector<Person> &vec){
    cout << "--------------------" << endl;
    for (const auto &el: vec)
        cout << el << endl;
    cout << "--------------------" << endl;
}

void DeletePinVec(vector<Person> &vec, int id){
    Person temp;
    temp.ID = id;
    auto it = find(vec.begin(), vec.end(), temp);
    if (it != vec.end()){
        vec.erase(it);
        cout << "This record was deleted from the Vector" << endl;
    } else {
        cout << "Sorry, could not delete it in vector. Not found" << endl;
    }
}
