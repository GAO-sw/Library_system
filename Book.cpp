#include "Book.h"
#include <iostream>



Book::Book() : LibraryItem(), author("Unknown Author"), isbn("N/A") {
    
}

Book::Book(int id_param, const std::string& title_param, const std::string& author_param, const std::string& isbn_param)
    : LibraryItem(id_param, title_param), // Call base class constructor
      author(author_param),
      isbn(isbn_param)
{
   
}



std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}



void Book::display() const {

    LibraryItem::display();
 
    std::cout << ", Author: " << author << ", ISBN: " << isbn;
}
