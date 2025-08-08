// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets?envType=problem-list-v2&envId=binary-search
// m is the number of bouquets we want to make, k is the number of flowers in each bouquet, and arr is the array of flower bloom days.
class Solution {
public:
    int is_possible(vector<int>& arr, int m, int k, int mid) { // Time: O(n), Space: O(1)
        int flowers_count = 0, bouquets_count = 0;
        for (int x : arr) {
            if (x <= mid) {
                flowers_count++;
                if (flowers_count == k) {
                    bouquets_count++;
                    flowers_count = 0;
                    if (bouquets_count >= m) return bouquets_count;
                }
            } else {
                flowers_count = 0;
            }
        }
        return bouquets_count;
    }

    int minDays(vector<int>& arr, int m, int k) { // Time: O(n * log(max(arr)) - log(min(arr))), Space: O(1)
        int ans = -1, n = arr.size();
        long long total_flower_required = 1LL * m * k;
        if (n < total_flower_required) return -1;

        int i = arr[0], j = arr[0];
        for (int x : arr) {
            i = min(x, i);
            j = max(x, j);
        }

        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (is_possible(arr, m, k, mid) >= m) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};
