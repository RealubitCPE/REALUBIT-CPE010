#include<iostream>
#include<stack>

int main(){
    
    std::stack<int> stack1;
    std::cout<<"Testing the stack STL."<<std::endl;
    
    //isEmpty

    std::cout<<"is the stack empty?"<<stack1.empty()<<std::endl;

    //push

    stack1.push(10);
    std::cout<< "The top of the stack is: "<<stack1.top()<<std::endl;
    stack1.push(9);
    std::cout<< "The top of the stack is: "<<stack1.top()<<std::endl;
    stack1.push(8);
    std::cout<< "The top of the stack is: "<<stack1.top()<<std::endl;
    stack1.push(7);
    std::cout<< "The top of the stack is: "<<stack1.top()<<std::endl;
    stack1.pop();
    std::cout<<"The top of the stack is: "<<stack1.top()<<std::endl;
    std::cout<<"is the stack empty?"<<stack1.empty()<<std::endl;
    std::cout<<"The size of the stack is: "<< stack1.size()<<std::endl;
    stack1.emplace(8);
    std::cout<<"The top of the stack is: "<<stack1.top()<<std::endl;
    stack1.emplace(7);
    std::cout<<"The top of the stack is: "<<stack1.top()<<std::endl;
    std::cout<<"The new size of the stack is: "<<stack1.size()<<std::endl;

    std::stack<int> stack2;
    std::cout<<"Stack 2"<< std::endl;

    stack2.emplace(1);
    std::cout<<"The top of stack 2: "<<stack2.top()<<std::endl;
    stack2.emplace(2);
    std::cout<<"The top of stack 2: "<<stack2.top()<<std::endl;
    stack2.emplace(3);
    std::cout<<"The top of stack 2: "<<stack2.top()<<std::endl;
    stack2.emplace(4);
    std::cout<<"The top of stack 2: "<<stack2.top()<<std::endl;

    std::cout<<"Before swapping: "<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    stack1.swap(stack2);

    std::cout<<"\nAfter Swapping."<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    std::cout<<"The top of stack 1: "<<stack1.top()<<std::endl;
    
}