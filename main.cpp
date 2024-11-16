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
	return expression; 
}

string Main::callParenthesis() //edit this to call class InputProcessor 
{
	ParenthesisHandler parenthesis //creates object of parenthesis handler 
	string expression=parenthesis.evalParenthesis() //keeps track of matching parenthesis, returns to main sub-expressions that need to be evaluated
	return expression; 
}

int main()
{
	Main start; //starts the program 
	start.callInput();
	return 0; 
}
