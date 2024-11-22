#include "addSubtract.h" //header file for this file
using namespace std;

class AddSub {
private:
    

public:
    
    template <typename T> T validateInput(T left, string operation, T right);

};


template <typename T> T AddSub::validateInput(T left, string operation, T right){
    try {
        //subtracts or adds based on the value of operation- operation should either be a "-" or "+"
        if (expression == "-") {
            return left - right;
        } else if (expression == "+")
            return left + right;
    } //if something goes wrong, an error will be printed to cout, and the function will return -1 
    catch (...) {
        cout << "Error arose within AddSub, expression that was being validated was " << left << expression << right << endl;
        return -1;
    }



