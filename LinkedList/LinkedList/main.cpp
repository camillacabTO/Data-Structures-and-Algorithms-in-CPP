//
//  main.cpp
//  LinkedList
//
//  Created by Camila Barros on 2019-08-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "LinkedList.hpp"

using namespace std;

Node* head;

int main(){
    
    head = NULL;
    head = AddatHead(head,6);
    head = AddatHead(head,7);
    head = AddatHead(head,8);
    head = AddatHead(head,9);
    Print(head);
//    cout << SearchNode(head,8) << endl;
//    PrintReversed(head);
    head = DeleteNode(head,9);
    head = DeleteNode(head,8);
    head = DeleteNode(head,7);
    head = DeleteNode(head,6);

    
    Print(head);

    return 0;
}
