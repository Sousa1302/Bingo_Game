#include "isNumGenerated.h"

/**
 * @brief Checks if a given number has already been drawn in the bingo game.
 * 
 * The function searches for the specified number in the list of drawn numbers.
 * It returns true if the number has already been drawn, otherwise false.
 * 
 * @param number The number to check.
 * @return True if the number has been drawn, false otherwise.
 */
bool isNumGenerated(int number){
    return find(drawnNumbers.begin(), drawnNumbers.end(), number) != drawnNumbers.end();
}