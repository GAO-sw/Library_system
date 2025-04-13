// Member.h
#pragma once

#include <string>
#include <vector>   // For storing borrowed item IDs
#include <iostream> // For std::ostream

// Represents a library member
class Member {
public:
    // --- Constructors ---
    Member();
    Member(int memberId, const std::string& name);

    // --- Accessors (Getters) ---
    int getMemberId() const;
    std::string getName() const;

    // --- Public Methods ---
    void borrowItem(int itemId); // Record item ID as borrowed
    void returnItem(int itemId); // Remove item ID from borrowed list
    void display() const;        // Display member information and borrowed items

    // --- Destructor ---
    ~Member();

private:
    // --- Private Members ---
    int memberId;
    std::string name;
    std::vector<int> borrowedItemIds; // List of IDs of borrowed items
};

// --- Operator Overloads ---
// Output member info to stream
std::ostream& operator<<(std::ostream& os, const Member& member);
// Add item ID to borrowed list (shortcut for borrowing)
Member& operator+=(Member& member, int itemId);
// Remove item ID from borrowed list (shortcut for returning)
Member& operator-=(Member& member, int itemId);
// Compare members based on ID
bool operator==(const Member& lhs, const Member& rhs);