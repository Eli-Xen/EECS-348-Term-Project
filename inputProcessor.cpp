#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin();

  // 2. Display a matrix
  void display() const;

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const;

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const;

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const;

  // 6. Swap matrix rows
  void swapRows(int row1, int row2);
  
  // setter
  void setMatrixElement(int row, int col, int value) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
		data[row][col] = value;
	}
  }
  
  // getter
  int getMatrixElement(int row, int col) const{
	if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
		return data[row][col];
	} else {
		return 0;
	}
  }
};

void Matrix::readFromStdin(){
	// get values from cin
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

void Matrix::display() const {
	//displays matrix
	int row_num = 0;
	int col_num = 0;
	for (int i = 0; i < SIZE*SIZE; i++) {
		//uses getter to get the necessary value
		int num = getMatrixElement(row_num, col_num);
		cout << num << " ";
		col_num++;
		if (col_num == SIZE) {
			//iterates through row/column, and prints a newline after the last column
			col_num = 0;
			row_num++;
			cout << endl;
		}
	}
}

Matrix Matrix::operator+(const Matrix& other) const {
	//adds two Matrix objects together and returns the result
	Matrix c;
	for (int row = 0; row < SIZE; row++){
		for (int col = 0; col < SIZE; col++) {
			c.setMatrixElement(row, col, this->getMatrixElement(row, col) + other.getMatrixElement(row, col));
		}
	}
	return c;
}

Matrix Matrix::operator*(const Matrix& other) const {
	//multiplies two Matrix objects and returns the result
	Matrix c;
	for (int row = 0; row < SIZE; row++){
		for (int col = 0; col < SIZE; col++) {
			int sum = 0;
			for (int k = 0; k < SIZE; k++) {
				sum += this->getMatrixElement(row, k) * other.getMatrixElement(k, col);
			}
			c.setMatrixElement(row, col, sum);
		}
	}
	return c;
}

int Matrix::sumOfDiagonals() const {
	//sums the diagonals
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += getMatrixElement(i, i);
	}
	return sum;
}

void Matrix::swapRows(int row1, int row2) {
	//checks for invalid row input
	if (row1 >= SIZE || row2 >= SIZE || row1 < 0 || row2 < 0) {
		return;
	}
	//swaps rows
	for (int col = 0; col < SIZE; col++) {
		int temp = getMatrixElement(row1, col);
		setMatrixElement(row1, col, getMatrixElement(row2, col));
		setMatrixElement(row2, col, temp);
	}
}



