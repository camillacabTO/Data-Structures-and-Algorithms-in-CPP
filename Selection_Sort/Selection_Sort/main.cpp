//
//  main.cpp
//  Selection_Sort
//
//  Created by Camila Barros on 2019-08-06.
//  Copyright © 2019 Camila Barros. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "SeletionSort.h"

using namespace std;

int main() {

    vector<int> vecmain = {8,4,2,7,9,1,3,6};
    vector<char> vecchar = {'a','z','y','i','p'};
    vector<float> vecfloat = {4.5,6.9,3.6,15.8,43.67,1.2,5.78};
    
    SelectionSort(vecchar);
    Print(vecchar);
    cout << endl;
    SelectionSort(vecmain);
    Print(vecmain);
    cout << endl;
    SelectionSort(vecfloat);
    Print(vecfloat);
    
    
    return 0;
}
