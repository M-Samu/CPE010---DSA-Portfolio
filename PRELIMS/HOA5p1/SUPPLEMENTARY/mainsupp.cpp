#include <iostream>
#include "suppqueueLL.h"

// 1. Class Job
class Job{
    public:
        int identification;
        std::string employee;
        int toPrint;

   
    Job(int ID=0, std::string name= "", int pages=0){
        identification = ID;
        employee = name;
        toPrint = pages;
    }
};

// 2. Class Printer
class Printer{
    private:
        qNode<Job>* front;
        qNode<Job>* back;   

    public:
        Printer(){
            front = nullptr;
            back = nullptr;
        }
    
    void addJob(Job newJob){
        enqueue(newJob, &front, &back);
        
        std::cout << "Job added to the queue!" << std::endl;
        std::cout << "Job ID: " << newJob.identification << std::endl;
        std::cout << "Employee: " << newJob.employee << std::endl;  
        std::cout << "Page/s: " << newJob.toPrint << std::endl; 
        std::cout << "\n";
    }   
    
    void printJob(){
        if (front == nullptr){
            std::cout << "Nothing to print." << std::endl;
            return;
        }
        std::cout << "======================" << std::endl;
        std::cout << "Printing Job ID: " << front->data.identification << std::endl;

        dequeue(&front, &back);

        std::cout << "Printing Complete!" << std::endl;
        std::cout << "======================" << std::endl;
        std::cout << "\n";          
    }

    void displayQueue(){
        if (front == nullptr){
            std::cout << "The queue is empty." << std::endl;
            return;
        }

        qNode<Job>* temp = front;
        std::cout << "======================" << std::endl;
        std::cout << "Current Queue: " << std::endl;
        std::cout << "======================" << std::endl;
        while (temp != nullptr){
            std::cout << "Job ID: " << temp->data.identification << std::endl;
            std::cout << "Employee: " << temp->data.employee << std::endl;  
            std::cout << "Page/s: " << temp->data.toPrint << std::endl; 
            std::cout << "------------------------" << std::endl;   
            temp = temp->next;
        }
        std::cout << "\n\n";
    }

    void displayFront(){
        if (front == nullptr){
            std::cout << "Nothing to print." << std::endl;
            return;
        }
        std::cout << "======================" << std::endl;
        std::cout << "Front of the queue: " << std::endl;
        std::cout << "======================" << std::endl;
        std::cout << "Job ID: " << front->data.identification << std::endl;
        std::cout << "Employee: " << front->data.employee << std::endl;
        std::cout << "Page/s: " << front->data.toPrint << std::endl;
        std::cout << "\n\n";
    }   

    void displayBack(){
        if (front == nullptr){
            std::cout << "Nothing to print." << std::endl;
            return;
        }
        
        std::cout << "======================" << std::endl;
        std::cout << "Back of the queue: " << std::endl;
        std::cout << "======================" << std::endl;
        std::cout << "Job ID: " << back->data.identification << std::endl;\
        std::cout << "Employee: " << back->data.employee << std::endl;  
        std::cout << "Page/s: " << back->data.toPrint << std::endl;
        std::cout << "\n\n";  
    }
        
        
};


int main(){
    Printer p;

    // Scenario:
    p.addJob(Job(101, "Alice", 10));
    p.addJob(Job(102, "Bob", 5));          
    p.addJob(Job(103, "Charlie", 15));  
    
    // The users wants to see who is first or what their current queue is
    p.displayFront();
    p.displayQueue();
   

    p.printJob();   
    p.printJob();
    p.printJob();

    // testing the empty queue function after all jobs were printed
    p.printJob();
    


    return 0;
}