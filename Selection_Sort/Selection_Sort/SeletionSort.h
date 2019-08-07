//
//  SeletionSort.h
//  Selection_Sort
//
//  Created by Camila Barros on 2019-08-06.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef SeletionSort_h
#define SeletionSort_h

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void SelectionSort(vector<T> &vec){
    int min;
    T temp;
    for(int i = 0; i < vec.size(); i++){
        min = i;
        for(int j = i + 1; j < vec.size(); j++){
            if(vec.at(j) < vec.at(min)){
                min = j;
            }
        }
    temp = vec.at(i);
    vec.at(i) = vec.at(min);
    vec.at(min) = temp;
    }
}

template<typename T>
void Print(vector<T> const & vec){
    for(const auto &e: vec)
        cout << e << ' ';
}
#endif /* SeletionSort_h */
