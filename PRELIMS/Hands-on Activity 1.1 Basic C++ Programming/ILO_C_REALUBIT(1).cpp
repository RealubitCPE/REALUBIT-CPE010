#include <iostream>
#include <cmath>

void swapVariables(int &a, int &b); // Swapping two numbers
void KelvintoFahrenheit(double kelvin); // Converting Kelvin to Fahrenheit
void DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2); // Calculating distance between two points

int main(){
    int a = 5;
    int b = 10;
    std::cout<< "Before swap: a = " << a << ", b = " << b << std::endl;
    swapVariables(a, b);
    std::cout<< "After swap: a = " << a << ", b = " << b << std::endl;

    double kelvin;
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;
    KelvintoFahrenheit(kelvin);

    double x1, y1, x2, y2;
    std::cout << "Enter coordinates of first point (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of second point (x2 y2): ";
    std::cin >> x2 >> y2;
    DistanceBetweenTwoPoints(x1, y1, x2, y2);

    return 0;
}

void swapVariables(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void KelvintoFahrenheit(double kelvin) {
    double fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    std::cout << kelvin << " Kelvin is equal to " << fahrenheit << " Fahrenheit." << std::endl;
}

void DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2) {
    double distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    std::cout << "The distance between the points (" << x1 << ", " << y1 << ") and ("<< x2 << ", " << y2 << ") is: " << distance << std::endl;
}