//include gaurds 
#ifndef EXPRESSIONEVAL_H //checks if EXPRESSIONEVAL_H has alrdy been defined, if true then this file will be skipped 
#define EXPRESSIONEVAL_H //starts defenition for header file 

#include "modulus.h"
#include "addSubtract.h"
#include "multDiv.h"
#include "expo.h"
#include <vector>
using namespace std;

class ExpressionEval {
//This is a class that will tokenize the input string
//Then it will use those tokens to feed input to the operations classes 
private:
    //Store the input string
    string expression;
    //A vector for storing our tokens
    //Vector is similar to the python list 
    vector<string> tokens;
public:
    void token(){};

    template <typename T> T run();

    bool isOperator(char character){
        return (character == '*' || character == '/' || character =='%' || character == '-' || character == '+');
        
    }
    string getExp(){
        return expression;
    }
};