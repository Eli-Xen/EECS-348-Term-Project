//include gaurds 
#ifndef ADDSUBTRACT_H //checks if MODULUS_H has alrdy been defined, if true then this file will be skipped 
#define ADDSUBTRACT_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class addSub
{
private:
	string expression;
public: 
	int add(int left, int right);
    int findOperators(string data); 
	int run();
    int sub(int left, int right);

}; 
#endif //ends defenition of header file 