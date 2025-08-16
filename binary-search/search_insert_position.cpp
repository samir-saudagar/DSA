// https://leetcode.com/problems/search-insert-position?envType=study-plan-v2&envId=top-interview-150
// n is the length of the array
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // O(log n) time, O(1) space
        int n = nums.size();
        int i = 0, j = n - 1, mid;
        while(i <= j) {
            mid = (i + j) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return i;
    }
};