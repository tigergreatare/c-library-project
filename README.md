Library Management System:
Welcome to the Library Management System project! This C++ application provides a user-friendly interface for managing a library's collection of books and members. Users can easily add new books, register library members, and facilitate book borrowing and returning processes. The system maintains up-to-date records of available books and tracks borrowed items for each member. This project is designed to help users efficiently manage their library resources, making it an ideal solution for small libraries or personal collections. Future enhancements will include additional features such as search functionalities, user authentication, and improved data storage options. Feel free to contribute and explore the code!
**functionalities**
1. **addBook**:
    - Adds a new Book object to the library's books list by using push_back.
    - **Concepts**: Basic use of C++ STL's vector container to store and manage collections.
2. **registerMember & registerUserAddedMember**:
    - Adds a Member object to either the members or userAddedMembers list.
    - **Concepts**: Similar to addBook, these functions demonstrate vector manipulation and help organize members into different lists.
3. **displayBook**:
    - Loops through each book in books and displays the title, author, ISBN, and availability.
    - **Concepts**: for loop with constant reference (const auto&) to avoid unnecessary copying and cout for output formatting.
4. **borrowBook**:
    - Searches for a member by ID, then checks for an available book by ISBN.
    - If the book is available, marks it as borrowed, adds it to the member's list, and outputs a message.
    - **Concepts**: Nested for loop to search collections, pointer usage (BorrowedBooks.push_back(&book)) for referencing the actual book object, and early return for efficiency.
5. **returnBook**:
    - Similar to borrowBook, but checks if a member has a specific book in their BorrowedBooks.
    - Marks the book as available, removes it from the member’s list, and returns true if successful.
    - **Concepts**: Iterator (it) for efficient element removal, dereferencing (\*it), and control statements for member-specific checking.
6. **addBookFromUserInput**:
    - Prompts the user for book details and creates a new Book object.
    - **Concepts**: cin.ignore() to handle newline characters after cin operations, getline for multi-word strings, and dynamic object creation.
7. **displayMembers**:
    - Displays each member’s name and ID.
    - **Concepts**: Basic looping through members list and use of cout for formatting.
8. **editBook**:
    - Searches for a book by ISBN, allows updating its title and author, and applies the changes if non-empty.
    - **Concepts**: Conditionals to handle empty input and avoid unnecessary updates, getline for string inputs.
9. **searchBookByTitle & searchBookByISBN**:
    - Searches for a book by title or ISBN, respectively, and returns a pointer to the book if found.
    - **Concepts**: Loop with early return for efficiency, pointer return to allow external access to the book object, and nullptr to signify absence.

Each function integrates C++ standard concepts like STL containers, pointers, iterators, conditionals, and formatted input/output, providing a foundation for library management in object-oriented programming.
