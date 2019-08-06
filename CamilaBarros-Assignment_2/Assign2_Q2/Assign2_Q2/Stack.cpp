//
//  Stack.cpp
//  Assign2_Q2
//
//  Created by Camila Barros on 2019-07-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack(int maxNum){
    top = NULL;
    count = 0;
    max = maxNum;
}
void Stack::push(int newel){
    if(count < max){
        Node* ptr = new Node();
        ptr->data = newel;
        ptr->next = top;
        top = ptr;
        count++;
    } else {
        cout << "Insertion not allowed. The Stack is full!" << endl;
    }
}
bool Stack::isempty(){
    if(top == NULL)
        return true;
    else
        return false;
}
void Stack::pop(){
    if(isempty()) {
        cout << "Stack is Empty" << endl;
    } else {
        Node* ptr = top;
        top = top->next;
        delete(ptr);
        count--;
    }
}
void Stack::status(){
    if (top == NULL) {
        cout << "Stack empty" << endl;
    }
    Node* temp;
    temp = top;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "The total number of elements in the Stack is: " << count << endl;
}
bool Stack::isfull(){
    if(count >= max){
        cout << "The Stack is full" << endl;
        return true;
    } else {
        cout << "The Stack is not full" << endl;
        return false;
    }
}
