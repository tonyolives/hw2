#include "clothing.h"
#include <iostream>

int main() {
    Clothing c("clothing", "Men's Fitted Shirt", 39.99, 25, "Medium", "J. Crew");

    std::cout << "Keywords: ";
    for (const auto& kw : c.keywords()) {
        std::cout << kw << " ";
    }
    std::cout << "\n\nDisplay String:\n" << c.displayString() << std::endl;

    std::cout << "\nDump Output:\n";
    c.dump(std::cout);

    return 0;
}
