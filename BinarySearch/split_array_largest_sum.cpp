// https://leetcode.com/problems/split-array-largest-sum?envType=problem-list-v2&envId=binary-search
// n is size of arr, k is number of subarrays
// binary search on answer

class Solution {
public:
    bool is_possible(vector<int>& arr, int k, int mid) { // Time: O(n), Space: O(1)
        int subarray_sum_count = 0, subarray_count = 1;

        for(int x : arr) {
            if(x > mid) return false;

            if(subarray_sum_count + x > mid) {
                subarray_count++;
                subarray_sum_count = x;
            }else subarray_sum_count += x;
        }

        if(subarray_count <= k) return true;
        return false;
    }
    int splitArray(vector<int>& arr, int k) { // Time: O(n log(sum(arr) - max(arr))), Space: O(1)
        if(arr.size() < k) return -1;
        int i = INT_MIN, j = 0, ans = -1;

        for(int x : arr) {
            i = max(i, x);
            j += x; 
        }

        while(i <= j) {
            int mid = i + (j - i) / 2;
            
            if(is_possible(arr, k, mid)) {
                ans = mid;
                j = mid - 1;
            }else i = mid + 1;
        }
        return ans;
    }
};
// here we have to find the minimum maximum sum of subarrays such that k subarrays can be formed
// Note: observation:
// If we can split the array into k subarrays with a maximum sum of mid, then we can also split it with a maximum sum greater than mid.
// Since we want to minimize the maximum sum, we discard the right half of the search space and search in the left half.