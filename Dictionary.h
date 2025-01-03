/*
 * Dictionary.h
 * Brianna Taborda (btabor01)
 * 
 * The purpose of this class is to handle all opertions concerning the
 * dictionary such as initialization, lookup, and insertion.
*/

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Dictionary
{
public:
    Dictionary();
    void populateDict(const std::string& filename);
    bool wordExists(const std::string& word) const;
private:
    std::unordered_set<std::string> dict;
    void insertWord(const std::string& word);
};
#endif