#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream> // Added: Required for std::cout and std::endl

template<typename T>
class BinaryTree{
    private:
        T key;
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;
    public:
        BinaryTree(T rootObj);

        void insertLeftChild(T newNode);
        void insertRightChild(T newNode);
        
        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();
        
        T getRootVal();
        void setRootVal(T Obj);

        bool isleaf();
        void checkLeaf();
};

template <typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
}

template <typename T>
void BinaryTree<T>::insertLeftChild(T newNode){
    if(leftChild == nullptr){
        leftChild = new BinaryTree<T>(newNode);
    }
    else{
        BinaryTree<T> *newChild = new BinaryTree<T> (newNode);
        newChild->leftChild = leftChild;
        leftChild = newChild; 
    } 
}

template <typename T>
void BinaryTree<T>::insertRightChild(T newNode){
    if(rightChild == nullptr){
        rightChild = new BinaryTree<T>(newNode);
    }
    else{
        BinaryTree<T> *newChild = new BinaryTree<T> (newNode);
        newChild->rightChild = rightChild;
        rightChild = newChild; 
    }
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild(){
    return leftChild;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild(){
    return rightChild;
}

template<typename T>
T BinaryTree<T>::getRootVal(){
    return key;
}

template<typename T>
void BinaryTree<T>::setRootVal(T obj){
    key = obj;
}

template<typename T>
bool BinaryTree<T>::isleaf(){
    return leftChild == nullptr && rightChild == nullptr;
}

template<typename T>
void BinaryTree<T>::checkLeaf() {
    std::cout << "Node " << key << " | Is Leaf? " << isleaf() << std::endl;

    if (leftChild != nullptr) {
        leftChild->checkLeaf();
    }

    if (rightChild != nullptr) {
        rightChild->checkLeaf();
    }
}
    
#endif //BINARY_TREE_H
