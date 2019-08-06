//
//  main.cpp
//  HashChaning
//
//  Created by Camila Barros on 2019-07-30.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "HChaning.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace  std;

int main(){
    
    HashItem Table;
    
    Table.InsertHashi(01, "Camila");
    Table.InsertHashi(02, "Mariana");
    Table.InsertHashi(03, "Antonia");
    Table.InsertHashi(04, "Eduarda");
    Table.InsertHashi(05, "Priscila");
    Table.InsertHashi(07, "Luke");
    Table.InsertHashi(18, "Jeff");
    Table.InsertHashi(19, "Gord");
    Table.InsertHashi(10, "Tanya");
    Table.InsertHashi(14, "Jesus");
    Table.InsertHashi(15, "Jezz");
    Table.InsertHashi(16, "Mia");
    cout << "This person is index #: " << Table.HashKey("Gord") << endl;
    Table.PrintTable();
    cout << "+++++++++++++++++++++" << endl;
    Table.DeleteHashi("Jezz");
    Table.DeleteHashi("Jeff");
    Table.DeleteHashi("Eduarda");
    Table.DeleteHashi("Sonia");
    Table.DeleteHashi("Mariana");
    Table.PrintTable();

    return 0;
}
