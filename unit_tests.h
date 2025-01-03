/*
 * Brianna Taborda (btabor01)
 * 
 * Unit testing to ensure the funtionality and accuracy of Dictionary and Ladder
 * Note: these tests all worked before I hardcoded dictionary.txt into the
 *       constructors.
*/

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include "Dictionary.h"
#include "Ladder.h"

/*                            DICTIONARY TESTS                                */

//tests that wordExists is working properly
void wordExists_test() {
    Dictionary d;
    std::string apple = "apple";
    std::string boy = "boy";

    d.insertWord(apple);
    d.insertWord(boy);

    //valid words
    assert(d.wordExists("APPLE") == true);
    assert(d.wordExists("BOY") == true);
    //invalid words
    assert(d.wordExists("PLOT") == false);
    //case insensitivity
    assert(d.wordExists("boy") == true);
    assert(d.wordExists("apple") == true);
}

//tests that populate Dict works correctly
void populateDict_test() {
    const std::string testFile = "testDict.txt";
    Dictionary d(testFile); //runs populate Dict
    //d.populateDict(testFile);

    //uppercase words
    assert(d.wordExists("APPLE") == true);
    assert(d.wordExists("BOY") == true);
    assert(d.wordExists("COFFEE") == true);
    assert(d.wordExists("TOY") == true);
    assert(d.wordExists("PLACES") == true);

    //lowercase words
    assert(d.wordExists("apple") == true);
    assert(d.wordExists("boy") == true);
    assert(d.wordExists("coffee") == true);
    assert(d.wordExists("toy") == true);
    assert(d.wordExists("places") == true);

    //invalid words
    assert(d.wordExists("PONY") == false);
    assert(d.wordExists("brianna") == false);
}

/*                              LADDER TESTS                                  */

//tests getNeighbors
void getNeighbors_test() {
    const std::string testFile = "testDict.txt";
    Dictionary dict(testFile);
    Ladder l(dict);

    //valid cases
    std::vector<std::string> neighbors = l.getNeighbors("BOY");
    assert(std::find(neighbors.begin(), neighbors.end(), "TOY") != neighbors.end());
    assert(std::find(neighbors.begin(), neighbors.end(), "COY") != neighbors.end());

    //invalid case
    neighbors = l.getNeighbors("APPLE");
    assert(neighbors.empty());

    //not in dictionary
    neighbors = l.getNeighbors("A");
    assert(neighbors.empty());

    //single letter
    std::vector<std::string> single = l.getNeighbors("D");
    assert(std::find(single.begin(), single.end(), "H") != single.end());
    assert(std::find(single.begin(), single.end(), "J") != single.end());
}

//tests getLadder
void getLadder_test() {
    const std::string testFile = "testDict.txt";
    Dictionary dict(testFile);
    Ladder l(dict);

    //valid case
    std::vector<std::string> ladder1 = l.getLadder("BOY", "GOT");
    std::vector<std::string> answer1 = {"BOY", "COY", "COT", "GOT"};

    //same word
    std::vector<std::string> ladder2 = l.getLadder("PLACES", "PLACES");
    std::vector<std::string> answer2 = {"PLACES"};

    //invalid
    std::vector<std::string> ladder3 = l.getLadder("GOT", "BIN");

    //single letter
    std::vector<std::string> ladder4 = l.getLadder("D", "J");
    std::vector<std::string> answer4 = {"D", "J"};
    
    assert(ladder1 == answer1);
    assert(ladder2 == answer2);
    assert(ladder3.empty());
    assert(ladder4 == answer4);
}

//tests getLadder on an empty dictionary
void getLadder_empty_test() {
    const std::string testFile = "empty.txt";
    Dictionary dict(testFile);
    Ladder l(dict);

    std::vector<std::string> ladder = l.getLadder("BOY", "GOT");
    assert(ladder.empty());
}

//tests getLadder on large dictionary
void getLadder_large_test() {
    const std::string testFile = "dictionary.txt";
    Dictionary dict(testFile);
    Ladder l(dict);

    std::vector<std::string> ladder = l.getLadder("DOG", "CAT");
    assert(ladder.size() == 4);
}

//tests otherWords
void otherWords_test() {
    const std::string testFile = "testDict.txt";
    Dictionary dict(testFile);
    Ladder l(dict);

    //valid
    int test1 = l.otherWords("BOY");
    assert(test1 == 4);

    //invalid - no neighbors
    int test2 = l.otherWords("PLACES");
    assert(test2 == 0);

    //not in word list
    int test3 = l.otherWords("PIE");
    assert(test3 == -1);
}

//tests otherWords on large dictionary
void otherWords_large_test() {
    const std::string testFile = "dictionary.txt";
    Dictionary dict(testFile);
    Ladder l(dict);

    int test = l.otherWords("TUMOR");
    assert(test == 8417);
}