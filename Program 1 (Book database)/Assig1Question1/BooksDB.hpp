//
//  BooksDB.hpp
//  Assig1Question1
//
//  Created by Camila Barros on 2019-06-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef BooksDB_hpp
#define BooksDB_hpp

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Book
{
public:
    Book();
    Book(string new_author, string new_title, string new_date);
    void setData(string new_author, string new_title, string new_date);
    string getAuthor() const;
    string getTitle() const;
    string getDate() const;
    bool friend operator< (const Book &book1, const Book &book2);
private:
    string author, title, date;
};

#endif /* BooksDB_hpp */
