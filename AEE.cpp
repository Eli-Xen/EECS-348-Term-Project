#include <iostream>
#include <string>
#include <sstream>
#include "inputProcessor.h"
#include "expressionTree.h"
#include "AEE.h" //header file for this file

using namespace std;

string AEE::callInput() //edit this to call class InputProcessor 
{
	InputProcessor  inputProcessor;
	string expression = inputProcessor.run(); //change the name of method based on what its called 
	//inputProcessor will return an empty string to quit the program, the string "input error" if input is invalid,
	//or the cleaned/validated string if the input is good
	return expression; 
}

string AEE::callParenthesis(string expression) //edit this to call class InputProcessor 
{
	ExpressionTree tree;//creates object of parenthesis handler 
	string express = tree.run(expression); //keeps track of matching parenthesis, returns to main sub-expressions that need to be evaluated
	//idea is to interact between parenthesis and main to evaulate each sub-expression one at a time and update the expression 
	return express; 
}

int main()
{
	AEE start; //starts the program 
	//start.setCleanInput(start.callInput()); 
	while(true){
		string input;
		cout << "Enter an arithmetic expression: ";
		getline(cin, input);
		//start.callParenthesis(start.getCleanInput()); 
		start.callParenthesis(input); 
	}
	return 0; 
}
