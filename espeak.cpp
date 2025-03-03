#include "espeak.h"

void espeak(string text){
    string command = "espeak \"" + text + "\"";
    system(command.c_str());
}