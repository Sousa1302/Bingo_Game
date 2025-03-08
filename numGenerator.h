#ifndef NUMGENERATOR_H
#define NUMGENERATOR_H

#include "bingoGame.h"

class NumGenerator : public BingoGame{
    private:
        int min, max;
        
    public:
        NumGenerator(int maxVal);

        int generate();
};

#endif