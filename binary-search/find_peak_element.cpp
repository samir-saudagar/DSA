// https://leetcode.com/problems/find-peak-element?envType=problem-list-v2&envId=binary-search
// n is the length of the input array

class Solution {
public:
    int findPeakElement(vector<int>& nums) { // Time: O(log n), Space: O(1)
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;

            bool is_left_ok  = (mid == 0) ? true : (nums[mid] > nums[mid - 1]);
            bool is_right_ok = (mid == nums.size() - 1) ? true : (nums[mid] > nums[mid + 1]);

            if (is_left_ok && is_right_ok) return mid;
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
                i = mid + 1;
            else
                j = mid - 1;
        }
        return -1; 
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) { // Time: O(log n), Space: O(1)
        int n = nums.size(); 
        if (n == 1) return 0; 
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int i = 1, j = n - 2; //alredy checked the first and last elements
        // we can safely assume nums[i] and nums[j] are not the peak elements
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if (nums[mid] < nums[mid + 1])
                i = mid + 1;
            else
                j = mid - 1;
        }
        return -1; 
    }
};
