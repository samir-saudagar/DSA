// https://leetcode.com/problems/next-permutation?envType=problem-list-v2&envId=array

class Solution {
public:
    void nextPermutation(vector<int>& nums) { // Time: O(n) Space: O(1)
        int n = nums.size();
        int i = n - 1, j = n - 1;
        
        if (n == 1) return;
        if (n == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        
        while(i > 0 && nums[i - 1] >= nums[i]) i--;
        if(i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        while(nums[i - 1] >= nums[j]) j--;
        swap(nums[i - 1], nums[j]);
        
        reverse(nums.begin() + i, nums.end());
    }
};