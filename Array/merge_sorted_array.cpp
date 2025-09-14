//https://leetcode.com/problems/merge-sorted-array?envType=study-plan-v2&envId=top-interview-150
// m = size of nums1 excluding the extra space
// n = size of nums2

// using extra space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // Time O(m+n) Space O(m+n)
        vector<int> merged(m + n);
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) merged[k++] = nums1[i++];
            else merged[k++] = nums2[j++];
        }

        while (i < m) {
            merged[k++] = nums1[i++];
        }

        while (j < n) {
            merged[k++] = nums2[j++];
        }

        nums1 = merged;
    }  
};

// without using extra space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // time O(m+n) space O(1)
        int i = m -1;
        int j = n -1;
        int k = m + n - 1;

        while (i >=0 && j >= 0){
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }

        while (j >=0) {
            nums1[k--] = nums2[j--];
        }
    }  
};
