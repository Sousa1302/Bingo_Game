#ifndef PLAYER_H
#define PLAYER_H

#include <bingoGame.h>
#include <bingoCard.h>

class Player :  public BingoGame{
    private:
        string name;
        BingoCard card;
    public:
        Player(string playerName);

        int    markNumber(int num);
        bool   hasBingo();
        string getName();
};

#endif