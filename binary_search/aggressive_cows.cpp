// https://www.geeksforgeeks.org/problems/aggressive-cows/1
// n is size of arr, k is number of cows, m is the maximum distance between cows(arr[n - 1] - arr[0])
class Solution {
  public:
    bool is_possible(const vector<int>& arr, int k, int n, int mid) { // Time: O(n), Space: O(1)
        int placed_cow_count = 1;
        int last_placed_cow_position = 0;
        
        for(int i = 1; i < n; i ++) {
            if(arr[i] - arr[last_placed_cow_position] >= mid) {
                placed_cow_count++;
                last_placed_cow_position = i;
            }
        }
    
        if(placed_cow_count >= k) return true;
        return false;
    }
    
    int aggressiveCows(vector<int>& arr, int k) { // Time: O(n log m), Space: O(1)
        int n = arr.size(), ans = -1;
        
        sort(arr.begin(), arr.end());
        
        int i = 1, j = arr[n - 1] - arr[0];
        
        while(i <= j) {
            int mid = i + (j - i) / 2;
            if(is_possible(arr, k, n, mid)) {
                ans = mid;    
                i = mid + 1;
            }
            else j= mid - 1;
        }
        return ans;
    }
};

// here we have to find the maximum minimum distance between cows such that k cows can be placed in the stalls
// Note: observation:
// If we can place k cows with a minimum distance of mid, then we can also place k cows with a minimum distance less than mid
// so we can discard the left half of the search space and search in the right half 