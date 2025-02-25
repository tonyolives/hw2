#include "book.h"
#include <iostream>

int main() {
    Book b("book", "C++ Programming", 39.99, 10, "978-013292372-9", "Bjarne Stroustrup");

    std::cout << "Keywords: ";
    for (const auto& kw : b.keywords()) {
        std::cout << kw << " ";
    }
    std::cout << "\n\nDisplay String:\n" << b.displayString() << std::endl;

    std::cout << "\nDump Output:\n";
    b.dump(std::cout);
    
    return 0;
}
