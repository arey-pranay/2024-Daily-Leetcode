#include <vector>

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        // Create a 3D vector to store dynamic programming results
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        // Call the helper function to calculate the number of paths
        return countPaths(m, n, maxMove, startRow, startColumn, dp);
    }

    int countPaths(int m, int n, int moves, int row, int col, vector<vector<vector<int>>>& dp) {
        const int MOD = 1e9 + 7;

        // Base cases
        if (row < 0 || row >= m || col < 0 || col >= n) {
            // If out of boundary, return 1 path
            return 1;
        }

        if (moves == 0) {
            // If no more moves left, return 0 paths
            return 0;
        }

        if (dp[row][col][moves] != -1) {
            // If result is already computed, return it
            return dp[row][col][moves];
        }

        // Calculate paths recursively in all four directions
        long long paths = 0;
        paths += countPaths(m, n, moves - 1, row - 1, col, dp);
        paths += countPaths(m, n, moves - 1, row + 1, col, dp);
        paths += countPaths(m, n, moves - 1, row, col - 1, dp);
        paths += countPaths(m, n, moves - 1, row, col + 1, dp);

        // Modulo to avoid integer overflow
        dp[row][col][moves] = paths % MOD;

        return dp[row][col][moves];
    }
};
