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
	string countParenthesis(); 
	string subExpressionEval(); //call to expression Eval and incorporation back into expression eliminate parenthesis in fullExpression, could be incorporated into countParenthesis and just make evalParenthesis 

};


string Parenthesis::countParenthesis() 
{
	int count=0; //whenever there is a ( count+=1, when there is a ) count-=1 
	//seperation of subexpressions and numbers 
}

string Parenthesis::subExpressionEval() //edit this to call class InputProcessor 
{
	expressionEval evaluator
}
