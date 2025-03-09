#include "bingoCard.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include "game.h"
#include "setFileReadOnly.h"
using namespace std;

BingoCard::BingoCard(int cardSize, int max_value, int card_number) : size(cardSize) {
    numbers.resize(size * size);
    generateSaveCard(max_value, card_number);
}

bool BingoCard::isNumOnCard(int num) const {
    return find(numbers.begin(), numbers.end(), num) != numbers.end();
}

void BingoCard::generateSaveCard(int max_value, int card_number) {
    vector<int> cardNumbers;
    for (int x = 1; x <= max_value; x++) {
        cardNumbers.push_back(x);
    }

    fisherYatesShuffle(cardNumbers); 

    
    numbers.assign(cardNumbers.begin(), cardNumbers.begin() + (size * size));
    sort(numbers.begin(), numbers.end()); 

    string filename = "Card_" + to_string(card_number) + ".txt";
    ofstream file(filename);
    
    file << "+-----+-----+-----+-----+-----+\n";
    for (int x = 0; x < size * size; x++) {
        if (x % size == 0) file << "| "; 
        if (x == (size * size) / 2) {
            file << setw(3) << "C++" << " | "; 
        } else {
            file << setw(3) << numbers[x] << " | "; 
        }
        if (x % size == size - 1) file << "\n+-----+-----+-----+-----+-----+\n";
    }
    file.close();
    setFileToReadOnly(filename);
}

int BingoCard::markNum(int num) {
    auto it = find(numbers.begin(), numbers.end(), num);
    if (it != numbers.end()) {
        *it = -1; 
        return 1; 
    }
    return 0; 
}

bool BingoCard::isComplete() const {
    return all_of(numbers.begin(), numbers.end(), [](int num) { return num == -1; });
}

void BingoCard::fisherYatesShuffle(vector<int>& vec) {
    for (int i = vec.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(vec[i], vec[j]);
    }
}

void BingoCard::displayBingoTable(int max_value, const vector<int>& drawnNumbers) {
    string separator = "+===========================================================+";
    
    cout << endl;
    cout << setw(37) << "Bingo Table\n" << endl << separator << endl;
    for (int x = 1; x <= max_value; x++) {
        
        if (x % 10 == 1) {
            cout << "| ";
        }

        
        bool isDrawn = find(drawnNumbers.begin(), drawnNumbers.end(), x) != drawnNumbers.end();
        cout << (isDrawn ? COLOR_RED : "") << setw(3) << x << COLOR_RESET;

        
        if (x % 10 == 0 || x == max_value) {

            if (x % 10 != 0) {
                for (int i = 0; i < 10 - (x % 10); i++) {
                    cout << "     "; 
                }
            }
            cout << " |\n" << separator << "\n";
        } else {
            cout << " | ";
        }
    }
    cout << endl;
}