#ifndef BINGOCARD_H
#define BINGOCARD_H

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

class BingoCard {
public:
    BingoCard(int cardSize = 5, int max_value = 99, int card_number = 1);
    bool isNumOnCard(int num) const;
    void generateSaveCard(int max_value, int card_number);
    int markNum(int num); 
    bool isComplete() const; 
    void displayBingoTable(int max_value, const vector<int>& drawnNumbers);

private:
    int size;
    vector<int> numbers;
    void fisherYatesShuffle(vector<int>& vec);
};

#endif