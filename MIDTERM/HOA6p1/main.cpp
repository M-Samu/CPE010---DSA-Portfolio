#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main(){

    // generate
    int dataset[max_size];
    srand(time(0));
    for (int i=0; i<max_size; i++){
        dataset[i] = rand();
    }
    for (int i=0; i<max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int userInput;
    std::cout << "What number to search? ";
    std::cin >> userInput;
    std::cout << "Array result Linear Search? ";

    linearSearchArr(max_size, userInput, dataset);
     std::cout << std::endl;

    // create a linked list: J I M L O R D
    Node<char> *name1 = new_node('J');
    Node<char> *name2 = new_node('I');
    Node<char> *name3 = new_node('M');
    Node<char> *name4 = new_node('L');
    Node<char> *name5 = new_node('O');
    Node<char> *name6 = new_node('R');
    Node<char> *name7 = new_node('D');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;

    std::cout << "Linked List result Linear Search(LS): ";
    linearSearchLL(name1, 'R');
    std::cout << std::endl;

    Node<char> *name_1 = new_node('A');
    Node<char> *name_2 = new_node('B');
    Node<char> *name_3 = new_node('C');
    Node<char> *name_4 = new_node('D');
    Node<char> *name_5 = new_node('E');

    name_1->next = name_2;
    name_2->next = name_3;
    name_3->next = name_4;
    name_4->next = name_5;
    

    
    std::cout << "Linked List result Binary Search: ";
    binarySearchLL(name_1, 'B');

    char testArr[5] = {'A', 'B', 'C', 'D', 'E'};
    std::cout << "Array result Binary Search: ";
    binarySearchArr(5, 'A', testArr);
}