// https://leetcode.com/problems/rotate-image?envType=problem-list-v2&envId=array

// n is the number of rows or columns in the n x n 2D matrix
// Transpose + Reverse
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { // Time: O(n^2), Space: O(1)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Layer by Layer Rotation - Four Way Swap
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { // Time: O(n^2), Space: O(1)
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            int end = n - i - 1;

            for (int j = i; j < end; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};