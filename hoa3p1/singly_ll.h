#ifndef SINGLY_LL_H
#define SINGLY_LL_H

// node creation
template <typename T>
class SingleList{
    public: 
        T data;
        SingleList<T>* next = nullptr;
};

template <typename T>
void ListTraversal(SingleList<T>* head){
    if(head == nullptr){
        std::cout<<"The list is empty.";
        return; 
    }
    while (head != nullptr){
        // PRINT data of N
        std::cout << head->data;

        if(head->next != nullptr){
            std::cout << " -> ";
        }

        // Go to the next node
        head = head->next;
    }
    
    std::cout << std::endl;

}

template <typename T>
void sll_insert_head(T newData, SingleList<T>** currentHead){
    //1. Allocate memory for the new node
    SingleList<T>* newNode = new SingleList<T>;

    //2. Put our data into the new node
    newNode->data = newData;

    //3. Set the next of the new node to point to the previous head
    newNode->next = *currentHead;

    //4. Reset head to point to the new node
    *currentHead = newNode;

}

template <typename T>
//1. Check if it is the head node(previous node is null)
void sll_general_insert(T newData, SingleList<T>* prevNode){
    // 2. If null, print "Previous node cannot be nullptr" and return
    if(prevNode == nullptr){
        std::cout <<"Previous node cannot be nullptr" << std::endl;
        return;
    }
    // 3. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
   // 4. Store data in the new node
   newNode->data = newData;
   //5. Point to the new node to the node previous node was pointing to
   newNode->next = prevNode->next;
    //6. Point previous node to the new node
    prevNode-> next = newNode;
}

template <typename T>
void sll_insert_end(T newData, SingleList<T>** head){
    //1. Allocate new node
    SingleList<T>* newNode = new SingleList<T>;
    //2. Dereference to the head node
    SingleList<T>* currentNode = *head;
    //3. Store data in new node
    newNode->data = newData;
    //4. Point to null
    newNode-> next = nullptr;
    //5. Traverse the list until pointed to null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    //6. Point the next of the current node to the new node
    currentNode->next = newNode;
}

template <typename T>
void sll_Delete_Node(T findData, SingleList<T>** head ){
    //if there is nothing to delete
    if(*head == nullptr) return;

    // 
    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    // Searching the node: 1. the node does not exist + we found the data
    while(currNode != nullptr && currNode->data != findData){
        prevNode =currNode;
        currNode = prevNode->next;
    }
    //if data not found currNode == nullptr in the while loop:
    if(currNode == nullptr){
        std::cout<<"The data is not found \n"<<std::endl;
    }
    //if data was found
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    delete currNode;
}

template <typename T>
void sll_Deleting_List(SingleList<T> **head){
    SingleList<T>* current = *head;

    while(current != nullptr){

        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}
#endif