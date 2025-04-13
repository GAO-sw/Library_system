// LibraryItem.cpp
#include "LibraryItem.h"
#include <iostream>

// --- Constructor Implementations ---

LibraryItem::LibraryItem() : id(0), title("Unknown") {
    // Default constructor initializes members
}

LibraryItem::LibraryItem(int id_param, const std::string& title_param) : id(id_param), title(title_param) {
    // Parameterized constructor initializes members using provided values
}

// --- Accessor Implementations ---

int LibraryItem::getID() const {
    return id;
}

std::string LibraryItem::getTitle() const {
    return title;
}

// --- Method Implementations ---

void LibraryItem::display() const {
    // Base implementation for displaying item info
    std::cout << "ID: " << id << ", Title: " << title;
}

// --- Destructor Implementation ---

LibraryItem::~LibraryItem() {
    // Nothing specific to clean up in the base class for now
}

// --- Operator Overload Implementation ---

std::ostream& operator<<(std::ostream& os, const LibraryItem& item) {
    // Calls the virtual display() function to handle output polymorphically
    item.display();
    return os;
}