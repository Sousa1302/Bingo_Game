#include "setFileReadOnly.h"

void setFileToReadOnly(const string& filename){
    if (chmod(filename.c_str(), S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        cerr << "Failed to set file to read-only: " << filename << endl;
    }
}