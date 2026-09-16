#include <iostream>
#include "binaryTree.h"



main(){


    //creating the root node:
    BinaryTree<char>* root = new BinaryTree<char>('A');


    //creating a child of root node A:
    root->insertLeftChild('B');
    root->insertRightChild('C');

    //insert a child to node B;
    root->getLeftChild()->insertLeftChild('D');
    root->getRightChild()->insertRightChild('F');

    //insert a child to node C:
    root->getLeftChild()->insertRightChild('E');

    //print the root node:

    std::cout<<"Root: "<< root->getRootVal()<<std::endl;

    // children of the root node
    std::cout<<"root Left Child: "<< root->getLeftChild()->getRootVal()<<std::endl;
    std::cout<<"root Right Child: "<< root->getRightChild()->getRootVal()<<std::endl;

    //children of the sub trees B and C
    std::cout<<"node B left child: "<<root->getLeftChild()->getLeftChild()->getRootVal()<<std::endl;
    std::cout<<"node B right child: "<<root->getLeftChild()->getRightChild()->getRootVal()<<std::endl;

    root->getLeftChild()->getRightChild()->setRootVal('E');
    std::cout<<"node B right child: "<<root->getLeftChild()->getRightChild()->getRootVal()<<std::endl;


    return 0;
}
