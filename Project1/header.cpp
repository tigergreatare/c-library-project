#include "header.h"
using namespace std;

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::registerMember(const Member& member) {
    members.push_back(member);
}
void Library::registerUserAddedMember(const Member& member) {
    userAddedMembers.push_back(member);
}
void Library::displayBook() {
    for (const auto& book : books) {
        std::cout << "Title: " << book.title
            << ", Author: " << book.author
            << ", ISBN: " << book.ISBN
            << ", Available: " << (book.isavailable ? "Yes" : "No") << endl;
    }
}

bool Library::borrowBook(int memberId, const std::string& ISBN) {
    for (auto& member : members) {
        if (member.ID == memberId) {
            for (auto& book : books) {
                if (book.ISBN == ISBN && book.isavailable) {
                    book.isavailable = false; // Mark the book as borrowed
                    member.BorrowedBooks.push_back(&book); // Add to member's list
                    std::cout << member.name << " borrowed " << book.title << std::endl;
                    return true;
                }
            }
            std::cout << "Book not available or does not exist." << std::endl;
            return false; // Book not available or doesn't exist
        }
    }
    std::cout << "Member not found." << std::endl;
    return false; // Member not found
}

bool Library::returnBook(int memberId, const std::string& ISBN) {
    for (auto& member : members) {
        if (member.ID == memberId) {
            for (auto it = member.BorrowedBooks.begin(); it != member.BorrowedBooks.end(); ++it) {
                if ((*it)->ISBN == ISBN) {
                    (*it)->isavailable = true; // Mark the book as available
                    std::cout << member.name << " returned " << (*it)->title << std::endl;
                    member.BorrowedBooks.erase(it); // Remove from member's list
                    return true;
                }
            }
            std::cout << "This book was not borrowed by the member." << std::endl;
            return false; // Book was not borrowed by the member
        }
    }
    std::cout << "Member not found." << std::endl;
    return false; // Member not found
}
void Library::addBookFromUserInput() {
    string title, author, isbn;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book ISBN: ";
    getline(cin, isbn);

    Book newBook(title, author, isbn);
    addBook(newBook);
    cout << "Book added successfully!" << endl;
}
