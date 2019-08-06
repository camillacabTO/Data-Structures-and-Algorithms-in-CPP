//
//  main.cpp
//  HashTableQ2
//
//  Created by Camila Barros on 2019-07-23.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "HashTable.hpp"

using namespace std;


int main() {
    
    hashClass newClass(10);
    newClass.AddStudent("Camila", 13, 9.5);
    newClass.AddStudent("Bruna", 18, 8.9);
    newClass.AddStudent("Mariana", 4, 6.3);
    newClass.AddStudent("Julia", 40, 4.7);
    newClass.AddStudent("Luke", 33, 7.8);
    newClass.AddStudent("Mia", 25, 5.2);
    newClass.AddStudent("Eduarda", 63, 9.8);
    newClass.PrintTable();
    cout << "There are " << newClass.NumberOfStudents() << " students registred in this class" << endl;
    newClass.FindStudent("Mariana");
    cout << "+++++++++++++++++++++" << endl;
    newClass.DeleteStudent("Camila");
    newClass.DeleteStudent("Mia");
    cout << "There are " << newClass.NumberOfStudents() << " students registred in this class" << endl;
    newClass.PrintTable();


    return 0;
}
