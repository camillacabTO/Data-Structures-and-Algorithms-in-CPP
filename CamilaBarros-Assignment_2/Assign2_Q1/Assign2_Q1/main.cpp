//
//  main.cpp
//  Assign2_Q1
//
//  Created by Camila Barros on 2019-07-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include "myfriends.hpp"
#include <stdio.h>
#include <string>

struct Node {
    myFriends friInfo;
    struct Node* next;
    struct Node* prev;
};
Node* head;

void insert(myFriends novoFri)
{
    Node* new_node = new Node;
    new_node->friInfo = novoFri;
    new_node->next = head;
    new_node->prev = NULL;
    
    if (head != NULL){
        head->prev = new_node;
    }
    head = new_node;
}

void print(Node* head)
{
    Node* current_node;
    current_node = head;
    while (current_node != NULL) {
        cout << current_node->friInfo << endl;
        current_node = current_node->next;
    }
}

Node* search_name(Node** head, string name) {
    Node* current_node;
    current_node = *head;
    while (current_node != NULL) {
        if(current_node->friInfo.getName() == name){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

Node* search_address(Node** head, string addr) {
    Node* current_node;
    current_node = *head;
    while (current_node != NULL) {
        if(current_node->friInfo.getAddress() == addr){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

Node* search_phone(Node** head, string phone) {
    Node* current_node;
    current_node = *head;
    while (current_node != NULL) {
        if(current_node->friInfo.getNumber() == phone){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

void del_friend(Node** head2, string name2) {
    Node* del = search_name(head2,name2);
    if (*head2 == del)
        *head2 = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    cout << del->friInfo.getName() << " was deleted!" << endl;
}

void Menu(){
    cout<<"Select one of the options below: "<<endl;
    cout<<"1. Add a New Friend"<<endl;
    cout<<"2. Search for a friend by name"<<endl;
    cout<<"3. Search for a friend by address"<<endl;
    cout<<"4. Search for a friend by phone number"<<endl;
    cout<<"5. Delete contact"<<endl;
    cout<<"6. Print contact list"<<endl;
    cout<<"7. Quit the program"<<endl;
    cout<<"Enter your choice"<<endl;
}

int main() {

    myFriends fri1("Camila", "13/04/88","Aikman Ave", "647-863-2442");
    myFriends fri2("Eduarda", "03/09/91","Toronto", "647-432-654");
    myFriends fri3("Rafaela", "05/05/95","Fortaleza", "3231-01-20");
    insert(fri1);
    insert(fri2);
    insert(fri3);
    
    int run{1},choice;
    while(run){
    Menu();
    string findfri,findadd,findphone,fridel;
    cin>>choice;
    cin.ignore(30, '\n');
        
    switch(choice){
        case 1:{
            string friname,fribday,friaddress,fricontact;
            cout<<"Enter the name of your new friend: "<<endl;
            getline(cin, friname);
            cout<<"Enter his/her birthdate " << endl;
            getline(cin, fribday);
            cout<<"Enter his/her address " << endl;
            getline(cin, friaddress);
            cout<<"Enter his/her contact number " << endl;
            getline(cin, fricontact);
            myFriends fri4(friname,fribday,friaddress,fricontact);
            insert(fri4);
            cout << endl;
            break;
        }
        case 2:{
            cout<<"What friend's name would you like to search for:  "<<endl;
            cin>>findfri;
            cin.ignore(30, '\n');
            if(search_name(&head, findfri) != NULL){
                cout << findfri << " was found!" << endl;
                cout << search_name(&head, findfri)->friInfo << endl;
            } else {
                cout << "Friend not found!" << endl;
            }
            cout << endl;
            break;
        }
        case 3:{
            cout<<"What address would you like to search for:  "<<endl;
            cin>>findadd;
            cin.ignore(30, '\n');
            if(search_address(&head, findadd) != NULL){
                cout << "A friend was found at this address!" << endl;
                cout << search_address(&head, findadd)->friInfo << endl;
            } else {
                cout << "Address not found!" << endl;
            }
            cout << endl;
            break;
        }
        case 4:{
            cout<<"What phone number would you like to search for:  "<<endl;
            cin>>findphone;
            cin.ignore(30, '\n');
            if(search_phone(&head, findphone) != NULL){
                cout << "A friend was found with this phone number!" << endl;
                cout << search_phone(&head, findphone)->friInfo << endl;
            } else {
                cout << "Phone number not found!" << endl;
            }
            cout << endl;
            break;
        }
        case 5: {
            cout<<"What friend's name would you like to delete:  "<<endl;
            cin>>fridel;
            cin.ignore(30, '\n');
            del_friend(&head,fridel);
            cout << endl;
            break;
        }
        case 6: {
            cout<<"Printing list of friends;  "<<endl;
            print(head);
            cout << endl;
            break;
        }
        case 7:{
            cout<<"Program is quiting. Thank you!"<<endl;
            run = 0;
            break;
        }
        default:
            break;
    }
}
    return 0;
}
