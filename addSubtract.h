//include gaurds 
#ifndef ADDSUBTRACT_H //checks if ADDSUBTRACT_H has alrdy been defined, if true then this file will be skipped 
#define ADDSUBTRACT_H //starts defenition for header file 
#include <iostream>
#include <string> //so we can return strings from functions 
using namespace std;

class AddSub{
public:
    
    string validateInput(string left, string operation, string right);
    
};
#endif //ends defenition of header file 
