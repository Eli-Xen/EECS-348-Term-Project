#include "modulus.h"
#include "addSubtract.h"
#include "multDiv.h"
#include "expo.h"
#include <vector>
using namespace std;

class ExpressionEval {
//This is a class that will tokenize the input string
//Then it will use those tokens to feed input to the operations classes 
private:
    //Store the input string
    string expression;
    //A vector for storing our tokens
    //Vector is similar to the python list 
    vector<string> tokens;
public:
    //The method that will turn the input into tokens 
    void token(){};

    //Method that will call operations on the tokens
    template <typename T> T run();

    //Method to check if a char is an operator
    bool isOperator(char character){
        return (character == '*' || character == '/' || character =='%' || character == '-' || character == '+');
        
    }
    //Getter for the expression var
    string getExp(){
        return expression;
    }

    

};

void ExpressionEval::token(){
    //Set exp as a short hand for the input string 
    string exp = getExp();
    //Set a current token
    //We will be added to this in the cases like decimals and negitives 
    string currentToken;
    for (int i = 0; i < exp.length(); i++) {
        //Main loop
        if (isdigit(exp[i]) || '.') {
            //Check if the current char is a number or a decimal place
            //If it is we can add it to our current token
            currentToken += exp[i];
        }
        //Check if the current char is a negitive sign
        //We have to do a be of checking to make sure that its not a minus operation 
        else if (exp[i] == '-' && (i == 0 || isOperator(exp[i-1])) || (exp[i-1] == '*') && exp[i-2] == '*'){
            //If it is a negitive sign, we can add it to the token 
            //If the logic works this should always be at the start of a token
            currentToken += exp[i];
        }

        //Because c++ hates my happness exponents can't be checked as a char
        //So we have to check if the current char is a *. Then we can check if the next char is as well
        else if (exp[i] == '*'&& exp[i + 1] == '*'){
            //If there is already an expression in the current token, we clear it 
            if (currentToken != "") {
                tokens.push_back(currentToken);
                currentToken = "";
            }
            //Add the operator 
            tokens.push_back("**");
            i++;
        }
        //Checks if the current char is a normal one length operator
        else if (isOperator(exp[i])){
            //Checks if there is already stuff in the current token 
            if (currentToken != "") {
                tokens.push_back(currentToken);
                currentToken = "";
            }
            //C++ and I got into a fight about chars and strings 
            //This abomination was our compromise
            string s = "";
            tokens.push_back(s + exp[i]);

        }

    }
    //Pushes the last token to the vector 
    if (currentToken != ""){
        tokens.push_back(currentToken);
    }


    
}
template <typename T> T ExpressionEval::run(){
    //This block of for loops should evaluate the tokens acording to PEMDAS
    //It's still a bit of a work in progress 
    for(int i = 0; i < tokens.size(); i++ ){
        //Find all exponets and send them to be evaluated 
        if(tokens[i] == "**"){
            Expo::evaluateExpo(tokens[i-1],tokens[i+1]);
        }
    }

    for(int i = 0; i < tokens.size(); i++ ){
        //Find all the multiplication, division, and modulus.
        if(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "%"){
            //Seperate check for mod because we have to call a different class
            if(tokens[i] == "%"){
                Modulus::validateInput(tokens[i-1], tokens[i+1]);
            }
            else{
                MultDiv::validateInput(tokens[i-1] + tokens[i] + tokens[i+1]);
            }
        }
    }

    for(int i = 0; i < tokens.size(); i++ ){
        //Find all the addition and subtraction
        if(tokens[i] == "+" || tokens[i] == "-"){
            AddSub::validateInput(tokens[i-1] + tokens[i] + tokens[i+1]);
        }
    }


}
