// Member.cpp
#include "Member.h"
#include <iostream>
#include <algorithm> // For std::find and std::vector::erase

// --- Constructor Implementations ---
Member::Member() : memberId(0), name("Unknown Member") {
    // Default constructor
}

Member::Member(int memberId_param, const std::string& name_param)
    : memberId(memberId_param), name(name_param) {
    // Parameterized constructor
}

// --- Accessor Implementations ---
int Member::getMemberId() const {
    return memberId;
}

std::string Member::getName() const {
    return name;
}

// --- Method Implementations ---

void Member::borrowItem(int itemId) {
    // Add item ID to the end of the vector
    borrowedItemIds.push_back(itemId);
}

void Member::returnItem(int itemId) {
    // Find the item ID in the vector
    auto it = std::find(borrowedItemIds.begin(), borrowedItemIds.end(), itemId);
    // If found, remove it
    if (it != borrowedItemIds.end()) {
        borrowedItemIds.erase(it);
    }
    // No error message for simplicity if not found
}

void Member::display() const {
    std::cout << "Member ID: " << memberId << ", Name: " << name;
    if (!borrowedItemIds.empty()) {
        std::cout << ", Borrowed Items (IDs): ";
        for (int id : borrowedItemIds) {
            std::cout << id << " ";
        }
    } else {
        std::cout << ", No items borrowed.";
    }
}

// --- Destructor Implementation ---
Member::~Member() {
    // Vector cleans up its own memory, nothing needed here
}

// --- Operator Overload Implementations ---

std::ostream& operator<<(std::ostream& os, const Member& member) {
    member.display(); // Use display method for output
    return os;
}

Member& operator+=(Member& member, int itemId) {
    member.borrowItem(itemId); // Call borrowItem method
    return member;
}

Member& operator-=(Member& member, int itemId) {
    member.returnItem(itemId); // Call returnItem method
    return member;
}

bool operator==(const Member& lhs, const Member& rhs) {
    // Compare members based on their ID
    return lhs.getMemberId() == rhs.getMemberId();
}