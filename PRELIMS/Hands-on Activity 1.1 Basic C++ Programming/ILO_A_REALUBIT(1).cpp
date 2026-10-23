#include <iostream>

void sumOfTwoNum(int fNum, int sNum); // Sum of two numbers
bool compareTwoNum(int fNum, int sNum); // Compare two numbers
bool logicgateOfTwoNum(bool fNum, bool sNum); // Logic gate of two numbers

int main() {
    
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    sumOfTwoNum(a, b);

    bool isGreater = compareTwoNum(a, b);
    if (isGreater) {
        std::cout << "The first number is greater than the second number." << std::endl;
    } else {
        std::cout << "The first number is not greater than the second number." << std::endl;
    }

    bool result = logicgateOfTwoNum(a > 0, b > 0);
    
    return 0;
}

void sumOfTwoNum(int fNum, int sNum) {
    int sum = fNum + sNum;
    std::cout << "The sum of two numbers is: " << sum << std::endl;
}

bool compareTwoNum(int fNum, int sNum) {
    return fNum > sNum;
}

bool logicgateOfTwoNum(bool fNum, bool sNum) {
    std::cout << std::boolalpha;
    std::cout << "The result of AND gate is: " << (fNum && sNum) << std::endl;
    std::cout << "The result of OR gate is: " << (fNum || sNum) << std::endl; 
    std::cout << "The result of NOT gate for first number is: " << (!fNum) << std::endl;
    std::cout << "The result of NOT gate for second number is: " << (!sNum) << std::endl; 
    return true;
}