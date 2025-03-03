#include "generateSaveCard.h"
#include "generateRandNum.h"

/**
 * @brief Generates a bingo card with random numbers and saves it to a file.
 * 
 * The function creates a bingo card containing 25 random numbers within the given range.
 * The numbers are written to a text file named "Card_<card_number>.txt", formatted in a 5x5 grid.
 * If the file cannot be created, an error message is displayed.
 * 
 * @param max_value The maximum number that can be included in the bingo card.
 * @param card_number The identifier for the bingo card, used in the filename.
 */
void generateSaveCard(int max_value, int card_number){
    ofstream file("Card_" + to_string(card_number) + ".txt");
    if(!file){
        cerr << "There was a problem while trying to create the Bingo Card number: " << card_number << endl;
        return;
    }

    vector<int> cardNumbers;
    for(int x = 0; x < 25; x++){
        int num = generateRandNum(max_value);
        cardNumbers.push_back(num);
        file << num << ((x % 5 == 4) ? "\n" : " | ");
    }
    file.close();

}