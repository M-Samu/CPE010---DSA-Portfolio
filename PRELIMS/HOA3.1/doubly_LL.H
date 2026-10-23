#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

// create a new node
template <typename T>
DoubleList<T>* createNode(T newData){
    // dynamically allocate memory for the new node
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Return the address of the 
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T> *currentNode){

    DoubleList<T>* tail;

    //checking if may empty list
    if(currentNode == nullptr){
        std::cout << "The list is empty.";
        return;
    }

    // forward traversal
    std::cout <<"Forward: " << std::endl;
    // moves toward the last node till it becomes nullptr
    while(currentNode != nullptr){
        // prints the data
        std::cout << currentNode->data;
        // save
        tail = currentNode;
        // move to the next node
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
    
    //backward traversing
    std::cout << "Backward: " << std::endl;
    // moves towards the head
    while (tail != nullptr){
        // printed the data
        std::cout << tail-> data<< " ";
        // move towards the previous node
        tail = tail->prev;
    }
    std::cout << "-------------" << std::endl << std::endl;
}

template <typename T>
void dllInsertHead (T newData, DoubleList<T>** currentHead){
    // createa node
    DoubleList<T>* newNode = createNode(newData);
    // new node should point to the current head
    newNode->next = *currentHead;
    
    // current head should point back to the new node
    (*currentHead)->prev = newNode;
    // update the header pointer
    *currentHead = newNode; 
}

template <typename T>
void dllInsertEnd (T newData, DoubleList<T>* currentHead){
    // create a new node
    DoubleList<T>* newNode = createNode(newData);
    // traverse to the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    // connect the last node to the new node
    currentHead->next = newNode;
    // connect the new node back to the last node
    newNode->prev = currentHead;
}

//insert at any node
template <typename T>
void dllGeneralInsert (T newData, DoubleList<T>* currentNode){
    // checking if node is null
    if(currentNode == nullptr){
        return;
    }

    DoubleList<T>* newNode = createNode(newData);

    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    
    if(currentNode->next != nullptr){
        currentNode->next = newNode;
    }
    currentNode->next = newNode;
}

// delete node
template <typename T>
void dllDeleteNode (T findData, DoubleList<T>** head){
    // check if there is no list to be deleted
    if (*head == nullptr){
        return;
    }

    DoubleList<T>* currNode = *head ;

    // searching loop
    while (currNode != nullptr && currNode -> data != findData){
        currNode = currNode->next;
    }

    // if data was not found
    if (currNode == nullptr){
        std::cout << "Data not found." << std::endl;
        return;
    }

    if (currNode == *head){
        *head = currNode->next;
        if (*head != nullptr){
            (*head)->prev = nullptr;
        }
    }
    
    else{
        currNode->prev->next = currNode->next;
        if (currNode->next != nullptr){
            currNode->next->prev = currNode->prev;
        }
    }
}
    
template <typename T>
void dllDeleteList(DoubleList<T>** head){
    DoubleList<T>* currentNode = *head;

    while (currentNode != nullptr){
        DoubleList<T>* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    *head = nullptr;
}

#endif 