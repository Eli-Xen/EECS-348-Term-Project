#include "modulus.h" //header file for this file
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Modulus {
private:
    //I'm not sure what type of data we want to pass into these classes
    //For now I left it as string. Feel free to change as needed
    string expression;

public:
    string evaluateModulus(string left, string right);

    //Function for checking if the data is vaild
    //For example, if negitive values are passes in we need to do some preprocessing
    //Also we can convert the string into ints here
    int validateInput(string left, string right);

};

string Modulus::evaluateModulus(string left, string right){
    if (validateInput(left, right)==-1) //validate input first within 
        return "error: invalid operands for modulus" 
    double l = stod(left);
    double r = stod(right);
    double result = 0.0;

    /*in case we need to handle negatives*/
    // if (l < 0.0 || r < 0.0) {        
    //     if (l < 0.0 && r > 0.0) {
    //         int i = -1;
    //         while (r > l) {
    //             r = r*i;
    //             i--;
    //         }
    //         result = l - r;
    //         return result;
    //     } else if ()
        result = fmod(l,r); //fmod allows modulus calculation of doubles through cmath
        string s_result = to_string(result);
        return s_result;
    // }

}


int Modulus::validateInput(string left, string right){
/*Not quite sure what I should return as an error, I imagine we are making
a method later that will be used to stop the program, leaving logic here*/
    double l = stod(left);
    double r = stod(right);
    if (r == 0.0) { //checks division by zero
        return -1; 
        //cerr needs to be followed by an error message, correct? same with the one two lines below. not super certain how it works so i might be wrong
    } else if (l < 0.0 || r < 0.0) {    //checks if any operands are negative
        return -1;
    } else {
        return 0;
    }
}

