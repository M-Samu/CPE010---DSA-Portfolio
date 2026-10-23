#ifndef SIMPLY_LL_H
#define SIMPLY_LL_H

template <typename T>
class SimplyList{
    public:
        T data;
        SimplyList<T> *next = nullptr;
};
/*ListTraversal (parameter: pointer to node n)
WhILE n IS NOT EQUAL TO null
RINT data OF n
GO TO NEXT NODE n := next
ENDWHILE
PRINT next line
END */

template <typename T>
void listTraversal(SimplyList<T>* head){

    if(head == nullptr){
        std::cout << "List is empty" << std::endl;
        return;
    }

    while (head!=nullptr){
        std::cout<< head->data;
        if (head->next != nullptr){
            std::cout << "->";
        }
        head = head -> next;
    }
    std::cout<<std::endl;
};


template <typename T>
void sllinsertHead(T newData, SimplyList<T>** currentHead){
    // 1. Allocate memory for the new node
    SimplyList<T>* newNode = new SimplyList<T>;
    //2. Put our data into the new node
    newNode -> data = newData;
    //3. Set next to the new node to the previous head
    newNode -> next = *currentHead;
    //4. Reset Head to point to the new node
    *currentHead = newNode; 
}

template <typename T>
void sllGeneralInsert(T newData, SimplyList<T>* prevNode){
    //2. if null, print "Previous node cannot be null"
    if(prevNode == nullptr){
        std::cout << "Previous Node cannot be Null" << std::endl;
        return;
    }

    //allocate a new node
    SimplyList<T>* newNode = new SimplyList<T>;

    //4. Store data in the new node
    newNode->data = newData;
        
    //5. point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    //6. point previous code to the new node
    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SimplyList<T>** head){
    //1. allocate new code
    SimplyList<T> newNode = new SimplyList<T>;
    //2. dereference to the head node
    SimplyList<T>* currentNode = *head;
    //3. Store data in new node
    newNode -> data = newData;
    //4. point next of new node to null
    newNode -> next = nullptr;

    //traverse the list until next of the node is null;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    //6. Point the next of the current node to the new node
    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){
    // check if the is no list to be deleted
    if (*head == nullptr){
        return;
    }

    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = nullptr;

    // searching loop
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    // if data was not found
    if (currNode ==nullptr) return;

    // what if the nod to be deleted is the head node?
    if(prevNode == nullptr){
        *head = currNode -> next;
    }
    else{
        prevNode->next = currNode->next;
    }

    // we have to delete the node?
    delete currNode;

    //1. find previous node of the node to be deleted

}

template <typename T>
void sllDeleteList(SimplyList<T>** head){
    SimplyList<T>* current = *head;

    while(current != nullptr){
        SimplyList<T>* temp = current;
        current = current -> next;
        delete temp;
    }
    *head = nullptr;
}

#endif