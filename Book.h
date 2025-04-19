
#pragma once

#include "LibraryItem.h" 
#include <string>
#include <iostream>


class Book : public LibraryItem {
public:
   
    Book();
    Book(int id, const std::string& title, const std::string& author, const std::string& isbn);


    std::string getAuthor() const;
    std::string getISBN() const;



    void display() const override;

private:

    std::string author;
    std::string isbn;
};
