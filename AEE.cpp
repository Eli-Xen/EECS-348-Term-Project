#include <iostream>
#include <string>
#include <sstream>

using namespace std;
#include "main.h" //header file for this file

class Main {
private:
	//A varable to store the clean input after InputProcessor is called
	string cleanInput;


public:
	//makes first call to input processor class
	string callInput(); 
	string callParenthesis(); 
	//other functions for parenthesis class and other decision making (run) 

	//Setters for string varables
	void setCleanInput(string data){
		cleanInput = data;
	}

	//Getters for string varables
	string getCleanInput(){
		return cleanInput;
	}

};


string Main::callInput() //edit this to call class InputProcessor 
{
	InputProcessor inputProcessor
	string expression=inputProcessor.run() //change the name of method based on what its called 
	//inputProcessor will return an empty string to quit the program, the string "input error" if input is invalid,
	//or the cleaned/validated string if the input is good
	return expression; 
}

string Main::callParenthesis() //edit this to call class InputProcessor 
{
	ParenthesisHandler parenthesis //creates object of parenthesis handler 
	string expression=parenthesis.evalParenthesis() //keeps track of matching parenthesis, returns to main sub-expressions that need to be evaluated
	//idea is to interact between parenthesis and main to evaulate each sub-expression one at a time and update the expression 
	return expression; 
}

int main()
{
	Main start; //starts the program 
	start.callInput(); 
	start.callParenthesis(); 
	return 0; 
}
