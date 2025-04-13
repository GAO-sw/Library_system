// Book.h
#pragma once

#include "LibraryItem.h" // Include base class header
#include <string>
#include <iostream>

// Represents a Book, derived from LibraryItem
class Book : public LibraryItem {
public:
    // --- Constructors ---
    Book();
    Book(int id, const std::string& title, const std::string& author, const std::string& isbn);

    // --- Accessors (Getters) ---
    std::string getAuthor() const;
    std::string getISBN() const;

    // --- Public Methods ---
    // Override the display method to show book-specific information
    void display() const override;

private:
    // --- Private Members ---
    std::string author;
    std::string isbn;
};