// https://leetcode.com/problems/koko-eating-bananas?envType=problem-list-v2&envId=binary-search
// n is the number of piles and h is the number of hours Koko has to eat all bananas.
class Solution {
public:
    long long find_rate(const vector<int>& arr, int mid) { // Time: O(n), Space: O(1)
        long long result = 0;
        for (int i : arr) {
            result += (i + mid - 1) / mid;
        }
        return result;
    }

    int minEatingSpeed(vector<int>& arr, int h) { // Time: O(n * log(max(piles))), Space: O(1)
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (find_rate(arr, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
