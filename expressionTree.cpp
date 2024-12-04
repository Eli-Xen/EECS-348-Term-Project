#include <iostream>
#include <string>
#include <sstream> 
#include <vector> 
#include <stack>
#include <algorithm>
#include "expressionTree.h"
#include "addSubtract.h"
#include "multDiv.h"
#include "expo.h"
#include "modulus.h"

//#include <iomanip>


vector<string> ExpressionTree::tokenizer(string expression){
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
vector<string> ExpressionTree::cleanToken(vector<string> &tokens){
    //Throw error if we have operations at the end of the expression 
    if(tokens.size() == 1 && isdigit(tokens[0][0])){
        return tokens;
    }
    if(isOperator(tokens[tokens.size()-1])){
        cout << "Expression invalid. Expression cannot end with operator.";
        vector<string> v;
        v.push_back("!");
        return v;
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
        int j = 0;
        while(j < tokens.size()){
            if(j-1 >= 0 && tokens[j] == "(" && tokens[j-1] == "-"){
                if(j-2 >= 0 && !isdigit(tokens[j-2][tokens[j-2].size() -1])){
                    tokens[j-1] = "-1";
                    tokens.insert(tokens.begin() + j, "*");
                }
                else if(j-2 < 0){
                    tokens[j-1] = "-1";
                    tokens.insert(tokens.begin() + j, "*");                   
                }
            }
            j++;
    }
    return tokens;
}


vector<string> ExpressionTree::postFix(const vector<string>& tokens) //passes vector by referance but uses const to avoid changes 
{
    vector<string> postfix; //vector that stores result 
    stack<string> stck;
    
    //Check if the token is a number or a negative number
    for (const string& token : tokens) {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1 && isdigit(token[1]))) {
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
            while (!stck.empty() && stck.top() != "(" &&
                   ((token == "+" || token == "-") || 
                    (token == "*" || token == "/") && (stck.top() == "*" || stck.top() == "/" || stck.top() == "**") || 
                    (token == "**" && stck.top() == "**"))) {
                postfix.push_back(stck.top());
                stck.pop();
            }
            stck.push(token); // Push the current operator
        }
    }
    //pop remaining
    while (!stck.empty()) {
        postfix.push_back(stck.top());
        stck.pop();
    }
    return postfix; //return vector directly 
}


Node* ExpressionTree::expressionTree(const vector<string>& postfix) //needs to recurse so takes a node and a vector 
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

string ExpressionTree::evaluateExpression(Node* root) 
{
    if (!root) return "error: empty tree"; //if root is nullptr or doesnt exist 
    Node* current=root; 


    //cout << "Expression tree visualization: " << endl;
    //visualizeTree(root);


    while(!(isdigit(root->value[root->value.length() - 1]) || root->value[root->value.length() - 1]=='e')) //until the root is a digit or returns error //isgdigit only takes char so to checks if first char in string is digit 
    {
        if (!current) return ""; //base case, if current is null 	
        else if (current->left && !isdigit(current->left->value[current->left->value.length() - 1])) //if left exists and is operator (so doesnt check nonexistent node and cause error)... 
            {current=current->left; } //...traverse left 
        else if (current->right && !isdigit(current->right->value[current->right->value.length() - 1])) //if right exists and is operator...
            {current=current->right; } //..traverse right 
        else if (current->left && current->right && isdigit(current->left->value[current->left->value.length() - 1]) && isdigit(current->right->value[current->right->value.length() - 1])) //if both left and right exist and are digits then use current value (operator) to evaluate 
        {
            cout << "current token: " << current->value << endl; 
            if (current->value=="+" || current->value=="-"){
                AddSub addSubtract;
                current->value=addSubtract.evalAddSub(current->left->value, current->value, current->right->value);
            }
            else if (current->value=="*" || current->value=="/"){
                MultDiv multDiv;
                current->value=multDiv.evalMultDiv(current->left->value, current->value, current->right->value); //function name might change so check this 
            }
            else if (current->value=="%"){
                Modulus modulus;
                current->value=modulus.evaluateModulus(current->left->value, current->right->value); 
            }
            else if (current->value=="**"){
                Expo expo;
                current->value=expo.evlExponent(current->left->value, current->right->value); 
            }
            else
                return "error: unknown operand in ExpressionTree::evaluateExpression()"; 
        
            //left and right children are deleted so that they dont mess up the tree 
            delete current->left;
            delete current->right;
            current->left = nullptr;
            current->right = nullptr; 
            current = root; //restart traversal so that current isnt stuck at node we just evaluated 
        }
        else return "error: evaluateExpression"; //somethings really bad
        //visualizeTree(root);    
    } 

	return root->value;
}


string ExpressionTree::run(string expression){
    ExpressionTree runObject;
    vector<string> tokens = runObject.tokenizer(expression);
    cout << endl;
    tokens = runObject.postFix(tokens);
    cout << "Postfix: ";
    for (const string& token : tokens) {
        cout << '"' << token << '"' << ", ";
    }
    cout << endl;
    Node * tree = runObject.expressionTree(tokens);
    string result = runObject.evaluateExpression(tree);
    cout << "Result: " << result<<endl;
    return result;
}
