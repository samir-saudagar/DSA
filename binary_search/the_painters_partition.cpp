// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// n is the number of boards and k is the number of painters.
// binary search on answer
class Solution {
public:
    bool is_possible(vector<int>& arr, int k, int mid) { // Time: O(n), Space: O(1)
        int subarray_sum_count = 0, painter_count = 1;

        for(int x : arr) {
            if(x > mid) return false;

            if(subarray_sum_count + x > mid) {
                painter_count++;
                subarray_sum_count = x;
            }else subarray_sum_count += x;
        }

        if(painter_count <= k) return true;
        return false;
    }
    int minTime(vector<int>& arr, int k) { // Time: O(n log(sum(arr) - max(arr))), Space: O(1)
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

// here we to find the minimum time required to paint all boards such that k painters can be used
// Note: observation:
// If we can paint all boards with a maximum time of mid, then we can also paint them with a maximum time greater than mid.
// Since we want to minimize the maximum time, we discard the right half of the search space and search in the left half.