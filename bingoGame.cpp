/**
 * @file bingoGame.cpp
 * @brief Implementation of the BingoGame class for managing a bingo game.
 */

#include "bingoGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "espeak.h"
#include <unordered_set>

using namespace std;

/**
 * @brief Runs the bingo game, handling the setup and main game loop.
 * This function initializes the game, prompts the user for game settings, generates player cards, and starts the game loop.
 */
void BingoGame::runBingo() {
    srand(time(0));
    system("clear");

    string welcomePhrase = "Welcome to the grannay's paradise....i mean BINGOOOOOOOOOOO !";
    cout << welcomePhrase << endl;
    espeak(welcomePhrase);

    int choice;
    do {
        cout << "Choose the amount of nums:\n";
        cout << "1. 50 ( Quick Game )\n";
        cout << "2. 90 ( Normal Game )\n";
        cin >> choice;

        if (choice < 1 || choice > 2) {
            system("clear");
            cout << "Invalid option!\n";
        }
    } while (choice < 1 || choice > 2);

    system("clear");

    int max_value = getMaxValue(choice);

    int generator_type;
    do {
        cout << "Type of generator:\n";
        cout << "1. Automatic\n";
        cout << "2. Manual\n";
        cin >> generator_type;

        if (generator_type < 1 || generator_type > 2) {
            cout << "Invalid option, choose option 1 or 2.\n";
        }
    } while (generator_type < 1 || generator_type > 2);

    system("clear");

    int amount_cards;
    do {
        cout << "Number of cards you wish to generate: ";
        cin >> amount_cards;

        if (amount_cards < 2) {
            cout << "There must be at least two players playing !\n";
        }
    } while (amount_cards < 2);

    for (int x = 1; x <= amount_cards; x++) {
        string playerName = "Player " + to_string(x);
        players.push_back(Player(5, max_value, x));
    }

    system("clear");
    playBingo(max_value, generator_type == 1);
}

/**
 * @brief Generates a random number within a specified range.
 * 
 * @param max_value The upper limit for the random number generation.
 * @return int A random number between 1 and max_value.
 */
int BingoGame::generateRandNum(int max_value) {
    return rand() % max_value + 1;
}

/**
 * @brief Determines the maximum value for the bingo numbers based on user choice.
 * 
 * @param choice The user's choice for the game type (1 for 50 numbers, 2 for 90 numbers).
 * @return int The maximum value for the bingo numbers.
 */
int BingoGame::getMaxValue(int choice) {
    switch (choice) {
        case 1: return 50;
        case 2: return 90;
        default: return 0;
    }
}

/**
 * @brief Checks if any player has completed a line, column, or the entire card.
 * 
 * This function reads each player's card from a file and checks if any line, 
 * column, or the entire card matches the drawn numbers.
 * 
 * @param drawnNumbers A vector containing the numbers that have been drawn so far.
 * @return int Returns 0 if no winner is found, otherwise returns the player index who won.
 */
int BingoGame::checkCardForWin(const vector<int>& drawnNumbers) {
    string separator = "+===========================================================+";
    int amountColumnCompleted = 0, amountLineCompleted = 0;
    unordered_set<int> drawnSet(drawnNumbers.begin(), drawnNumbers.end());

    for (int playerIndex = 1; playerIndex <= players.size(); playerIndex++) {
        string filename = "Card_" + to_string(playerIndex) + ".txt";
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            continue;
        }

        vector<vector<int>> card(5, vector<int>(5));
        string line;
        int row = 0;

        while (getline(file, line)) {
            
            if (line.find("+---") != string::npos) {
                continue;
            }

            
            line.erase(remove(line.begin(), line.end(), '|'), line.end());
            stringstream ss(line);
            int num;
            int col = 0;

            while (ss >> num) {
                if (row < 5 && col < 5) {
                    card[row][col] = num;
                    col++;
                }
            }
            row++;
        }
        
        cout << endl  << setw(37) << "Achievements" << endl << separator << endl;

        for (int i = 0; i < 5; i++) {
            bool lineComplete = true;
            for (int j = 0; j < 5; j++) {
                if (drawnSet.find(card[i][j]) == drawnSet.end()) {
                    lineComplete = false;
                    break;
                }
            }
            if (lineComplete) {
                cout << "Player with card " << playerIndex << " completed a line!\n";
                amountLineCompleted += 1;
            }
        }

        
        for (int j = 0; j < 5; j++) {
            bool columnComplete = true;
            for (int i = 0; i < 5; i++) {
                if (drawnSet.find(card[i][j]) == drawnSet.end()) {
                    columnComplete = false;
                    break;
                }
            }
            if (columnComplete) {
                cout << "Player with card " << playerIndex << " completed a column!\n";
                amountColumnCompleted += 1; 
            }
        }

        if(amountColumnCompleted == 5 && amountLineCompleted == 5){
            system("clear");
            cout << "Player with card " << playerIndex << " has shouted BINGO !\n";
            sleep(2);
            return 0;
        }
    }
    cout << endl;
    return 0; 
}

/**
 * @brief Manages the main game loop, drawing numbers and checking for winners.
 * 
 * This function handles the drawing of numbers, displays the current state of the game,
 * and checks if any player has won after each draw.
 * 
 * @param max_value The maximum value for the bingo numbers.
 * @param isAutomatic A boolean indicating if the game is in automatic mode (true) or manual mode (false).
 */
void BingoGame::playBingo(int max_value, bool isAutomatic) {
    vector<int> drawnNumbers;

    while (true) {
        int num = generateRandNum(max_value);
        if (find(drawnNumbers.begin(), drawnNumbers.end(), num) == drawnNumbers.end()) {
            drawnNumbers.push_back(num);
            cout << "Number drawn: " << num << endl;

            if (drawnNumbers.size() > 1) {
                cout << "Last number drawn: " << drawnNumbers[drawnNumbers.size() - 2] << endl;
            }
            
            BingoCard tempCard(5, max_value, 1);
            tempCard.displayBingoTable(max_value, drawnNumbers);
            
            int winner = checkCardForWin(drawnNumbers);
            if (winner > 0) {
                cout << "Player " << winner << " wins!" << endl;
                sleep(3);
                system("clear");
                break; 
            }

            espeak(to_string(num));
            sleep(2);
            
            if (!isAutomatic) {
                cout << "Press any key to continue: ";
                cin.ignore();
                cin.get();
            }
            system("clear");
        }
    }
}