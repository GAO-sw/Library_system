
#include "Journal.h"
#include <iostream>


Journal::Journal() : LibraryItem(), issueNumber(0), publicationDate("Unknown Date") {
  
}

Journal::Journal(int id_param, const std::string& title_param, int issueNumber_param, const std::string& publicationDate_param)
    : LibraryItem(id_param, title_param), // Call base class constructor
      issueNumber(issueNumber_param),
      publicationDate(publicationDate_param)
{
   
}



int Journal::getIssueNumber() const {
    return issueNumber;
}

std::string Journal::getPublicationDate() const {
    return publicationDate;
}



void Journal::display() const {
 
    LibraryItem::display();

    std::cout << ", Issue: " << issueNumber << ", Date: " << publicationDate;
}
