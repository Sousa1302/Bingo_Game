#include "generateRandNum.h"
#include <iostream>
using namespace std;

/**
 * @brief Generates a random number between 1 and the specified maximum value.
 * 
 * The function uses the `rand()` function to generate a random integer, 
 * and then ensures the number is within the range [1, max_value].
 * 
 * @param max_value The upper limit for the generated random number.
 * @return A random number between 1 and the given max_value .
 */
int generateRandNum(int max_value){
    return rand() % max_value + 1;
}