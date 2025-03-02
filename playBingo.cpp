#include "playBingo.h"
#include "isNumGenerated.h"
#include "displayBingoTable.h"
#include "isNumGenerated.h"
#include "generateRandNum.h"

/**
 * @brief Starts and manages the Bingo game.
 * 
 * @param max_value Maximum value for drawn numbers.
 * @param automatic Defines whether the game progresses automatically or waits for user input.
 */
void playBingo(int max_value, bool automatic){
    int lastDrawnNumber = 0;
    char playAgain;
    do {
        int drawnNumber;
        do {
            drawnNumber = generateRandNum(max_value);
        } while (isNumGenerated(drawnNumber));
        drawnNumbers.push_back(drawnNumber);

        cout << "\nÚltimo número: " << lastDrawnNumber << "\nNúmero sorteado: " << drawnNumber << endl;
        displayBingoTable(max_value);
        lastDrawnNumber = drawnNumber;

        if (automatic) {
            sleep(2);
            system("clear || cls");
        } else {
            cout << "Continuar? (y/n): ";
            cin >> playAgain;
        }
    } while (automatic || playAgain == 'y' || playAgain == 'Y');
}