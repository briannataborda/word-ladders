/*
 * WordLadder.h
 * Brianna Taborda (btabor01)
 * 
 * The purpose of the WordLadder class is to call the appropriate Ladder
 * functions based on the OP_CODE given in the command arguments.
*/

#ifndef _WORDLADDER_H_
#define _WORDLADDER_H_

#include "Ladder.h"

class WordLadder
{
public:
    WordLadder();
    void operationOne(std::string& start, std::string& end);
    int operationTwo(std::string& word);
private:
    Dictionary dict;
};
#endif