#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// This file is used to display the number of directory, files or bytes according the the option that user entered

int main(int argc, char *argv[])
{
	char resultsPrompt[256];
	if(strcmp("-d", argv[1]) && strcmp("-b", argv[1]) && strcmp("-f", argv[1]))
	{
		cout << "The option you provide is invalid" << endl;
	} // End case of the option is not d, b or f

	// Loop while the standard input is not null
	while(fgets(resultsPrompt, 256, stdin) != NULL)
    {
		if(!strcmp("-d", argv[1]) && strstr(resultsPrompt, "directories") != NULL)
        {
                cout << resultsPrompt << endl;
			break;
		} // End case of user enter the option for directory
		else if((!strcmp("-f", argv[1])&& strstr(resultsPrompt, "files") != NULL))
        {
			cout << resultsPrompt << endl;
			break;
		} // End case of user enter the option for file
		else if((!strcmp("-b", argv[1])) && strstr(resultsPrompt, "bytes") != NULL)
        {
			cout << resultsPrompt << endl;
			break;
		} // End case of user enter the option for bytes
	}
}
