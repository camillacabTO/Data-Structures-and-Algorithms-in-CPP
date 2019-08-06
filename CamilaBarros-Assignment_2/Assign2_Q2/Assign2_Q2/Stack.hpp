//
//  Stack.hpp
//  Assign2_Q2
//
//  Created by Camila Barros on 2019-07-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int count;
    int max;
public:
    Stack(int maxNum);
    void push(int newel);
    void pop();
    void status();
    bool isempty();
    bool isfull();
};

#endif /* Stack_hpp */

