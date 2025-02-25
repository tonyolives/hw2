#include "movie.h"
#include <iostream>

int main() {
    Movie m("movie", "Inception", 14.99, 10, "Sci-Fi", "PG-13");

    std::cout << "Keywords: ";
    for (const auto& kw : m.keywords()) {
        std::cout << kw << " ";
    }
    std::cout << "\n\nDisplay String:\n" << m.displayString() << std::endl;

    std::cout << "\nDump Output:\n";
    m.dump(std::cout);

    return 0;
}
