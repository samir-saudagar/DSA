// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) { // Time: O(n), Space: O(n)
        unordered_map<int, int> prefixSumIndex;
        int sum = 0, maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                maxLength = i + 1; 
            }

            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[sum - k]);
            }

            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLength;
    }
};
