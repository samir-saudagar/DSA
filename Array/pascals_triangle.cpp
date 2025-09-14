// https://leetcode.com/problems/pascals-triangle?envType=problem-list-v2&envId=array


class Solution {
public:
    vector<vector<int>> generate(int numRows) { // Time: O(numRows^2), Space: O(numRows^2)
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

class Solution {
public:
    vector<vector<int>> generate(int numRows) { // Time: O(numRows^2), Space: O(numRows^2)
        vector<vector<int>> pascal(numRows);

        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i + 1, 1); 
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        return pascal;
    }
};
