#include "node.h"
#include <iostream>

#ifndef SEARCHINGALGO3_H
#define SEARCHINGALGO3_H


template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low = 0, up = arrSize - 1, mid;
    int iteration = 1;
    
    while (low <= up){
        mid = (low + up) / 2; 

        std::cout << "Iteration " << iteration << ":\n";
        std::cout << "  - low index = " << low << ", up index = " << up << "\n";
        std::cout << "  - calculated mid index = " << mid << " (Value: " << list[mid] << ")\n";

        if (dataFind == list[mid]){
            std::cout << "  -> Match Found! Value " << dataFind << " equals list[" << mid << "].\n\n";
            std::cout << "Searching successful\n" << std::endl;
            return;
        }
        else if (dataFind < list[mid]){
            std::cout << "  -> Target " << dataFind << " < " << list[mid] << ". Shifting up bound to " << mid - 1 << ".\n\n";
            up = mid - 1;
        }
        else{
            std::cout << "  -> Target " << dataFind << " > " << list[mid] << ". Shifting low bound to " << mid + 1 << ".\n\n";
            low = mid + 1;
        }
        iteration++;
    }
    std::cout << "Searching not successful\n" << std::endl;
}

#endif