// main.cpp
#include <iostream>
#include <vector>
#include <string>

#include "Library.h"
#include "Book.h"
#include "Journal.h"
#include "Member.h"

int main() {
    // 1. Create library
    Library myLibrary("City Central Library");
    std::cout << "Welcome to " << myLibrary.getName() << "!" << std::endl;

    // 2. Create items (using new for polymorphism)
    Book* book1 = new Book(101, "The Lord of the Rings", "J.R.R. Tolkien", "978-0618260274");
    Book* book2 = new Book(102, "Pride and Prejudice", "Jane Austen", "978-0141439518");
    Journal* journal1 = new Journal(201, "National Geographic", 150, "2024-03");
    Journal* journal2 = new Journal(202, "Nature", 580, "2024-04-01");

    // 3. Add items to library
    myLibrary.addItem(book1);
    myLibrary.addItem(book2);
    myLibrary.addItem(journal1);
    myLibrary.addItem(journal2);

    // 4. Create members
    Member member1(1, "Alice");
    Member member2(2, "Bob");
    Member member3(3, "Charlie");

    // 5. Add members to library
    myLibrary.addMember(member1);
    myLibrary.addMember(member2);
    myLibrary.addMember(member3);

    // 6. Display initial state
    myLibrary.displayAllItems();
    myLibrary.displayAllMembers();

    // 7. Demonstrate operator<<
    std::cout << "\n--- Demonstrating Operator Overloads ---" << std::endl;
    std::cout << "Book 1 Info: " << *book1 << std::endl;
    std::cout << "Member 1 Info: " << member1 << std::endl;
    std::cout << "Library Status: " << myLibrary << std::endl;

    // 8. Demonstrate Member operators += and -=
    std::cout << "\n--- Demonstrating Member Operators += and -= ---" << std::endl;
    Member* charliePtr = myLibrary.findMemberById(3); // Get pointer to member in library
    if (charliePtr != nullptr) {
        std::cout << "Initial state: " << *charliePtr << std::endl;
        std::cout << "Charlie borrows Book 101..." << std::endl;
        *charliePtr += 101; // Use +=
        std::cout << "State now: " << *charliePtr << std::endl;
        std::cout << "Charlie borrows Journal 201..." << std::endl;
        *charliePtr += 201;
        std::cout << "State now: " << *charliePtr << std::endl;
        std::cout << "Charlie returns Book 101..." << std::endl;
        *charliePtr -= 101; // Use -=
        std::cout << "State now: " << *charliePtr << std::endl;
        std::cout << "Charlie tries to return Book 999..." << std::endl;
        *charliePtr -= 999; // Try returning non-borrowed item
        std::cout << "State finally: " << *charliePtr << std::endl;
    } else {
        std::cout << "Could not find Charlie in the library." << std::endl;
    }

    // 9. Demonstrate Library lend/return methods
    std::cout << "\n--- Demonstrating Library lendItem and returnItem ---" << std::endl;
    std::cout << "Alice tries to borrow Book 102..." << std::endl;
    if (myLibrary.lendItem(1, 102)) {
        std::cout << "Lend successful." << std::endl;
    }
    Member* alicePtr = myLibrary.findMemberById(1);
    if(alicePtr) std::cout << "Alice's state now: " << *alicePtr << std::endl;

    std::cout << "Alice tries to return Book 102..." << std::endl;
     if (myLibrary.returnItem(1, 102)) {
        std::cout << "Return successful." << std::endl;
    }
     if(alicePtr) std::cout << "Alice's state finally: " << *alicePtr << std::endl;

     std::cout << "Trying invalid operations..." << std::endl;
     myLibrary.lendItem(2, 500);    // Item doesn't exist
     myLibrary.lendItem(99, 101);   // Member doesn't exist

    // 10. Demonstrate Member operator==
    std::cout << "\n--- Demonstrating Member Operator == ---" << std::endl;
    Member anotherAlice(1, "Alice Smith"); // Same ID as member1
    Member bobCopy = *myLibrary.findMemberById(2); // Copy of Bob from library

    if (member1 == anotherAlice) {
        std::cout << "member1 (ID 1) is equal to anotherAlice (ID 1)." << std::endl;
    } else {
         std::cout << "member1 (ID 1) is NOT equal to anotherAlice (ID 1)." << std::endl;
    }
    if (member1 == bobCopy) {
        std::cout << "member1 (ID 1) is equal to bobCopy (ID 2)." << std::endl;
    } else {
         std::cout << "member1 (ID 1) is NOT equal to bobCopy (ID 2)." << std::endl;
    }

    std::cout << "\n--- Library Simulation End ---" << std::endl;

    // Library object goes out of scope here, its destructor handles cleanup of 'new' items.
    return 0;
}