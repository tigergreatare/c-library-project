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
        cout << "Title: " << book.title
            << ", Author: " << book.author
            << ", ISBN: " << book.ISBN
            << ", Available: " << (book.isavailable ? "Yes" : "No") << endl;
    }
}

bool Library::borrowBook(int memberId, const string& ISBN) {
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
            cout << "Book not available or does not exist." << std::endl;
            return false; // Book not available or doesn't exist
        }
    }
    cout << "Member not found." << std::endl;
    return false; // Member not found
}

bool Library::returnBook(int memberId, const std::string& ISBN) {
    for (auto& member : members) {
        if (member.ID == memberId) {
            for (auto it = member.BorrowedBooks.begin(); it != member.BorrowedBooks.end(); ++it) {
                if ((*it)->ISBN == ISBN) {
                    (*it)->isavailable = true; // Mark the book as available
                    cout << member.name << " returned " << (*it)->title << std::endl;
                    member.BorrowedBooks.erase(it); // Remove from member's list
                    return true;
                }
            }
            cout << "This book was not borrowed by the member." << std::endl;
            return false; // Book was not borrowed by the member
        }
    }
    cout << "Member not found." << std::endl;
    return false; // Member not found
}

void Library::addBookFromUserInput() {
    string title, author, isbn;
    cin.ignore();
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

void Library::displayMembers() {
    for (const auto& member : members) {
        cout << "Name: " << member.name << ", ID: " << member.ID << endl;
    }
}

void Library::editBook(const string& ISBN) {
    for (auto& book : books) {
        if (book.ISBN == ISBN) {
            string newTitle, newAuthor;
            cout << "Enter new title (or press enter to keep the current title): ";
            getline(cin, newTitle);
            cout << "Enter new author (or press enter to keep the current author): ";
            getline(cin, newAuthor);
            if (!newTitle.empty()) book.title = newTitle;
            if (!newAuthor.empty()) book.author = newAuthor;
            cout << "Book details updated!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

Book* Library::searchBookByTitle(const string& title) {
    for (auto& book : books) {
        if (book.title == title) {
            return &book;
        }
    }
    return nullptr; 
}

Book* Library::searchBookByISBN(const string& ISBN) {
    for (auto& book : books) {
        if (book.ISBN == ISBN) {
            return &book;
        }
    }
    return nullptr; 
}

