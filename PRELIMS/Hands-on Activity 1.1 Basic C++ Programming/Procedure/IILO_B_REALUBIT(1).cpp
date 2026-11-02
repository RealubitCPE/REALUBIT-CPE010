#include <iostream>

class Triangle {
private: 
    double totalAngle, angleA, angleB, angleC;
public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
};
int main(){
    //driver code
    Triangle set1(40,30,100);
    if(set1.validateTriangle()){
        std::cout<<"The shape is a valid triangle.\n";
    } else {
        std::cout<<"The shape is not a valid triangle.\n";
    }

    set1.setAngles(60, 60, 60);
    if(set1.validateTriangle()){
        std::cout<<"The shape is a valid triangle.\n";
    } else {
        std::cout<<"The shape is not a valid triangle.\n";
    }
}
Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;
}
void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;
}
const bool Triangle::validateTriangle(){
    return (totalAngle == 180);
}
