#ifndef GENTREE_H
#define GENTREE_H

#include <iostream> 

template<typename T>
class Node{
    public:

        T data;
        Node<T>* firstChild;
        Node<T>* nextSibling;
        Node(T value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
        Node<T>* AddChild(T childValue);
        void preOrder();
        void inOrder();
        void postOrder();

        Node<T>* SearchPreOrder(T key);
        Node<T>* SearchInOrder(T key);
        Node<T>* SearchPostOrder(T key);
        void FindData(std::string choice, T key);
        void AddNodeO();

};

template<typename T>
Node<T>* Node<T>::AddChild(T childValue){

    Node<T>* newNode = new Node<T>(childValue);

    if (this->firstChild == nullptr){
        this->firstChild = newNode;

    }else{
        Node<T>* temp = this->firstChild;
        while (temp->nextSibling != nullptr){
            temp = temp->nextSibling;
        }
        temp->nextSibling = newNode;
    }
    return newNode;
}

template<typename T>
void Node<T>::preOrder(){
    
    std::cout << data << " ";
    
    if(firstChild != nullptr){
        firstChild->preOrder();
    }
    
    if(nextSibling != nullptr){
        nextSibling->preOrder();
    }
}

template<typename T>
void Node<T>::inOrder(){
   
    if(firstChild != nullptr){
        firstChild->inOrder();
    }
    
    std::cout << data << " ";

    if(nextSibling != nullptr){
        nextSibling->inOrder();
    }
}

template<typename T>
void Node<T>::postOrder(){

    Node<T>* child = firstChild;

    while (child != nullptr){
        child->postOrder();
        child = child->nextSibling;
    }

    std::cout << data << " ";
}

template<typename T>
Node<T>* Node<T>::SearchPreOrder(T key){

    if (this->data == key) {
        return this;
    }
    
    Node<T>* child = this->firstChild;
    
    while (child != nullptr) {
        
        Node<T>* result = child->SearchPreOrder(key);
        
        if (result != nullptr) {
            return result;
        }
        
        child = child->nextSibling;
    }
    
    return nullptr;
}

template<typename T>
Node<T>* Node<T>::SearchInOrder(T key) {
   
    Node<T>* child = this->firstChild;

    if (child != nullptr) {
      
        Node<T>* result = child->SearchInOrder(key);
        if (result != nullptr) {
            return result;
        }

        if (this->data == key) {
            return this;
        }

        child = child->nextSibling;
        
        while (child != nullptr) {
            result = child->SearchInOrder(key);
            if (result != nullptr) {
                return result;
            }
            child = child->nextSibling;
        }
    }else {
        
        if (this->data == key) {
            return this;
        }
    }

    return nullptr;
}

template<typename T>
Node<T>* Node<T>::SearchPostOrder(T key) {

    Node<T>* child = this->firstChild;
    
    while (child != nullptr) {

        Node<T>* result = child->SearchPostOrder(key);
        
        if (result != nullptr) {
            return result;
        }
        
        child = child->nextSibling;
    }
    
    if (this->data == key) {
        return this;
    }
    
    return nullptr;
}

template<typename T>
void Node<T>::FindData(std::string choice, T key) {

    Node<T>* result = nullptr;

    if (choice == "PreOrder") {
        result = this->SearchPreOrder(key);

    } else if (choice == "PostOrder") {
        result = this->SearchPostOrder(key);

    } else if (choice == "InOrder") {
        result = this->SearchInOrder(key);
    }

    if (result != nullptr) {
        std::cout << key << " was found!" << std::endl;
    }
}


template<typename T>
void Node<T>::AddNodeO() {

    Node<T>* G = this->SearchPreOrder('G');
    
    if (G != nullptr) {
        G->AddChild('O');
    }
}

#endif //GENTREE_H
