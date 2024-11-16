#include <iostream>
#include <string>
#include <sstream>

#include "inputProcessor.h" //header file for this file
using namespace std;

class InputProcessor {
private:
	//put the string in here
        //Varable to store the input from terminal
	string uncleanInput;

public:
	// 1. Read values from stdin into a private variable uncleanInput
	string getInput();

	// 2. Clean input str
	void cleanInput();

	// 3. Check input str
	int checkInput();

	//setter (defined in class)

	void setUncleanInput(string data){
		uncleanInput = data;
	}
	//getter (defined in class)
	string getUncleanInput(){
		return uncleanInput;
	}
	
};

string InputProcessor::getInput(){
	//Ask user for input
	cout << "Enter expression: ";
	string tempStorage;
	getline(cin, tempStorage);
	//Use setter to set private varable
	setUncleanInput(tempStorage);
	cleanInput();
}

void InputProcessor::cleanInput() {
	//gets the str
	string tempStorage = getUncleanInput();
	string cleanInput;
	//cleans it of whitespace
	for (int i = 0; i < tempStorage.length(); i++) {
		if (tempStorage[i] == " ")
			continue;
		cleanInput.append(tempStorage[i]);
	}
	//assigns the cleaned value to the "uncleaned input" member var- 
	//should we rename that or make a new var?
	setUncleanInput(cleanInput);
}

int InputProcessor::checkInput(){
	string tempStorage = getUncleanInput();
	if (tempStorage == "q") || (tempStorage == "Q")
		return -1;
	for (int i = 0; i < (tempStorage.length() - 1); i++) {
		//trying to convert to ascii this might not work if str slicing is not type char
		if (36 < int(tempStorage[i]) < 58) {
			//means its either a number or mostly valid numerical chars
			if (tempStorage[i] != "'" && tempStorage[i] != "," && tempStorage[i] != "-") {
				//chars are all valid
				//this is terrible
				
			}
		}
	}
	return 0;
}




