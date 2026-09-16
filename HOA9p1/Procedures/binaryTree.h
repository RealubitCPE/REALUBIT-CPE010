#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template<typename T>
class BinaryTree{
    private:
        T key;
        //pointers:
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;
    public:

        //constructor:
        BinaryTree(T rootObj);

        // adding/inserting a child node:
        void insertLeftChild(T newNode);
        void insertRightChild(T newNode);
        
        //pointer
        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();
        
        T getRootVal();
        void setRootVal(T Obj);

        bool isleaf();
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
        //create a new node:
        BinaryTree<T> *newChild = new BinaryTree<T> (newNode);

        //move the existing left child below the new Node
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
        //create a new node:
        BinaryTree<T> *newChild = new BinaryTree<T> (newNode);

        //move the existing left child below the new Node
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
#endif //BINARY_TREE_H