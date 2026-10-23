#include <iostream>
#include "queueLL.h"


int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    // Testing enqueue 
    enqueue('S', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('A', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('M', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;

    // Testing dequeue
    dequeue(&front, &back);
     std::cout << front->data << " " << back->data << std::endl;

     // deq
    dequeue(&front, &back);
    dequeue(&front, &back);
    dequeue(&front, &back);

    //enqueue
    enqueue('S', &front, &back);
    enqueue('A', &front, &back);
    enqueue('M', &front, &back);

    // Testing qFront
    qFront(&front, &back);

    // Testing qFront
    qBack(&front, &back);

    // Testing displayAll
    displayAll(&front, &back);

    dequeue(&front, &back);
    dequeue(&front, &back);
    dequeue(&front, &back);

    // Testing if empty
    qFront(&front, &back);
    qBack(&front, &back);
    displayAll(&front, &back);



    return 0;
}