#include "displayBingoTable.h"

/**
 * @brief Displays the bingo table with numbers from 1 to the specified maximum value.
 * 
 * The function iterates over the numbers from 1 to max_value, printing each number in a table format.
 * If a number has been drawn, it will be displayed in red.
 * The table is organized with 10 numbers per line.
 * 
 * @param max_value The upper limit of the numbers to be displayed on the bingo table.
 */
void displayBingoTable(int max_value){
    cout << "Bingo Table:\n" << endl;
    for(int x = 1; x <= max_value ; x++){
        bool isDrawn = find(drawnNumbers.begin(), drawnNumbers.end(), x) != drawnNumbers.end();
        cout << (isDrawn ? COLOR_RED : "") << setw(3) << x << COLOR_RESET;
        cout << ((x % 10 == 0) ? "\n" : " | ");
    }
    cout << endl;
}