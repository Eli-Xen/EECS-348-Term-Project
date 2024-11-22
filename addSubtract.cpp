#include "addSubtract.h" //header file for this file
using namespace std;

class AddSub {
private:
    

public:

    template <typename T> T validateInput(T left, string operation, T right);

};


template <typename T> T AddSub::validateInput(T left, string operation, T right){
    try {
        if (expression == "-") {
            return left - right;
        } else if (expression == "+")
            return left + right;
    }
    catch (...) {
        cout << "Error arose within AddSub, expression that was being validated was " << left << expression << right << endl;
    }



