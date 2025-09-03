// https://leetcode.com/problems/subsets?envType=problem-list-v2&envId=backtracking

// n is the size of the input array nums
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, const vector<int> nums, int k, int n) { // Time: O(2^n * n), Space: O(n)
        if (k == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[k]);
        backtrack(ans, temp, nums, k + 1, n);

        temp.pop_back();
        backtrack(ans, temp, nums, k + 1, n);
    }

    vector<vector<int>> subsets(vector<int> &nums) { // Time: O(2^n * n), Space: O(n)
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();

        backtrack(ans, temp, nums, 0, n);

        return ans;
    }
};

// another approach
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, 
                   vector<int>& nums, vector<bool>& visited, int start) { // Time: O(2^n * n), Space: O(n)
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);

            backtrack(ans, temp, nums, visited, i + 1);

            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) { // Time: O(2^n * n), Space: O(n)
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        backtrack(ans, temp, nums, visited, 0);

        return ans;
    }
};
