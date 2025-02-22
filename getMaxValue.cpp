#include "getMaxValue.h"

/**
 * @brief Returns the maximum allowed value for the bingo draw, 
 *        based on the user's choice.
 * 
 * The function returns:
 *  - 75 if the user selects option 1.
 *  - 90 if the user selects option 2.
 *  - 100 if the user selects option 3.
 * 
 * @param choice The option selected by the user tod efine the number range
 * @return The maximum value for the numbers drawn, based on the user's choice
 */                                         
int getMaxValue(int choice){
    switch(choice){
        case 1 : return 75;
        case 2 : return 90;
        case 3 : return 100;
        default : return 0;
    }
}