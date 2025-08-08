// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold?envType=problem-list-v2&envId=binary-search
// n is the size of nums and thr is the threshold value
class Solution {
public:
    bool find_sum(const vector<int>& nums, int mid, int thr) { // Time: O(n), Space: O(1)
        int sum = 0;
        for(int i : nums) {
            sum += (i + mid - 1) / mid;
            if(sum > thr) return false;
        }
        return sum <= thr;
    }
    int smallestDivisor(vector<int>& nums, int thr) { // Time: O(n * log(max(nums))), Space: O(1)
        int i = 1, ans = -1, j = *max_element(nums.begin(), nums.end());

        while(i <= j) {
            int mid = i + (j - i) / 2;
            if(find_sum(nums, mid, thr)) {
                ans = mid;
                j = mid - 1;
            }else i = mid + 1;
        }
        return ans;
    }
};