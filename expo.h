//include gaurds 
#ifndef EXPO_H //checks if EXPO_H has alrdy been defined, if true then this file will be skipped 
#define EXPO_H //starts defenition for header file 

#include <string> //so we can return strings from functions 
using namespace std;

class Expo {
private:
    string expression;

public:

    template <typename T> T evlExponent(T base, T power);

};
#endif //ends defenition of header file 