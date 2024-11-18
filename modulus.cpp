#include "modulus.h" //header file for this file
using namespace std;

class Modulus {
private:
    //I'm not sure what type of data we want to pass into these classes
    //For now I left it as string. Feel free to change as needed
    string expression;

public:
    int evaluateModulus(int left, int right);

    int run()
    //Function for checking if the data is vaild
    //For example, if negitive values are passes in we need to do some preprocessing
    //Also we can convert the string into ints here
    int validateInput(string data);

}

int Modulus::evaluateModulus(int left, int right){

}
int Modulus::run(){

}

int Modulus::validateInput(string data){

}
