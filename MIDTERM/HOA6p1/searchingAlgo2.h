#include "node.h"
#include <iostream>

#ifndef SEARCHINGALGO2_H
#define SEARCHINGALGO2_H

// Counts all occurrences of 'k' in an Array
template <typename T>
int countOccurrencesArr(int arrSize, T k, T list[]) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (list[i] == k) {
            count++;
        }
    }
    return count;
}

// Counts all occurrences of 'k' in a Linked List
template <typename T>
int countOccurrencesLL(Node<T>* head, T k) {
    int count = 0;
    while (head != nullptr) {
        if (head->data == k) {
            count++;
        }
        head = head->next;
    }
    return count;
}

#endif