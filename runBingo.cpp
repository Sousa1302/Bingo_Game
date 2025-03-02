#include "runBingo.h"
#include "getMaxValue.h"
#include "generateSaveCard.h"
#include "playBingo.h"

/**
 * @brief Runs the Bingo game setup and starts the game.
 * 
 * The function initializes the random number generator, prompts the user 
 *          for game settings, generates bingo cards, and starts the game loop.
 */
void runBingo(){
    srand(time(0));
    int choice;
    do{
        cout << "Choose an amount of numbers: \n1. 75 \n2. 90 \n3. 100 \n";
        cin >> choice;
    } while (choice < 1 || choice > 3);

    int max_value = getMaxValue(choice);

    int generator_type;
    do{
        cout << "Type of generator: \n1. Automatic \n2.Manual \n";
        cin >> generator_type;
    } while (generator_type < 1 || generator_type > 2);

    int amount_cards;
    cout << "Number of cards you wish to generate: ";
    cin >> amount_cards;
    for(int x = 1; x <= amount_cards; x++){
        generateSaveCard(max_value, x);
    }

    playBingo(max_value, generator_type == 1);
}

