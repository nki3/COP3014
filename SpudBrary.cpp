//
// Created by NateB on 4/13/2025.
//

#include <iomanip>
#include <iostream>


struct Book {
    std::string title;
    std::string author;
    int pubYear;
    int id;
};

void truncate(std::string& string, int length, const std::string& message) {
    // Truncate a string to a specific length and output a message alerting the user
    if (string.length() > length) {
        string = string.substr(0, length);
        printf("Note: %s has been truncated to %i characters.\n", message.c_str(), length);
    }
}

void addBook(Book books[], int& count, int& nextId) {

    if (count == 10) {
        std::cout << "Library is full!" << std::endl;
        return;
    }
    std::string title;
    std::string author;
    int pubYear;

    // The nextId variable will never decrease ever. Each book receives a unique id that increments to infinity.
    nextId++;
    count++;
    int bookIndex = count - 1;
    books[bookIndex].id = nextId;
    std::cout << "Enter book title (15 characters max): ";
    std::getline(std::cin, title);

    const int max_title_length = 15;
    truncate(title, max_title_length, "Title");
    books[bookIndex].title = title;

    std::cout << "Enter book author (30 characters max): ";
    std::getline(std::cin, author);

    const int max_author_length = 30;
    truncate(author, max_author_length, "Author name");
    books[bookIndex].author = author;

    std::cout << "Enter publication year: ";
    std::string pubYear_string;
    std::getline(std::cin, pubYear_string);
    pubYear = stoi(pubYear_string);

    books[bookIndex].pubYear = pubYear;
    std::cout << "Book added successfully!" << std::endl;
}

void displayBooks(const Book books[], int count) {
    std::cout << std::endl << "Books in Library:" << std::endl;

    // Loop through every book in the library
    for (int i = 0; i < count; i++) {
        const int id_width = 2;
        const int title_width = 15;
        const int author_width = 30;
        const int year_width = 4;

        // Format output for each book
        std::cout << "ID: " << std::right << std::setw(id_width) << books[i].id;
        std::cout << ", Title: " << std::left << std::setw(title_width) << books[i].title.c_str();
        std::cout << ", Author: " << std::left << std::setw(author_width) << books[i].author.c_str();
        std::cout << ", Year: " << std::left << std::setw(year_width) << books[i].pubYear << std::endl;
    }
}

void removeBook(Book books[], int &count) {
    int id;
    std::cout << "Enter book ID to remove: ";
    std::string id_string;
    std::getline(std::cin, id_string);
    id = stoi(id_string);
    bool found = false;
    // Loop through each book in the array
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = true;
        }
        // Shift each book after the condition one
        if (found) {
            books[i] = books[i + 1];
        }
    }
    if (!found) {
        std::cout << "Book ID not found." << std::endl;
    } else {
        count--;
        std::cout << "Book removed successfully!" << std::endl;
    }
}

void displayMenu(Book books[10], int& id, int& total_books, bool& finished) {
    int option;
    std::cout << "Welcome to the Library Management System" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Remove Book" << std::endl;
    std::cout << "3. Display Books" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose an option: ";
    std::string option_string;
    std::getline(std::cin, option_string);
    option = stoi(option_string);

    switch (option) {
        case 1: addBook(books, total_books, id); break;
        case 2: removeBook(books, total_books); break;
        case 3: displayBooks(books, total_books); break;
        case 4: finished = true; break;
        default: std::cout << "Invalid option. Please try again." << std::endl; break;
    }
}

int main() {
    Book books[10];
    int id = 0;
    int total_books = 0;
    bool finished = false;

    while (!finished) {
        displayMenu(books, id, total_books, finished);
    }
    std::cout << "Exiting the program..." << std::endl;
    return 0;
}