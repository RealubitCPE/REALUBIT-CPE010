#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template<typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    int i = 0;
    //while loop implementation
    while(i < size){
        if(dataFind == array[i]){
            std::cout<<"Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout<<"Searching is unsuccessful\n";

    //for loop implementation
    for(int j = 0; j < size; i++){ 
         if(dataFind = array[i]){
            std::cout<<"Searching is successful\n";
            return;
        }
    }
    std::cout<<"Searching is unsuccessful\n";

}

template<typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    //repeat the loop until the correct node is not NULL

    while(nodes != nullptr){
        
        //check if the item = current node data
        if(nodes->data == dataFind){
            std::cout<<"The data: "<< nodes->data<< " was Found successfully.\n";
            return;
        }
        // move on to the next node
        nodes = nodes->next;
    }
    //display unsuccessful
        std::cout<<"Searching is unsuccessful.\n";
}

template<typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = (int)((low + high)/2);
        if(dataFind == data[middle]){
            std::cout<<"The data was found\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }

    std::cout<<"The data was not found\n";
}

//middle function getter:
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    //continue until fast reaches the end or the last node of the current search rang

    while(fast != last && fast->next != last){
        //move slow one step
        slow = slow->next;
        //move fast two steps
        fast = fast->next->next;
    }
    return slow; // return middle
}

template<typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    //step 1: Set start to the head of the list and set last to null
    Node<T>* last = nullptr;

    // Middle element is calculated using the two pointers approach discussed above
    while(start != last){
        Node<T> *middle = getMiddle(start, last);

        //If the middle element is same as the key to be sorted, we return it
        if(middle->data == dataFind){
            std::cout<<"searching is Successfull\n";
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }

    std::cout<<"Searching is unsuccessful\n";
}
#endif