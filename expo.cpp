#include "expo.h" //header file for this file
using namespace std;

class Expo {
private:
    //I'm not sure what type of data we want to pass into these classes
    //For now I left it as string. Feel free to change as needed
    string expression;

public:

    template <typename T> T evlExponent(T base, T power);

    template <typename T> T identifyComponents(string data);

    template <typename T> T run();


};

template <typename T> T Expo::evlExponent(T left, T right){

}

template <typename T> T Expo::identifyComponents(string data){

}

template <typename T> T Expo::run(){

}