#include "setFileReadOnly.h"

/**
 * @brief Sets the specified file to read-only mode.
 * 
 * This function changes the file permissions of the given file to read-only for the user,
 * group, and others. It uses the `chmod` system call to modify the file permissions.
 * If the operation fails, an error message is printed to the standard error stream.
 * 
 * @param filename The name of the file to set to read-only mode.
 */
void setFileToReadOnly(const string& filename){
    if (chmod(filename.c_str(), S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        cerr << "Failed to set file to read-only: " << filename << endl;
    }
}