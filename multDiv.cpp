#include "multDiv.h" 
#include <iostream> // Standard
using namespace std; // cout, cin, etc.

class MultDiv {

public:
    template <typename T> 
    T evaluateDiv(T left, T right) {
    if (right == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return -1; // This returns an error value 
    }
    return to_string(left/right); // perform normal division if otherwise
  } 

    template <typename T> 
    T evaluateMult(T left, T right) {
        return to_string(left * right); // perform normal multiplication
    }


    int validateInput(string left, string oper, string right){
        if (oper != "*" && oper != "/") {
            cout << "Error: Invalid operator, please use '*' or '/' " << endl;
            return -1; // Returns error value 
        } 
        // I'm not sure if necessary, but just a thought, this is a error handeling to check if both left and right numbers are numeric, delete if not needed
        for (char c : left + right) { // combine both strings 
            if (!isdigit(c) && c != '.') { // Allow digits and a decimal point
                cout << "Error: Invalid input. Make sure inputs are numbers" << endl;
                return -1; // Invalid input 
            } 
        }
        return 0; // Input is valid, yippee!!
    }  
};

 


