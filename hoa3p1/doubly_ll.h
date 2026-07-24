#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

// node creation
template <typename T>
class DoubleList{
    public: 
        T data;
        DoubleList<T>* next = nullptr;
        DoubleList<T>* prev = nullptr;   // new: lets us walk backward too
};

// forward traversal (identical logic to singly, just a different class type)
template <typename T>
void ListTraversal(DoubleList<T>* head){
    if(head == nullptr){
        std::cout << "The list is empty.";
        return; 
    }
    while (head != nullptr){
        std::cout << head->data;

        if(head->next != nullptr){
            std::cout << " <-> ";
        }

        head = head->next;
    }
    std::cout << std::endl;
}

// new: backward traversal, only possible because of prev
template <typename T>
void ListTraversalReverse(DoubleList<T>* tail){
    if(tail == nullptr){
        std::cout << "The list is empty.";
        return;
    }
    while(tail != nullptr){
        std::cout << tail->data;

        if(tail->prev != nullptr){
            std::cout << " <-> ";
        }

        tail = tail->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void dll_insert_head(T newData, DoubleList<T>** currentHead){
    //1. Allocate memory for the new node
    DoubleList<T>* newNode = new DoubleList<T>;

    //2. Put our data into the new node
    newNode->data = newData;

    //3. New node's next points to the old head; new node's prev points to nothing (it's now first)
    newNode->next = *currentHead;
    newNode->prev = nullptr;

    //4. If a head already existed, fix its prev to point back at newNode
    if(*currentHead != nullptr){
        (*currentHead)->prev = newNode;
    }

    //5. Reset head to point to the new node
    *currentHead = newNode;
}

// Only needs a single pointer, same reasoning as singly:
// we're rewiring existing real nodes, not reassigning main()'s head variable
// (unless prevNode is the tail — handled with the null check, as we discussed)
template <typename T>
void dll_general_insert(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout << "Previous node cannot be nullptr" << std::endl;
        return;
    }

    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;

    newNode->next = prevNode->next;   // 1
    newNode->prev = prevNode;         // 2

    if(prevNode->next != nullptr){    // guard: is there a node after prevNode?
        prevNode->next->prev = newNode;  // 4 — must happen BEFORE step 3
    }

    prevNode->next = newNode;         // 3
}

template <typename T>
void dll_insert_end(T newData, DoubleList<T>** head){
    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    // Handle empty list (this is the check singly's sll_insert_end was missing!)
    if(*head == nullptr){
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    DoubleList<T>* currentNode = *head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;   // new: link backward too
}

template <typename T>
void dll_Delete_Node(T findData, DoubleList<T>** head){
    if(*head == nullptr) return;

    DoubleList<T>* currNode = *head;

    // search — no need for a separate prevNode pointer anymore;
    // currNode->prev already gives us that, for free
    while(currNode != nullptr && currNode->data != findData){
        currNode = currNode->next;
    }

    if(currNode == nullptr){
        std::cout << "The data is not found \n" << std::endl;
        return;   // the fix for the missing return we found in the singly version!
    }

    // fix the node BEFORE currNode (if it exists)
    if(currNode->prev != nullptr){
        currNode->prev->next = currNode->next;
    } else {
        // currNode was the head — reassign main()'s head, hence needing **
        *head = currNode->next;
    }

    // fix the node AFTER currNode (if it exists)
    if(currNode->next != nullptr){
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}

template <typename T>
void dll_Deleting_List(DoubleList<T>** head){
    DoubleList<T>* current = *head;

    while(current != nullptr){
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}
#endif
