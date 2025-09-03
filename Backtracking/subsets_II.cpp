// https://leetcode.com/problems/subsets-ii?envType=problem-list-v2&envId=backtracking

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

        int i = k + 1;
        while (i < n && nums[i] == nums[i - 1]) {
            i++;
        }
            
        backtrack(ans, temp, nums, i, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) { // Time: O(2^n * n), Space: O(n)
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
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
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);

            backtrack(ans, temp, nums, visited, i + 1);

            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) { // Time: O(2^n * n), Space: O(n)
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> visited(n, false);

        sort(nums.begin(), nums.end());  // important for duplicates

        backtrack(ans, temp, nums, visited, 0);

        return ans;
    }
};
