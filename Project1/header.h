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

	Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isavailable(true){}

};
class Member{
public:
	string name;
	int ID;
	vector<Book*> BorrowedBooks;

	Member(string n, int id) : name(n), ID(id){}
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
	bool borrowBook(int memberId, const string& ISBN);
	bool returnBook(int memberId, const string& ISBN);
	void addBookFromUserInput();
};
// add a function that takes the user input and store the Book as registered member
// add another function that display all added members and it need to seperate the user input from the auto registered members 
// we can also read data from a csv file, as a source file 
// two functions DUE 10/15/2024
// data file DUE 10/17/2024 