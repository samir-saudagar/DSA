// https://leetcode.com/problems/spiral-matrix?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { // Time: O(m*n), Space: O(1)
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = col - 1, top = 0, bottom = row - 1;

        vector<int> ans;

        while (left <= right && top <= bottom) {
            // left - right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // top - bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top > bottom) break;

            // right - left
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;

            if (left > right) break;
            
            // bottom - top
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
};