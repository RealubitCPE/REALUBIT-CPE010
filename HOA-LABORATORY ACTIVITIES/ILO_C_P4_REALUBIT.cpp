#include <iostream>
#include <cmath>

class Triangle {
private: 
    double sideA, sideB, sideC;
    double totalAngle, angleA, angleB, angleC;
public:
    Triangle(double A, double B, double C, double sideA, double sideB, double sideC);
    void setSides(double sA, double sB, double sC);
    void setAngles(double A, double B, double C);
    void getArea();
    void getPerimeter();
    void getTriangleType();
    const bool validateTriangle();
};

int main(){
    //driver code
    Triangle set1(40,30,100,50,60,70);
    if(set1.validateTriangle()){
        std::cout<<"The shape is a valid triangle.\n";
    } else {
        std::cout<<"The shape is not a valid triangle.\n";
    }

    set1.setSides(50, 60, 70);
    if(set1.validateTriangle()){
        std::cout<<"The shape is a valid triangle.\n";
    } else {
        std::cout<<"The shape is not a valid triangle.\n";
    }

    set1.getArea();
    set1.getPerimeter();
    set1.getTriangleType();
}

Triangle::Triangle(double A, double B, double C, double sA, double sB, double sC){
    sideA = sA;
    sideB = sB;
    sideC = sC;
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;
}

void Triangle::setSides(double sA, double sB, double sC){
    sideA = sA;
    sideB = sB;
    sideC = sC;
    totalAngle = angleA + angleB + angleC;
}

const bool Triangle::validateTriangle(){
    return (totalAngle == 180);
}

void Triangle::getArea() {
    double s = (sideA + sideB + sideC) / 2;
    double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    std::cout << "The area of the triangle is: " << area << std::endl;
}

void Triangle::getPerimeter() {
    double perimeter = sideA + sideB + sideC;
    std::cout << "The perimeter of the triangle is: " << perimeter << std::endl;
}

void Triangle::getTriangleType() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        std::cout << "The triangle is acute." << std::endl;
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        std::cout << "The triangle is obtuse." << std::endl;
    } else {
        std::cout << "Others." << std::endl;
    }
}

