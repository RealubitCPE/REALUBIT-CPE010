#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>
#include <functional>
#include "sortingAlgo-2.h"

const int maxSize = 100;

void displayArray(int arr[]);

int main(){
    int unsortedArr[maxSize];
    int prob2[15] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    srand(time(0));

    for(int i=0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }

    std::cout<<"Unsorted Array: \n"<< std::endl;
    displayArray(unsortedArr);
    std::cout << std::endl;

    int testCopy[maxSize];

    std::copy(unsortedArr, unsortedArr + maxSize, testCopy);

    std::cout<<"Problem 1: "<<std::endl;
    int pi = partition(testCopy, 0, maxSize - 1);
    std::cout<<"Pivot placed on index: "<< pi <<std::endl;
    
    insertionSortRange(testCopy, 0, pi - 1);
    insertionSortRange(testCopy, pi + 1, maxSize -1);

    std::cout<<std::endl;
    displayArray(testCopy);

    std::cout<<"\nProblem 2: "<<std::endl;

    std::vector<std::pair<std::string, std::function<void(int[], int)>>> algorithms = {
        {"Shell Sort", [](int arr[], int size){ shellSort(arr, size); }},
        {"Merge Sort", [](int arr[], int size){ mergeSort(arr, 0, size - 1); }},
        {"Quick Sort", [](int arr[], int size){ quickSort(arr, 0, size - 1); }}
    };  

    for (const auto& [name, sortFunction]: algorithms){
        int copy[15];
        std::copy(prob2, prob2 + 15, copy);

        auto start = std::chrono::high_resolution_clock::now();
        sortFunction(copy, 15);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout << name << ": " << duration.count() << " ns" << std::endl;
    }
    
    return 0;
}

void displayArray(int arr[]){
    for (int i = 0; i < maxSize; i++) {
    std::cout << arr[i] << " ";
}
    std::cout << std::endl;
}
