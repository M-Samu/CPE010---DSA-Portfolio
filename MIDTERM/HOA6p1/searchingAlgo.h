#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind , T list[]){

    for (int i = 0; i<arrSize; i++){
        if (dataFind == list[i]){
        std::cout << "Searching is successful" << std::endl;
        return;
        }
    }
    std::cout << "Searching is unsuccessful" << std::endl;
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind){
    while (head != nullptr){
        if (head->data == dataFind){
            std::cout << "Searching is successful." << std::endl;
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is unsuccessful" << std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        // move slow one step
        slow = slow->next;

        // move fast two steps
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    Node<T>* last = nullptr;

    while (start != last){
        Node<T>* mid = getMiddle(start, last);

        if (mid->data == dataFind){
            std::cout << "Searching is successful\n" << std::endl;
            return;
        }

        else if (dataFind < mid->data){
            last = mid;
        }

        else{
            start = mid->next;
        }
    }
    std::cout << "Searching is not successful\n" << std::endl;

}


// for array binary search
template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low=0, up=arrSize-1, mid;
    while (low <= up){
        mid = int((low+up)/2);

        if (dataFind == list[mid]){
            std::cout << "Searching successful\n" << std::endl;
            return;
        }
        else if (dataFind < list[mid]){
            up = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    std::cout << "Searching not successful\n" << std::endl;
}


#endif

