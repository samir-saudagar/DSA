// https://leetcode.com/problems/remove-element?envType=study-plan-v2&envId=top-interview-150
// n is the length of the array
class Solution {
public:
    int removeElement(vector<int>& nums, int val) { // O(n) time, O(1) space
        int n = nums.size();
        int i = 0, j = n - 1, count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == val) count++;
        }
        while(i <= j) {
           if(nums[i] == val && nums[j] != val) {
            swap(nums[i], nums[j]);
            i++;
            j--;
           } else if( nums[j] == val) {
            j--;
           } else i++;
           
        }
        return n - count;
    }
};
