#include <iostream>
#include "node.h"
#include "searchingAlgo3.h"

const int size = 10;

int main(){
    
    int sortedList[size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int targetKey = 8;

    std::cout << "Searching for key: " << targetKey << "\n\n";

    binarySearchArr(size, targetKey, sortedList);

    return 0;
}
