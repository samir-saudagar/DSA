// https://leetcode.com/problems/rotate-array?envType=problem-list-v2&envId=array

class Solution {
public:
    void rotate(vector<int>& nums, int k) { // Time: O(n), Space: O(1)
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};