//
//  Doubly Linked List.hpp
//  Doubly LinkedList
//
//  Created by Camila Barros on 2019-08-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef Doubly_Linked_List_hpp
#define Doubly_Linked_List_hpp

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLList{
public:
    int length;
    Node* head;
    
    DoublyLList();
    ~DoublyLList();
    void AddNodeatHead(int data);
    void AddNodeatTail(int data);
    void PrintReverse();
    void Test();

    
};

DoublyLList::DoublyLList(){
    length = 0;
    head = NULL;
}

DoublyLList::~DoublyLList(){
    cout << "Doubly Linked List deleted" << endl;
}

Node* CreateNode(int data){
    Node* Nnode = new Node();
    Nnode->data = data;
    Nnode->next = NULL;
    Nnode->prev = NULL;
    return Nnode;
}

void DoublyLList::AddNodeatHead(int data){
    Node* toAdd = CreateNode(data);
    if(head == NULL){
        head = toAdd;
        return;
    }
    this->head->prev = toAdd;
    toAdd->next = this->head;
    this->head = toAdd;
    this->length++;
}

void DoublyLList::AddNodeatTail(int data){
    Node* toAdd = CreateNode(data);
    Node* temp = this->head;
    if(this->head == NULL){
        this->head = toAdd;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = toAdd;
    toAdd->prev = temp;
}

void DoublyLList::PrintReverse(){
    Node* temp = this->head;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->prev;
    }
}


#endif /* Doubly_Linked_List_hpp */
