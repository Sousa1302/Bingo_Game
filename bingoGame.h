#ifndef BINGOGAME_H
#define BINGOGAME_H

#include <vector>
#include <string>
#include "player.h"
#include "bingoCard.h" 
using namespace std;

class BingoGame {
private:
    vector<int> drawnNumbers;
    int checkCardForWin(const vector<int>& drawnNumbers);
    public:
    vector<Player> players;
    void runBingo(); 
    int generateRandNum(int max_value);
    int getMaxValue(int choice); 
    void playBingo(int max_value, bool isAutomatic); 
    
    static inline const string COLOR_RED = "\u001b[31m";
    static inline const string COLOR_RESET = "\u001b[0m";
};

#endif