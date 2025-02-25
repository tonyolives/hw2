#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;

// ctor
Clothing::Clothing(const string category, const string name, double price, int qty, const string size, const string brand) :
    Product(category, name, price, qty), size_(size), brand_(brand) {}

set<string> Clothing::keywords() const {
    // return approriate keywords for this product: name_, brand_

    set<string> keys;

    // product name
    keys = parseStringToWords(name_);

    // clothign brand
    keys.insert(brand_);

    return keys;
}

string Clothing::displayString() const {
    ostringstream oss;
    oss << fixed << setprecision(2) << price_; // ✅ Two decimal places

    return name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + oss.str() + " " + to_string(qty_) + " left.";
}

void Clothing::dump(ostream& os) const {
    // outputs product info in database format
    os << "clothing\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}