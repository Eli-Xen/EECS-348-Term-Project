//include gaurds 
#ifndef ADDSUBTRACT_H //checks if ADDSUBTRACT_H has alrdy been defined, if true then this file will be skipped 
#define ADDSUBTRACT_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class addSub
{
    private:
        string expression;
public:

    template <typename T> T  add(T left, T right);

    template <typename T> T findOperators(string data);

    template <typename T> T run();

    template <typename T> T  sub(T left,T right);

};
#endif //ends defenition of header file 