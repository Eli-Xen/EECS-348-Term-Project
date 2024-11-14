#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Main {
private:
	//Varable to store the input from terminal
	string uncleanInput;
	//A varable to store the clean input after InputProcessor is called
	string cleanInput;


public:
	//makes first call to input processor class
	string callInput();
	//Method for getting the user input from terminal
	string getInput();

	//Setters for string varables
	void setCleanInput(string data){
		cleanInput = data;
	}
	void setUncleanInput(string data){
		uncleanInput = data;
	}
	//Getters for string varables
	string getCleanInput(){
		return cleanInput;
	}
	string getUncleanInput(){
		return uncleanInput;
	}

};



int main()
{
	Main start; //starts the program 
	start.callInput();
	return 0; 
}


string Main::callInput() //edit this to call class InputProcessor 
{
	InputProcessor inputProcessor
	string expression=inputProcessor.processInput() //change the name of method based on what its called 
	return expression; 
}

string Main::getInput(){
	//Ask user for input
	cout << "Enter expression: ";
	string tempStorage;
	getline(cin, tempStorage);
	//Use setter to set private varable
	setUncleanInput(tempStorage);
	//If we are just sending raw data to the inputProcessor I think this is enough 
	
	
}

int InputProcessor::cleanInput(string) {
	
}

int InputProcessor::checkInput(string){
	
}


