#include "expo.h" //header file for this file
#include <string> //so we can return strings from functions 
#include <iostream>
#include <sstream> 
using namespace std;

string Expo::evlExponent(string strBase, string strPower) {
//takes in operand and left (base) and right (exponent) 
    //loop that multiplies base by iteself exponent amount of times 
    //acommodate for negative exponents: solve as normal loop and then divide 1 by that result then return that 
    double base=stod(strBase);
    int power=stoi(strPower); //assumes power is pos/neg int 
    int neg=0; //tracks of power is negative, initially set to 0
    double result=1.0; 
    if (power<0)
        {power=power*-1; neg+=1;} //if power is negative set neg to True/1 
    for(int i=0; i<power; i++)
        {result*=base;}
    if (neg>0) //happens if power<0 
        {result=(1.0/base);} //divides 1 by the result to account for netaive
    return to_string(result); 
    
}

