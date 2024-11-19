#include "addSubtract.h" //header file for this file
using namespace std;

class AddSub {
private:
    //I'm not sure what type of data we want to pass into these classes
    //For now I left it as string. Feel free to change as needed
    string expression;

public:

    template <typename T> T  add(T left, T right);

    template <typename T> T findOperators(string data);


    template <typename T> T  sub(T left,T right);

};

template <typename T> T AddSub::add(T left, T right){
    
}

template <typename T> T AddSub::findOperators(string data){

}

template <typename T> T AddSub::sub(T left, T right){

}
