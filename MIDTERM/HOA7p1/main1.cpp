#include <iostream> 
#include <cstdlib> 
#include <ctime>      
#include "sortingAlgo.h" 

const int maxSize = 100; 

void displayAll(const int arr[]); 

int main(){ 
    int randomNumbers[maxSize]; 
    srand(time(0)); 
    
    for (int i=0; i<maxSize; i++){ 
        randomNumbers[i] = rand(); 
    } 

    displayAll(randomNumbers); 

    // bubbleSort(randomNumbers, maxSize); 
    // selectionSort(randomNumbers, maxSize);
    insertionSort(randomNumbers, maxSize);  
    std::cout << "\nAfter sorting: \n";
    
    displayAll(randomNumbers); 

    
    
    return 0; 
} 

void displayAll(const int arr[]){ 
    for (int i=0; i<maxSize; i++){ 
        std::cout << arr[i] << " "; 
    } 
    std::cout << std::endl; 
}
