//include gaurds 
#ifndef AEE_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define AEE_H //starts defenition for header file 

#include <string> 
using namespace std;

class AEE {
private:
	//A varable to store the clean input after InputProcessor is called
	string cleanInput;


public:
  AEE() : cleanInput("") {} 
	//makes first call to input processor class
	string callInput(); 
	string callTree(string expression); 
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

#endif 
