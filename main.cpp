#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Main {
private:
	//Varable to store the input from terminal
	string uncleanInput;
	//A varable to store the clean input after InputProcessor is called
	string cleanInput;


public:
	//makes first call to input processor class
	string callInput();

};



void main()
{
	Main start; //starts the program 
	start.callInput();
	return 0; 
}


string Main::callInput() //edit this to call class InputProcessor 
{
	InputProcessor inputProcessor
	string expression=inputProcessor.processInput() //change the name of method based on what its called 
	return expression; 
}

string Main::getInput(){
	
	cout << "Enter expression: ";
	string tempStorage;
	getline(cin, tempStorage);
	setUncleanInput(tempStorage);
	//If we are just sending raw data to the inputProcessor I think this is enough 
	
	// some of this code is reusable so 
	istringstream iss(mat_str);
	int x;
	int row_num = 0;
	int col_num = 0;
	while (iss >> x) {
		if (row_num >= SIZE) {
			// if input size is too large, return
			return;
		}
		setMatrixElement(row_num, col_num, x);
		col_num++;
		if (col_num == SIZE) {
			//iterates 1 through (SIZE-1) for both column and row
			col_num = 0;
			row_num++;
		}
	}
}

int InputProcessor::cleanInput(string) {
	
}

int InputProcessor::checkInput(string){
	
}


