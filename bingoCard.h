#ifndef BINGOCARD_H
#define BINGOCARD_H

#include "bingoGame.h"
#include <vector>

class BingoCard : public BingoGame{
    private: 
        int size;
        vector<int> numbers;

        bool isNumOnCard(int num);
    
    public:
        BingoCard(int cardSize);

        void generateSaveCard();
};

#endif