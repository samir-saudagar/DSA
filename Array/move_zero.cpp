// https://leetcode.com/problems/move-zeroes?envType=problem-list-v2&envId=array

class Solution {
public:
    void moveZeroes(vector<int>& nums) { // Time: O(n) Space: O(n)
        vector<int> temp(nums.size());
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) temp[k++] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }

    }
};