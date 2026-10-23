#include <iostream>
#include "doubly_LL.H"

int main(){

    // creating the first node 'C', 'P', 'E'
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    // Link the nodes together
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;
    
    std::cout << "Traversal Testing: " << std::endl;
    dllTraverse(head);

    std::cout << "Insert Head Testing: " << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);
    
    std::cout << "Insert End Testing: " << std::endl;
    dllInsertEnd('Y', head);
    dllTraverse(head);

    std::cout << "General Insert Testing: " << std::endl;
    dllGeneralInsert('P', head->next->next);
    dllTraverse(head);

    std::cout << "Delete Node Testing: " << std::endl;
    dllDeleteNode('X', &head);
    dllTraverse(head);

    std::cout << "Delete List Testing: " << std::endl;
    dllDeleteList(&head);
    dllTraverse(head);
    
    return 0;
}