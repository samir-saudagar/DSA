// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days?envType=problem-list-v2&envId=binary-search
// n is the size of arr and days is the number of days within which we want to ship the packages
class Solution {
public:
    bool is_possible(const vector<int>& arr, int days, int mid) { // Time: O(n), Space: O(1)
        int day_count = 1, sum = 0;

        for(int w : arr) {
            if (w > mid) return false;
            if(sum + w > mid){
                day_count++;
                sum = w;
            }else sum += w;
        }
        return day_count <= days;
    }
    int shipWithinDays(vector<int>& arr, int days) { // Time: O(n * log(sum(arr) - max(arr) + 1)), Space: O(1)
        int i = 1, j = 0, ans = -1; 
        for(int w : arr) {
            i = max(i, w);
            j += w;
        }

        while(i <= j) {
            int mid = i + (j - i) / 2;
            if(is_possible(arr, days, mid)) {
                ans = mid;
                j = mid - 1;
            }else i = mid + 1;
            
        }
        return ans;
    }
};