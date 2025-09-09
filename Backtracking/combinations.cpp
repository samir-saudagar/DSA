// https://leetcode.com/problems/combinations?envType=problem-list-v2&envId=backtracking

// n is the range of numbers from 1 to n
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, int i, int n, int k) { // Time: O(k * (n choose k)) Space: O(k)
        if (temp.size() == k) {
            ans.push_back(temp);
        }

        for (int j = i; j <= n; j++) {
            temp.push_back(j);
            backtrack(ans, temp, j + 1 , n, k);
            temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) { // Time: O(k * (n choose k)) Space: O(k)
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(ans, temp, 1, n, k);

        return ans;
    }
};