// https://leetcode.com/problems/check-knight-tour-configuration

class Solution {
public:
    bool backtrack(vector<vector<int>> &grid, int k, int i, int j, int n) { // Time: O(8^(n^2)), Space: O(n^2)
        if (i < 0 || j < 0 || i >= n || j >= n) return false;

        if (grid[i][j] != k) return false;

        if (k == n * n - 1) {
            return true;
        }
 
        bool ans = 
            backtrack(grid, k + 1, i - 2, j + 1, n) ||
            backtrack(grid, k + 1, i - 1, j + 2, n) ||
            backtrack(grid, k + 1, i + 1, j + 2, n) ||
            backtrack(grid, k + 1, i + 2, j + 1, n) ||
            backtrack(grid, k + 1, i + 2, j - 1, n) ||
            backtrack(grid, k + 1, i + 1, j - 2, n) ||
            backtrack(grid, k + 1, i - 1, j - 2, n) ||
            backtrack(grid, k + 1, i - 2, j - 1, n);

        return ans;

    }

    bool checkValidGrid(vector<vector<int>>& grid) { // Time: O(8^(n^2)), Space: O(n^2)
        int n = grid.size();

        if (backtrack(grid, 0, 0, 0, n)) {
            return true;
        }

        return false;

    }
};