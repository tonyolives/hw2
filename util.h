#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    // set intersection == items both sets have
    std::set<T> result;

    // look at first set
    for (typename std::set<T>::iterator it1 = s1.begin(); it1 != s1.end(); ++it1) {
        // check if current item in s1 is present in s2
        if (s2.find(*it1) != s2.end()) {
            // found! add to result set
            result.insert(*it1);
        }
    }

    return result;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    // set union = all items from both sets
    std::set<T> result;

    // add s1 to result
    result = s1;

    // add s2 to result (set auto detects duplicates)
    for (typename std::set<T>::iterator it1 = s2.begin(); it1 != s2.end(); ++it1) {
        result.insert(*it1);
    }

    return result;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
