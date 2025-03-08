#include "bingoGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

void BingoGame::runBingo() {
    srand(time(0));

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

    // Cria os jogadores e seus cartões
    for (int x = 1; x <= amount_cards; x++) {
        string playerName = "Player " + to_string(x);
        players.push_back(Player(playerName, 5, max_value, x)); 
    }

    playBingo(max_value, generator_type == 1);
}

int BingoGame::generateRandNum(int max_value) {
    return rand() % max_value + 1;
}

bool BingoGame::checkWinner() {
    for (Player& player : players) {
        if (player.hasBingo()) {
            cout << "Parabéns, " << player.getName() << " venceu!" << endl;
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

void BingoGame::playBingo(int max_value, bool isAutomatic) {
    vector<int> drawnNumbers;

    while (true) {
        int num = generateRandNum(max_value);
        if (find(drawnNumbers.begin(), drawnNumbers.end(), num) == drawnNumbers.end()) {
            drawnNumbers.push_back(num);
            cout << "Número sorteado: " << num << endl;

            
            BingoCard tempCard(5, max_value, 1); 
            tempCard.displayBingoTable(max_value, drawnNumbers);
            
            sleep(2);
            
            for (Player& player : players) {
                player.markNumber(num);
            }

            
            if (checkWinner()) {
                cout << "Bingo! Temos um vencedor!" << endl;
                break;
            }

            if (!isAutomatic) {
                cout << "Pressione Enter para sortear o próximo número...";
                cin.ignore();
                cin.get();
            }
        }
    }
}