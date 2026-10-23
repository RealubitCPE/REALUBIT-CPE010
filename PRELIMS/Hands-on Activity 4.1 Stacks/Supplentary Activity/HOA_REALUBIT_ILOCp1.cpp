#include <iostream>
#include <string>

//Global stack state
char* stackArr;
int top = -1;

//Stack primitives
bool isEmpty() {
    if (top == -1)return true;
    return false;
}

bool isFull(int size) {
    if (top == size - 1)return true;
    return false;
}

void push(char newData){
    stackArr[++top] = newData;
}

char pop(){
    if(isEmpty()){
        return '\0';
    }
    char poppedValue = stackArr[top--];
    return poppedValue;
}   

//Symbol-matching function
bool isOpening(char c){
    return(c =='(' || c == '{' || c == '[');
}

bool isClosing(char c){
    return(c == ')' || c == '}' || c == ']');
}

bool isMatchingPair(char open, char close){
    switch(close){
        case ')':
            return open == '(';
        case '}':
            return open == '{';
        case ']':
            return open == '[';
    }
    return false;
}

//Main function
bool isBalanced(std::string expr){
    stackArr = new char[expr.length()];
    top = -1;
    bool result = true;

    for(int i = 0; i <expr.length(); i++){
        char currentSymbol = expr[i];

        if(isOpening(currentSymbol)){
            push(currentSymbol);
        }
        else if(isClosing(currentSymbol)){
            if(isEmpty()){
                result = false;
                break;
            }
            char poppedSymbol = pop();
            if(!isMatchingPair(poppedSymbol, currentSymbol)){
                result = false;
                break;
            }
        }
    }

    if(!isEmpty()){
        result = false;
    }
    delete[] stackArr;
    return result;
}

int main(){
    std::string expr;
    std::cout<< "Enter an expression to check: ";
    std::getline(std::cin, expr);

    if(isBalanced(expr)){
        std::cout<< "The expression is balanced." << std::endl;
    }
    else{
        std::cout<< "The expression is not balanced." << std::endl;
    }
    return 0;
}
