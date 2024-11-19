#include "multDiv.h" //header file for this file
using namespace std;

class MultDiv {
private:
    //I'm not sure what type of data we want to pass into these classes
    //For now I left it as string. Feel free to change as needed
    string expression;

public:

    template <typename T> T evaluateDiv(T left, T right);

    template <typename T> T evaluateMult(T left, T right);

    template <typename T> T run();

    int validateInput(string data);



};

template <typename T> T MultDiv::evaluateDiv(T left, T right){
    
}

template <typename T> T MultDiv::evaluateMult(T left, T right){

}
template <typename T> T MultDiv::run(){

}


int MultDiv::validateInput(string data){

}