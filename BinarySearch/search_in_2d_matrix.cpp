// https://leetcode.com/problems/search-a-2d-matrix?envType=problem-list-v2&envId=binary-search
// m = rows, n = cols
class Solution {
public:
    int find_rows(vector<vector<int>>& matrix, int rows, int cols, int target) { // Time: O(log m), Space: O(1)
        int i = 0, j = rows - 1, ans = -1;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (matrix[mid][cols - 1] >= target) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }

    int find_cols(vector<vector<int>>& matrix, int row, int cols, int target) { // Time: O(log n), Space: O(1)
        int i = 0, j = cols - 1, ans = -1;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (matrix[row][mid] >= target) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) { // Time: O(log m + log n), Space: O(1)
        //if (matrix.empty() || matrix[0].empty()) return false; dont need here as per problem constraints but never forget to check in real scenarios

        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = find_rows(matrix, rows, cols, target);
        if (i == -1) return false;

        int j = find_cols(matrix, i, cols, target);
        if (j == -1) return false;

        return matrix[i][j] == target;
    }
};
