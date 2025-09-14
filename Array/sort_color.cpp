// https://leetcode.com/problems/sort-colors?envType=problem-list-v2&envId=array

// brute force approach

class Solution {
public:
    void sortColors(vector<int>& nums) { // Time: O(n^2), Space: O(1)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) swap(nums[i], nums[j]);
            }
        }
    }
};

// optimised approach

class Solution {
public:
    void sortColors(vector<int>& nums) { // Time: O(n), Space: O(1)
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++; mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { 
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// you can use merge sort or quick sort also to sort the array

