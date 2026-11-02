#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArray(int arr[]);   

int main(){
    
    //create an array with unsorted list with 100 maximum size
    int unsortedArr[maxSize];
    // use time (0) as seed for random values
    srand(time(0));
    //populate the array with random values
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()% 100; // random values between 0 and 99
    }
    //display the randomly displayed array
    std::cout << "Unsorted Array: \n" << std::endl;
    displayArray(unsortedArr);

    // std::cout << "\nBubble Sort: \n" << std::endl;
    // bubbleSort(unsortedArr, maxSize);
    // displayArray(unsortedArr);

    // std::cout << "\nSelection Sort: \n" << std::endl;
    // selectionSort(unsortedArr, maxSize);
    // displayArray(unsortedArr);

    std::cout << "\nInsertion Sort: \n" << std::endl;
    insertionSort(unsortedArr, maxSize);
    displayArray(unsortedArr);
}

void displayArray(int arr[]) {
    
    for (int i = 0; i < maxSize; i++) {
    std::cout << arr[i] << " ";
}
    std::cout << std::endl;
}