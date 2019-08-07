//
//  Bubble_Search.h
//  Bubble_Search
//
//  Created by Camila Barros on 2019-08-07.
//  Copyright © 2019 Camila Barros. All rights reserved.
//


#ifndef Bubble_Search_h
#define Bubble_Search_h

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int Bubble_Search(int arr[], int fi, int li, int search){
    if(li >= fi){
        int mid = round((fi + li) / 2);
        
        if(arr[mid] == search)
            return mid;
        if(arr[mid] > search)
            return Bubble_Search(arr, fi , mid - 1, search);
        return Bubble_Search(arr, mid + 1, li, search);
    }
    return -1;
}

#endif /* Bubble_Search_h */
