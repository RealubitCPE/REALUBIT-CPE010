#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){
    // create list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;
    
    //traversal
    std::cout<<"Testing the DLL Traversal: "<< std::endl;
    dllTraverse(head);
    
    //testing the insert at the head
    std::cout<<"Testing the insertion at the head node: "<<std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //testing the insert at the end
    std::cout<<"Testing the insertion at the end: "<<std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    //testing the general insert 
    std::cout<<"Testing the general insert: "<<std::endl;
    dllGeneralInsert('F', head->next->next);
    dllTraverse(head);

    //testing the delete node
    std::cout<<"Testing dll Delete Node: "<<std::endl;
    dllDeleteNode('X', &head); 
    dllTraverse(head);
    dllDeleteNode('0', &head);
    dllTraverse(head);
    dllDeleteNode('F', &head);
    dllTraverse(head);
}
   