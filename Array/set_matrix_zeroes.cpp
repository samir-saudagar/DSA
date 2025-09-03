// https://leetcode.com/problems/set-matrix-zeroes?envType=problem-list-v2&envId=array
// k is the number of zeroes in the matrix

class Solution {
public:
    struct index {
        int i;
        int j;
    };

    void helper(vector<vector<int>>& matrix, const vector<index> temp, int cols, int rows) { // Time: O(m*n) Space: O(k)
        for (int k = 0; k < temp.size(); k++) {
            for (int i = 0; i < rows; i++) {
                matrix[i][temp[k].j] = 0;
            }

            for (int i = 0; i < cols; i++) {
                matrix[temp[k].i][i] = 0;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) { // Time: O(m*n) Space: O(k)
        if (matrix.size() == 1 and matrix[0].size() == 1)
            return;

        int cols = matrix[0].size();
        int rows = matrix.size();

        vector<index> temp;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!matrix[i][j]) {
                    index k;
                    k.j = j;
                    k.i = i;
                    temp.push_back(k);
                }
            }
        }

        helper(matrix, temp, cols, rows);
    }
};