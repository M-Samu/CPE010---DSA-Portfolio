#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::vector<int> arr = {14, 7, 22, 9, 31, 5, 18, 27, 3, 40,
                        11, 36, 25, 8, 19, 33, 2, 29, 16, 21};

std::mutex mtx;
int foundIndex = -1;

void linearSearch(int id, int start, int end, int target) {
    for (int i = start; i < end; i++) {
        if (arr[i] == target) {
            std::lock_guard<std::mutex> lock(mtx);
            foundIndex = i;
            std::cout << "Thread " << id << " found " << target
                      << " at index " << i << std::endl;
            return;
        }
    }
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " searched index " << start
              << " to " << end - 1 << ": not found" << std::endl;
}

int main() {
    int target = 36;
    int numThreads = 4;
    int size = arr.size();
    int chunk = size / numThreads;

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; i++) {
        int start = i * chunk;
        int end = start + chunk;
        threads.push_back(std::thread(linearSearch, i, start, end, target));
    }

    for (auto &th : threads) {
        th.join();
    }

    if (foundIndex != -1) {
        std::cout << "Target " << target << " is at index " << foundIndex << std::endl;
    } else {
        std::cout << "Target " << target << " was not found" << std::endl;
    }

    return 0;
}