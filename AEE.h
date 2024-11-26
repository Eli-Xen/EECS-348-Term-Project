//include gaurds 
#ifndef MAIN_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define MAIN_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std; 

class Main
{
private: 
  string cleanInput; 
public: 
  string callInput();
	void setCleanInput(string data); //setter 
	string getCleanInput(); //getter 
};
#endif //ends defenition of header file 
