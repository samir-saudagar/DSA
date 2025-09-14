// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated?envType=problem-list-v2&envId=array

class Solution {
public:
    bool check(vector<int>& nums) { // Time: O(n), Space: O(1)
        int k = 1;
        while (k < nums.size() && nums[k] >= nums[k - 1]) k++;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};