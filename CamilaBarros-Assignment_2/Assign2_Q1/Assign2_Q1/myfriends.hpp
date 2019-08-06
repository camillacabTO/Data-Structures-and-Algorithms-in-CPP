//
//  myfriends.hpp
//  Assign2_Q1
//
//  Created by Camila Barros on 2019-07-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef myfriends_hpp
#define myfriends_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class myFriends {
private:
    string name;
    string birthdate;
    string address;
    string contact_number;
public:
    myFriends() = default;
    myFriends(string n, string b, string a, string c);
    string getName() const;
    string getBirthdate() const;
    string getAddress() const;
    string getNumber() const;
    friend ostream &operator<<(ostream &os, const myFriends &fri);
};
#endif /* myfriends_hpp */
