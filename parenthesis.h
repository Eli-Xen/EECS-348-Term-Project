//include gaurds 
#ifndef PARENTHESIS_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define PARENTHESIS_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
#include <iostream>
#include <sstream> 
using namespace std; 

class Parenthesis
{
private:
	string fullExpression;
	string subExpression; 
public: 
	string countParenthesis(); 
	string subExpressionEval();
}; 
#endif //ends defenition of header file 
