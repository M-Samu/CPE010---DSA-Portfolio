#include <iostream>
#include <vector>

// Recursive function
int countPaths(const std::vector<std::vector<int>>& mat, int m, int n, 
    int i, int j, int cost) {
    // If cost is reduced to less than 0
    if (i >= m || j >= n || cost < 0) {
        return 0;
    }

    // If reached destination cell 
    if (i == m - 1 && j == n - 1) {
        return (cost == mat[i][j]) ? 1 : 0; 
    }

    // Subtracts remaining cost by current cell
    int remainingCost = cost - mat[i][j];

    // Recurse down (i+1, j) and right (i, j+1)
    int downPaths = countPaths(mat, m, n, i + 1, j, remainingCost);
    int rightPaths = countPaths(mat, m, n, i, j + 1, remainingCost);

    // Returns the total number of paths from current cell
    return downPaths + rightPaths;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int m = mat.size();
    int n = mat[0].size();
    int targetCost = 25;

    int totalPaths = countPaths(mat, m, n, 0, 0, targetCost);

    std::cout << "Total Number of Paths with Cost " << targetCost << ": " << totalPaths << std::endl;

    return 0;
}