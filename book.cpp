#include "book.h"
#include "util.h"
#include <iomanip>
#include <sstream>


using namespace std;

Book::Book(const string category, const string name, double price, int qty, const string isbn, const string author) :
    Product(category, name, price, qty), isbn_(isbn), author_(author) {}

set<string> Book::keywords() const {

    // return appropriate keywords for book: name_, isbn, author
    set<string> keys;

    // product name
    keys = parseStringToWords(name_);

    // author name
    set<string> authorKeys = parseStringToWords(author_);
    keys.insert(authorKeys.begin(), authorKeys.end());

    // book isbn number
    keys.insert(isbn_);

    return keys;
}

string Book::displayString() const {
    ostringstream oss;
    oss << fixed << setprecision(2) << price_; // Ensure two decimal places

    return name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + oss.str() + " " + to_string(qty_) + " left.";
}

// output product info in database format
void Book::dump(ostream& os) const {
    os << "book\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}