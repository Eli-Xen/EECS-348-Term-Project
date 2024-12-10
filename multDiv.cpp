#include "multDiv.h"
#include <iostream>
#include <string>
using namespace std;

string MultDiv::evalMultDiv(string left, string operation, string right) {
    // Convert strings to doubles
    double double_left = stod(left);
    double double_right = stod(right);

    // Check operator and performs operation
    if (operation == "*") {
        return to_string(double_left * double_right); // simple mult.
    } else if (operation == "/") {
        if (double_right == 0) { //Error for dividing by zero
            return "error: Division by zero is not allowed.";
        }
        return to_string(double_left / double_right); //simple division
    } else {
        return "error: Invalid operator.";  // in case user doesnt use correct syntax
    }
}
