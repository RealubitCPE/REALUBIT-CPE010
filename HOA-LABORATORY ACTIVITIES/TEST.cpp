#include <iostream>

class Triangle{
    private: 
        double totalAngle, angleA, angleB, angleC;
    public: 
        //constructor
        Triangle(double A, double B, double C);
        //set a different 
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        int area((int base * int add)/2.0)
        return area

};

int main(){

    Triangle setl(40,50,110);
    if(setl.validateTriangle()){
        std::cout<<"the shape is a valid triangle \n";
    }
    else{
        std::cout<<"the shape is not a triangle. \n";
    }
   
    setl.setAngles(30,40,50);
    if(setl.validateTriangle()){
        std::cout<<"the shape is a valid triangle. \n";
    }else{
        std::cout<<"the shape is NOT a valid triangle. \n";
    }
    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
    return(totalAngle<=180);
}

