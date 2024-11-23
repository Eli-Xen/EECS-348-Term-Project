#include <iostream>
#include <string>
#include <sstream> 
#include <vector>

using namespace std;

class Parenthesis {
private:
	//A varable to store the clean input after InputProcessor is called
	string originalExpression; //original string expression after inputProcessor does its thing
	vector<string> tokens; //vector that holds tokens after tokenizer runs 
	vector<string> postfix; //vector that holds postfix toekns expression after postfix runs 
	vector<string> final; //vector expressionTree runs 
public:
	//each has pointer to vector it returns 
	vector<string> tokenizer(string expression); 
	vector<string> postfix(const vector<string>& tokens); //call to expression Eval and incorporation back into expression eliminate parenthesis in fullExpression, could be incorporated into countParenthesis and just make evalParenthesis 
	vector<string> expressionTree(const vector<string>& postfix); 
};



vector<string> Parenthesis::tokenizer(string expression)
{
	vector<string> tokens; //vector that stores result 




	return tokens; //return vector directly 
}

vector<string> Parenthesis::postfix(const vector<string>& tokens) //passes vector by referance but uses const to avoid changes 
{
	vector<string> postfix; //vector that stores result 




	return postfix; //return vector directly 
}

vector<string> Parenthesis::expressionTree(const vector<string>& postfix)
{
	vector<string> final; //vector that stores result; idk what exactly were returning yet 




	return final; //return vector directly 
}