#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

//creating a node:
template <typename T>
DoubleList<T> *CreateNewNode(T newData){

    //dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;

    //store the data in the node
    newNode->data = newData;

    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // return the address of the newly created node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){

    // temp variable to store the last node visited
    DoubleList<T> *tail;

    //check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The List is empty"<<std::endl;
        return;
    }
    //move forward
    while(currentNode != nullptr){
        std::cout<< currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    //add a next line
    std::cout<<std::endl;
    //move backward
    std::cout<<"Backward \n";
    while(tail != nullptr){
        std::cout<< tail->data <<" ";
        tail = tail->prev;
    }
}

template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    //creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);
    
    //new node should point to the current head
    newNode->next = *currentHead;
    //current Head should point back to the newNode 
    (*currentHead)->prev = newNode;
    //update the pointer head
    *currentHead = newNode;
}

template<typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    //create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    //connect the last node to the new node 
    currentHead->next = newNode;

    //connect the new node back to the last node
    newNode->prev = currentHead;
}

template<typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Preious node cannot be nullptr" << std::endl;
        return;
    }

    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

template<typename T>
void dllDeleteNode(T newData, DoubleList<T>** head){
    
    if(*head == nullptr) return;

    DoubleList<T>* currNode = *head;
  
    while(currNode != nullptr && currNode->data != findData){
        currNode = currNode->next;
    }

    if(currNode == nullptr){
        std::cout<<"The data is not found \n"<<std::endl;
        return;
    }

    if(currNode == nullptr){
        currNode->prev->next = currNode->next;
    }else{
        *head = currNode->next;
    }

    if(currNode->next !=nullptr){
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}








#endif

