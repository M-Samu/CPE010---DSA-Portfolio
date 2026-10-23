
#include <iostream>
#include <thread>
#include <mutex>

// Global variable
int globalValue = 0;

// Prevents data races
std::mutex mtx;

void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    globalValue += value;
}

int main() {
    // Create three threads
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    // Initial value
    std::cout << "Global Variable: " << globalValue << std::endl;

    // After T1
    T1.join();
    std::cout << "Global Variable (T1): " << globalValue << std::endl;

    // After T2
    T2.join();
    std::cout << "Global Variable (T2): " << globalValue << std::endl;

    // After T3
    T3.join();
    std::cout << "Global Variable (T3): " << globalValue << std::endl;

    return 0;
}
