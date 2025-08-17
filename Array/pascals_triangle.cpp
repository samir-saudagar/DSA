// https://leetcode.com/problems/pascals-triangle?envType=daily-question&envId=2025-08-01
// n is the number of rows in Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) { // O(n^2) time, O(n^2) space
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1, 1);
            ans.push_back(temp);
            for(int j = 1; j< i ; j++) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};
