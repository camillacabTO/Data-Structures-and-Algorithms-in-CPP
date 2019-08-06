//
//  Dictionary.hpp
//  Assignment1Question2
//
//  Created by Camila Barros on 2019-06-10.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Word {
private:
    string word;
    string meaning;
    string antonym;
    string example_sentence;
    
public:
    Word() = default;
    Word(string w, string m, string a, string e);
    void setData(string w, string m, string a, string e);
    string getWord() const;
    string getMeaning() const;
    string getAntonym() const;
    string getExample() const;
    friend ostream &operator<<(ostream &os, const Word &wordOb);

};

#endif /* Dictionary_hpp */
