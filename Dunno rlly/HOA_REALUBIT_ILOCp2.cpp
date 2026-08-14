#include <iostream>
#include <string>
#include "stackList.h"


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

bool isBalanced(std::string expr){
    while(!isEmpty<char>()) pop<char>();

    bool result = true;
    for(int i = 0; i < expr.length(); i++){
        char currentSymbol = expr[i];

        if(isOpening(currentSymbol)){
            push<char>(currentSymbol);
        }
        else if(isClosing(currentSymbol)){
            if(isEmpty<char>()){
                result = false;
                break;
            }
            char poppedSymbol = pop<char>();
            if(!isMatchingPair(poppedSymbol, currentSymbol)){
                result = false;
                break;
            }
        }
    }

    if(!isEmpty<char>()){
        result = false;
    }
    while(!isEmpty<char>()) pop<char>();
    return result;
}

int main(){
    std::string expr;
    std::cout << "Enter a expression: ";
    std::getline(std::cin, expr);

    if(isBalanced(expr)){
        std::cout << "The expression is balanced." << std::endl;
    }
    else{
        std::cout << "The expression is not balanced." << std::endl;
    }

    return 0;
}