#include <iostream>
#include "listStack2.h"

int main(){
    std::string choice;

    std::cout << "Enter Expression: ";
    std::cin >> choice;

    bool balanced = true;

    for(int i = 0; i < choice.length(); i++){

        char ch = choice[i];

        if(isOpening(ch)){
            push(ch);
        }

        else if(isClosing(ch)){

            if(isEmpty<char>()){
                std::cout << "Stack Underflow\n";   
                balanced = false;
                break;
            }
            char open = pop<char>();

            if(!isMatch(open, ch)){
                balanced = false;
                break;
            }
        }
    }

    if(!isEmpty<char>()){
        std::cout << "Stack not Empty\n";
        balanced = false;
    }
    if(balanced)
        std::cout << "Balanced Expression";
    else
        std::cout << "Unbalanced Expression";

    return 0;
}
    

