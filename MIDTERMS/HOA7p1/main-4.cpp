#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "sortingAlgo-1.h"

const int maxSize = 100;

void displayArray(int arr[]);

int main(){ 

    int tallies[6] = {0}; // Array to store tallies for values 1-5

    std::string candidates[6] = {
        "",
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    int unsortedArr[maxSize];
    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = (rand()% 5)+1; 
    }

    std::cout << "Unsorted Array: \n" << std::endl;
    displayArray(unsortedArr);


    int insertionArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        insertionArr[i] = unsortedArr[i];
    }
    std::cout << "\nInsertion Sort: \n" << std::endl;
    insertionSort(unsortedArr, maxSize);
    displayArray(unsortedArr);

    int bubbleArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        bubbleArr[i] = unsortedArr[i];
    }
    std::cout << "\nBubble Sort: \n" << std::endl;
    bubbleSort(unsortedArr, maxSize);
    displayArray(unsortedArr);

    int selectionArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        selectionArr[i] = unsortedArr[i];
    }
    std::cout << "\nSelection Sort: \n" << std::endl;
    selectionSort(unsortedArr, maxSize);
    displayArray(unsortedArr);

   for (int i = 0; i < maxSize; i++) {
        tallies[unsortedArr[i]]++; // Increment the tally for the corresponding value
    }

    std::cout << "\nTallies: \n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Candidate: " << candidates[i] << ": " << tallies[i] << std::endl;
    }

    int Winner = 0;
    int maxTally = 0;
    for (int i = 1; i <= 5; i++) { 
        if (tallies[i] > maxTally) {
            maxTally = tallies[i];
            Winner = i;
        }
    }

    std::cout << "Winner: " << candidates[Winner] << std::endl;

}

void displayArray(int arr[]) {
    
    for (int i = 0; i < maxSize; i++) {
    std::cout << arr[i] << " ";
}
    std::cout << std::endl;
}