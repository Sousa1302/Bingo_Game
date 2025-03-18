#include <iostream>
#include <filesystem> 
#include <vector>
#include <string>
#include "deleteTxtFile.h"
#include <unistd.h>

namespace fs = filesystem; 

void deleteTxtFiles(const std::vector<int>& playerIndexes) {
    for (int playerIndex : playerIndexes) {
        std::string filename = "Card_" + std::to_string(playerIndex) + ".txt";
        
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