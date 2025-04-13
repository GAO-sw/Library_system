// Journal.cpp
#include "Journal.h"
#include <iostream>

// --- Constructor Implementations ---

Journal::Journal() : LibraryItem(), issueNumber(0), publicationDate("Unknown Date") {
    // Default constructor
}

Journal::Journal(int id_param, const std::string& title_param, int issueNumber_param, const std::string& publicationDate_param)
    : LibraryItem(id_param, title_param), // Call base class constructor
      issueNumber(issueNumber_param),
      publicationDate(publicationDate_param)
{
    // Parameterized constructor
}

// --- Accessor Implementations ---

int Journal::getIssueNumber() const {
    return issueNumber;
}

std::string Journal::getPublicationDate() const {
    return publicationDate;
}

// --- Method Implementations ---

void Journal::display() const {
    // Call base class display first
    LibraryItem::display();
    // Add journal-specific details
    std::cout << ", Issue: " << issueNumber << ", Date: " << publicationDate;
}