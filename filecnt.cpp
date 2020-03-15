#include <iostream>
#include <string>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include "version.h"

// this program has a makefile
//
// This file is a command used in Linux that can take one argument that is the path of a directory.
// This file is used for counting the total number of directories, files and bytes in directory
using namespace std;

// function parameter
void cntFunction(char *, int *, int *, int *);
static const double VERSION=1.2;

int main(int argc, char *argv[]) {
	displayVersion();
	int numberOfDir = 0;
	int numberOfFiles = 0;
	int numberOfBytes = 0;

	if(argc < 2)
    {
	    cout << "The pathname is incorrect." << endl;
        return 0;
    }

	// call the counting function to count number of directories, files and bytes
	cntFunction(argv[1], &numberOfDir, &numberOfFiles, &numberOfBytes);

	// Output the results
	cout << "The total number of directories in directory " << argv[1] << " is: " << numberOfDir << "."<< endl;
	cout << "The total number of files in directory " << argv[1] << " is: " << numberOfFiles << "."<<  endl;
	cout << "The total number of bytes in directory " << argv[1] << " is: " << numberOfBytes << "."<<  endl;

	return 0;
}

// This function is used for counting the total number of directories, files and bytes
void cntFunction(char *pathName, int *numberOfDir, int *numberOfFiles, int *numberOfBytes)
{
    // open the directory
    DIR *directory = opendir(pathName);
    // Defining variables
	char newPath[256];
	struct dirent *dir;
	struct stat statFile;

	if(!directory)
    {
        return;
    } // end case of the directory is null

    // loop until directory is null
	while((dir=readdir(directory)) != NULL)
    {
		strcpy(newPath, pathName);
		strcat(newPath, "/");
		strcat(newPath, dir->d_name);

		if(dir->d_type == DT_REG)
        {
			(*numberOfFiles)++;
			stat(newPath, &statFile);
			(*numberOfBytes) += statFile.st_size;
		}
		else if(dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0  && strcmp(dir->d_name, "..") != 0)
        {
			(*numberOfDir)++;
            // call the  counting function recursively
			cntFunction(newPath, numberOfDir, numberOfFiles, numberOfBytes);
		}
	}
	// close the directory
	closedir(directory);
}
