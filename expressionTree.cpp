#include <iostream>
#include <string>
#include <sstream> 
#include <vector> 
#include <stack>
#include <algorithm>

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


vector<string> Parenthesis::postfix(const vector<string>& tokens) {
    vector<string> postfix; // This will store the resulting postfix expression
    stack<string> stck;     // This stack helps manage operators and parentheses

    // Helper function for operator precedence
    int precedence(const string& op) {
        if (op == "**") return 3; // Highest precedence for exponentiation
        if (op == "*" || op == "/" || op == "%") return 2; // Medium precedence
        if (op == "+" || op == "-") return 1; // Lowest precedence
        return 0; // Default for parentheses or unknown operators
    }   // Basically the four lines of code will help out with PEMDAS rules

    // Helper function to check if a token is a number
    bool isNumber(const string& token) {
        for (char c : token) {
            if (!isdigit(c)) {
                return false; // If any character is not a digit, it's not a number
            } // in other words, this will loop over each characther in the string token, and if each characther in the string is a digit number, it returns true, otherwise false
        }
        return true; // All characters are digits
    }

    // Main loop for converting infix to postfix
    for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i]; // Get the current token

        if (isNumber(token)) {
            // If the token is a number, add it to the postfix expression
            postfix.push_back(token);
        } else if (token == "(") {
            // If the token is an opening parenthesis, push it onto the stack
            stck.push(token);
        } else if (token == ")") {
            // If the token is a closing parenthesis, pop until an opening parenthesis is found
            while (!stck.empty() && stck.top() != "(") {
                postfix.push_back(stck.top());
                stck.pop();
            }
            if (!stck.empty() && stck.top() == "(") {
                stck.pop(); // Remove the opening parenthesis
            }
        } else if (isOperator(token)) {
            // If the token is an operator, manage precedence
            while (!stck.empty() && precedence(stck.top()) >= precedence(token)) {
                postfix.push_back(stck.top());
                stck.pop();
            }
            stck.push(token); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!stck.empty()) {
        postfix.push_back(stck.top());
        stck.pop();
    }
// push back will push back tokens to the end of the postfix vector 
    return postfix; // Return the resulting postfix expression
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
    if (!root) return "error: empty tree"; //if root is nullptr or doesnt exist 
    Node* current=root; 
    while(!(isdigit(root->value[0]) || root->value[0]=='e')) //until the root is a digit or returns error //isgdigit only takes char so to checks if first char in string is digit 
    {
        if (!current) return ""; //base case, if current is null 
        else if (current->left && !isdigit(current->left->value[0])) //if left exists and is operator (so doesnt check nonexistent node and cause error)... 
            {current=current->left; } //...traverse left 
        else if (current->right && !isdigit(current->right->value[0])) //if right exists and is operator...
            {current=current->right; } //..traverse right 
        else if (current->left && current->right && isdigit(current->left->value[0]) && isdigit(current->right->value[0])) //if both left and right exist and are digits then use current value (operator) to evaluate 
        {
            if (current->value=="+" || current->value=="-")
                current->value=addSubtract.evalAddSub(current->left->value, current->value, current->right->value);
            else if (current->value=="*" || current->value=="/")
                current->value=multDiv.evalMultDiv(current->left->value, current->value, current->right->value); //function name might change so check this 
            else if (current->value=="%")
                current->value=modulus.evaluateModulus(current->left->value, current->right->value); 
            else if (current->value=="**")
                current->value=expo.evlExponent(current->left->value, current->right->value); 
            else 
                return "error: unknown operand"; 
        }
        else return "error: evaluateExpression"; //somethings really bad
            
    } 

	return root->value;
}
