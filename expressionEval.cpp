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

    int verifyTokens():

    //Method that will call operations on the tokens
    string run(string express);

    //Method to check if a char is an operator
    bool isOperator(char character){
        return (character == '*' || character == '/' || character =='%' || character == '-' || character == '+');
        
    }
    //Setter for the expession var
    void setExp(string val){
        expression = val;
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
    //We will be adding to this in the cases like decimals and negitives 
    string currentToken;
    for (int i = 0; i < exp.length(); i++) {
        if(isspace(exp[i])){
            continue;
        }
        //Main loop
        if (isdigit(exp[i]) || '.') {
            //Check if the current char is a number or a decimal place
            //If it is we can add it to our current token
            currentToken += exp[i];
        }
        //Check if the current char is a negitive sign
        //We have to do a bit of checking to make sure that its not a minus operation 
        else if (exp[i] == '-' && (i == 0 || isOperator(exp[i-1]))){
            //If it is a negitive sign, we can add it to the token 
            //If the logic works this should always be at the start of a token
            currentToken += exp[i];
        }

        //Because c++ hates my happiness exponents can't be checked as a char
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
            tokens.push_back(string(1,exp[i]));

        }

    }
    //Pushes the last token to the vector 
    if (currentToken != ""){
        tokens.push_back(currentToken);
    }
}

int verifyToken(){
    //Throw error if we have operations at the end of the expression 
    if(isOperator(tokens[tokens.size()-1])){
        return -1;
    }

    int i = 0;
    //Looks for repeated operations in the tokens
    //Example: +--+2 + 2
    //This should be simplified to 2+2
    while(i < tokens.size()){
        //Short hand for current token
        string token = tokens[i];
        //Checks if the current token is an operator 
        if(isOperator(token)){
            //Count to keep track of negitives 
            int count = 0;
            //Sets a variable to start where we found the first operator 
            int j = i;
            //If we haven't hit the end of the vector and we have more operators, keep going
            while(j < tokens.size() && isOperator(tokens[j])){
                if(tokens[j] == '-'){
                    count += 1;
                }
                j++;
            }
            //Shorthand c++ statment
            //Reads if count mod 2 is 0 then simplify = "+"
            //If not, simplify = "-"
            string simplify = (count % 2 == 0) ? "+" : "-";
            //Set the first operator to the simplified operator 
            tokens[i] = simplify;
            //Remove all operators between the new one and the next number 
            tokens.erase(tokens.begin() + i+1,tokens.begin() + j);
        }
        //Adjust index after removing elements from the vector
        i = j;
    }
    return 0;
}
string ExpressionEval::run(string express){
    setExp(express);
    token();
    verifyToken();
    //This block of for loops should evaluate the tokens acording to PEMDAS
    //It's still a bit of a work in progress 
    int i = 0
    while(i < tokens.size(); i++ ){
        //Find all exponets and send them to be evaluated 
        if(tokens[i] == "**"){
            string value = Expo::evaluateExpo(tokens[i-1],tokens[i+1]);
            tokens[i] = value;
            tokens.erase(tokens.begin() + i+1);
            tokens.erase(tokens.begin() + i-1);
            //Add to i to move 
            if(i < tokens.size()){
                i++;
            }
            else{
                break;
            }

        }
    }
    int i = 0
    while(i < tokens.size(); i++ ){
        //Find all the multiplication, division, and modulus.
        if(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "%"){
            //Seperate check for mod because we have to call a different class
            if(tokens[i] == "%"){
                string value = Modulus::validateInput(tokens[i-1], tokens[i+1]);
                tokens[i] = value;
                tokens.erase(tokens.begin() + i+1);
                tokens.erase(tokens.begin() + i-1);
                if(i < tokens.size()){
                    i++;
                }
                else{
                    break;
                }
            }
            else{
                string value = MultDiv::validateInput(tokens[i-1], tokens[i], tokens[i+1]);
                tokens[i] = value;
                tokens.erase(tokens.begin() + i+1);
                tokens.erase(tokens.begin() + i-1);
                if(i < tokens.size()){
                    i++;
                }
                else{
                    break;
                }
            }
        }
    }
    int i = 0
    while(i < tokens.size(); i++ ){
        //Find all the addition and subtraction
        if(tokens[i] == "+" || tokens[i] == "-"){
            string value = AddSub::validateInput(tokens[i-1], tokens[i],tokens[i+1]);
            tokens[i] = value;
            tokens.erase(tokens.begin() + i+1);
            tokens.erase(tokens.begin() + i-1);
            if(i < tokens.size()){
                i++;
            }
            else{
                break;
            }
        }
    }
}
