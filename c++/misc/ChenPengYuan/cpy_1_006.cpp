#include <iostream>
#include <vector>

class Book {
public:
    Book(std::string title, std::string author, int year)
            : title_(title), author_(author), year_(year) {}

    std::string GetTitle() const { return title_; }
    std::string GetAuthor() const { return author_; }
    int GetYear() const { return year_; }

private:
    std::string title_;
    std::string author_;
    int year_;
};

class Library {
public:
    void AddBook(const Book& book) {
        books_.push_back(book);
    }

    Book* FindBookByTitle(const std::string& title) {
        for (auto& book : books_) {
            if (book.GetTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    size_t CountBooksByAuthor(const std::string& author) {
        size_t count = 0;
        for (auto& book : books_) {
            if (book.GetAuthor() == author) {
                ++count;
            }
        }
        return count;
    }

private:
    std::vector<Book> books_;
};

int main() {
    Library library;
    library.AddBook(Book("The C++ Programming Language", "Bjarne Stroustrup", 2013));
    library.AddBook(Book("Effective Modern C++", "Scott Meyers", 2014));

    Book* found = library.FindBookByTitle("Effective Modern C++");
    if (found != nullptr) {
        std::cout << "Found book: " << found->GetTitle() << ", Author: " << found->GetAuthor() << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }

    std::cout << "Books by Bjarne Stroustrup: " << library.CountBooksByAuthor("Bjarne Stroustrup") << std::endl;

    return 0;
}
