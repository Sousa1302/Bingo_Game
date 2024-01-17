#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int numLinhasCartao     = 5;
const int numColunasCartao    = 5;
const int numColunasPainel    = 20;
const int intervaloEntreBolas = 500000;
const int msgPause            = 200000;

int sorteados      = 0;
int numeroSorteado = 0;
int numeroAnterior = 0;

int numerodeBolas, tipoSorteio, NumeroDeCartoes;

string red   = "\u001b[31m";
string blue  = "\u001b[34m";
string green = "\u001b[32m";
string reset = "\u001b[0m";
string bold  = "\u001b[1m";

typedef struct {
    int numero;
    bool sorteado;
} bingoPanel;

bingoPanel bingo[] = {};

void CenterString(string mensagem){
    int l = mensagem.length();
    int pos = (int) ((numColunasPainel * 3 - (l)) / 2);
    for (int i = 0; i < pos; i++){
        cout << " ";
    }
    cout << blue;
    cout << mensagem << reset;
    cout << blue << endl;
}

void initArray(){
    for ( int i = 0; i <= numerodeBolas; i++){
        bingo[i].numero = i+1;
        bingo[i].sorteado = false;
    }
}

void opcoes(){
    tipoSorteio = 0;

    while (tipoSorteio != 1 && tipoSorteio != 2 && tipoSorteio != 3 && tipoSorteio != 4){
        system("clear || cls");
        cout << blue << bold
        << "M E N U    P R I N C I P A L\n" << reset << blue
        << "-----------------------------" << endl
        << "1. Sorteio Manual\n"
        << "2. Sorteio Automático\n"
        << "3. Gerar Cartoes\n"
        << "4. Sair\n"
        << "-----------------------------" << endl
        << bold << "Opção: " << reset << blue;
    cin >> tipoSorteio;

    }
}


int main(){
    
    return 0;
}