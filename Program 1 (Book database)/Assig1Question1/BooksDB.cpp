//
//  BooksDB.cpp
//  Assig1Question1
//
//  Created by Camila Barros on 2019-06-09.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "BooksDB.hpp"
#include <stdio.h>

Book::Book(string new_author, string new_title, string new_date)
    :author{new_author}, title{new_title}, date{new_date}{}

void Book::setData(string new_author, string new_title, string new_date){
    author = new_author;
    title = new_title;
    date = new_date;
}

string Book::getAuthor() const{
    return author;
}

string Book::getTitle() const{
    return title;
}

string Book::getDate() const{
    return date;
}

bool operator<(const Book &book1, const Book &book2){
    return (book1.author < book2.author);
}


