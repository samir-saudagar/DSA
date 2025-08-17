// imp problem
// https://leetcode.com/problems/median-of-two-sorted-arrays?envType=problem-list-v2&envId=binary-search
// m = size of nums1, n = size of nums2

// brute force approach
// this solution merges the two sorted arrays and then finds the median but it is not optimal as it takes O(m + n) time and O(m + n) space
// but we asked for O(log(min(m, n))) time and O(1) space
// so we will use binary search to find the median in O(log(min(m, n)))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { // Time: O(m + n), Space: O(m + n)
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        while (i < nums1.size()) merged.push_back(nums1[i++]);
        while (j < nums2.size()) merged.push_back(nums2[j++]);

        int n = merged.size();
        if (n % 2 == 0) return (merged[n/2] + merged[n/2 - 1]) / 2.0;
        return merged[n/2];
    }
};

// optimized approach using binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { // Time: O(log(min(m, n))), Space: O(1)
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int i = 0, j = n1; 

        while (i <= j) {
            int mid1 = i + (j - i) / 2;
            int mid2 = n / 2 - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;  
                else return min(r1, r2);        
            } 
            else if (l1 > r2) j = mid1 - 1;
            else  i = mid1 + 1;
        }
        return 0.0;    
    }
};


