#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    // product name, book author, clothing brand: any string more than 2 chars
    // split at each punctuation, resulting substrings (2 or more chars) should also be used as keywords

    // convert to lower
    rawWords = convToLower(rawWords);

    // result set
    set<string> keywords;
    string word;

    for (char c : rawWords) {
        // check if space or punctuation
        if (c == '\'' || c == ':' || c == ',' || c == '.' || c == ' ') {
            // it is space or punct, check if valid word
            if (word.size() >= 2) {
                // valid, add to keywords
                keywords.insert(word);
            }
            // clear word
            word.clear();
        }
        else {
            // not space or punct, add to word
            word += c;
        }
    }

    // insert last word if valid
    if (word.size() >= 2) {
        keywords.insert(word);
    }

    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/


// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}