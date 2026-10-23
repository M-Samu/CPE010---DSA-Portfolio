#include <iostream>
#include "doublysupp_LL.H"
#include <string>

int main(){

    // creating a playlist
    DoubleList<std::string>* head = createNode(std::string("Nothing"));
    DoubleList<std::string>* second = createNode(std::string("Easy"));
    DoubleList<std::string>* third = createNode(std::string("Old Fashioned"));
    
   
    // linkling the nodes to form a circular list
    head->next = second;
    head->prev = third;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = head;

    // printing all songs at once
    dllTraverse(head);

    // Inserting a new song at the head of the playlist
    dllInsertHead(std::string("UNDERSTAND"), &head);   
    dllTraverse(head);

    // Inserting a new song at the end of the playlist      
    dllInsertEnd(std::string("I Like Me Better"), head);    
    dllTraverse(head);

    // Inserting a new song anywhere in the playlist      
    dllGeneralInsert(std::string("Mean It"), head->next->next); 
    dllTraverse(head);  

    // Deleting a song from the playlist
    dllDeleteNode(std::string("Mean It"), &head);        
    dllTraverse(head);


    // Deleting the entire playlist 
    dllDeleteList(&head);
    dllTraverse(head);      
    
    return 0;
}