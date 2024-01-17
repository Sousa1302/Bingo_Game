/**
 * @file duvidas.cpp
 * @author Paulo Leite
 * @brief Jogo do bingo
 * @version 0.1
 * @date 17 / 1 / 2024
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>                        // Library to use "sort" so i can order the sorted numbers
#include <unistd.h>                         // To use delays when generator type == automatic 

using namespace std;

string color_red = "\u001b[31m";
string color_reset = "\u001b[0m";
int new_amount_value;
vector<int> drawnNumbers;

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


void printSortedNumbers(vector<int> &numbers){                   // &numbers so i can modify the original numbers vector instead of a copy, so i can change the vector directly
    sort(numbers.begin(), numbers.end());

    cout << "Sorted Numbers: ";
    for (int x = 0; x < numbers.size(); x++)
        {
            cout << color_red << numbers[x] << color_reset << " ";
        }
    cout << endl;
}


void generateAndSaveCard(int max_value, int card_number){                   // Function to save and generate a card with the values
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

            if (generator_type == 1){               // automatic generator
                
                int intervalo = 2.5;              // 2 and a half seconds
                
                AmountCards_Conversion_to_corresponded_num(amount_nums);

                for(int x = 0; x < new_amount_value; x++){
                    drawnNumber = Number_Generator_Bingo(amount_nums);

                    while (isNumberGenerated(drawnNumbers, drawnNumber)){                // verifys if the number has been generated , 1st parameter is the vector of dranwnumbers and the 2nd is the number that we will verify
                        drawnNumber = Number_Generator_Bingo(amount_nums);
                    }

                drawnNumbers.push_back(drawnNumber);

                cout << endl;
                cout << "Last drawn number: " << drawnNumbers[drawnNumbers.size() - 2] << endl;         // [drawnNumbers.size() - 2] is to access the value of the last number generated
                cout << "Drawn number: " << drawnNumber << endl;

                printSortedNumbers(drawnNumbers);

                sleep(intervalo);
                system("clear || cls");
                }
            }

            else if (generator_type == 2){                      // Manual generator
                drawnNumber = Number_Generator_Bingo(amount_nums);

                while (isNumberGenerated(drawnNumbers, drawnNumber)){                // verifys if the number has been generated , 1st parameter is the vector of dranwnumbers and the 2nd is the number that we will verify
                        drawnNumber = Number_Generator_Bingo(amount_nums);
                    }

                drawnNumbers.push_back(drawnNumber);

                cout << endl;
                cout << "Last drawn number: " << drawnNumbers[drawnNumbers.size() - 2] << endl;         // [drawnNumbers.size() - 2] is to access the value of the last number generated
                cout << "Drawn number: " << drawnNumber << endl;

                printSortedNumbers(drawnNumbers);

                cout << "Do you want to play again? (y/n): ";
                cin >> playAgain;
                cout << endl;
                system("clear || cls");
            }

        } while (playAgain == 'y' || playAgain == 'Y');
    

    return 0;
}
