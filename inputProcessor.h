//include gaurds 
#ifndef INPUTPROCESSOR_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define INPUTPROCESSOR_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class InputProcessor
{
private:
	string uncleanInput;
public: 
	string getInput();
	int cleanInput(string);
	int checkInput(string);
	void setUncleanInput(string data); //setter 
	string getUncleanInput(); //getter
}; 
#endif //ends defenition of header file 
