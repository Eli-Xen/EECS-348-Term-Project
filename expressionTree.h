//include gaurds 
#ifndef PARENTHESIS_H //checks if INPUTPROCESSOR_H has alrdy been defined, if true then this file will be skipped 
#define PARENTHESIS_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
#include <iostream>
#include <sstream> 
#include <vector>
using namespace std; 

class Node //cute little binary node class right here! 
{
public: 
    string value; 
    Node* left; 
    Node* right; 
    Node(const std::string& value) : value(value), left(nullptr), right(nullptr) {} //constructor so it automatically makes the value given the value element 
}; 

class ExpressionTree {
private:
	//A varable to store the clean input after InputProcessor is called
	string originalExpression; //original string expression after inputProcessor does its thing
	vector<string> tokens; //vector that holds tokens after tokenizer runs 
	vector<string> postfix; //vector that holds postfix toekns expression after postfix runs 
	Node* root; //vector expressionTree runs 
    string final; 
public:
    string run(string expression);
	//Method to check if a char is an operator
    bool isOperator(string character){return (character == "*" || character == "/" || character =="%" || character == "-" || character == "+" || character == "**");}  
	//each has pointer to vector it returns 
	vector<string> tokenizer(string expression); 
	vector<string> cleanToken(vector<string> &tokens);
	vector<string> postFix(const vector<string>& tokens); //call to expression Eval and incorporation back into expression eliminate parenthesis in fullExpression, could be incorporated into countParenthesis and just make evalParenthesis 
	Node* expressionTree(const vector<string>& postfix); 
    	string evaluateExpression(Node* root); //evaluates expression tree to a single string return 
};


#endif // PARENTHESIS_H

