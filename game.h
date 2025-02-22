#ifndef GAME_H
#define GAME_H

#include "libraries.h"

using namespace std;

extern const string COLOR_RED, COLOR_RESET;
int rangeNumsGenerated;
vector<int> drawnNumbers;

void displayBingoTable();
void generateRandNum();
void getMaxValue();
bool isNumGenerated();
void generateSaveCard();
void playBingo();


#endif


