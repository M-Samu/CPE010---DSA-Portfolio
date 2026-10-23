#include <iostream>
#include <chrono>
#include <cstdint>
using namespace std;
using namespace chrono;

//Ordinary recursive power
uint64_t rpower(uint64_t x, int n) {
    if (n == 0)
        return 1;
    return x * rpower(x, n - 1);
}

//Binary recursive power
uint64_t brpower(uint64_t x, int n) {
    if (n == 0)
        return 1;

    uint64_t y = brpower(x, n / 2);

    if (n % 2 == 1)
        return x * y * y;

    return y * y;
}

void power_test(int n) {
    const uint64_t x = 2;
    const int repetitions = 10000;

    if (n < 0 || n > 63) {
        cout << "Exponent must be between 0 and 63.\n";
        return;
    }

    uint64_t checksum1 = 0;
    uint64_t checksum2 = 0;

    auto start1 = steady_clock::now();

    for (int i = 0; i < repetitions; ++i)
        checksum1 += rpower(x, n);

    auto end1 = steady_clock::now();

    auto start2 = steady_clock::now();

    for (int i = 0; i < repetitions; ++i)
        checksum2 += brpower(x, n);

    auto end2 = steady_clock::now();

    double time1 =
        duration<double, nano>(end1 - start1).count()
        / repetitions;

    double time2 =
        duration<double, nano>(end2 - start2).count()
        / repetitions;

    cout << "\nExponent n: " << n << '\n';
    cout << "rpower average time: " << time1 << " ns\n";
    cout << "brpower average time: " << time2 << " ns\n";
    cout << "Results match: "
         << (checksum1 == checksum2 ? "Yes" : "No") << '\n';
}

int main() {
    power_test(10);
    power_test(20);
    power_test(30);
    power_test(40);
    power_test(50);
    power_test(60);

    return 0;
}