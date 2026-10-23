#include <iostream>
#include "listStack.h"
int main(){
    std::cout << "------- Pushing 'I' 'E' 'E' 'E' -------\n\n";
    
    // pushing
    push('I');
    push('E');
    push('E');
    push('E');
 


    
    // display top
    Top<char>();

    // Test display all
    std::cout << "Testing display all" << std::endl;
    displayAll<char>();


    // pop and print each element
    std::cout << "------- popping 'E' 'E' 'E' 'I' -------\n";
    while (!isEmpty<char>()){
        std::cout << "popping: " << pop<char>() << std::endl;
    }  
    std::cout << std::endl;
 


    // test stack underflow
    
    pop<char>();

}