#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// Check if all elements in an array are unique
bool Unique(std::vector<int>& A){
    int n = A.size();

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (A[i] == A[j]){
                return false;
            }
        }
    }
    return true;
}

// Generate a random array
std::vector<int> generate_random_array(int size){
    std::random_device rd;
    std::mt19937 rand(rd());

    std::uniform_int_distribution<int> uniform_dist(1, size);

    std::vector<int> A;

    for (int i=0; i<size; i++){
        A.push_back(uniform_dist(rand));
    }
    return A;
}

// Test the unique algorithm
void unique_test(int size){
    std::vector<int> A = generate_random_array(size);

    // measures time taken
    auto begin = std::chrono::steady_clock::now();

    bool result = Unique(A);

    auto end = std::chrono::steady_clock::now();

    std::cout << "Input size: " << size << std::endl;
    
    std::cout << "Time taken to check: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl; 

    if (result){
        std::cout << "All elements are unique." << std::endl;
    }
    else{
        std::cout << "Array contains duplicate elements." << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    unique_test(1000);
    unique_test(10000);
    unique_test(100000);

    return 0;
}