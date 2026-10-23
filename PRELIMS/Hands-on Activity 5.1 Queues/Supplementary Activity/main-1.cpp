#include <iostream>
#include "printer.h"

int main() {
    Printer printer;

    printer.addJob(Job(1, "Alice", 5));
    printer.addJob(Job(2, "Bob", 10));
    printer.addJob(Job(3, "Charlie", 15));

    std::cout << "Current Print Queue:" << std::endl;
    printer.displayQueue();
    std::cout << std::endl;
    std::cout << "Processing all jobs:" << std::endl;
    printer.processAll();
    std::cout << std::endl;
    std::cout<<"Finished Queue: "<<std::endl;
    printer.displayQueue();



    return 0;
}