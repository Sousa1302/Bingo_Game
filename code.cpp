#include <iostream>
#include <fstream>

using namespace std;


int nums_card[5][5];
int amount_nums, random_nums_card, type_generator, number_generated = 0, random_nums_generated, last_num_generated = 0;
char keep_generating = 'n';


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
    cout << "1. Automatic \n2. Manual\n";
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
    
    /*do {
    Nums_Generator(amount_nums);

    if (number_generated != 0) {
        cout << "Last number: " << last_num_generated << endl; // Exibe o último número gerado após a primeira iteração
    }

    last_num_generated = number_generated; // Armazena o último número gerado
    number_generated = random_nums_generated; // Gera o próximo número

    cout << "Number generated: " << number_generated << endl;
    cout << "Do you wish to generate another number ?\n";
    cout << "y / n\n";
    cin >> keep_generating;

    } while (keep_generating == 'y' || keep_generating == 'Y');

    cout << "Last number: " << last_num_generated << endl; // Exibe o último número gerado antes de sair do loop
    */


    return 0;
}