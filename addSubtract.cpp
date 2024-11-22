#include "addSubtract.h" //header file for this file
#include <iostream>
#include <string>
using namespace std;

class AddSub {
private:
    

public:
    
    string validateInput(string left, string operation, string right);

};


string AddSub::validateInput(string left, string operation, string right){
    try {
        //converts to double
        double double_left = stod(left);
        double double_right = stod(right);
        //subtracts or adds based on the value of operation- operation should either be a "-" or "+"
        if (operation == "-") {
            return string(double_left - double_right);
        } else if (operation == "+")
            return string(double_left + double_right);
    } //if something goes wrong, an error will be printed to cout, and the function will return -1 
    catch (...) {
        cout << "Error arose within AddSub, expression that was being validated was " << left << operation << right << endl;
        return "error";
    }



