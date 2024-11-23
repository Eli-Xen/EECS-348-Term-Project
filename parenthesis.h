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
	string originalExpression; 
	vector<string> tokens; 
	vector<string> postfix; 
	vector<string> final; 
public: 
	vector<string> tokenizer(string expression); 
	vector<string> postfix(const vector<string>& tokens); 
	vector<string> expressionTree(const vector<string>& postfix); 
}; 
#endif //ends defenition of header file 
