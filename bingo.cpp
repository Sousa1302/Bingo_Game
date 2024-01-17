/**
 * @file bingo.cpp
 * @author Gonçalo Sousa
 * @brief Jogo do bingo
 * @version 0.1
 * @date 17 / 1 / 2024
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>                        // Library to use "sort" so i can order the sorted numbers
#include <unistd.h>                         // To use delays when generator type == automatic 
#include <iomanip>

using namespace std;

string color_red = "\u001b[31m";
string color_reset = "\u001b[0m";
int new_amount_value;
vector<int> drawnNumbers;

// Generates a table on which are displayed the numbers already generated and the not generated ones
void displayBingoTable(const vector<int> &drawnNumbers, int amount_nums) {           // const because this function is destined to only print numbers and not modify the vector itself
    cout << "Bingo Table:" << endl;

    for (int i = 0; i <= amount_nums; i++) {
        bool isDrawn = find(drawnNumbers.begin(), drawnNumbers.end(), i) != drawnNumbers.end();
        
        if (isDrawn) {
            cout << color_red << setw(3) << i << color_reset;
        } else {
            cout << setw(3) << i;       // sets the width to 3 characters
        }

        if ((i + 1) % 10 == 0 && i != 0) {  // Jumps lines when it gets to 10
            cout << endl;
        } else {
            cout << " | ";
        }
    }

    cout << endl;
}


// Generates x amount of cards
int Number_Generator_Cards(int max_value){
    return rand() % max_value + 1;
}

int Number_Generator_Bingo(int max_amount){
    if (max_amount == 1)
        {
            return rand() % 75 + 1;
        }
    if (max_amount == 2)
        {
            return rand() % 90 + 1;
        }
    if (max_amount == 3)
        {
            return rand() % 100 + 1;
        }
    return 0;
}


int AmountCards_Conversion_to_corresponded_num(int conversion){
    if (conversion == 1){
            new_amount_value = 75;
        }
    if (conversion == 2){
            new_amount_value = 90;
        }
    if (conversion == 3){
            new_amount_value = 100;
        }
    return 0;

}

bool isNumberGenerated(const vector<int> &numbers, int number){
    for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == number)
                {
                    return true;                            // if number has already been generated
                }
        }
    return false;                                   // if number has not been generated yet
}


void printSortedNumbers(vector<int> &numbers) {         // &numbers so i can modify the original numbers vector instead of a copy, so i can change the vector directly
    vector<int> sortedNumbers = numbers;                // Creates a copy of the original vector to sort
    sort(sortedNumbers.begin(), sortedNumbers.end());

    cout << "Sorted Numbers: ";
    for (int x = 0; x < sortedNumbers.size(); x++) {
        cout << color_red << sortedNumbers[x] << color_reset << " ";
    }
    cout << endl;
}



void generateAndSaveCard(int max_value, int card_number){                   // Function to save and generate a card with the values generated 
    ofstream file("Card" + to_string(card_number) + ".txt");

    if (file.is_open()){
            vector<int> cardNumbers;
            for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                        {
                            int num = Number_Generator_Cards(max_value);
                            cardNumbers.push_back(num);
                            file << num << " | ";
                        }
                    file << endl;
                }
            file.close();


            cout << "Card " << card_number << " Numbers: ";                         // Defines the card number
            for (int x = 0; x < cardNumbers.size(); x++)
                {
                    cout << cardNumbers[x] << " ";
                }
            cout << endl;
        }
    else{
            cerr << "Unable to open file for card " << card_number << endl;
        }
}


int main(){
    srand(time(0));

    int amount_nums;
    cout << "Choose the amount of numbers\n";
    cout << "1. 75 nums \n2. 90 nums \n3. 100 nums\n";
    cin >> amount_nums;

    int generator_type;
    cout << "Choose the type of generator!\n";
    cout << "1. Automatic \n2. Manual \n";
    cin >> generator_type;

    int amount_cards;
    cout << "Type the amount of cards you want to generate: ";
    cin >> amount_cards;

    for (int i = 1; i <= amount_cards; i++){
            switch (amount_nums)
                {
                case 1:
                    generateAndSaveCard(75, i);
                    break;

                case 2:
                    generateAndSaveCard(90, i);
                    break;

                case 3:
                    generateAndSaveCard(100, i);
                    break;

                default:
                    cout << "You must type a number between 1-3!\n";
                    return 1;
                }
        }

    char playAgain;
    do {
        int drawnNumber;
        int lastDrawnNumber = 0;

        if (generator_type == 1) {  // automatic generator
            int intervalo = 2.5;    // 2 and a half seconds

            AmountCards_Conversion_to_corresponded_num(amount_nums);

            for (int x = 0; x < new_amount_value; x++) {
                drawnNumber = Number_Generator_Bingo(amount_nums);

                while (isNumberGenerated(drawnNumbers, drawnNumber)) {
                    drawnNumber = Number_Generator_Bingo(amount_nums);
                }

                drawnNumbers.push_back(drawnNumber);

                cout << endl;
                cout << "Last drawn number: " << lastDrawnNumber << endl;
                cout << "Drawn number: " << drawnNumber << endl;

                displayBingoTable(drawnNumbers, new_amount_value);  

                lastDrawnNumber = drawnNumber;

                sleep(intervalo);
                system("clear || cls");
            }
        }  
        else if (generator_type == 2) {  // Manual generator
    do {
        AmountCards_Conversion_to_corresponded_num(amount_nums);
        drawnNumber = Number_Generator_Bingo(amount_nums);

        while (isNumberGenerated(drawnNumbers, drawnNumber)) {
            drawnNumber = Number_Generator_Bingo(amount_nums);
        }

        drawnNumbers.push_back(drawnNumber);

        cout << endl;
        cout << "Last drawn number: " << lastDrawnNumber << endl;
        cout << "Drawn number: " << drawnNumber << endl;

        lastDrawnNumber = drawnNumber;

        displayBingoTable(drawnNumbers, new_amount_value);  

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
        system("clear || cls");
    } while (playAgain == 'y' || playAgain == 'Y');
}


    }   while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}