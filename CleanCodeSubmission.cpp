#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(string titleOfBook, string authorOfBook, int year) : title(titleOfBook), author(authorOfBook), publicationYear(year) {}

    //getters
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getPublicationYear()  {
        return publicationYear;
    }


    //setters
    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setPublicationYear(int year) {
        publicationYear = year;
    }
};

class Library {
private:
    vector<Book> books;

public:
   
    void addBookToLibrary(const Book& book) {
        books.push_back(book);
    }

    
    vector<Book> searchBookByTitle(string title)  {
        vector<Book> result;
        for (const Book& book : books) {
            if (book.getTitle() == title) {
                result.push_back(book);
            }
        }
        return result;
    }

    
    vector<Book> searchBookByAuthor(string author)  {
        vector<Book> result;
        for (const Book& book : books) {
            if (book.getAuthor() == author) {
                result.push_back(book);
            }
        }
        return result;
    }

    int getTotalNumberOfBooksInLibrary() {
        return books.size();
    }
};

int main() {
    // Create some books
    Book book1("Book 1", "Author A", 2000);
    Book book2("Book 2", "Author B", 2010);

    // Create a library
    Library library;

    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);


    vector<Book> authorBooks = library.searchBookByAuthor("Author A");
    cout << "Books by Author A:" << endl;
    for (const Book& book : authorBooks) {
        cout << book.getTitle() << " (" << book.getPublicationYear() << ")" << endl;
    }

    cout << "Total number of books in the library: " << library.getTotalNumberOfBooksInLibrary() << endl;

    return 0;
}
