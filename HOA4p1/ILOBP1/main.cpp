#include <iostream>
#include <stack>

//global declaration
#define maxCap 10

int stackArr[maxCap];
int top = -1, newData;
//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display_Stack();

int main(){
// main driver 
    while(true)
    {   
        int choice;
        std::cout<<"======================================================="<<std::endl;
        std::cout<<"Stack Operations: \n"<<std::endl;
        std::cout<<"1. PUSH 2. POP 3. TOP 4. isEmpty 5. Is Full 6. Display Stack 7. Exit"<<std::endl;
        std::cout<<"======================================================="<<std::endl;
        std::cin>> choice;

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<<"is stack empty?"<< isEmpty()<<std::endl;
            break;
            case 5: std::cout<<"is the stack full?"<< isFull()<<std::endl;
            break;
            case 6: display_Stack();
            break;
            case 7: 
                std::cout<<"Exit"<<std::endl;
                exit(0);
            default: std::cout<<"Invalid Choice."<<std::endl;
            break;
        }
    }
    return 0;
}

//function definition
bool isEmpty(){
    //how do we verify if the stack is empty?
    if(top == -1) return true;
    return false;
}

bool isFull(){
    //how do we verify if the stack if full?
    if(top == maxCap -1)return true;
    return false;
}

void push(){
    //error checking
    if(isFull()){
        std::cout<<"Stack overflow."<<std::endl;
        return;
    }
    //pushing to the stack
    std::cout<<"Enter a new value: "<<std::endl;
    std::cin>> newData;
    //how do we insert the data into the stack>
    stackArr[++top] = newData;
}
void pop(){
    //error checking
    if(isEmpty){
        std::cout<<"Stack underflow."<<std::endl;
        return;
    }

    //Display the value that we are going to pop:
    std::cout<<"Popping: "<<stackArr[top]<<std::endl;

    //Decrement the top value from the stack
    top--;
}

void Top(){
    //error catching:
    if(isEmpty()){
        std::cout<<"The stack is empty."<<std::endl;
        return;
    }
    //check the top value:
    std::cout<<stackArr[top]<<std::endl;
}

void display_Stack(){
    //error catching
    if(isEmpty()){
        std::cout<<"The stack is empty. \n"<<std::endl;
        return;
    }
    std::cout<<"Stack: "<< std::endl;
    for(int i = top; i>= 0; i--){
        std::cout<<stackArr[i]<<" ";
    }
    std::cout<<std::endl;
}

