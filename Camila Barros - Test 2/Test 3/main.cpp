//
//  main.cpp
//  Test 3
//
//  Created by Camila Barros on 2019-07-24.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "Containers.hpp"

using namespace std;

//i.    Insert Record
//ii.    Search Node
//iii.    Display Record (For tree use in-order traversal method)
//iv.    Delete


int main(){

    vector <Person> PersonsVector;
    BSTitem* root = NULL;
    HashItem HashMain;
    int choice{0},run{1},id{};
    string name;
    
    while(run){
        cout << "Welcome to The Person Database Program using Data Structures" << endl;
        cout << "********************************" << endl;
        cout << "1) Insert a new record" << endl;
        cout << "2) Search for a record" << endl;
        cout << "3) Display all records in all Data Structures" << endl;
        cout << "4) Delete a record" << endl;
        cout << "5) Exit the program" << endl;
        cout << "*********************************" << endl;
        cout << "Enter the number that represents your choice";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout<<"Enter the name of the new Person to create a new record"<<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout<<"Enter the ID of the new Person to create a new record"<<endl;
                cin>>id;
                PersonsVector.emplace_back(id,name);
                if(root == NULL)
                    root = InsertBSTi(root,id,name);
                else
                    InsertBSTi(root,id,name);
                HashMain.InsertHashi(id, name);
                cout << "The new record was inserted in the Vector, Hash Table and BST" << endl;
                break;
            case 2:
                cout<<"Enter the name of the Person to be searched for"<<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout<<"Enter the ID of the Person to be searched for"<<endl;
                cin>>id;
                SearchPinVec(PersonsVector,id);
                cout << endl;
                if(SearchBSTi(root,name))
                    cout << "This person was found in the BST" << endl;
                else
                    cout << "This person was not found in the BST" << endl;
                if(HashMain.FindHashi(name) == -1)
                    cout << "This person was not found in the Hash Table" << endl;
                break;
            case 3:
                cout << "Display all entries in the Vector" << endl;
                cout << "---------------------------------" << endl;
                DisplayVector(PersonsVector);
                cout << "Display all entries in the BST" << endl;
                cout << "---------------------------------" << endl;
                PrintBSTi(root);
                cout << "Display all entries in the Hash Table" << endl;
                cout << "---------------------------------" << endl;
                HashMain.PrintTable();
                break;
            case 4:
                cout<<"Enter the name of the Person to be deleted"<<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout<<"Enter the ID of the Person to be deleted"<<endl;
                cin>>id;
                cout << "Deleting this record from the Vector" << endl;
                DeletePinVec(PersonsVector,id);
                cout << "Deleting this record from the BST" << endl;
                DeleteBSTi(root,id);
                cout << "Deleting this record from the Hash Table" << endl;
                HashMain.DeleteHashi(name);
                break;
            case 5:
                cout<<"Thanks for using The Person Database Program!"<<endl;
                run = 0;
                break;
        }
    }
    return 0;
}
