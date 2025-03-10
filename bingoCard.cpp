#include "bingoCard.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include "game.h"
#include "setFileReadOnly.h"
using namespace std;

/**
 * @brief Constructor for the BingoCard class.
 * @param cardSize The size of the bingo card (5 for a 5x5 card).
 * @param max_value The maximum number that can appear on the card.
 * @param card_number The unique identifier for the bingo card.
 * @details Initializes the card size and generates/saves the bingo card.
 */
BingoCard::BingoCard(int cardSize, int max_value, int card_number) : size(cardSize) {
    numbers.resize(size * size);
    generateSaveCard(max_value, card_number);
}


/**
 * @brief Generates a bingo card, saves it to a file, and sets the file to read-only.
 * @param max_value The maximum number that can appear on the card.
 * @param card_number The unique identifier for the bingo card.
 * @details Generates a shuffled list of numbers, selects the required amount for the card,
 *          sorts them, and saves the card in a formatted text file.
 */
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


/**
 * @brief Checks if the bingo card is complete (all numbers marked).
 * @return True if all numbers on the card are marked as -1, false otherwise.
 */
bool BingoCard::isComplete() const {
    return all_of(numbers.begin(), numbers.end(), [](int num) { return num == -1; });
}


/**
 * @brief Shuffles a vector of integers using the Fisher-Yates algorithm.
 * @param vec The vector to shuffle.
 * @details Randomly shuffles the elements of the vector to ensure randomness.
 */
void BingoCard::fisherYatesShuffle(vector<int>& vec) {
    for (int i = vec.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(vec[i], vec[j]);
    }
}


/**
 * @brief Displays the bingo table with drawn numbers highlighted.
 * @param max_value The maximum number that can appear on the table.
 * @param drawnNumbers A vector containing the numbers that have been drawn.
 * @details Displays a formatted table of numbers, highlighting those that have been drawn.
 */
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