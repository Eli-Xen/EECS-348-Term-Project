//include gaurds 
#ifndef INPUTPROCESSOR_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define INPUTPROCESSOR_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class InputProcessor {
private:
	//put the string in here
        //Varable to store the input from terminal
	string input;

public:
	InputProcessor(){}
	// 1. Read values from stdin into a private variable input
	void getInput();

	// 2. Clean input str
	void cleanInput();

	// 3. Check input str
	int checkInput();

	//could also make a run function
	string run();

	//setter (defined in class)
	void setStrInput(string data){
		input = data;
	}
	//getter (defined in class)
	string getStrInput(){
		return input;
	}
	
};

#endif 
