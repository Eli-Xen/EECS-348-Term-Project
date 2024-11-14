#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class InputProcessor {
private:
	//put the string in here
    //Varable to store the input from terminal
	string uncleanInput;

public:
	// 1. Read values from stdin into a matrix
	string getInput();

	// 2. Clean input str
	int cleanInput(string);

	// 3. Check input str
	int checkInput(string);

	//getter (defined in class)

	//setter (defined in class)

	void setUncleanInput(string data){
		uncleanInput = data;
	}
	//Getters for string varables
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
}

int InputProcessor::cleanInput(string) {
	
}

int InputProcessor::checkInput(string){
	
}




