#include "expo.h" //header file for this file
#include<bits/stdc++.h> //https://www.geeksforgeeks.org/cpp-string-to-float-double-and-vice-versa/#
#include <string> //so we can return strings from functions 
#include <iostream>
#include <sstream> 
using namespace std;

class Expo {
private: 
    string expression;

public:

    template <typename T> T evlExponent(T base, T power);

};

template <typename T> T Expo::evlExponent(T base, T power){
//takes in operand and left (base) and right (exponent) 
    //loop that multiplies base by iteself exponent amount of times 
    //acommodate for negative exponents: solve as normal loop and then divide 1 by that result then return that 
    double base=stod(base);
    int power=stoi(power); //assumes power is pos/neg int 
    int neg=0; //tracks of power is negative, initially set to 0
    if (power<0)
        {power*-1; neg+=1;} //if power is negative set neg to True/1 
    for(int i; i<power; i++)
        {base*base;}
    if (neg>0) //happens if power<0 
        {base=(1/base);} //divides 1 by the result to account for netaive
    string result=to_string(base); 
    return result; 
    
}

