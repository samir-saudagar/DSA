// https://leetcode.com/problems/combination-sum-iii?envType=problem-list-v2&envId=backtracking

// k is the size of each combination
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, int k, int target, int i) { // Time: O(k * (9 choose k)) Space: O(k)
        if (target == 0 && k == temp.size()) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || temp.size() > k || i > 9) {
            return;
        }

        for (int j = i; j <= 9; j++) {
            temp.push_back(j);
            backtrack(ans, temp, k, target - j, j + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int target) { // Time: O(k * (9 choose k)) Space: O(k)
        vector<vector<int>> ans; 
        vector<int> temp;

        backtrack(ans, temp, k, target, 1);

        return ans;
    }
};