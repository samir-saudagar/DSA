// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// optimized approach: traverse from right to left and keep track of current leader
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) { // Time: O(n) Space: O(1)
        vector<int> ans;
        int currLeader = INT_MIN;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] >= currLeader) {
                ans.insert(ans.begin(), arr[i]);
                currLeader = arr[i];
            }
        }
        
        
        return ans;
    }
};

// brute force approach: for each element check if there is any greater element on right side