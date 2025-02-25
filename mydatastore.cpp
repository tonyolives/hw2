#include "mydatastore.h"
#include "util.h"
#include <iostream>

#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {
    // free dyn alloc products

    // loop through vector of products
    for (size_t i = 0; i < products_.size(); i++) {
        delete products_[i];
    }
    // free dyn alloc users
    for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        delete it->second;
    }
}

// adding prod and users

void MyDataStore::addProduct(Product* p) {
    products_.push_back(p);

    // get keywords anf index them
    set<string> keys = p->keywords();

    // iterate through keyword set
    for (set<string>::iterator it = keys.begin(); it != keys.end(); ++it) {
        keywordMap_[*it].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    users_[u->getName()] = u;
}

// searching

vector<Product*> MyDataStore::search(vector<string>& terms, int type) {
    set<Product*> results;
    bool firstTerm = true;

    // iterate thru string
    for (size_t i = 0; i < terms.size(); i++) {
        string term = convToLower(terms[i]); // make lowercase

        if (keywordMap_.find(term) != keywordMap_.end()) {
            if (firstTerm) {
                results = keywordMap_[term]; // first term initializes results
                firstTerm = false;
            }
            else {
                if (type == 0) { // AND search
                    results = setIntersection(results, keywordMap_[term]);
                }
                else { // OR search
                    results = setUnion(results, keywordMap_[term]);
                }
            }
        }
        // AND search with no missing term = no reaults
        else if (type == 0) {
            return vector<Product*>();
        }
    }

    return vector<Product*>(results.begin(), results.end());
}

void MyDataStore::dump(ostream& ofile) {
    // [PRODUCT] section
    ofile << "<products>" << endl;

    // iter over products and write each product
    for (size_t i = 0; i < products_.size(); i++) {
        products_[i]->dump(ofile); // dumps in correct format
    }

    ofile << "</products>" << endl;

    // [USERS] section
    ofile << "<users>" << endl;

    // iter over users and write each
    for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        it->second->dump(ofile); // writes in correct format
    }
    ofile << "</users>" << endl;
}

 // user shopping carts stuff (cart functions)
 void MyDataStore::addToCart(string username, Product* p) {
    // username not found
    if (users_.find(username) == users_.end()) {
        cout << "Invalid request" << endl;
        return;
    }
    // add to username's cart
    carts_[username].push_back(p);
 }

 void MyDataStore::viewCart(string username) const {
    // get iterator of username's cart
    map<string, vector<Product*> >::const_iterator userCart = carts_.find(username);

    // username not found
    if (userCart == carts_.end()) {
        cout << "Invalid username" << endl;
        return;
    }
    // cart is empty
    if (userCart->second.empty()) {
        cout << "Cart is empty!" << endl;
        return;
    }
    // at this point cart is valid = display
    for (size_t i = 0; i < userCart->second.size(); ++i) {
        cout << "Item " << (i + 1) << ":\n" << userCart->second[i]->displayString() << "\n" << endl;
    }
 }

 void MyDataStore::buyCart(string username) {
    // get user iterator
    map<string, User*>::iterator userIt = users_.find(username);

    // user not found
    if (userIt == users_.end()) {
        cout << "Invalid username" << endl;
        return;
    }

    // user found -> assign
    User* user = userIt->second;
    
    // cart iterator
    map<string, vector<Product*> >::iterator cartIt = carts_.find(username);
    
    // cart not found
    if (cartIt == carts_.end()) return;

    vector<Product*> newCart;

    // iter through cart
    for (size_t i = 0; i < cartIt->second.size(); i++) {
        Product* p = cartIt->second[i];

        if (p->getQty() > 0 && user->getBalance() >= p->getPrice()) {
            p->subtractQty(1);
            user->deductAmount(p->getPrice());
        } else {
            newCart.push_back(p); // keep unpurchased items in cart
        }
    }
    cartIt->second = newCart; // update cart
 }