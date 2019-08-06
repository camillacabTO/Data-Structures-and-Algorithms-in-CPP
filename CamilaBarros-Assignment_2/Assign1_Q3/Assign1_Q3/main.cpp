//
//  main.cpp
//  Assign1_Q3
//
//  Created by Camila Barros on 2019-07-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include "Queue.hpp"

using namespace std;

int main() {
    Queue *q = new Queue(10);
    q->enqueue(8);
    q->enqueue(9);
    q->enqueue(10);
    q->enqueue(11);
    q->isfull();
    q->enqueue(12);
    q->enqueue(13);
    q->enqueue(14);
    q->enqueue(15);
    q->enqueue(16);
    q->enqueue(17);
    q->status();
    q->displayfront();
    q->enqueue(18);
    q->dequeue();
    q->dequeue();
    q->status();
    q->displayfront();
    if(q->isempty())
        cout<<"The Queue is empty"<<endl;
    else
        cout<<"The Queue is not empty"<<endl;
    return 0;
}
