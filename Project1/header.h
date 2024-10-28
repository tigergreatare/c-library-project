#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isavailable;

    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isavailable(true) {}
};

class Member {
public:
    string name;
    int ID;
    vector<Book*> BorrowedBooks;

    Member(string n, int id) : name(n), ID(id) {}
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Member> userAddedMembers;
public:
    void addBook(const Book& book);
    void registerMember(const Member& member);
    void registerUserAddedMember(const Member& member);
    void displayBook();
    void displayMembers();  // New function to display all members
    bool borrowBook(int memberId, const string& ISBN);
    bool returnBook(int memberId, const string& ISBN);
    void addBookFromUserInput();
    void editBook(const string& ISBN);  // New function to edit book details
    Book* searchBookByTitle(const string& title);  // New function to search for a book by title
    Book* searchBookByISBN(const string& ISBN);  // New function to search for a book by ISBN
};



// we can also read data from a csv file, as a source file 
// data file due date : 11/9/2024