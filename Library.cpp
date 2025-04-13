// Library.cpp
#include "Library.h"
#include "Book.h"       // Include derived class headers if needed for specific ops,
#include "Journal.h"    // though not strictly necessary if only using virtual functions.
#include <iostream>
#include <algorithm> // For potential use of std::find_if, etc.

// --- Constructor Implementation ---
Library::Library(const std::string& name_param) : libraryName(name_param) {
    // Vectors are initialized automatically
}

// --- Method Implementations ---

std::string Library::getName() const {
    return libraryName;
}

void Library::addItem(LibraryItem* item) {
    if (item != nullptr) { // Basic null check
        items.push_back(item);
    }
}

void Library::addMember(const Member& member) {
    // Copy the member object into the vector
    members.push_back(member);
    // Could add check for duplicate member ID for robustness
}

LibraryItem* Library::findItemById(int itemId) const {
    for (LibraryItem* item_ptr : items) {
        if (item_ptr != nullptr && item_ptr->getID() == itemId) {
            return item_ptr; // Found
        }
    }
    return nullptr; // Not found
}

Member* Library::findMemberById(int memberId) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getMemberId() == memberId) {
            return &(*it); // Return pointer to the member object in the vector
        }
    }
    return nullptr; // Not found
}

bool Library::lendItem(int memberId, int itemId) {
    Member* member_ptr = findMemberById(memberId);
    LibraryItem* item_ptr = findItemById(itemId);

    if (member_ptr == nullptr) {
        std::cerr << "Error: Member with ID " << memberId << " not found for lending." << std::endl;
        return false;
    }
    if (item_ptr == nullptr) {
        std::cerr << "Error: Item with ID " << itemId << " not found for lending." << std::endl;
        return false;
    }

    // Basic lending logic: update member's record
    // For simplicity, does not check if item is already borrowed
    member_ptr->borrowItem(itemId);
    return true;
}

bool Library::returnItem(int memberId, int itemId) {
    Member* member_ptr = findMemberById(memberId);
    // Finding item is optional here, main logic is in member's returnItem
    // LibraryItem* item_ptr = findItemById(itemId);

    if (member_ptr == nullptr) {
        std::cerr << "Error: Member with ID " << memberId << " not found for returning." << std::endl;
        return false;
    }

    // Basic returning logic: update member's record
    member_ptr->returnItem(itemId); // Member::returnItem handles case where ID is not found
    return true;
}

void Library::displayAllItems() const {
    std::cout << "\n--- Items in " << libraryName << " ---" << std::endl;
    if (items.empty()) {
        std::cout << "No items in the library." << std::endl;
    } else {
        for (const LibraryItem* item_ptr : items) {
            if (item_ptr != nullptr) {
                std::cout << *item_ptr << std::endl; // Use overloaded operator<<
            }
        }
    }
    std::cout << "-------------------------" << std::endl;
}

void Library::displayAllMembers() const {
    std::cout << "\n--- Members of " << libraryName << " ---" << std::endl;
    if (members.empty()) {
        std::cout << "No members registered." << std::endl;
    } else {
        for (const Member& member : members) {
            std::cout << member << std::endl; // Use overloaded operator<<
        }
    }
    std::cout << "--------------------------" << std::endl;
}

// --- Destructor Implementation ---
Library::~Library() {
    // Crucial: Delete all dynamically allocated LibraryItem objects
    for (LibraryItem* item_ptr : items) {
        delete item_ptr;
    }
    // The vectors 'items' and 'members' will be destroyed automatically
}

// --- Operator Overload Implementation ---
// Friend function implementation
std::ostream& operator<<(std::ostream& os, const Library& library) {
    // Access private members via friend status or public getters
    os << "Library: " << library.libraryName << " - Status: Contains "
       << library.items.size() << " items and "
       << library.members.size() << " members.";
    return os;
}