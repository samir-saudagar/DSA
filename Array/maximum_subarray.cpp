// https://leetcode.com/problems/maximum-subarray?envType=problem-list-v2&envId=array

// brute force

int maxSubArray(vector<int>& nums) { // Time: O(n^2), Space: O(1)
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];   
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// kadnes algorithm
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) { // Time: O(n), Space: O(1)
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
