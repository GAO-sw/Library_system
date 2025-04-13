// LibraryItem.h
#pragma once

#include <string>
#include <iostream> // For std::ostream

// Base class for all items that can be borrowed from the library
class LibraryItem {
public:
    // --- Constructors ---
    LibraryItem();
    LibraryItem(int id, const std::string& title);

    // --- Accessors (Getters) ---
    int getID() const;
    std::string getTitle() const;

    // --- Public Methods ---
    // Virtual function to display item information (can be overridden by derived classes)
    virtual void display() const;

    // --- Destructor ---
    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~LibraryItem();

private:
    // --- Private Members ---
    int id;
    std::string title;
};

// --- Operator Overloads ---
// Overload the << operator to print LibraryItem objects to an output stream
std::ostream& operator<<(std::ostream& os, const LibraryItem& item);