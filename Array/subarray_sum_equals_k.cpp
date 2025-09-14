// https://leetcode.com/problems/subarray-sum-equals-k?envType=problem-list-v2&envId=array

// brute force approach

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { // Time: O(n^2), Space: O(1)
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }

        return count;
    }
};

// optimized approach using unordered_map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { // Time: O(n), Space: O(n)
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }

        return count;
    }
};