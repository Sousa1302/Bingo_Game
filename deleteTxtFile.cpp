#include <iostream>
#include <filesystem> 
#include <vector>
#include <string>
#include "deleteTxtFile.h"
#include <unistd.h>

namespace fs = filesystem; 

/**
 * @brief Deletes text files associated with the given player indexes.
 *
 * This function iterates through a vector of player indexes, constructs the corresponding
 * filenames in the format "Card_<playerIndex>.txt", and attempts to delete each file.
 * If the file exists and is successfully deleted, a confirmation message is printed.
 * If the file does not exist or cannot be deleted, an appropriate error message is displayed.
 * After each file operation, the function pauses for 2 seconds and clears the console.
 *
 * @param playerIndexes A vector of integers representing the indexes of players whose
 *                      associated text files are to be deleted.
 */
void deleteTxtFiles(const std::vector<int>& playerIndexes) {
    for (int playerIndex : playerIndexes) {
        string filename = "Card_" + to_string(playerIndex) + ".txt";
        
        if (fs::exists(filename)) {
            
            if (fs::remove(filename)) {
                cout << "Deleted file: " << filename << endl;
            } else {
                cerr << "Error: Could not delete file " << filename << endl;
            }
        } else {
            cerr << "Error: File " << filename << " does not exist." << endl;
        }
        sleep(2);
        system("clear");
    }
}