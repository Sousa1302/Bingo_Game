#include "espeak.h"

/**
 * @brief Converts the given text to speech using the `espeak` command-line tool.
 * 
 * This function takes a string of text and uses the `espeak` command to convert it
 * into speech. The text is passed as an argument to the `espeak` command, which
 * is executed using the `system` function.
 * 
 * @param text The text to be converted into speech.
 */
void espeak(string text){
    string command = "espeak \"" + text + "\"";
    system(command.c_str());
}