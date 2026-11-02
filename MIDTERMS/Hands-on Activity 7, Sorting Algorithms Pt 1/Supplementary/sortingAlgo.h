#include <cstdlib>
#include <cstddef>
#include <iostream>
#ifndef SORTING_H
#define SORTING_H

template <typename T>
int bubbleSort(T arr[], size_t arrSize) {
    int passCount = 0;
    //step 1: for i = 0 to N-1 repeat inner loop
    for (int i = 0; i < arrSize; i++) {
        passCount = passCount + 1;
        //step 2: inner loop that for K = i+1 to N-1 repeat
        for (int j = i + 1; j < arrSize; j++) {
            //step 3: swap if the arr[j] is greater than arr[i]
            if (arr[i] > arr[j]) {
                //swap arr[j] and arr[i]
                std::swap(arr[i], arr[j]);
            }
        }
    }
    return passCount;
}

template <typename T>
//array, current position, size of array
int routineSmallest(T arr[], int K, const int arrSize) {
    int position, j;
    T smallestElement = arr[K];
    position = K; 
    
    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElement) {
            smallestElement = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
int selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass = 0;
    for (int i = 0; i < arrSize; i++) {
        POS = routineSmallest(arr, i, arrSize);
        //swapping 
        temp = arr[i];
        arr[i] = arr[POS];
        arr [POS] = temp;
        
        //for verification and counting the number of passes that was done
        pass++;
        }
    return pass;
}


template <typename T>
int insertionSort(T arr[], size_t arrSize) {
    int passCount = 0;
    for (size_t K = 1; K < arrSize; K++) {
        T temp = arr[K];
        int J = K - 1;
 
        while (J >= 0 && temp <= arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        passCount++;
    }
    return passCount;
}



#endif //SORTING_H