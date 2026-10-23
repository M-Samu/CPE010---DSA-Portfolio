#include <iostream>
#include <queue>

void display (std::queue<char> copyQ);


int main(){
    // create an object
    std::queue<char> myQ;

    myQ.push('S');
    myQ.push('A');
    myQ.push('M');
    myQ.push('U');
    myQ.push('E');
    myQ.push('L');
    display(myQ);

    // try all member functions
    // empty
    if (myQ.empty()){
        std::cout << "The queue is empty." << std::endl;
        std::cout << std::endl;
    }
    else{
        std::cout << "The queue is not empty." << std::endl;
        std::cout << std::endl;
    }
    // size
    std::cout << "The length of the queue is: " << myQ.size() << std:: endl;
    std::cout << std::endl;
    // front
    std::cout << "The front of the queue is: " << myQ.front() << std::endl;
    std::cout << std::endl;
    // back
    std::cout << "The back of the queue is: " << myQ.back() << std::endl;
    std::cout << std::endl;
    // pop
    std::cout << "Popping..." << std::endl;
    std::cout << std::endl;
    myQ.pop();
    // display
    display(myQ);
    // push
    std::cout << "Pushing..." << std::endl;
    std::cout << std::endl;
    myQ.push('R');
    // display
    display(myQ);


    return 0;
}

void display (std::queue<char> copyQ){
    // creates a copy of the queue that was passed
    std::queue<char> c = copyQ;
    std::cout << "Displaying the queue: " << std::endl;

    while (!c.empty()){
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}