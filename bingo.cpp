#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <iomanip>

using namespace std;

const string COLOR_RED = "\u001b[31m";
const string COLOR_RESET = "\u001b[0m";
vector<int> drawnNumbers;

void displayBingoTable(int max_value) {
    cout << "Bingo Table:\n" << endl;
    for (int i = 1; i <= max_value; i++) {
        bool isDrawn = find(drawnNumbers.begin(), drawnNumbers.end(), i) != drawnNumbers.end();
        cout << (isDrawn ? COLOR_RED : "") << setw(3) << i << COLOR_RESET;
        cout << ((i % 10 == 0) ? "\n" : " | ");
    }
    cout << endl;
}

int generateRandomNumber(int max_value) {
    return rand() % max_value + 1;
}

int getMaxValue(int choice) {
    switch (choice) {
        case 1: return 75;
        case 2: return 90;
        case 3: return 100;
        default: return 0;
    }
}

bool isNumberGenerated(int number) {
    return find(drawnNumbers.begin(), drawnNumbers.end(), number) != drawnNumbers.end();
}

void generateAndSaveCard(int max_value, int card_number) {
    ofstream file("Card" + to_string(card_number) + ".txt");
    if (!file) {
        cerr << "Erro ao criar ficheiro para o cartão " << card_number << endl;
        return;
    }
    vector<int> cardNumbers;
    for (int i = 0; i < 25; i++) {
        int num = generateRandomNumber(max_value);
        cardNumbers.push_back(num);
        file << num << ((i % 5 == 4) ? "\n" : " | ");
    }
    file.close();

    cout << "Cartão " << card_number << " números: ";
    for (int num : cardNumbers) cout << num << " ";
    cout << endl;
}

void playBingo(int max_value, bool automatic) {
    int lastDrawnNumber = 0;
    char playAgain;
    do {
        int drawnNumber;
        do {
            drawnNumber = generateRandomNumber(max_value);
        } while (isNumberGenerated(drawnNumber));
        drawnNumbers.push_back(drawnNumber);

        cout << "\nÚltimo número: " << lastDrawnNumber << "\nNúmero sorteado: " << drawnNumber << endl;
        displayBingoTable(max_value);
        lastDrawnNumber = drawnNumber;

        if (automatic) {
            sleep(2);
            system("clear || cls");
        } else {
            cout << "Continuar? (y/n): ";
            cin >> playAgain;
        }
    } while (automatic || playAgain == 'y' || playAgain == 'Y');
}

int main() {
    srand(time(0));
    int choice;
    do {
        cout << "Escolhe a quantidade de números:\n1. 75\n2. 90\n3. 100\n";
        cin >> choice;
    } while (choice < 1 || choice > 3);
    
    int max_value = getMaxValue(choice);
    
    int generator_type;
    do {
        cout << "Tipo de gerador:\n1. Automático\n2. Manual\n";
        cin >> generator_type;
    } while (generator_type < 1 || generator_type > 2);
    
    int amount_cards;
    cout << "Número de cartões a gerar: ";
    cin >> amount_cards;
    for (int i = 1; i <= amount_cards; i++) {
        generateAndSaveCard(max_value, i);
    }
    
    playBingo(max_value, generator_type == 1);
    return 0;
}
