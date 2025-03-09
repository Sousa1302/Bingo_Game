#include "bingoGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "espeak.h"
using namespace std;

void BingoGame::runBingo() {
    srand(time(0));

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

    int amount_cards;
    do{
        cout << "Number of cards you wish to generate: ";
        cin >> amount_cards;

        if(amount_cards < 2){
            cout << "There must be at least two players playing !\n";
        }
    }while(amount_cards < 2);


    for (int x = 1; x <= amount_cards; x++) {
        string playerName = "Player " + to_string(x);
        players.push_back(Player(playerName, 5, max_value, x)); 
    }

    system("clear");
    playBingo(max_value, generator_type == 1);
}

int BingoGame::generateRandNum(int max_value) {
    return rand() % max_value + 1;
}

bool BingoGame::checkWinner() {
    for (Player& player : players) {
        if (player.hasBingo()) {
            cout << "Congrats, " << player.getName() << " won!" << endl;
            return true;
        }
    }
    return false; 
}

int BingoGame::getMaxValue(int choice) {
    switch (choice) {
        case 1: return 50;
        case 2: return 90;
        default: return 0; 
    }
}

int BingoGame::checkCardForWin(const string& filename, const vector<int>& drawnNumbers) {
    ifstream file(filename);
    if (!file) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return 0; 
    }

    vector<vector<int>> card(5, vector<int>(5)); 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            file >> card[i][j];
        }
    }

    
    for (int i = 0; i < 5; i++) {
        bool lineComplete = true;
        for (int j = 0; j < 5; j++) {
            if (find(drawnNumbers.begin(), drawnNumbers.end(), card[i][j]) == drawnNumbers.end()) {
                lineComplete = false;
                break;
            }
        }
        if (lineComplete) {
            return 1; 
        }
    }

    
    for (int j = 0; j < 5; j++) {
        bool columnComplete = true;
        for (int i = 0; i < 5; i++) {
            if (find(drawnNumbers.begin(), drawnNumbers.end(), card[i][j]) == drawnNumbers.end()) {
                columnComplete = false;
                break;
            }
        }
        if (columnComplete) {
            return 2; 
        }
    }

    
    bool bingoComplete = true;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (find(drawnNumbers.begin(), drawnNumbers.end(), card[i][j]) == drawnNumbers.end()) {
                bingoComplete = false;
                break;
            }
        }
        if (!bingoComplete) break;
    }
    if (bingoComplete) {
        return 3; 
    }

    return 0; 
}

void BingoGame::playBingo(int max_value, bool isAutomatic) {
    vector<int> drawnNumbers;

    while (true) {
        int num = generateRandNum(max_value);
        if (find(drawnNumbers.begin(), drawnNumbers.end(), num) == drawnNumbers.end()) {
            drawnNumbers.push_back(num);
            cout << "Number sorted: " << num << endl;

            if (!drawnNumbers.empty()) {
                cout << "Last number sorted: " << drawnNumbers[drawnNumbers.size() - 2] << endl;
            } else {
                cout << "Last number sorted: " << endl;
            }

            
            BingoCard tempCard(5, max_value, 1); 
            tempCard.displayBingoTable(max_value, drawnNumbers);
            
            espeak(to_string(num));
            sleep(2);
            
            system("clear");

            bool bingoComplete = false;
            for (int i = 1; i <= players.size(); i++) {
                string filename = "Card_" + to_string(i) + ".txt";
                int result = checkCardForWin(filename, drawnNumbers);

                if (result == 1) {
                    cout << "Player " << i << " has completed a row!" << endl;
                } else if (result == 2) {
                    cout << "Player " << i << " has completed a column!" << endl;
                } else if (result == 3) {
                    cout << "Player " << i << " shouted!" << endl;
                    bingoComplete = true;
                    break; 
                }
            }

            if (bingoComplete) {
                break; 
            }


            for (Player& player : players) {
                player.markNumber(num);
            }

            if (checkWinner()) {
                cout << "Bingo! We have a winner!" << endl;
                break;
            }

            if (!isAutomatic) {
                cout << "Press any key to continue: ";
                cin.ignore();
                cin.get();
            }
        }
    }
}