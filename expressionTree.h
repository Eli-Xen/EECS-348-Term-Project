//include gaurds 
#ifndef PARENTHESIS_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define PARENTHESIS_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
#include <iostream>
#include <sstream> 
#include <vector>
using namespace std; 

class Parenthesis
{
private:
	string originalExpression; 
	vector<string> tokens; 
	vector<string> postfix; 
	Node* root; 
	string final; 
public: 
	bool isOperator(string character){return (character == "*" || character == "/" || character =="%" || character == "-" || character == "+" || character == "**");} 
	vector<string> tokenizer(string expression); 
	vector<string> postfix(const vector<string>& tokens); 
	Node* expressionTree(const vector<string>& postfix); 
	string evaluateExpression(Node* root); 
}; 
#endif //ends defenition of header file 
