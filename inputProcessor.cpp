#include <iostream>
#include <string>
#include <sstream>

#include "inputProcessor.h" //header file for this file
using namespace std;

class InputProcessor {
private:
	//put the string in here
        //Varable to store the input from terminal
	string input;

public:
	// 1. Read values from stdin into a private variable uncleanInput
	void getInput();

	// 2. Clean input str
	void cleanInput();

	// 3. Check input str
	int checkInput();

	//could also make a run function
	int run();

	//setter (defined in class)
	void setInput(string data){
		input = data;
	}
	//getter (defined in class)
	string getInput(){
		return input;
	}
	
};

int InputProcessor::run(){
	getInput();
	cleanInput();
	int check = checkInput();
	return check; //this will return a -1 if the user wants to quit the program, a 0 if the input is valid, and a 1 if input is invalid

}

void InputProcessor::getInput(){
	//Ask user for input
	cout << "Enter expression: ";
	string tempStorage;
	getline(cin, tempStorage);
	//Use setter to set private varable
	setInput(tempStorage);
}

void InputProcessor::cleanInput() {
	//gets the str
	string tempStorage = getInput();
	string cleanInput;
	//cleans it of whitespace
	for (int i = 0; i < tempStorage.length(); i++) {
		if (tempStorage[i] == " ")
			continue;
		cleanInput.append(tempStorage[i]);
	}
	//assigns the cleaned value to the member var
	setInput(cleanInput);
}

int InputProcessor::checkInput(){
	string tempStorage = getInput();
	if (tempStorage == "q") || (tempStorage == "Q") //to quit program
		return -1; //sends to run function and returns to main to indicate quit 
	for (int i = 0; i < tempStorage.length(); i++) {
		//trying to convert to ascii this might not work if str slicing is not type char
		if (36 < int(tempStorage[i]) < 58) {
			//means its either a number or mostly valid numerical chars
			if (tempStorage[i] != "'" && tempStorage[i] != "," && tempStorage[i] != "-") {
				//chars are all valid
				//now testing if two invalid operators r placed together
				//doesn't check if the final char is adjacent 
				if (i == tempStorage.length()-1)
					continue;
				//if the slice is a non-number and the next slice is a non-number- again might not work if string slicing doesn't cast to char
				if (int(tempStorage[i] < 48 ) && (int(tempStorage[i+1] < 48) {
					//if any of these two are placed side by side, its valid, so it continues
					if (tempStorage[i] == "*" && tempStorage[i+1] == "*") || (tempStorage[i] == ")" && tempStorage[i+1] == ")") || (tempStorage[i] == "(" && tempStorage[i+1] == "(")
						continue;
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




