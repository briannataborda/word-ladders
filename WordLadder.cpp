/*
 *  WordLadder.cpp
 *  Brianna Taborda
 *
 * This is the implementation of the WordLadder class. The constructor
 * automatically loads the dictionary. operationOne runs getLadder from the
 * Ladder class so that the shortest ladder is found and printed out.
 * operationTwo runs otherWords from the Ladder class and returns an int 
 * representing the number of words that could possibly be found from an input
 * word to be printed out accordingly in main. 
*/

#include "WordLadder.h"

/*
 * name:      WordLadder
 * purpose:   constructor for WordLadder class
 * arguments: a Dictionary object
 * returns:   none
 * effects:   same as purpose
*/
WordLadder::WordLadder() : dict() {
    //loads automatically now that dictionary.txt is hardcoded in Dictionary.cpp
}

/*
 * name:      operationOne
 * purpose:   run methods needed for OP_CODE 1
 * arguments: a start word and an end word
 * returns:   none
 * effects:   none
*/
void WordLadder::operationOne(std::string& start, std::string& end) {
    Ladder ladder(dict);
    std::vector<std::string> shortest = ladder.getLadder(start, end);

    if (!shortest.empty()) {
        cout << " Word-ladder between " << start << " and " << end << " of length "
        << shortest.size() << " has been found:" << endl;
        for (size_t i = 0; i < shortest.size(); i++) {
            cout << "\t" << shortest[i] << endl;
        }
    } else {
        cout << " No word-ladder possible between " << start << " and " << end 
        << "." << endl;    
    }
}

/*
 * name:      operationTwo
 * purpose:   run methods needed for OP_CODE 2
 * arguments: a string representing a word
 * returns:   an int representing the number of other words
 * effects:   none
*/
int WordLadder::operationTwo(std::string& word) {
    Ladder ladder(dict);
    return ladder.otherWords(word);
}