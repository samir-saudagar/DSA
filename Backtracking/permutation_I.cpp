// https://leetcode.com/problems/permutations?envType=problem-list-v2&envId=backtracking

// n is the size of the input array nums

class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, int k, int n) { // Time: O(n*n!), Space: O(n)
        if (k == n) {
            ans.push_back(nums);
            return;
        }

        for (int j = k; j < n; j++) {
            swap(nums[k], nums[j]);
            backtrack(ans, nums, k + 1, n);
            swap(nums[k], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) { // Time: O(n*n!), Space: O(n)
        vector<vector<int>> ans;
        int n = nums.size();
        
        backtrack(ans, nums, 0, n);
        
        return ans;
    }
};


// better - simple to understand 
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, vector<bool> &used, int n) { // Time: O(n*n!), Space: O(n)
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;  
            
            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(ans, temp, nums, used, n);

            temp.pop_back();   
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) { // Time: O(n*n!), Space: O(n)
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> used(n, false);

        backtrack(ans, temp, nums, used, n);
        
        return ans;
    }
};
