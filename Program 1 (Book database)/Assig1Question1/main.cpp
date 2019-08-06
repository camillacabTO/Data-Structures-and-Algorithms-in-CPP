//
//  main.cpp
//  Assig1Question1
//
//  Created by Camila Barros on 2019-06-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "BooksDB.hpp"
    
using namespace std;
    
void AddNewBook(vector<Book> *bookdata);
void PrintBooks(vector<Book> &bookdata);
void SortBooks(vector<Book> &bookdata);
void PrintMenu();
    
int main()
{
    vector<Book> bookdata;
    Book bsample("Haverbeke,Marjin", "Eloquent JavaScript", "2011");
    bookdata.push_back(bsample);
    Book bsample2("Stroustrup, Bjarne", "The C++ Programming Language", "1985");
    bookdata.push_back(bsample2);
    int choice{}, run{1};
    cout<<"Welcome to the most advanced books database program"<< endl;
    while(run){
    PrintMenu();
    cin>>choice;
    switch(choice){
        case 1:
            AddNewBook(&bookdata);
            break;
        case 2:
            SortBooks(bookdata);
            PrintBooks(bookdata);
            break;
        case 3:
            cout<<"Thanks for using this amazing book database program!"<<endl;
            run = 0;
            break;
        }
    }
    return 0;
}

void PrintMenu(){
    cout<<"___________________________________________________"<<endl;
    cout<<"Select one of the options below"<<endl;
    cout<<"1. Add a new book"<<endl;
    cout<<"2. Print list of books sorted by author"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Enter your choice"<<endl;
}

void AddNewBook(vector<Book> *bookdata){
    string tit, aut,dat;
    cout<<"Enter title"<<endl;
    cin.ignore(30, '\n');
    getline(cin, tit);
    cout<<"Enter author"<<endl;
    getline(cin, aut);
    cout<<"Enter date"<<endl;
    getline(cin, dat);
    Book b1{aut,tit,dat};
    bookdata->push_back(b1);
}

void SortBooks(vector<Book> &bookdata){
    sort(bookdata.begin(), bookdata.end());
}

void PrintBooks(vector<Book> &bookdata){
    cout<<"The books entered so far, sorted alphatetically by author are: "<<endl;
    for(auto it = bookdata.cbegin(); it != bookdata.cend(); it++){
        cout<<it->getAuthor()<< ", " <<it->getTitle()<< ", " <<it->getDate()<< "." <<endl;
    }
}
