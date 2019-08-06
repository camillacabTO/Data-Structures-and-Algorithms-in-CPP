//
//  main.cpp
//  Assign2_Q2
//
//  Created by Camila Barros on 2019-07-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"

using namespace std;

int main() {
    Stack *st = new Stack(4);
    if(st->isempty())
        cout<<"The Stack is empty"<<endl;
    else
        cout<<"The Stack is not empty"<<endl;
    st->push(1);
    st->push(2);
    st->push(3);
    st->status();
    st->pop();
    st->status();
    st->push(4);
    st->push(5);
    st->push(6);
    st->status();
    st->isfull();
    return 0;
}
