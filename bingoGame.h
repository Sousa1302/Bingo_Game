#ifndef BINGOGAME_H
#define BINGOGAME_H

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class BingoGame{
    private:
        const string COLOR_RED, COLOR_RESET;
        set<int> drawnNumbers;
        vector<string> players;
        int cardSize;

        bool isNumGenerated(int num);

    public:
        void   runBingo();
        int    generateRandNum();
        string checkWinner();

};

#endif