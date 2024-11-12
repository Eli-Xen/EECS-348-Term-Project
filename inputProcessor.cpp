#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class InputProcessor {
private:
  //put the string in here

public:
  // 1. Read values from stdin into a matrix
  string getInput();

  // 2. Clean input str
  int cleanInput(string);

  // 3. Check input str
  int checkInput(string);

	//getter (defined in class)

	//setter (defined in class)
	
};

string InputProcessor::getInput(){
	// some of this code is reusable so
	string mat_str;
	getline(cin, mat_str);
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




