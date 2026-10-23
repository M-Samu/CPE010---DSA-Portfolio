
#include <iostream>
#include <chrono>
#include <iomanip>

int linearSearch(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int A[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

template <typename Search>
double measureSearch(Search search, int A[], int n,
                     int key, int repetitions) {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        search(A, n, key);
    }

    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration<double, std::milli>(
        end - start
    ).count() / repetitions;
}

int main() {
    int sizes[] = {1000, 10000, 100000};
    int repetitions = 1000;

    std::cout << "SEARCHING ALGORITHM ANALYSIS\n";
    std::cout << "Average time per search in milliseconds\n\n";
    std::cout << std::fixed << std::setprecision(8);

    for (int n : sizes) {
        int* A = new int[n];

        for (int i = 0; i < n; i++) {
            A[i] = i + 1;
        }
        int key = 0; 

        double binaryTime = measureSearch(
            binarySearch, A, n, key, repetitions);

        double linearTime = measureSearch(
            linearSearch, A, n, key, repetitions);

        std::cout << "Input Size: " << n << '\n';
        std::cout << "Binary Search: " << binaryTime << " ms\n";
        std::cout << "Linear Search: " << linearTime << " ms\n\n";
        delete[] A;
    }
    return 0;
}
