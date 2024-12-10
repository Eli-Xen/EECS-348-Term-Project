#include <iostream>
#include <string>
#include <sstream>

#include "inputProcessor.h" //header file for this file
using namespace std;

string InputProcessor::run()
{
	getInput();
	// cout << "getInput finished" << endl;
	cleanInput();
	// cout << "cleanInput finished" << endl;
	int check = checkInput();
	// cout << "checkInput finished" << endl;
	//cout << check;
	switch (check) 
	{
		case -1: //this means user wants to quit: returns empty str
		{
			// cout << "case -1" << endl;
			return "";
			break;
		}
		case 0: //validation was successful
		{
			// cout << "case 0" << endl;
			return getStrInput();
			break;
		}
		case 1: //error detected 
		{
			// cout << "case 1" << endl;
			return "error: input error or invalid input";
			break;
		}
	}
	return "error: inputProcessor::run()"; //this is to clear warning "control reaches end of non-void function" for function ending without clear return 
}

void InputProcessor::getInput()
{
	cout << "Enter arithmetic expression: "; //Ask user for input
	string tempStorage;
	getline(cin, tempStorage);
	setStrInput(tempStorage); //Use setter to set private varable
}

void InputProcessor::cleanInput() 
{
	string tempStorage = getStrInput();
	string cleanInput;
	
	for (int i = 0; i < tempStorage.length(); i++) //cleans it of whitespace- doesn't append value if it's whitespace
	{
		if (tempStorage[i] == ' ')
			continue;
		cleanInput += tempStorage[i];
	}
	setStrInput(cleanInput); //assigns the cleaned value to the member var
}

// int InputProcessor::checkInput(){
// 	string tempStorage = getStrInput();
// 	if (tempStorage == "q" || tempStorage == "Q") //to quit program
// 		return -1; //sends to run function and returns to main to indicate quit 
// 	for (int i = 0; i < tempStorage.length(); i++) {
// 		//converts to ascii
// 		if (36 < int(tempStorage[i]) && int(tempStorage[i]) < 58) {
// 			//means its either a number or mostly valid numerical chars
// 			if (tempStorage[i] != '\'' && tempStorage[i] != ',' && tempStorage[i] != '-') {
// 				//chars are all valid
// 				//now testing if two invalid operators r placed together
// 				//doesn't check if the final char is adjacent (what does this mean, past lily?)
// 				if (i == tempStorage.length()-1)
// 					continue;
// 				//if the slice is a non-number and the next slice is a non-number
// 				if (36 < int(tempStorage[i]) && int(tempStorage[i]) < 58) {
// 					//if any of these two are placed side by side, its valid, so it continues
// 					if ((tempStorage[i] == '*' && tempStorage[i+1] == '*' )|| (tempStorage[i] == ')' && tempStorage[i+1] == ')' )|| (tempStorage[i] == '(' && tempStorage[i+1] == '('))
// 						continue;
// 					else
// 						return 1;
// 				}
// 				//numbers automatically continue
// 				continue;
				
// 			}
// 		}
// 		return 1; //if it didn't hit any of the continues and successfully exits the loop, something was messed up, so it returns error
// 	}
// 	return 0; //all chars validated successfully
// }


int InputProcessor::checkInput()
{
	string tempStorage=getStrInput(); 
	if (tempStorage=="q" || tempStorage=="Q") return -1; //user wants to quit, return quit int 
	int starCount = 0;
	bool wasOperator = false;
	for (int i=0; i<tempStorage.length(); i++)
	{
		if (i - 1 > 0 && tempStorage[i-1] == '(' && tempStorage[i] == ')'){
			//This catches things like 2*()
			return 1;
		}
		if (wasOperator && !isdigit(tempStorage[i]) && tempStorage[i] != '('){
				//This returns an error for expression like (2+2*)
				return 1;
		}
		if (i-1 >= 0 && isdigit(tempStorage[i-1]) && (tempStorage[i]=='(')){
			//This catches things like 5(2+3)
			return 1;
		}
		if (isdigit(tempStorage[i]) || tempStorage[i]=='+' || tempStorage[i]=='-' || tempStorage[i]=='*' || tempStorage[i]=='/'  || tempStorage[i]=='%' || tempStorage[i]=='(' || tempStorage[i]==')') //check for allowed characters 
		{
			if (tempStorage[i]=='+' || tempStorage[i]=='-' || tempStorage[i]=='*' || tempStorage[i]=='/'  || tempStorage[i]=='%') {
				//This keeps track of the operations so that we can catch things like (2+2*)
				wasOperator = true;
			}
			else{
				wasOperator = false;
			}
			if (i<tempStorage.length()-1) //prevents out of bounds 
			{
				if (tempStorage[i] == '*'){
					starCount++;
				}
				if (starCount > 2){
					//We can't have more than two '*' in a row
					return 1;
				}
				if (tempStorage[i]=='*' && tempStorage[i+1]=='*') 
				{
					starCount++;
                    ++i; 
					continue; //continues to next loop after the * becuase valid 
				}

				if ((tempStorage[i]=='+' || tempStorage[i]=='-' || tempStorage[i]=='*' || tempStorage[i]=='/' || tempStorage[i]=='%') && 
				(tempStorage[i+1]=='+' || tempStorage[i+1]=='-' || tempStorage[i+1]=='*'  || tempStorage[i+1]=='/' || tempStorage[i+1]=='%')){ //if theres multiple operands in a row
					return 1; 
				}
				else if (tempStorage[i]==')' && tempStorage[i+1]=='(')
					return 1; //two parenthesis together like this is bad 

				if ((tempStorage[i]=='+' || tempStorage[i]=='-') && !(i==0 || tempStorage[i-1]=='(' || (tempStorage[i-1]=='+' || tempStorage[i-1]=='-' || tempStorage[i-1]=='*' || tempStorage[i-1]=='/' || tempStorage[i-1]=='%')) && !isdigit(tempStorage[i+1]) && tempStorage[i+1] != '('){ 
					return 1; //if current is +/- and its not the beggining of string and there wasnt a prenthesis before operator or another +/- and the next things isnt a digit 
				}
				if (tempStorage[i] != '*'){
					starCount = 0;
				}

			}
			if (tempStorage[tempStorage.size()-1] =='+' || tempStorage[tempStorage.size()-1] =='-' || tempStorage[tempStorage.size()-1] =='*' || tempStorage[tempStorage.size()-1] =='/'  || tempStorage[tempStorage.size()-1] =='%'){
				//The input can't end with an operator 
				return 1;
			}
			if (tempStorage[0] =='*' || tempStorage[0] =='/'  || tempStorage[0] =='%'){
				//The input can't start with an operator thats not '+' or '-'
				return 1;
			}
			
		}
		else return 1; //invalid char other than operators and digits 
		
	}
	return 0; //nothing triggered so everything good 
}