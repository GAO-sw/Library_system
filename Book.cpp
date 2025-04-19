// Book.cpp
#include "Book.h"
#include <iostream>

// --- Constructor Implementations ---

Book::Book() : LibraryItem(), author("Unknown Author"), isbn("N/A") {
    // Default constructor calls base constructor and initializes book members
}

Book::Book(int id_param, const std::string& title_param, const std::string& author_param, const std::string& isbn_param)
    : LibraryItem(id_param, title_param), // Call base class constructor
      author(author_param),
      isbn(isbn_param)
{
    // Parameterized constructor initializes base part and book members
}

// --- Accessor Implementations ---

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

// --- Method Implementations ---

void Book::display() const {
    // Call base class display first
    LibraryItem::display();
    // Add book-specific details
    std::cout << ", Author: " << author << ", ISBN: " << isbn;
}
