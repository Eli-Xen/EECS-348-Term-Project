#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

class Parenthesis {
private:
	//A varable to store the clean input after InputProcessor is called
	string fullExpression;
  string subExpression; 

public:
	//pointer to return array 
	arr tokenizer(string expression); 
	arr postfix(pointer to array after tokenizer); //call to expression Eval and incorporation back into expression eliminate parenthesis in fullExpression, could be incorporated into countParenthesis and just make evalParenthesis 
	//make new array that stores result and reutrn pointer to that array 
	arr expressionTree(pointer to array); 
};


string Parenthesis::tokenizer(string expression) 
{
	
}

string Parenthesis::postfix(pointer to tokenized array) //edit this to call class InputProcessor 
{
	expressionEval evaluator
}
