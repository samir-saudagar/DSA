// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array?envType=problem-list-v2&envId=binary-search
// n is the length of the input array

class Solution {
public:
    int findMin(vector<int>& nums) { // Time: O(log n), Space: O(1)
        int i = 0;
        int j = nums.size() - 1;
        int ans = INT_MAX;
        while(i <= j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] >= nums[i]) {
                ans = min(ans, nums[i]);
                i = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                j = mid - 1;
            }
        }
        return ans;
    }
};

// if they ask about how many time arry is rotated you can return index of minimum element