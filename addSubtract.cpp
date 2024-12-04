#include "addSubtract.h" //header file for this file
#include <iostream>
#include <string>
using namespace std;

string AddSub::evalAddSub(string left, string operation, string right){
    try {
        //converts to double
        double double_left = stod(left);
        double double_right = stod(right);
        double result;
        //subtracts or adds based on the value of operation- operation should either be a "-" or "+"
        if (operation == "-") {
            result = double_left - double_right;
            return to_string(result);
        } 
        else if (operation == "+"){
            result = double_left + double_right;
            return to_string(result);
        }
    } //if something goes wrong, an error will be printed to cout, and the function will return -1 
    catch (...) {
        cout << "Error arose within AddSub, expression that was being validated was " << left << operation << right << endl;
        return "error: AddSUbtract catch";
    }
    return "error: AddSubtract"; //this is to clear warning "control reaches end of non-void function" for function ending without clear return 
}

