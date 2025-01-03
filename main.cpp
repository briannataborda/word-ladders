/*
 * main.cpp
 * Brianna Taborda (btabor01)
 *
 * Main.cpp opens and closes the dictionary and input files and throws errors
 * when needed. It uses the arguments and calls upon specific functions in the
 * WordLadder class based on the operation code specified in the arguments. 
 */

#include <iostream>
#include <cctype>
#include "WordLadder.h"
using namespace std;

/*
 * name:      main
 * purpose:   starts the program
 * arguments: the files provided by the user (int argc and char *argv[])
 * returns:   an integer
 * effects:   calls WordLadder
*/
int main(int argc, char *argv[])
{
    if ((argc != 3)) {
        throw std::runtime_error("Usage: ./ladder <FILE_NAME> <OP_CODE>");
    }

    //initialize and assign the arguments so that they can be used
    std::string inputFile = argv[1];
    int OP_CODE;
    try {
        OP_CODE = std::stoi(argv[2]);
    } catch (const std::invalid_argument&) {
        throw std::runtime_error("Operation code should be 1 or 2");
    }

    WordLadder wordLadder;

    //open input file
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening input file.");
    }

    if (OP_CODE == 1) {
        std::string start, end;
        int lineNum = 1;
        while (file >> start >> end) {
            if (start.empty() or end.empty()) { //if not properly formatted
                throw std::runtime_error("Error: Line " + std::to_string(lineNum) + 
                " is not properly formatted.");
            }
            cout << lineNum << ".";
            wordLadder.operationOne(start, end);
            cout << endl;
            lineNum++;
        }
    } else if (OP_CODE == 2) {
        std::string word;
        int lineNum = 1;
        while(file >> word) {
            if (word.empty()) { //if not properly formatted
                throw std::runtime_error("Error: Line " + std::to_string(lineNum) + 
                " is not properly formatted.");
            }
            cout << lineNum << ". ";
            int count = wordLadder.operationTwo(word);
            if (count == -1) {
                cout << word << ": not contained in word-list." << endl;
            } else if (count == 1) {
                cout << word << ": 1 other word can be made." << endl;
            } else {
                cout << word << ": " << count << " other words can be made." << endl; 
            }
            lineNum++;
        }
    } else {
        cout << "Operation code should be 1 or 2" << endl;
    }
    file.close();    
    return 0;
}