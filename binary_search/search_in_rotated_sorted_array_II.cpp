// https://leetcode.com/problems/search-in-rotated-sorted-array-ii
// n is the length of nums
class Solution {
public:
    bool search(vector<int>& nums, int target) { // Time: O(log n), Space: O(1)
        int i = 0, j = nums.size() - 1;

        while(i <= j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] == target) return true;
            if(nums[i] == nums[mid] && nums[j] == nums[mid]){
                i++;
                j--;
            }

            else if(nums[i] <= nums[mid]){ // left sorted
                if(nums[i] <= target && nums[mid] >= target) j = mid - 1;
                else i = mid + 1;
            } else{ // right sorted
                if(nums[mid] <= target && nums[j] >= target) i = mid + 1;
                else j = mid - 1;
            }
        }
        return false;
    }
};