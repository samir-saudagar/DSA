// https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1

class Solution {
  public:
    bool  backtrack(int n, const vector<int> &arr, int target, int i) { // Time: O(n * 2^n), Space: O(n)
        if (target == 0) return true;
        
        if (target < 0 || i == arr.size()) return false;
        
        for (int j = i; j < n; j++) {
            if (arr[j] > target) return false;
            
            if (backtrack(n, arr, target - arr[j], j + 1)) return true;
        }
        
        return false;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) { // Time: O(n * 2^n), Space: O(n)
        
        sort(arr.begin(), arr.end());
        
        if (backtrack(n, arr, k, 0)) {
            return true;
        }
        
        return false;
    }
};