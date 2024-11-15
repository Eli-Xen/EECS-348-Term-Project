#ifndef INPUTPROCESSOR_H 
#define INPUTPROCESSOR_H 

#include <string> //so we can return strings from functions 
using namespace std;

class InputProcessor
{
private:
  extern string uncleanInput;
public: 
	string getInput();
	int cleanInput(string);
	int checkInput(string);
	void setUncleanInput(string data); //setter 
	string getUncleanInput(); //getter
}; 
#endif
