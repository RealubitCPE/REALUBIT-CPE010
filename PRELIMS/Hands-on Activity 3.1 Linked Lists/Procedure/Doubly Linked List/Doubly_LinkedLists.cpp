#include <iostream> 
#include "doubly_ll.h"

int main(){
    //create a list 'C P E's
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');


    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    //traversal
    std::cout<<"Testing the DLL Traversal"<<std::endl;
    dllTraverse(head);

    //testing the insert at the head
    std::cout<<"Testing the insertion at the head node"<<std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //testing the insertion at the end
    std::cout<<"Testing the insertion at the end"<<std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    std::cout<<"Testing of dllGenerealInsert:"<<std::endl;
    dllGeneralInsert('Z', head->next->next);
    dllTraverse(head);

    std::cout<<"Testing of dllDeleteNode"<<std::endl;
    dllDeleteNode('X', &head);
    dllTraverse(head);

    return 0;
}