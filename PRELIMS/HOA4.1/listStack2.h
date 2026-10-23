#ifndef LISTSTACK_H
#define LISTSTACK_HSSSs

// class node with data and next numebers
template <typename T>
class Node{
    public:
        T data;
        Node<T>* next = nullptr;
};

// create a pointer/reference tip that always points to t   he current top node

// global
template <typename T>
Node<T>* head = nullptr;


// pushing operation
template <typename T>
void push(T newData){
    // create a new node
    Node<T>* newNode = new Node<T>;
    // assign the data to the newnode
    newNode->data = newData;
    // point the newNode next to the current top
    newNode->next = head<T>;
    // assign the new top to the new node
    head<T> = newNode;
}

// isEmpty()
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    // if the stack is empty, error catch:
    if (isEmpty<T>()){
        std::cout << "Stack Underflow" << std::endl;
    }

    // saving a current top node to a temporary variable
    Node<T>* temp = head<T>;
    // store the data to a temp variable
    T tempVal = temp->data;
    // move the head to the next node
    head<T> = head<T>->next;
    // free up the memory
    delete temp;
    // return the temporary variable
    return tempVal;
}

template <typename T>
void Top(){
    // what if the stack is empty
    if (isEmpty<T>()) return; 
 
    std::cout << "The top is: " << head<T>->data << std::endl;
    std::cout << std::endl;
}

template <typename T>
void displayAll(){
    // stack is empty
    if (isEmpty<T>()) return; 

    // store the head with temp
    Node<T>* temp = head<T>;

    while (head<T> != nullptr){
        std::cout << head<T>->data << std::endl;
        head<T> = head<T>->next;
    }
    // makes sure the head doesn't change its value
    head<T> = temp;
    std::cout << std::endl;
}

template <typename T>
bool isOpening(T newData){
    return newData == '(' || newData == '[' || newData == '{';
}

template <typename T>
bool isClosing(T newData){
    return newData == ')' || newData == ']' || newData == '}';
}

template <typename T>
bool isMatch(T open, T close){
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

#endif