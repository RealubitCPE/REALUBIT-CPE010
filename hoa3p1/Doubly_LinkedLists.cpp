#include <iostream>
#include "doubly_ll.h"
int main(){

    // creation of nodes "SETH"

    // creating a node stored in the stack
    DoubleList<char>* head = nullptr;
    DoubleList<char>* second = nullptr;
    DoubleList<char>* third = nullptr;
    DoubleList<char>* fourth = nullptr;

    //allocate memory in the heap
    head = new DoubleList<char>();
    second = new DoubleList<char>();
    third = new DoubleList<char>();
    fourth = new DoubleList<char>();

    //Storing a value inside the node
    head->data = 'S';
    second->data = 'E';
    third->data = 'T';
    fourth->data = 'H';

    //Linking the nodes forward AND backward
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = nullptr;
    head->prev = nullptr;

    std::cout << "Testing of forward Traversal: \n";
    ListTraversal(head);

    std::cout << "Testing of reverse Traversal (starting from fourth): \n";
    ListTraversalReverse(fourth);

    std::cout << "Testing of dll_insert_head: \n";
    dll_insert_head('Q', &head);
    ListTraversal(head);

    std::cout << "Testing of dll_general_insert: \n";
    dll_general_insert('X', head->next->next);
    ListTraversal(head);

    std::cout << "Testing of dll_insert_end: \n";
    dll_insert_end('U', &head);
    ListTraversal(head);

    std::cout << "Confirming prev arrows are correct after inserts (reverse traversal): \n";
    // walk forward to find the current last node, then traverse backward from it
    DoubleList<char>* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    ListTraversalReverse(tail);

    std::cout << "Testing of deleting the node: \n";
    dll_Delete_Node('U', &head);
    ListTraversal(head);
    dll_Delete_Node('Q', &head);
    ListTraversal(head);
    dll_Delete_Node('X', &head);
    ListTraversal(head);

    std::cout << "Testing deletion of data that does not exist (should not crash): \n";
    dll_Delete_Node('Z', &head);
    ListTraversal(head);

    std::cout << "Deleting all nodes: \n";
    dll_Deleting_List(&head);
    ListTraversal(head);

    return 0;

}
