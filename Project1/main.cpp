#include "header.h"
using namespace std;

int main() {
    Library library;

    // Add books
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "123456789"));
    library.addBook(Book("1984", "George Orwell", "987654321"));

    // Register members
    library.registerMember(Member("Alice", 1));
    library.registerMember(Member("Bob", 2));

    // Display books
    library.displayBook();

    // Add a book from user input
    library.addBookFromUserInput();

    // Display books again after adding the new book
    library.displayBook();

    // Borrow books
    library.borrowBook(1, "123456789"); // Alice borrows The Great Gatsby

    // Display books again
    library.displayBook();

    // Return book
    library.returnBook(1, "123456789"); // Alice returns The Great Gatsby

    // Display books again
    library.displayBook();

    return 0;
}
