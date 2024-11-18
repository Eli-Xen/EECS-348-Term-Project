//include gaurds 
#ifndef MULTDIV_H //checks if MULTDIV_H has alrdy been defined, if true then this file will be skipped 
#define MULTDIV_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class MultDiv{
    private:
        string expression;

    public:

        int evaluateDiv(int left, int right);

        int evaluateMult(int left, int right);

        int run();

        int validateInput(string data);

};
#endif //ends defenition of header file 