#include <iostream> 
#include <cstdlib> 
#include <ctime>      
#include "sortingAlgo.h" 

const int maxSize = 100;    

void displayAll(const int arr[]);
void countVotes(const int arr[]); 

int main(){
    srand(time(0));
    int votes[maxSize]; 

    for (int i=0; i<maxSize; i++){
        votes[i] = rand() % 5 + 1; 
    }   

    displayAll(votes);
    bubbleSort(votes, maxSize);
    std::cout << "\nAfter sorting: \n";
    displayAll(votes);  
    countVotes(votes);



    return 0;
}

void displayAll(const int arr[]){ 
    for (int i=0; i<maxSize; i++){ 
        std::cout << arr[i] << " "; 
    } 
    std::cout << std::endl; 
}

void countVotes(const int arr[]) {
    int counts[6] = {0}; 
    std::string candidateNames[6] = {"", "Bo Dalton Capistrano", "Cornelius Raymon Agustin", "Deja Jayla Banyaga", "Lalla Brielle Yabu", "Franklin Relano Castro"};    

    for (int i = 0; i < maxSize; i++) {
        int vote = arr[i];
        if (vote >= 1 && vote <= 5) {
            counts[vote]++;
        }
    }

    std::cout << "\n--- Vote Tally ---\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Number of Votes for Candidate No. " << i << " " << candidateNames[i] << ": " << counts[i] << "\n";
    }
    std::cout << "------------------\n";
}