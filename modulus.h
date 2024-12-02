//include gaurds 
#ifndef MODULUS_H //checks if MODULUS_H has alrdy been defined, if true then this file will be skipped 
#define MODULUS_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class Modulus {
private:
    string expression;

public:
    string evaluateModulus(string left, string right);

    //Function for checking if the data is vaild
    //For example, if negitive values are passes in we need to do some preprocessing
    //Also we can convert the string into ints here
    int validateInput(string left, string right);

};
#endif //ends defenition of header file 