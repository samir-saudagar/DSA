// https://leetcode.com/problems/spiral-matrix-ii?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) { // Time: O(n*n), Space: O(1)
        int left = 0, right = n - 1, top = 0, bottom = n - 1, num = 1;

        vector<vector<int>> ans(n, vector<int>(n, 0));

        while (left <= right && top <= bottom) {
            // left - right
            for (int i = left; i <= right; i++) {
                ans[top][i] = num++;
            }
            top++;

            // top - bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            if (top > bottom) break;

            // right - left
            for (int i = right; i >= left; i--) {
                ans[bottom][i] = num++;
            }
            bottom--;

            if (left > right) break;
            
            // bottom - top
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = num++;
            }
            left++;
        }

        return ans;

    }
};