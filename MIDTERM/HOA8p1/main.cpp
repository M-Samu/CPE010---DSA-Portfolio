#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sortingAlgo.h"

const int maxSize = 100;

int main(){
    int randomNumbers[maxSize];
    srand(time(0));

    for (int i=0; i<maxSize; i++){
        randomNumbers[i] = rand() % 100;
    }

    displayAll(randomNumbers, maxSize);

    // shellSort(randomNumbers, maxSize);
    // mergeSort(randomNumbers, 0, maxSize-1); 
    // quickSort(randomNumbers, 0, maxSize-1);
    hybridQuickSort(randomNumbers, 0, maxSize-1, maxSize);    


    std::cout << "\nSorted array: " << std::endl;
    displayAll(randomNumbers, maxSize);
    

    return 0;
}