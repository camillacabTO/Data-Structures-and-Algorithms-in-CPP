//
//  Dictionary.cpp
//  Assignment1Question2
//
//  Created by Camila Barros on 2019-06-10.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "Dictionary.hpp"

Word::Word(string w, string m, string a, string e)
    :word{w},meaning{m},antonym{a},example_sentence{e}{};

void Word::setData(string w, string m, string a, string e){
    word = w;
    meaning = m;
    antonym = a;
    example_sentence = e;
}
string Word::getWord() const{
    cout<<"Word: ";
    return word;
}

string Word::getMeaning() const{
    cout<<"Meaning: ";
    return meaning;
}

string Word::getAntonym() const{
    cout<<"Antonym: ";
    return antonym;
}

string Word::getExample() const{
    cout<<"Explamble: ";
    return example_sentence;
}

ostream &operator<<(ostream &os, const Word &wordOb){
    os << wordOb.getWord()<<endl;
    os << wordOb.getMeaning()<<endl;
    os << wordOb.getAntonym()<<endl;
    os << wordOb.getExample()<<endl;
    return os;
}



