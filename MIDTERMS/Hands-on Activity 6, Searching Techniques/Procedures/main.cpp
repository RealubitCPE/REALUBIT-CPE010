#include <iostream>
#include <cstdlib> // for generating random integers
#include <time.h> //will be used for our seeding function
#include "searchingAlgo.h"
#include "node.h"
const int max_size = 50;

int main(){

    // int dataset[max_size];
    // srand(time(0));
    // for(int i = 0; i <max_size; i++){
    //     dataset[i] = rand();
    //    std::cout<<dataset[i] << " ";
    // }
    // std::cout<<std::endl;

    // std::cout<<"What number to find: ";
    // int choice;
    // std::cin >> choice; 

    //linearSearchAR(max_size, choice, dataset);

    // //Creating a node for your name
    // Node<char> *char1 = new_node('J');
    // Node<char> *char2 = new_node('I');
    // Node<char> *char3 = new_node('M');
    // Node<char> *char4 = new_node('L');
    // Node<char> *char5 = new_node('O');
    // Node<char> *char6 = new_node('R');
    // Node<char> *char7 = new_node('D');

    // //Connect the nodes
    // char1->next = char2;
    // char2->next = char3;
    // char3->next = char4;
    // char4->next = char5;
    // char5->next = char6;
    // char6->next = char7;

    // linearSearchLL(char1, 'D');

    // int newArr[10] = {1,2,3,4,5,6,7,8,9,10};

    // //generate a sorted array: (use for loop)
    // for (int i = 0; i < max_size; i++ ){
    //     newArr[i] = i;
    // }

    // binarySearchArr(newArr, max_size, 100);

    Node<int> *char1 = new_node(10);
    Node<int> *char2 = new_node(11);
    Node<int> *char3 = new_node(12);
    Node<int> *char4 = new_node(13);
    Node<int> *char5 = new_node(14);
    Node<int> *char6 = new_node(15);
    Node<int> *char7 = new_node(16);

    //Connect the nodes
    char1->next = char2;
    char2->next = char3;
    char3->next = char4;
    char4->next = char5;
    char5->next = char6;
    char6->next = char7;

    binarySearchLL(char1, 18);
}