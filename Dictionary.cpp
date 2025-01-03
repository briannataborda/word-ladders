/*
 * Dictionary.cpp
 * Brianna Taborda
 *
 * This is the implementation of the Dictionary class. The constructor
 * initializes the dictionary which is an unordered set by calling populateDict.
 * populateDict populates the dictionary by opening the dictionary file,
 * getting each word, trimming any whitespace, and inserting it into the
 * dictionary. wordExists verifies if a word exists in the dictionary and
 * insertWord was a test function used to check that wordExists is proper.
*/

#include "Dictionary.h"

/*
 * name:      Dictionary constructor   
 * purpose:   Constructor for the dictionary
 * arguments: the name of the dictionary file
 * returns:   none
 * effects:   constructs the dictionary
*/
Dictionary::Dictionary() {
    populateDict("dictionary.txt");
}

/*
 * name:      populateDict   
 * purpose:   To load the words from the dictionary file into an unordered set
 * arguments: the name of the file to act as a dictionary
 * returns:   none
 * effects:   populates the unordered set
*/
void Dictionary::populateDict(const std::string& filename) {
    std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open " + filename);
        }
    
    std::string word;
    while (std::getline(file, word)) { 
        //trims whitespace to ensure accurate lookup
        word.erase(word.begin(), std::find_if_not(word.begin(), word.end(), ::isspace));
        word.erase(std::find_if_not(word.rbegin(), word.rend(), ::isspace).base(), word.end());

        //make word uppercase and add to unordered set
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);
        dict.insert(word);
    }
    file.close();
}

/*
 * name:      wordExists
 * purpose:   checks if a word exists in a dictionary
 * arguments: a string representing the word being found
 * returns:   a boolean verifying if a word exists in a dictionary
 * effects:  none 
*/
bool Dictionary::wordExists(const std::string& word) const {
    std::string upWord = word;
    std::transform(upWord.begin(), upWord.end(), upWord.begin(), ::toupper);
    return dict.find(upWord) != dict.end(); //turns iterator into bool
}

//used for testing wordExists
void Dictionary::insertWord(const std::string& word) {
    std::string upWord = word;
    std::transform(upWord.begin(), upWord.end(), upWord.begin(), ::toupper);
    dict.insert(upWord);
}