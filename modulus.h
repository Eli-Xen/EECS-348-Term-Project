//include gaurds 
#ifndef MODULUS_H //checks if MODULUS_H has alrdy been defined, if true then this file will be skipped 
#define MODULUS_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class Modulus
{
private:
	string expression;
public: 
	int evaluateModulus(int left, int right);
	int run();
	int validateInput(string data); 
}; 
#endif //ends defenition of header file 