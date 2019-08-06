//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Camila Barros on 2019-08-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* CreateNode(int data){
    Node* Nnode = new Node();
    Nnode->data = data;
    Nnode->next = NULL;
    return Nnode;
}

Node* AddNode(Node* head, int data){
    Node* toAdd = CreateNode(data);
    if(head == NULL){
        head = toAdd;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = toAdd;
    }
    return head;
}

Node* AddatHead(Node* head, int data){
    Node* toAdd = CreateNode(data);
    toAdd->next = head;
    head = toAdd;
    return head;
}

void Print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

bool SearchNode(Node* head, int data){
//    bool found = false;
//    Node* temp = head;
//    while(temp->data != data && temp->next != NULL)
//        temp = temp->next;
//    if(temp->data == data)
//        found = true;
//    return found;
    // Base case
    if(head == NULL)
        return false;
    if(head->data == data)
        return true;
    return SearchNode(head->next, data);
}

void PrintReversed(Node* head){
    if(head == NULL)
        return;
    PrintReversed(head->next);
    cout << head->data << endl;
}

Node* DeleteNode(Node* head, int data){
    Node* prev = head;
    Node* del;
    if(head->data == data){
        if(head->next == NULL){
            del = head;
            head = NULL;
        } else {
        del = head;
        head = head->next;
        }
        delete del;
        return head;
    }
    while(prev->next != NULL && prev->next->data != data)
        prev = prev->next;
    if(prev->next == NULL){
        cout << "\nGiven data is not present in Linked List";
        return head;
    }
    del = prev->next;
    prev->next = prev->next->next;
    delete del;
    return head;
}

#endif /* LinkedList_hpp */
