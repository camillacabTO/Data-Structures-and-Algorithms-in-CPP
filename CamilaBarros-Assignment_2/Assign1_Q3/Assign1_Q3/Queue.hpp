//
//  Queue.hpp
//  Assign1_Q3
//
//  Created by Camila Barros on 2019-07-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue{
public:
    Node *front = NULL;
    Node *rear = NULL;
    int max;
    int count{0};
    Queue(int maxnum);
    bool isempty();
    void enqueue(int newel);
    void dequeue();
    void displayfront();
    void status();
    bool isfull();
};

#endif /* Queue_hpp */
