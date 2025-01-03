/*
 * Ladder.cpp
 * Brianna Taborda
 *
 * This is the implementation of the Ladder class. The constructor automatically
 * loads in the hard-coded dictionary.txt file. getNeighbors is a helper
 * function for getLadder which stores all of the neighbors of a given word in
 * a vector of strings. getLadder stores the shortest ladder between a start and
 * end word in a vector of strings. If the start and end word are the same, the
 * vector just contains the start word and if no ladder is found, an empty
 * vector is returned. This functions is called to complete the operations
 * associated with OP_CODE 1. otherWords also uses getNeighbors to find all of
 * the words that can be created from the given word from any number of
 * transformations. Both getLadders and otherWords use BFS search. 
*/

#include "Ladder.h"

/*
 * name:      Ladder constructor
 * purpose:   initialize the dictionary for the Ladder class
 * arguments: a Dictionary object
 * returns:   none
 * effects:   same as purpose 
*/
Ladder::Ladder(Dictionary& dict) : dictionary(dict) {
    //Constructor
}

/*
 * name:      getNeighbors
 * purpose:   store all words in dictionary that differ by one letter from 
              original word
 * arguments: a string of a word passed by value since we don't have to modify
              the word itself
 * returns:   a vector of string holding all the neighbors
 * effects:   none
*/
std::vector<std::string> Ladder::getNeighbors(std::string word) {
    std::vector<std::string> neighbors = {};

    //ensures word is in dictionary
    if (dictionary.wordExists(word) != true) {
        return neighbors;
    }

    //goes through each character in word to check for neighbors
    for (size_t i = 0; i < word.size(); i++) { 
        std::string diffWord = word;
        for (char diff = 'A'; diff <= 'Z'; diff++) { //increments character
            diffWord[i] = diff; 
            if ((dictionary.wordExists(diffWord) == true) and (diffWord != word)) {
                neighbors.push_back(diffWord);
            }
        }
    }
    return neighbors;
}

/*
 * name:      getLadder
 * purpose:   return the shortest ladder if there exists one btwn two words
 * arguments: a start word and an end word
 * returns:   a vector of string representing the shortest ladder
 * effects:   same as purpose
*/
std::vector<std::string> Ladder::getLadder(std::string start, std::string end) {
    std::queue<std::vector<std::string>> shortest; //queue of ladders
    std::unordered_set<std::string> marked; //set of marked words to avoid redundancy

    //start word is same as end word, the ladder is itself
    if (start == end) {
        return {start};
    }

    //start with the start word
    shortest.push({start});
    marked.insert(start);

    //BFS search
    while(!shortest.empty()) {
        std::vector<string> currLadder = shortest.front(); 
        shortest.pop();
        std::string last = currLadder.back();
        std::vector<std::string> neighbors = getNeighbors(last);

        //BFS Search
        for (size_t i = 0; i < neighbors.size(); i++) {
            //if the neighbor hasn't been visited before, create a new ladder with it
            if (marked.find(neighbors[i]) == marked.end()) {
                marked.insert(neighbors[i]);
                std::vector<std::string> newLadder = currLadder;
                newLadder.push_back(neighbors[i]);
                //if the neighbor is the target word, we have found our shortest ladder
                if (neighbors[i] == end) {
                    return newLadder;
                }
            //otherwise, add the ladder to the queue to be explored later
            shortest.push(newLadder);
            }
        }
    }
    return {}; //if no vector is found
}

/*
 * name:      otherWords
 * purpose:   return the number of other words that can be created 
 * arguments: a string representing the word
 * returns:   an int representing how many words can be created from one word
 * effects:   none
*/
int Ladder::otherWords(std::string word) {
    int count = 0;
    std::unordered_set<std::string> marked; //set of marked words to avoid redundancy
    std::queue<std::string> total; //queue of words that can be created from word

    //if words is not in dictionary
    if (dictionary.wordExists(word) != true) {
        return -1;
    }

    total.push(word);
    marked.insert(word);

    while (!total.empty()) {
        std::string currWord = total.front();
        total.pop();
        std::vector<std::string> neighbors = getNeighbors(currWord);
        //same BFS logic from getLadder
        for (size_t i = 0; i < neighbors.size(); i++) {
            //check if word has already been visited
            if (marked.find(neighbors[i]) == marked.end()) {
                marked.insert(neighbors[i]);
                total.push(neighbors[i]);
                count++;
            }
        }
    }
    return count;
}

