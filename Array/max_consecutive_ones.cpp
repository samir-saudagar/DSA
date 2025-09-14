// https://leetcode.com/problems/max-consecutive-ones?envType=problem-list-v2&envId=array

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) { // Time: O(n), Space: O(1)
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) 
                count++;
            else {
                maxCount = max(count, maxCount);
                count = 0;
            }
        }

        return max(maxCount, count);
    }
};