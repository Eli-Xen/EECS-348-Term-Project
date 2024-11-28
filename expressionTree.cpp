#include <iostream>
#include <string>
#include <sstream> 
#include <vector> 
#include <stack>
#include <algorithm>
//#include <bits10_1.h>/stdc++.h> //idk why bits autopopulated '10_1.h' after it, might need to be removed


using namespace std;

class Parenthesis {
private:
	//A varable to store the clean input after InputProcessor is called
	string originalExpression; //original string expression after inputProcessor does its thing
	vector<string> tokens; //vector that holds tokens after tokenizer runs 
	vector<string> postfix; //vector that holds postfix toekns expression after postfix runs 
	Node* root; //vector expressionTree runs 
    string final; 
public:
	//Method to check if a char is an operator
    bool isOperator(string character){return (character == "*" || character == "/" || character =="%" || character == "-" || character == "+" || character == "**");}  
	//each has pointer to vector it returns 
	vector<string> tokenizer(string expression); 
	vector<string> Parenthesis::cleanToken(vector<string> &tokens);
	vector<string> postfix(const vector<string>& tokens); //call to expression Eval and incorporation back into expression eliminate parenthesis in fullExpression, could be incorporated into countParenthesis and just make evalParenthesis 
	Node* expressionTree(const vector<string>& postfix); 
    	string evaluateExpression(Node* root); //evaluates expression tree to a single string return 
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
        else if(exp[i] == '+' && (i-1 ) >= 0 && exp[i-1] == '('){
            continue;
        }
        else if (exp[i] == '(' || exp[i] == ')'){
            //If there is already an expression in the current token, we clear it 
            if (currentToken != "") {
                tokens.push_back(currentToken);
                currentToken = "";
            }
            //Add the parenthesis 
            tokens.push_back(string(1,exp[i]));
            currentToken = "";

        }
        //Check if the current char is a negitive sign
        //We have to do a bit of checking to make sure that its not a minus operation 
        //Worlds longest if statment 
        else if (exp[i] == '-' && currentToken[0] != '-' && (i == 0 || isOperator(string(1, exp[i-1])) || exp[i-1] == '(')){
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
        else if (isOperator(string(1, exp[i]))){
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
    tokens = cleanToken(tokens);
	return tokens;
}
vector<string> Parenthesis::cleanToken(vector<string> &tokens){
    //Throw error if we have operations at the end of the expression 
    if(tokens.size() == 1 && isdigit(tokens[0][0])){
        return tokens;
    }
    if(isOperator(tokens[tokens.size()-1])){
        //Throw error
        //Not sure how we want to handle this yet
    }
    int i = 0;
    //Looks for repeated operations in the tokens
    while(i < tokens.size()){
        //Checks if the first character in the token is a +
        if(tokens.size() > 0 && tokens[0] == "+"){
            tokens.erase(tokens.begin());//Removes the plus 
        }
        i++;
    }
    return tokens;
}


vector<string> Parenthesis::postfix(const vector<string>& tokens) //passes vector by referance but uses const to avoid changes 
{
	vector<string> postfix; //vector that stores result 
    stack<string> stck;
    
    //checks token if number, all_of() allows multidigit nums to be used
    for (const string& token : tokens) {
        if (all_of(token.begin(), token.end(), ::isdigit)) {
            postfix.push_back(token);
        }
        //operation for opening parenthesis
        else if (token == "(") {
            stck.push(token);
        }
        //operation for closing parenthesis
        else if (token == ")") {
            while (!stck.empty() && stck.top() != "(") {
                postfix.push_back(stck.top());
                stck.pop();
            }
            //removes the opening parenthesis
            if (!stck.empty() && stck.top() == "(") {
                stck.pop();
            }
        }
        //operation if token is operator
        else {
            while (!stck.empty() && stck.top() != "(") {
                postfix.push_back(stck.top());
                stck.pop();
            }
            stck.push(token);
        }

    }
    //pop remaining
    while (!stck.empty()) {
        postfix.push_back(stck.top());
        stck.pop();
    }

	return postfix; //return vector directly 
}


Node* Parenthesis::expressionTree(const vector<string>& postfix) //needs to recurse so takes a node and a vector 
{
	//vector<string> final; //vector that stores result; idk what exactly were returning yet 
    stack<Node*> tree; //starts a stack that holds nodes 
    
    for (int i=0; i<postfix.size(); i++)
    {
        if(!isOperator(postfix[i])) //if token is anything but an operator 
            {tree.push(new Node(postfix[i])); } 
        else //if token is operator 
        {
            Node* newOperator=new Node(postfix[i]);
            Node* right=tree.top(); //it needs pointers to be compatable with tree 
            tree.pop(); //apparently this doesnt autoamtically return the element so top then pop 
            Node* left=tree.top(); 
            tree.pop(); 
        
            newOperator->right=right; //updates the opeartors left and right to be the operands we just popped 
            newOperator->left=left; //we use -> when changing class elements that pointer points to 
            tree.push(newOperator); //puts the new operator node onto stack 
            //we dont need pointer * here because were making a new node and pushing 
        } 
    }   
    
	return tree.top(); //in theory returns the root/top of the expression tree to then be evaluated 
}

string Parenthesis::evaluateExpression(Node* root) 
{
	//while there are still operators in the tree 
	//the check for operators  kinda sucks here- taking the values of left and right nodes at index 0
	//operators would not be digits, while numbers *should* be digits in theory
    Node* current=root; 
	//while (!isdigit(root->right->value[0]) || !isdigit(root->left->value[0])) //while right and left values are not digits??? 
    //traverse to the lowest node that is still an operator

    if(!current) //base case, if current is null it returns 
        return ""; 
    else if ()
    else if (isdigit(current->left->value[0]) && isdigit(current->right->value[0])); //if both left and right are digits



    else if(isdigit(current->right->value[0]))//if the next's right value is a digit... //isgdigit only takes char so to checks if first
        Node* current = current->left; //traverse left 
    else 
        Node* current = current->right; //traverse left 



    if (isdigit(next->right->value)) //if the next's right value is a digit... 
        Node* next = root->left(); //traverse left 
    else
        Node* next = root->right();
    while (!isdigit(next->right->value[0]) || !isdigit(next->left->value[0])) 
    {
        if (isdigit(next->right->value)) 
        {
            next = next->left;
            continue;
        }
        next = next->right();
    //now... time for evaluating 
    string evaluatedExpression;
    if (next->value == "+" || next->value == "-")
        evaluatedExpression = AddSub.evalAddSub(next->left->value, next->value, next->right->value);
    else if (next->value == "*")
        evaluatedExpression = multDiv.evaluateMult(next->left->value, next->right->value);
    else if (next->value == "/")
        evaluatedExpression = multDiv.evaluateDiv(next->left->value, next->right->value);
    else if (next->value== "%")
        evaluatedExpression = Modulus.evaluateModulus(next->left->value, next->right->value); 
    else if (next->value == "**")
        evaluatedExpression = Expo.evlExponent(next->left->value, next->right->value);
    else //somethings really bad
        return "error in evaluateExpression";
    //turn next into the evaluated expression
    next->value() = evaluatedExpression;
    //this currently doesn't pop the terminal nodes, I don't think it needs to. we'll see

	return root->value();
}
