#include <iostream>
#include <string>

const size_t maxCap = 100;

char stack[maxCap];
int top = -1, elements;

// prototypes
bool arrisEmpty();
bool arrisFull();
void arrpush(char newData);
char arrpop();
char arrpeek();
bool arrIsOpening(char newData);
bool arrIsClosing(char newData);
bool arrMatch(char open, char close);   

int main(){

    std::cout << "Enter the maximum capacity: ";
    std::cin >> elements;

    std::string choice;

    std::cout << "Enter Expression: ";
    std::cin >> choice;

    bool balanced = true;

    for(int i = 0; i < choice.length(); i++){

        char ch = choice[i];

        if(arrIsOpening(ch)){
            arrpush(ch);
        }

        else if(arrIsClosing(ch)){

            if(arrisEmpty()){
                std::cout << "Stack Underflow\n";   
                balanced = false;
                break;
            }

            char open = arrpop();

            if(!arrMatch(open, ch)){
                balanced = false;
                break;
            }
        }
    }

    if(!arrisEmpty()){
        std::cout << "Stack not Empty\n";
        balanced = false;
    }
    if(balanced)
        std::cout << "Balanced Expression";
    else
        std::cout << "Unbalanced Expression";
    
    return 0;
}

bool arrisEmpty(){
    if(top < 0){
        return true;
    }
    return false;
}

bool arrisFull(){
    if (top >= elements - 1){
        return true;
    }   
    return false;
}

void arrpush(char newData){

    if(arrisFull()){
        std::cout << "Stack Overflow\n";
        return;
    }

    stack[++top] = newData;
}

char arrpop(){

    if(arrisEmpty()){
        return '\0';
    }

    return stack[top--];
}


bool arrIsOpening(char newData){
    return newData == '(' || newData == '[' || newData == '{';
}

bool arrIsClosing(char newData){
    return newData == ')' || newData == ']' || newData == '}';
}

bool arrMatch(char open, char close){

    if(open == '(' && close == ')')
        return true;

    if(open == '[' && close == ']')
        return true;

    if(open == '{' && close == '}')
        return true;

    return false;
}