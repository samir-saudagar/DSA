// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii?envType=study-plan-v2&envId=top-interview-150
// n is the length of the array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // O(n) time, O(1) space
        int n = nums.size();
        if (n <= 2) return n;

        int i = 1;
        int j = 1;
        int count = 1;

        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};
