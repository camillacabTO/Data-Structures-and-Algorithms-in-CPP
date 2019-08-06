//
//  Queue.cpp
//  Assign1_Q3
//
//  Created by Camila Barros on 2019-07-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "Queue.hpp"

Queue::Queue(int maxnum)
:max(maxnum){}

bool Queue::isempty(){
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}
void Queue::enqueue(int newel){
    if(count < max){
        Node *ptr = new Node();
        ptr->data = newel;
        ptr->next = NULL;
        if(front == NULL){
            front = ptr;
            rear = ptr;
        }else{
            rear->next = ptr;
            rear = ptr;
        }
        count++;
    }else{
        cout << "Insertion not allowed. The Queue is full!" << endl;
    }
    
}
void Queue::dequeue(){
    if(isempty())
        cout<<"Queue is empty"<<endl;
    else
        if(front == rear){
            free(front);
            front = rear = NULL;
            count--;
        }else{
            Node *ptr = front;
            front = front->next;
            free(ptr);
            count--;
        }
}
void Queue::displayfront(){
    if(isempty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Element at the front of the queue is: "<<front->data<< endl;
}
void Queue::status(){
    if (isempty()){
        cout<<"Queue is empty"<<endl;
    }else{
        Node *ptr = front;
        while(ptr !=NULL)
        {
            cout<<ptr->data<<" ";
            ptr= ptr->next;
        }
    }
    cout << endl;
    cout << "The total number of elements in the Queue is: " << count << endl;
}
bool Queue::isfull(){
    if(count >= max){
        cout << "The Queue is full" << endl;
        return true;
    } else {
        cout << "The Queue is not full" << endl;
        return false;
    }
}
