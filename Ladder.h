/*
 * Ladder.h
 * Brianna Taborda (btabor01)
 * 
 * The purpose of the Ladder class is to provide all of the funcitonality needed
 * for the two different possible operations given by OP_CODE in main. 
*/

#ifndef _LADDER_H_
#define _LADDER_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Dictionary.h"
using namespace std;

class Ladder
{
public:
   Ladder(Dictionary& dict); //constructor
   std::vector<std::string> getNeighbors(std::string word);
   std::vector<std::string> getLadder(std::string start, std::string end);
   int otherWords(std::string word);
private:
   std::unordered_set<std::string> dict;
   Dictionary &dictionary;
};
#endif