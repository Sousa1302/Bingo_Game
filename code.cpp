#include <iostream>
#include <fstream>

using namespace std;


int nums_card[5][5];
int amount_nums, random_nums_card, type_generator, random_nums_generated;
char keep_generating;


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

void Nums_Generator(int max_value){
    if (max_value == 1){
        random_nums_generated = 1 + rand() % 75;
    }
    if (max_value == 2){
        random_nums_generated = 1 + rand() % 90;
    }
    if(max_value == 3){
        random_nums_generated = 1 + rand() % 100;
    }
}

int main(){
    srand(time(NULL));

    cout << "Choose the amount of numbers\n";
    cout << "1. 75 nums \n2. 90 nums \n3. 100 nums\n";
    cin >> amount_nums;

    cout << "Do you want an automatic or a manual generator?\n";
    cout << "A. Automatic \nB. Manual\n";
    cin >> type_generator;

    ofstream ficheiro("Card.txt");

    switch (amount_nums){
        case 1:
        for (int x = 0; x < 5 ; x++){
            for (int y = 0; y < 5; y++){
                nums_card[x][y] = random_nums_card = 1 + rand() % 75;
            }
        }

        for (int z = 0; z < 5 ; z++){
           bubbleSort(nums_card[z], 5); 
        }
        
        if (ficheiro.is_open()){
            for (int x = 0; x < 5 ; x++){
                for (int y = 0; y < 5; y++){
                    ficheiro << nums_card[x][y] << " | ";
                }
            ficheiro << endl;
            }
        ficheiro.close();
        cout << "The values were saved in the file!\n";
        }

        break;
        
        case 2:
        for (int x = 0; x < 5 ; x++){
            for (int y = 0; y < 5; y++){
                nums_card[x][y] = random_nums_card = 1 + rand() % 90;
            }
        }

        for (int z = 0; z < 5 ; z++){
           bubbleSort(nums_card[z], 5); 
        }

        if (ficheiro.is_open()){
            for (int x = 0; x < 5 ; x++){
                for (int y = 0; y < 5; y++){
                    ficheiro << nums_card[x][y] << " | ";
                }
            ficheiro << endl;
            }
        ficheiro.close();
        cout << "The values were saved in the file!\n";
        }

        break;

        case 3:
        for (int x = 0; x < 5 ; x++){
            for (int y = 0; y < 5; y++){
                nums_card[x][y] = random_nums_card = 1 + rand() % 100;
                
            }
        }

        for (int z = 0; z < 5 ; z++){
           bubbleSort(nums_card[z], 5); 
        }

        if (ficheiro.is_open()){
            for (int x = 0; x < 5 ; x++){
                for (int y = 0; y < 5; y++){
                    ficheiro << nums_card[x][y] << " | ";
                }
            ficheiro << endl;
            }
        ficheiro.close();
        cout << "The values were saved in the file!\n";
        }

        break;

        default:
        cout << "You must type a number between 1-3!\n";
    }
    
    // cout << "The last number: "  << ultimo numero << endl;
    // cout << "The number generated: " << numero agr <<  endl;
    

    return 0;
}