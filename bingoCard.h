#ifndef BINGOCARD_H
#define BINGOCARD_H

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class BingoCard {
    private:
        int size;
        vector<int> numbers;
        void fisherYatesShuffle(vector<int>& vec);

    public:
        BingoCard(int cardSize = 5, int max_value = 90, int card_number = 1);
        void generateSaveCard(int max_value, int card_number);
        void displayBingoTable(int max_value, const vector<int>& drawnNumbers);
};

#endif
