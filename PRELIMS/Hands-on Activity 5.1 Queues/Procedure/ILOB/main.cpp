#include <iostream>
#include "queue_ll.h"
int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout<<"Testing the enqueue operator: \n"<<std::endl;
    enqueue('S', &front, &back);
    std::cout<<"Front: "<<front->data << " "<<"Back: "<<back->data<<std::endl;
    enqueue('E', &front, &back);
    std::cout<<"Front: "<<front->data << " "<<"Back: "<<back->data<<std::endl;
    enqueue('T', &front, &back);
    std::cout<<"Front: "<<front->data << " "<<"Back: "<<back->data<<std::endl;
    enqueue('H', &front, &back);
    std::cout<<"Front: "<<front->data << " "<<"Back: "<<back->data<<std::endl;
    
    display_All(&front, &back);

    std::cout<<"Testing the dequeue operator: \n"<<std::endl;
    dequeue(&front, &back);
    std::cout<<"Front: "<<front->data << " "<<"Back: "<<back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<<"Front: "<<front->data << " "<<"Back: "<<back->data<<std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);
    dequeue(&front, &back);

    isEmpty(&front, &back);


    return 0;
}