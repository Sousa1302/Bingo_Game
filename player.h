#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "bingoCard.h"
using namespace std;

class Player {
public:
    Player(int cardSize, int max_value, int card_number); 


private:
    string name;
    BingoCard card;
};

#endif