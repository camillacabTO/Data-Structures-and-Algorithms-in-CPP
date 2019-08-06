//
//  main.cpp
//  BSTQ1
//
//  Created by Camila Barros on 2019-07-23.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "FamilyMembersBST.hpp"

using namespace std;

void Menu();

int main(){
    Family_Member* Mainroot = NULL;
    int run{1}, choice, age;
    float height;
    string name, Nname;
    
    Mainroot = AddMember(Mainroot, 45, 1.90, "Lana");
    Mainroot = AddMember(Mainroot, 23, 1.65, "Camila");
    Mainroot = AddMember(Mainroot, 62, 1.43, "Luke");
    Mainroot = AddMember(Mainroot, 21, 1.42, "Carlos");
    
    while(run){
        Menu();
        cin >> choice;
        switch (choice){
            case 1:
                cout<<"Enter the name of the new Family Member"<<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout<<"Enter the age and height of the new Family Member"<<endl;
                cin>>age>>height;
                Mainroot = AddMember(Mainroot, age, height, name);
                break;
            case 2:
                cout<<"Enter the name of the Family Member you would like to delete"<<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                Mainroot = Delete(Mainroot, name);
                break;
            case 3:
                cout<< "Enter the name of the Family Member you would like to update the age" <<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout << "Enter the updated age" << endl;
                cin>>age;
                Mainroot = UpdateAge(Mainroot, name, age);
                break;
            case 4:
                cout<< "Enter the current name of the Family Member you would like to update the name" <<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout << "Enter the updated name" << endl;
                cin.ignore(30, '\n');
                getline(cin, Nname);
                Mainroot = UpdateName(Mainroot, name, Nname);
                break;
            case 5:
                cout<< "Enter the name of the Family Member you would like to update the height" <<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                cout << "Enter the updated height" << endl;
                cin>>height;
                Mainroot = UpdateHeight(Mainroot, name, height);
                break;
            case 6:
                cout<< "Enter the name of the Family Member you would like to search" <<endl;
                cin.ignore(30, '\n');
                getline(cin, name);
                if(Search(Mainroot, name))
                   cout << name << " was found" << endl;
                else
                    cout << name << " was not found" << endl;
                break;
            case 7:
                cout << "Printing Family Members Tree - InOrder" << endl;
                InOrderPrint(Mainroot);
                break;
            case 8:
                cout << "Thanks for using The Family Members tree program" << endl;
                run = 0;
                break;
            default:
                cout << "This is not a valid option. Try again" << endl;
                break;
        }
    }
    return 0;
}

void Menu(){
cout << "Welcome to The Family Members tree program" << endl;
cout << "********************************" << endl;
cout << "Please, choose one of the options below" << endl;
cout << "1) Insert a new Family Member" << endl;
cout << "2) Delete an existing Family Member" << endl;
cout << "3) Update age of an existing Family Member " << endl;
cout << "4) Update name of an existing Family Member " << endl;
cout << "5) Update height of an existing Family Member " << endl;
cout << "6) Search for a Family Member in the tree" << endl;
cout << "7) Display all Family Members in the tree" << endl;
cout << "8) Exit the program" << endl;
cout << "*********************************" << endl;
cout << "Enter the number that represents your choice";
}
