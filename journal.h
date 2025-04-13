// Journal.h
#pragma once

#include "LibraryItem.h" // Include base class header
#include <string>
#include <iostream>

// Represents a Journal, derived from LibraryItem
class Journal : public LibraryItem {
public:
    // --- Constructors ---
    Journal();
    Journal(int id, const std::string& title, int issueNumber, const std::string& publicationDate);

    // --- Accessors (Getters) ---
    int getIssueNumber() const;
    std::string getPublicationDate() const;

    // --- Public Methods ---
    // Override the display method to show journal-specific information
    void display() const override;

private:
    // --- Private Members ---
    int issueNumber;
    std::string publicationDate;
};