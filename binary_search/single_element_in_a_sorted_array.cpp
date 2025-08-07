// https://leetcode.com/problems/single-element-in-a-sorted-array?envType=problem-list-v2&envId=binary-search
// n is size of nums

// we can use two approaches to solve this problem but it not necessary as we can it using one pointer approach as well.
// method 1: One Pointer approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // Time: O(n), Space: O(1)
        int n = nums.size();
        int i = 0;
        
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 2] != nums[n - 1]) return nums[n - 1];

        while(i < n - 1){
            if(nums[i] != nums[i + 1]) return nums[i];
            i += 2;
        }
        return 0;
    }
};

// method 2: Binary Search approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // Time: O(log n), Space: O(1)
        int n = nums.size();
        int i = 0, j = n - 1;
        
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 2] != nums[n - 1]) return nums[n - 1];

        while(i <= j){
            int mid = i + (j - i) / 2;
            if(mid % 2 == 1) mid--;
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) return nums[mid];
            else if(nums[mid] == nums[mid + 1]) i = mid + 2;
            else j = mid - 2;

        }
        return 0;
    }
};

// method 3: one pointer approach with XOR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // Time: O(n), Space: O(1)
        int n = nums.size();
        int i = 0;
        
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 2] != nums[n - 1]) return nums[n - 1];

        while(i < n - 1){
            if(nums[i] ^ nums[i + 1]) return nums[i];
            i += 2;
        }
        return 0;
    }
};

//In this question we are given sorted aray hence binary search is the best approach to find the single element in O(log n) time complexity.
//when array is not sorted but element present in pairs then can use one/two pointer approach to find the single element in O(n) time complexity.
//when array is not sorted and element is not present in pairs then can use XOR approach to find the single element in O(n) time complexity.
// Note: XOR work with all type of input but it is not necessary that it will work with all type of output. It is best to use XOR when we have pairs of elements and one element is not present in pair.
// XOR is a bitwise operator that returns 1 if the bits are different and 0 if they are the same. It is useful for finding unique elements in a collection where every other element appears in pairs.
// Example: 1 ^ 1 = 0, 1 ^ 0 = 1, 0 ^ 0 = 0