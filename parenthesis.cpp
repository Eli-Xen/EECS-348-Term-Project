#include <iostream>
#include <string>
#include <sstream> 
#include <vector> 
#include <stack>

using namespace std;

class Parenthesis {
private:
	//A varable to store the clean input after InputProcessor is called
	string originalExpression; //original string expression after inputProcessor does its thing
	vector<string> tokens; //vector that holds tokens after tokenizer runs 
	vector<string> postfix; //vector that holds postfix toekns expression after postfix runs 
	vector<string> final; //vector expressionTree runs 
public:
	//Method to check if a char is an operator
    bool isOperator(char character){return (character == '*' || character == '/' || character =='%' || character == '-' || character == '+');
	//each has pointer to vector it returns 
	vector<string> tokenizer(string expression); 
	vector<string> postfix(const vector<string>& tokens); //call to expression Eval and incorporation back into expression eliminate parenthesis in fullExpression, could be incorporated into countParenthesis and just make evalParenthesis 
	vector<string> expressionTree(const vector<string>& postfix); 
};


class Node //cute little binary node class right here! 
{
public: 
    string value; 
    Node* left; 
    Node* right; 
    Node(const std::string& value) : value(value), left(nullptr), right(nullptr) {} //constructor so it automatically makes the value given the value element 
}; 


vector<string> Parenthesis::tokenizer(string expression){
	vector<string> tokens;
    //Set exp as a short hand for the input string 
    string exp = expression;
    //Set a current token
    //We will be adding to this in the cases like decimals and negitives 
    string currentToken;
    for (int i = 0; i < exp.length(); i++) {
        //Main loop
        if (isdigit(exp[i]) || exp[i] == '.') {
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

        //Check if the current char is a *. Then we can check if the next char is as well
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
	return tokens;
}


vector<string> Parenthesis::postfix(const vector<string>& tokens) //passes vector by referance but uses const to avoid changes 
{
	vector<string> postfix; //vector that stores result 




	return postfix; //return vector directly 
}

Node Parenthesis::expressionTree(const vector<string>& postfix) //needs to recurse so takes a node and a vector/array of functions (HELP)
{
	//vector<string> final; //vector that stores result; idk what exactly were returning yet 
    stack<Node*> tree; //starts a stack that holds nodes 
    
    for (int i=0; i<postfix.size(); i++)
    {
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%' || postfix[i]=='**')
        {
            Node* right=tree.top(); //it needs pointers to be compatable with tree 
            tree.pop(); //apparently this doesnt autoamtically return the element so top then pop 
            Node* left=tree.top(); 
            tree.pop(); 
            Node* newOperator=new Node(postfix[i]);
            newOperator->right=right; //updates the opeartors left and right to be the operands we just popped 
            newOperator->left=left; //we use -> when changing elements that pointer points to we have to use -> 
            tree.push(newOperator); //puts the new operator node onto stack 

        } 
        else //if token is operator 
            {tree.push(new Node(postfix[i])); } //we dont need pointer * here because were making a new node and pushing 
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%' || postfix[i]=='**')
            {
                
                
            }
    }   

	return tree.top(); //in theory returns the root/top of the expression tree to then be evaluated 
}

