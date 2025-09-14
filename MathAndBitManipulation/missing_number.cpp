// https://leetcode.com/problems/missing-number?envType=problem-list-v2&envId=array

class Solution {
public:
    int missingNumber(vector<int>& nums) { // Time: O(n) Space: O(1)
       int actualSum = 0;
       int n = nums.size();
       int sum = n * (n + 1) / 2;

       for (int i = 0; i < n; i++) actualSum += nums[i];

       return sum - actualSum;
       
    }
};

// for brute forcw use sorting and then check for missing number