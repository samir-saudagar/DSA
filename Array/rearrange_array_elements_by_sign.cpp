// https://leetcode.com/problems/rearrange-array-elements-by-sign?envType=problem-list-v2&envId=array

// brute force

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) { // Time: O(n) Space: O(n)
        int n = nums.size();
        vector<int> pNums;
        vector<int> nNums;

        for (int num : nums) {
            if (num < 0)
                nNums.push_back(num);
            else 
                pNums.push_back(num);
        }

        int i = 0, k = 0;

        while (i < n / 2) {
            nums[k++] = pNums[i];
            nums[k++] = nNums[i++];
        }

        return nums;

    }
};

// optimized approach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) { // Time: O(n) Space: O(n)
        int n = nums.size();
        vector<int> ans(n, 0);
        int pIndex = 0, nIndex = 1;
        
        for (int num : nums) {
            if (num < 0) {
                ans[nIndex] = num;
                nIndex += 2;
            } else {
                ans[pIndex] = num;
                pIndex += 2;
            }
        }

        return ans;

    }
};

