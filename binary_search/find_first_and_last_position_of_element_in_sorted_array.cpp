// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array?envType=problem-list-v2&envId=binary-search
// n is the length of nums
//methos - I - using lower_bound and upper_bound functions
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) { // Time: O(log n), Space: O(1)
        int i = 0, j = nums.size() - 1;
        int ans = nums.size();
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target) {
                ans = mid; 
                j = mid - 1; 
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }

    int upper_bound(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int ans = nums.size(); 
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > target) {
                ans = mid; 
                j = mid - 1;
            } else {
                i = mid + 1; 
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums, target);
        if(lb == nums.size() || nums[lb] != target) return {-1, -1};
        return {lb, upper_bound(nums, target) - 1}; 
    }
};

//method - II - using two binary search functions
class Solution {
public:
    int first_ocurrence(vector<int>& nums, int target) { // Time: O(log n), Space: O(1)
        int i = 0, j = nums.size() - 1;
        int first = -1;
        while(i <= j ){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target) {
                first = mid;
                j = mid - 1;
            }else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return first;
    }

    int last_ocurrence(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int last = -1;
        while(i <= j ){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target) {
                last = mid;
                i = mid + 1;
            }else if(nums[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_ocurrence(nums, target);
        if(first == -1) return {-1, -1};
        return {first, last_ocurrence(nums, target)};
    }
};

//note : if they askto count the number of occurrences of target in the array, you can use the formula
// count = last_ocurrence - first_ocurrence + 1 