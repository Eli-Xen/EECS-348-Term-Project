#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Main {
private:
	//A varable to store the clean input after InputProcessor is called
	string cleanInput;


public:
	//makes first call to input processor class
	string callInput();

	//Setters for string varables
	void setCleanInput(string data){
		cleanInput = data;
	}

	//Getters for string varables
	string getCleanInput(){
		return cleanInput;
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


int InputProcessor::cleanInput(string) {
	
}

int InputProcessor::checkInput(string){
	
}


