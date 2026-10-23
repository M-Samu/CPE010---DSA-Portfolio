#include <iostream>
#include "node.h"
#include "searchingAlgo2.h"

const int size = 10;

int main() {
    
    int k = 18; // Search element
    int testArray[size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    // 1. Array Test
    int arrayCount = countOccurrencesArr(size, k, testArray);
    std::cout << "Array count for '" << k << "': " << arrayCount << " time(s)." << std::endl;

    // 2. Linked List Test
    Node<int>* head = new_node(testArray[0]);
    Node<int>* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new_node(testArray[i]);
        current = current->next;
    }

    int llCount = countOccurrencesLL(head, k);
    std::cout << "Linked List count for '" << k << "': " << llCount << " time(s)." << std::endl;

    // Memory Cleanup
    current = head;
    while (current != nullptr) {
        Node<int>* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}