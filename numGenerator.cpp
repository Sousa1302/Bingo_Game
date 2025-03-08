#include "numGenerator.h"
#include <ctime>

NumGenerator::NumGenerator(int maxVal){
    max = maxVal;

    srand(time(0));
}

int NumGenerator::generate(){
    return rand() % max + 1;
}