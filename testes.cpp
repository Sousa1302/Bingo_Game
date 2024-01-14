#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ncurses.h>

using namespace std;

int Number_Generator_Cards(int max_value) {
    return rand() % max_value + 1;
}

int Number_Generator_Bingo(int max_amount) {
    if (max_amount == 1) {
        return rand() % 75 + 1;
    }
    if (max_amount == 2) {
        return rand() % 90 + 1;
    }
    if (max_amount == 3) {
        return rand() % 100 + 1;
    }
    return 0;
}

bool isNumberGenerated(const vector<int> &numbers, int number) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == number) {
            return true; // if number has already been generated
        }
    }
    return false; // if number has not been generated yet
}

void printSortedNumbers(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    printw("Sorted Numbers: ");
    for (int x = 0; x < numbers.size(); x++) {
        printw("%d ", numbers[x]);
    }
    printw("\n");
    refresh();
}

void generateAndSaveCard(int max_value, int card_number) {
    ofstream file("Card" + to_string(card_number) + ".txt");

    if (file.is_open()) {
        vector<int> cardNumbers;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int num = Number_Generator_Cards(max_value);
                cardNumbers.push_back(num);
                file << num << " | ";
            }
            file << endl;
        }
        file.close();

        printw("Card %d Numbers: ", card_number);
        for (int x = 0; x < cardNumbers.size(); x++) {
            printw("%d ", cardNumbers[x]);
        }
        printw("\n");
    } else {
        cerr << "Unable to open file for card " << card_number << endl;
    }
}

void Terminal_Verification() {
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_BLACK);

        attron(COLOR_PAIR(2));
    }
}

int main() {
    srand(time(0));
    initscr(); // Inicializa o modo ncurses
    Terminal_Verification();

    int amount_nums;
    printw("Choose the amount of numbers\n");
    printw("1. 75 nums \n2. 90 nums \n3. 100 nums\n");
    refresh();
    cin >> amount_nums;

    int generator_type;
    printw("Choose the type of generator!\n");
    printw("1. Automatic \n2. Manual \n");
    refresh();
    cin >> generator_type;

    int amount_cards;
    printw("Type the amount of cards you want to generate: ");
    refresh();
    cin >> amount_cards;

    vector<int> drawnNumbers;

    for (int i = 1; i <= amount_cards; i++) {
        switch (amount_nums) {
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
                printw("You must type a number between 1-3!\n");
                refresh();
                return 1;
        }
    }

    char playAgain;
    do {
        int drawnNumber = Number_Generator_Bingo(amount_nums);

        while (isNumberGenerated(drawnNumbers, drawnNumber)) {
            drawnNumber = Number_Generator_Bingo(amount_nums);
        }

        attron(COLOR_PAIR(1));
        drawnNumbers.push_back(drawnNumber);

        printw("Last drawn number: %d\n", drawnNumbers[drawnNumbers.size() - 2]);
        printw("Drawn number: %d\n", drawnNumber);

        printSortedNumbers(drawnNumbers);

        attroff(COLOR_PAIR(1));

        printw("Do you want to play again? (y/n): ");
        refresh();

        noecho(); // Desativa o eco para a entrada do usuário
        cin >> playAgain;
        echo();   // Ativa o eco novamente após a entrada do usuário
        printw("\n");
        refresh();

    } while (playAgain == 'y' || playAgain == 'Y');

    getch();
    endwin(); // Finaliza o modo ncurses

    return 0;
}
