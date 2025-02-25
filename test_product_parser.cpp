#include "book.h"
#include "clothing.h"
#include "movie.h"
#include <iostream>

int main() {
    Book b("book", "C++ Primer", 45.99, 15, "978-013292372-9", "Lippman");
    Clothing c("clothing", "Hoodie", 29.99, 30, "Large", "Nike");
    Movie m("movie", "The Matrix", 12.99, 10, "Action", "R");

    std::cout << "Book:\n" << b.displayString() << "\n\n";
    std::cout << "Clothing:\n" << c.displayString() << "\n\n";
    std::cout << "Movie:\n" << m.displayString() << "\n\n";

    return 0;
}
