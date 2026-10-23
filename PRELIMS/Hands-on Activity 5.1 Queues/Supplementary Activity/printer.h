#ifndef PRINTER_H
#define PRINTER_H
#include "queue_ll.h"
#include <string>
#include <iostream>

class Job{
    public:
        int jobId;
        std::string name;
        int numPages;

        Job(int id, std::string n, int pages): jobId(id), name(n), numPages(pages) {}
};

class Printer{
    private:
        qNode<Job>* frontPtr;
        qNode<Job>* backPtr;
    public:
        Printer(): frontPtr(nullptr), backPtr(nullptr) {}
        ~Printer();
        void addJob(Job newjob);
        void processAll();
        void displayQueue();
        bool isEmpty();
};

inline bool Printer::isEmpty(){
    return (frontPtr == nullptr && backPtr == nullptr);
}

inline void Printer::addJob(Job newjob){
    enqueue(newjob, &frontPtr, &backPtr);
}

inline void Printer::processAll(){
    while(!isEmpty()){
        Job currentJob = frontPtr->data;
        std::cout << "Job ID: " << currentJob.jobId << ", Name: " << currentJob.name << ", Pages: " << currentJob.numPages << std::endl;
        dequeue(&frontPtr, &backPtr);
    }
}

inline void Printer::displayQueue(){
    qNode<Job>* current = frontPtr;
    while(current != nullptr){
        Job currentJob = current->data;
        std::cout << "Job ID: " << currentJob.jobId << ", Name: " << currentJob.name << ", Pages: " << currentJob.numPages << std::endl;
        current = current->next;
    }
}

Printer::~Printer(){
    while(!isEmpty()){
        dequeue(&frontPtr, &backPtr);
    }
}

#endif // PRINTER_H