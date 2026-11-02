#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArray(int arr[]);

int main(){
    int unsortedArr[maxSize];

    srand(time(0));

    for(int i=0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }

    std::cout<<"Unsorted Array: \n"<< std::endl;
    displayArray(unsortedArr);
    std::cout << std::endl;

    int shellSortCopy[maxSize];
    int mergeSortCopy[maxSize];
    int quickSortCopy[maxSize];

    std::copy(unsortedArr, unsortedArr + maxSize, shellSortCopy);
    std::copy(unsortedArr, unsortedArr + maxSize, mergeSortCopy);
    std::copy(unsortedArr, unsortedArr + maxSize, quickSortCopy);

    shellSort(shellSortCopy, maxSize);
    std::cout << "Shell Sort: \n" << std::endl;
    displayArray(shellSortCopy);

    
    mergeSort(mergeSortCopy, 0, maxSize - 1);
    std::cout << "\nMerge Sort: \n" << std::endl;
    displayArray(mergeSortCopy);


   
    quickSort(quickSortCopy, 0, maxSize - 1);
    std::cout << "\nQuick Sort: \n" << std::endl;
    displayArray(quickSortCopy);


    return 0;

}

void displayArray(int arr[]){
    for (int i = 0; i < maxSize; i++) {
    std::cout << arr[i] << " ";
}
    std::cout << std::endl;
}
