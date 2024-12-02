#include <iostream>
#include <string>
#include <sstream>

#include "inputProcessor.h" //header file for this file
using namespace std;

string InputProcessor::run(){
	getInput();
	cleanInput();
	int check = checkInput();
	cout << check;
	switch (check) {
		case -1:
			//this means user wants to quit: returns empty str
			return "";
			break;
		case 0:
			//validation was successful
			return getStrInput();
			break;
		case 1:
			//error occurred
			//maybe send something to std::err??
			return "input error";
			break;
	}

}

void InputProcessor::getInput(){
	//Ask user for input
	cout << "Enter expression: ";
	string tempStorage;
	getline(cin, tempStorage);
	//Use setter to set private varable
	setStrInput(tempStorage);
}

void InputProcessor::cleanInput() {
	//gets the str
	string tempStorage = getStrInput();
	string cleanInput;
	//cleans it of whitespace- doesn't append value if it's whitespace
	for (int i = 0; i < tempStorage.length(); i++) {
		if (tempStorage[i] == ' ')
			continue;
		cleanInput += tempStorage[i];
	}
	//assigns the cleaned value to the member var
	setStrInput(cleanInput);
}

int InputProcessor::checkInput(){
	string tempStorage = getStrInput();
	if (tempStorage == "q" || tempStorage == "Q") //to quit program
		return -1; //sends to run function and returns to main to indicate quit 
	for (int i = 0; i < tempStorage.length(); i++) {
		//converts to ascii
		if (36 < int(tempStorage[i]) && int(tempStorage[i]) < 58) {
			//means its either a number or mostly valid numerical chars
			if (tempStorage[i] != '\'' && tempStorage[i] != ',' && tempStorage[i] != '-') {
				//chars are all valid
				//now testing if two invalid operators r placed together
				//doesn't check if the final char is adjacent (what does this mean, past lily?)
				if (i == tempStorage.length()-1)
					continue;
				//if the slice is a non-number and the next slice is a non-number
				if (36 < int(tempStorage[i]) && int(tempStorage[i]) < 58) {
					//if any of these two are placed side by side, its valid, so it continues
					if ((tempStorage[i] == '*' && tempStorage[i+1] == '*' )|| (tempStorage[i] == ')' && tempStorage[i+1] == ')' )|| (tempStorage[i] == '(' && tempStorage[i+1] == '('))
						continue;
					else
						return 1;
				}
				//numbers automatically continue
				continue;
				
			}
		}
		//if it didn't hit any of the continues and successfully exits the loop, something was messed up, so it returns error
		return 1;
	}
	//all chars validated successfully
	return 0;
}


