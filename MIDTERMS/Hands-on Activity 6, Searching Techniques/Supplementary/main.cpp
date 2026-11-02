#include <iostream>
#include "nodes.h"
#include "searchCore.h"

template<typename T>
void insertAtEnd(Node<T> **head, T newData){
    Node<T> *newNode = new_node(newData);
    Node<T> *last = *head;

    if(*head == nullptr){
        *head = newNode;
        return;
    }

    while(last->next != nullptr){
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

int main(){
    const int size = 10;
    int Data[size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int searchKey = 18;

    std::cout << "Linear Search in Array:\n";
    linearSearchAR(size, searchKey, Data);

    std::cout << "\nLinear Search in Linked List:\n";
    Node<int> *head = nullptr;
    for (int i = 0; i < size; i++) {
        insertAtEnd(&head, Data[i]);
    }

    linearSearchLL(head, searchKey);

    Node<int> *current = head;
    while (current != nullptr) {
        Node<int> *nextNode = current->next;
        delete current;
        current = nextNode;
    }

    int result = -1;

    int Data2[size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int searchKey2 = 8;

    std::cout << "\nBinary Search in Array:\n";
    binarySearchArr(Data2, size, searchKey2);

    if (result != -1) {
        std::cout << "The data: " << searchKey2 << " was found at index: " << result << "\n";

    }
    
    int iterations = 0;

    std::cout <<"\nBinary Search Recursive in Array:\n";
    binarySearchRecursive(Data2, 0, size - 1, searchKey2, iterations);
    if (result != -1) {
        std::cout << "The data: " << searchKey2 << " was found at index: " << result << "\n";
    }
    
    return 0;
}