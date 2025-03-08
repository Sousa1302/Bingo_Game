#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "bingoCard.h"
using namespace std;

class Player {
public:
    Player(string playerName, int cardSize, int max_value, int card_number); 
    int markNumber(int num);
    bool hasBingo() const;
    string getName() const;

private:
    string name;
    BingoCard card;
};

#endif