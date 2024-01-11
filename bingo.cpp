#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int nums_card[5][5];
int amount_nums, generator_type, amount_cards;



void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

vector<int> Number_Generator(int x){
    vector<int> numbers(x + 1);

    for (int y = 0; y <= x; y++){
        numbers[y] = 1 + rand() % x;
    }

    return numbers;
}


void generateAndSaveCard(int max_value, int card_number) {
    ofstream ficheiro("Card" + to_string(card_number) + ".txt");            //Conversion from an integer to a string

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            nums_card[x][y] = 1 + rand() % max_value;                   //Generates the numbers for the card
        }
    }

    if (ficheiro.is_open()) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                ficheiro << nums_card[x][y] << " | ";                   // Displays the bidimensional array values in the file.txt
            }
            ficheiro << endl;
        }
        ficheiro << endl; 
    }
}

int main() {
    srand(time(NULL));

    cout << "Choose the amount of numbers\n";
    cout << "1. 75 nums \n2. 90 nums \n3. 100 nums\n";
    cin >> amount_nums;


    cout << "Chose the type of generator!\n";
    cout << "1. Automatic \n2. Manual \n";
    cin >> generator_type;


    cout << "Type the amount of card you want to generate: ";
    cin >> amount_cards;


    for (int i = 1; i <= amount_cards; i++) {
        vector<int> Generated_Numbers;

        switch (amount_nums) {
            case 1:
                generateAndSaveCard(75, i);
                Generated_Numbers = Number_Generator(75);
                break;

            case 2:
                generateAndSaveCard(90, i);
                Generated_Numbers = Number_Generator(90);
                break;

            case 3:
                generateAndSaveCard(100, i);
                Generated_Numbers = Number_Generator(100);
                break;

            default:
                cout << "You must type a number between 1-3!\n";
                break;
        }

        /*cout << "Generated numbers: ";
        for ( int num : Generated_Numbers){                                     // Tests the amount and the range of the bingo numbers generated
            cout << num << " ";
        }
        cout << endl; */
    }

   return 0;
}