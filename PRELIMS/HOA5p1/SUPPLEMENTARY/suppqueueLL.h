#ifndef QUEUELL_H
#define QUEUELL_H


// create a class the node
template <typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

// creates the new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    // create the new node
    qNode<T>* newNode = new_node(newData);
    
    // inserting into an empty queue
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    //inserting an item into a non empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
    
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    // if the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty, nothing to dequeue." << std::endl;
        return;
    }

    // create a temporary node
    qNode<T>* deleteNode = nullptr;
    deleteNode = *frontPtr;

    // check if the queue has only 1 node
    if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    // delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

 // check the front
template <typename T>
void qFront(qNode<T>** frontPtr, qNode<T>** backPtr){
    // If queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty, nothing to display." << std::endl;
        return;
    }

    std::cout << (*frontPtr)->data << std::endl;
    return;
}

// check the back
template <typename T>
void qBack(qNode<T>** frontPtr, qNode<T>** backPtr){
    // If queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty, nothing to display." << std::endl;
        return;
    }

    std::cout << (*backPtr)->data << std::endl;
    return;
}


 // display all
template <typename T>
void displayAll(qNode<T>** frontPtr, qNode<T>** backPtr){

    qNode<T>* temp = *frontPtr;

    // If queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty, nothing to display." << std::endl;
        return;
    }
    do{
        std::cout << (*frontPtr)->data << " ";
        (*frontPtr) = (*frontPtr)->next;
    } while ((*frontPtr) != nullptr);
    *frontPtr = temp;
    std::cout << std::endl;
    return;
}
#endif