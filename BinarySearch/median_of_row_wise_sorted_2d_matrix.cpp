// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// brute force approach
// Time Complexity: O(n*m + n*m*log(n*m))
// Space Complexity: O(n*m) 
// stire eacch element of the matrix in a vector and sort it
// then return the middle element

// binary search approach

class Solution {
 public:
  int findUpperBound(const vector<vector<int>>& matrix, int row, int cols, int target) { // Time: O(log m), Space: O(1)
    int low = 0, high = cols - 1, pos = cols;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[row][mid] > target) {
        pos = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return pos; 
  }

  int countLessEqual(const vector<vector<int>>& matrix, int rows, int cols, int target) { // Time: O(n log m), Space: O(1)
    int count = 0;
    for (int i = 0; i < rows; ++i) {
      count += findUpperBound(matrix, i, cols, target);
    }
    return count;
  }

  int median(vector<vector<int>>& matrix) { // Time: O(n log m * log(max - min)), Space: O(1)
    int rows = matrix.size();
    int cols = matrix[0].size();
    int halfElements = (rows * cols) / 2;

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < rows; i++) {
      low = min(low, matrix[i][0]);
      high = max(high, matrix[i][cols - 1]);
    }

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (countLessEqual(matrix, rows, cols, mid) <= halfElements) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};
