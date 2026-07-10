#include <iostream>

int main (){

    int base, height;
    float area;
    

    std::cout<<"Base: ";
    std::cin>>base;

    std::cout<<"Height: ";
    std::cin>>height;

    area = (base * height)/2.0;
    std::cout<<"Area: "<< area;

    return 0;
}