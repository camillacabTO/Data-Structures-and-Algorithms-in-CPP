//
//  main.cpp
//  Doubly LinkedList
//
//  Created by Camila Barros on 2019-08-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "Doubly Linked List.hpp"

using namespace std;

int main() {
    
    DoublyLList TestL;
    TestL.AddNodeatHead(9);
    TestL.AddNodeatHead(14);
    TestL.AddNodeatHead(56);
    TestL.AddNodeatHead(90);
    TestL.AddNodeatHead(33);
    TestL.AddNodeatHead(25);
    TestL.PrintReverse();

    return 0;
}
