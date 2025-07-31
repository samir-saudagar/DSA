// https://leetcode.com/problems/remove-duplicates-from-sorted-array?envType=study-plan-v2&envId=top-interview-150
// n is the length of the array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // O(n) time, O(1) space
        int i = 1, j = 1, n = nums.size();
        while(i < n && j < n) {
            if(nums[i] == nums[i - 1]) i++;
            else if(nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                i++;
                j++;
            }
        }
        return j;
    }
};