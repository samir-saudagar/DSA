// https://leetcode.com/problems/permutations-ii?envType=problem-list-v2&envId=backtracking

// n is the length of nums
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<bool> &used, int n) {  // Tine: O(n * n!) Space: O(n) 
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;  

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            
            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(ans, temp, nums, used, n);

            temp.pop_back();   
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) { // Tine: O(n * n!) Space: O(n)
        vector<vector<int>> ans; 
        vector<int> temp;
        int n = nums.size();
        vector<bool> used(n, false);

        sort(nums.begin(), nums.end());

        backtrack(ans, temp, nums, used, n);
        
        return ans;
    }
};
