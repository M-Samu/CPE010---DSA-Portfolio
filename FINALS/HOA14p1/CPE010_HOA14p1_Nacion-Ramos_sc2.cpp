
#include <iostream>
#include <chrono>
#include <algorithm>

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

template <typename T>
double measureSort(T sort, int A[], int n) {
    int B[n];

    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }

    auto start = std::chrono::steady_clock::now();
    sort(B, n);
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration<double, std::milli>(
    end - start
    ).count();
}

int main() {
    int sizes[] = {100, 1000, 10000};

    std::cout << "SORTING ALGORITHM ANALYSIS\n";
    std::cout << "Time in milliseconds\n\n";

    for (int n : sizes) {
        int* sorted = new int[n];
        int* reversed = new int[n];

        for (int i = 0; i < n; i++) {
            sorted[i] = i + 1;
            reversed[i] = n - i;
        }
        std::cout << "Input Size: " << n << '\n';
        std::cout << "(Alg#1 Bubble Sort Best: " << measureSort(bubbleSort, sorted, n) << " ms\n";
        std::cout << "(Alg#1) Bubble Sort Worst: " << measureSort(bubbleSort, reversed, n) << " ms\n";
        std::cout << "(Alg#2) Insertion Sort Best: " << measureSort(insertionSort, sorted, n) << " ms\n";
        std::cout << "(Alg#2) Insertion Sort Worst: "<< measureSort(insertionSort, reversed, n) << " ms\n\n";

        delete[] sorted;
        delete[] reversed;
    }

    return 0;
}
