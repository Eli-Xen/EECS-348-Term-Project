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

string AEE::callTree(string expression) //edit this to call class InputProcessor 
{
	ExpressionTree tree;//creates object of Tree file  
	string result = tree.run(expression); //this runs tokenizer, reorganizes postfix into tokens, makes a tree out of tokens, and evaluates the tree 
	return result; 
}

int main()
{
	AEE start; //starts the program 
	while(true)
	{
		// string input;
		// cout << "Enter an arithmetic expression: ";
		// getline(cin, input);
		string processedInput=start.callInput(); 
		// cout << "callInput finished" << endl;
		if (processedInput=="") //if callInput returns empty string then that means user whats to quit 
		{
			cout << "you quit" << endl; 
			break; 
		}
		else if (processedInput.size() > 2 && processedInput[0]=='e' && processedInput[1]=='r' && processedInput[2]=='r'){
			cout << processedInput << endl; 
			continue;
		}
		string result = start.callTree(processedInput); 
		if (result.size() > 2 && result[0]=='e' && result[1]=='r' && result[2]=='r'){
			cout << result << endl; 
			continue;
		}
		cout << "Result: " << result << endl << endl;
	}
	return 0; 
}
