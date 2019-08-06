//
//  myfriends.cpp
//  Assign2_Q1
//
//  Created by Camila Barros on 2019-07-05.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "myfriends.hpp"


myFriends::myFriends(string n, string b, string a, string c)
:name(n),birthdate(b),address(a),contact_number(c){};

string myFriends::getName() const{
    return name;
}
string myFriends::getBirthdate() const{
    return birthdate;
}

string myFriends::getAddress() const{
    return address;
}

string myFriends::getNumber() const{
    return contact_number;
}

ostream &operator<<(ostream &os, const myFriends &fri){
    os << fri.getName() << " was born on ";
    os << fri.getBirthdate()<< endl;
    os << "Lives at " << fri.getAddress()<< " and her/his contact number is ";
    os << fri.getNumber()<<endl;
    return os;
}
