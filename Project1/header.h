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
public:
	void addBook(const Book& book);
	void registerMember(const Member& member);
	void displayBook();
	bool borrowBook(int memberId, const string& ISBN);
	bool returnBook(int memberId, const string& ISBN);
};