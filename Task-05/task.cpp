#include <iostream>
#include <vector>
#include <string>

// Book structure to store book details
struct Book {
    std::string title;
    std::string author;
    bool available;

    Book(const std::string& t, const std::string& a) : title(t), author(a), available(true) {}
};

// Borrower structure to store borrower details
struct Borrower {
    std::string name;
    int borrowerID;

    Borrower(const std::string& n, int id) : name(n), borrowerID(id) {}
};

// Transaction structure to store transaction details
struct Transaction {
    Book* book;
    Borrower* borrower;
    bool checkOut; // true for check-out, false for return

    Transaction(Book* b, Borrower* br, bool co) : book(b), borrower(br), checkOut(co) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Borrower> borrowers;
    std::vector<Transaction> transactions;
    int nextBorrowerID;

public:
    Library() : nextBorrowerID(1) {}

    // Function to add a book to the library
    void addBook(const std::string& title, const std::string& author) {
        books.emplace_back(title, author);
        std::cout << "Book added to the library.\n";
    }

    // Function to add a borrower to the library
    void addBorrower(const std::string& name) {
        borrowers.emplace_back(name, nextBorrowerID++);
        std::cout << "Borrower added to the library.\n";
    }

    // Function to perform a book transaction (check-out or return)
    void performTransaction(int bookIndex, int borrowerIndex, bool checkOut) {
        if (bookIndex >= 0 && bookIndex < books.size() &&
            borrowerIndex >= 0 && borrowerIndex < borrowers.size()) {

            Book& book = books[bookIndex];
            Borrower& borrower = borrowers[borrowerIndex];

            if (checkOut) {
                if (book.available) {
                    transactions.emplace_back(&book, &borrower, true);
                    book.available = false;
                    std::cout << "Book checked out successfully.\n";
                } else {
                    std::cout << "Book is not available for check-out.\n";
                }
            } else {
                auto it = std::find_if(transactions.begin(), transactions.end(),
                                       [&book, &borrower](const Transaction& t) {
                                           return t.book == &book && t.borrower == &borrower && t.checkOut;
                                       });

                if (it != transactions.end()) {
                    transactions.erase(it);
                    book.available = true;
                    std::cout << "Book returned successfully.\n";
                } else {
                    std::cout << "Book is not checked out by this borrower.\n";
                }
            }
        } else {
            std::cout << "Invalid book or borrower index.\n";
        }
    }

    // Function to display information about books in the library
    void displayBooks() const {
        if (books.empty()) {
            std::cout << "No books in the library.\n";
        } else {
            std::cout << "Books in the library:\n";
            for (size_t i = 0; i < books.size(); ++i) {
                std::cout << i + 1 << ". ";
                std::cout << "Title: " << books[i].title << ", Author: " << books[i].author;
                std::cout << ", Status: " << (books[i].available ? "Available" : "Checked Out") << '\n';
            }
        }
    }

    // Function to display information about borrowers in the library
    void displayBorrowers() const {
        if (borrowers.empty()) {
            std::cout << "No borrowers in the library.\n";
        } else {
            std::cout << "Borrowers in the library:\n";
            for (size_t i = 0; i < borrowers.size(); ++i) {
                std::cout << i + 1 << ". ";
                std::cout << "Name: " << borrowers[i].name << ", Borrower ID: " << borrowers[i].borrowerID << '\n';
            }
        }
    }
};

int main() {
    Library library;


    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBorrower("Alice Johnson");
    library.addBorrower("Bob Smith");


    library.displayBooks();
    library.displayBorrowers();

    
    library.performTransaction(0, 0, true); 
    library.performTransaction(1, 1, true); 

    library.displayBooks();

   
    library.performTransaction(0, 0, false); // Return "The Catcher in the Rye" from Alice Johnson

    library.displayBooks();

    return 0;
}
