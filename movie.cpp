#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;

// ctor
Movie::Movie(const string category, const string name, double price, int qty, const string genre, const string rating) :
    Product(category, name, price, qty), genre_(genre), rating_(rating) {}

set<string> Movie::keywords() const {
    // returns appropriate keywords for movie: genre_, name_
    set<string> keys;

    // product name
    keys = parseStringToWords(name_);

    // movie genre
    keys.insert(genre_);

    return keys;
}

string Movie::displayString() const {
    ostringstream oss;
    oss << fixed << setprecision(2) << price_; // ✅ Two decimal places

    return name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + oss.str() + " " + to_string(qty_) + " left.";
}

void Movie::dump(ostream& os) const {
    os << "movie\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}