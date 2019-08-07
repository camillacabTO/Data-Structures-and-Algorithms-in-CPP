//
//  main.cpp
//  Bubble_Search
//
//  Created by Camila Barros on 2019-08-07.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "Bubble_Search.h"

using namespace std;

int main() {
    
    int arr[] = { 2, 3, 4, 10, 40, 60, 70, 88, 99 };
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << Bubble_Search(arr, 0, size - 1, 88) << endl;
    return 0;
}
