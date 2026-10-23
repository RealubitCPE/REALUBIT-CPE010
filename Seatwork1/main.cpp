#include <iostream>
using namespace std;

int main(){

    int quiz_1, quiz_2, quiz_3;
    int total, avg;

    cout <<"Input score for quiz 1: ";
    cin >> quiz_1;

    cout << "Input score for quiz 2: ";
    cin >> quiz_2;

    cout << "Input score for quiz 2: ";
    cin >> quiz_3;

    total = quiz_1 + quiz_2 + quiz_3;

    avg = total/3;

    cout << "Total: " << total << endl;
    cout << "Avg: " << avg << endl; 

    return 0;
}