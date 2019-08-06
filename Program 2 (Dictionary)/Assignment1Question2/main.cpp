//
//  main.cpp
//  Assignment1Question2
//
//  Created by Camila Barros on 2019-06-10.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include "Dictionary.hpp"

using namespace std;

map<string,Word> dictionary;
void Menu();
void AddWord(map<string,Word> &map);
void PrintDic(map<string,Word> &map);
void SearchWord(map<string,Word> &map, string str);

int main(){
    
    Word sample1("slope", "a rising or falling surface", "declination", "the garden sloped down to a stream");
    dictionary.insert(make_pair("slope",sample1));
    Word sample2("overcast", "marked by a covering of gray clouds","sunny", "the sky was leaden with overcast");
    dictionary.insert(make_pair("overcast",sample2));
    string findthis;
    int run{1},choice;
    cout<<"Welcome to the English Dictionary program"<< endl;
    while(run){
    Menu();
    cin>>choice;
    cin.ignore(30, '\n');
    switch(choice){
        case 1:
            AddWord(dictionary);
            break;
        case 2:
            cout<<"Which word do you want to search for: "<<endl;
            cin>>findthis;
            cin.ignore(30, '\n');
            SearchWord(dictionary,findthis);
            break;
        case 3:
            PrintDic(dictionary);
            break;
        case 4:
            cout<<"Program quiting. Thank you!"<<endl;
            run = 0;
            break;
        default:
            cout<<"Invalid Option. Try again"<<endl;
            break;
    }
 }
    return 0;
}

void AddWord(map<string,Word> &map){
    string userWord,userMeaning,userAntonym,userExample;
    cout<<"Enter a word in the dictionary: "<<endl;
    getline(cin, userWord);
    cout<<"Enter a meaning for " << userWord <<endl;
    getline(cin, userMeaning);
    cout<<"Enter an antonym for " << userWord <<endl;
    getline(cin, userAntonym);
    cout<<"Enter an explample of use of " << userWord <<endl;
    getline(cin, userExample);
    Word w1(userWord,userMeaning,userAntonym,userExample);
    map.insert(make_pair(userWord,w1));
    cout<<endl;
}

void PrintDic(map<string,Word> &map){
    cout<<"Printing Dictionary: "<<endl;
    cout<<"______________________"<<endl;
    for (auto i = map.begin(); i != map.end(); i++)
        {
            cout<< i->second <<endl;
        }
}

void SearchWord(map<string,Word> &map, string str){
    auto it = map.find(str);
    if(it != map.end()){
        cout<<"The word was found"<<endl;
        cout<<endl;
        cout<< it->second <<endl;
    } else {
        cout<<"Word not found!"<<endl;
    }
    cout<<endl;
}

void Menu(){
    cout<<"Select one of the options below: "<<endl;
    cout<<"1. Add a New Word"<<endl;
    cout<<"2. Search for a specific Word"<<endl;
    cout<<"3. Print Dictionary"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<"Enter your choice"<<endl;
}
