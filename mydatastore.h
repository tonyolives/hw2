#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <vector>
#include <map>
#include <set>
#include "datastore.h"
#include "product.h"
#include "user.h"

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore();

    // required (virtual) functions from DataStore
    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;

    // user shopping carts stuff (cart functions)
    void addToCart(std::string username, Product* p);
    void viewCart(std::string username) const;
    void buyCart(std::string username);
private:
    std::vector<Product*> products_;  // stores products
    std::map<std::string, User*> users_;  // stores users by username
    std::map<std::string, std::set<Product*>> keywordMap_; // maps keywords to products
    std::map<std::string, std::vector<Product*>> carts_; // maps usernames to shopping carts

};

#endif