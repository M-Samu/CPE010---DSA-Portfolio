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
    
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->prev = newNode;
    newNode->next = newNode;;

    
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T> *head){

    DoubleList<T>* currentNode = head;

    // checks if the list is empty
    if(currentNode == nullptr){
        std::cout << "The Playlist Is Empty.";
        return;
    }

    std::cout <<"Now Playing: " << std::endl << std::endl;
    // moves toward the last node till it comes back to the head
    do{
        std::cout << currentNode->data << std::endl;
        currentNode = currentNode->next;
    } while(currentNode != head);
    std::cout << "-----------"<< std::endl;
    
}

template <typename T>
void dllInsertHead (T newData, DoubleList<T>** currentHead){

    DoubleList<T>* newNode = createNode(newData);
    DoubleList<T>* tail = (*currentHead)->prev;

    newNode->next = *currentHead;
    newNode->prev = tail;
    
    (*currentHead)->prev = newNode;
    tail->next = newNode;
    *currentHead = newNode; 
}

template <typename T>
void dllInsertEnd (T newData, DoubleList<T>* currentHead){
    // create a new node
    DoubleList<T>* newNode = createNode(newData);

    // keeps the head of the list to connect the new node back to it
    DoubleList<T>* head = currentHead;  
    
    // goes to the last node
    currentHead = currentHead->prev;    

    // connect the last node to the new node
    currentHead->next = newNode;
    head->prev = newNode;
    newNode->next = head;   
    // connect the new node back to the last node
    newNode->prev = currentHead;
}

//insert at any node
template <typename T>
void dllGeneralInsert (T newData, DoubleList<T>* currentNode){
    // create a new node
    DoubleList<T>* newNode = createNode(newData);

    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    
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
    do{
        currNode = currNode->next; 
    }
    while (currNode != *head && currNode -> data != findData);
    

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
    delete currNode;
}
    
template <typename T>
void dllDeleteList(DoubleList<T>** head){
    DoubleList<T>* currentNode = (*head)->next;

    while (currentNode != *head){
        DoubleList<T>* temp = currentNode;  
        currentNode = currentNode->next;
        delete temp;
    }
    delete *head;
    *head = nullptr;
}

#endif 