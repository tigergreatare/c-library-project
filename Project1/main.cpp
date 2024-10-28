#include "header.h"
#include <iostream>
using namespace std;

int main() {
    cout << "*************************************************************************" << endl;
    cout << "" << endl;
    cout << "              Library Management System        " << endl;
    cout << "" << endl;
    cout << "*************************************************************************" << endl;
    cout << "" << endl;
    Library library;
  
    // Add initial books
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "123456789"));
    library.addBook(Book("1984", "George Orwell", "987654321"));

    string userInput;

    // Display initial list of books
    library.displayBook();

    do {
        // Ask if the user wants to add a book
        cout << "Do you want to add a new book? (yes/no): ";
        cin >> userInput;

        if (userInput == "yes") {
            // Add a book from user input
            library.addBookFromUserInput();
        }

        // Ask if the user wants to display the books
        cout << "Do you want to display the registered books? (yes/no): ";
        cin >> userInput;

        if (userInput == "yes") {
            // Display the books
            library.displayBook();
        }

        // Ask if the user wants to register a new member
        cout << "Do you want to register a new member? (yes/no): ";
        cin >> userInput;

        if (userInput == "yes") {
            string memberName;
            int memberID;
            cout << "Enter member name: ";
            cin >> ws; // to consume any leading whitespace
            getline(cin, memberName);
            cout << "Enter member ID: ";
            cin >> memberID;
            library.registerMember(Member(memberName, memberID));
            cout << "Member registered successfully!" << endl;
        }

        // Ask if the user wants to display the members
        cout << "Do you want to display registered members? (yes/no): ";
        cin >> userInput;

        if (userInput == "yes") {
            library.displayMembers();
        }

    } while (userInput == "yes");

    cout << "Exiting program." << endl;

    return 0;
}

