// Library.h
#pragma once

#include <vector>
#include <string>
#include "LibraryItem.h" // Needs base class definition
#include "Member.h"      // Needs member definition
#include <iostream>     // For std::ostream

// Forward declarations to reduce header dependencies
class Book;
class Journal;

// Manages the collection of items and members in the library
class Library {
public:
    // --- Constructor ---
    Library(const std::string& name);
    // --- Destructor ---
    ~Library(); // Important for cleaning up dynamic memory

    // --- Public Methods ---
    void addItem(LibraryItem* item); // Add item (Book or Journal) using base pointer
    void addMember(const Member& member); // Add member (by copying)

    LibraryItem* findItemById(int itemId) const; // Find item by ID
    Member* findMemberById(int memberId);       // Find member by ID (non-const for modification)

    bool lendItem(int memberId, int itemId);    // Lend item to member
    bool returnItem(int memberId, int itemId);  // Return item from member

    void displayAllItems() const;               // Display all library items
    void displayAllMembers() const;             // Display all registered members

    std::string getName() const;                // Get the library's name

private:
    // --- Private Members ---
    std::string libraryName;
    // Store pointers to items to support polymorphism
    std::vector<LibraryItem*> items;
    // Store member objects directly
    std::vector<Member> members;

    // --- Friend Declarations ---
    // Allow operator<< to access private members for summary display
    friend std::ostream& operator<<(std::ostream& os, const Library& library);
};