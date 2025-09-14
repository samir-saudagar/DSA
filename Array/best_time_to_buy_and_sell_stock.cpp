// https://leetcode.com/problems/best-time-to-buy-and-sell-stock?envType=problem-list-v2&envId=array

class Solution {
public:
    int maxProfit(vector<int>& nums) { // Time: O(n), Space: O(1)
        int profit = 0, i = 0, j = 1;

        while (j < nums.size()) {
            if (nums[j] > nums[i]) {
                profit = max(profit, nums[j] - nums[i]);
            } else {
                i = j;
            }
            j++;
        }

        return profit;

    }
};