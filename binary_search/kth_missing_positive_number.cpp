// https://leetcode.com/problems/kth-missing-positive-number?envType=problem-list-v2&envId=binary-search
// n is size of arr
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { // Time: O(log n), Space: O(1)
        int i = 0, j = arr.size() - 1;

        while(i <= j) {
            int mid = i + (j - i) / 2;
            int missing_count = arr[mid] - (mid + 1);
            if(missing_count >= k) j = mid -1;
            else i = mid + 1;
        }
        return i + k;
    }
};

//Note: obervation:
// The number of missing positive integers before the mid index is equal to arr[mid] - (mid + 1)
// If the number of missing integers is greater than or equal to k, we need to search in the left half.
// If the number of missing integers is less than k, we need to search in the right half.
// Finally, the kth missing positive integer is at index i + k.
