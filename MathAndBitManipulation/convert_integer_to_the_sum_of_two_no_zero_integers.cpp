// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

class Solution {
public:
    bool isPossible(int a, int b) { // Time: O(log n), Space: O(1)
        while (a > 0) {
            int d = a % 10;
            if (d == 0) return false;
            a = a / 10;
        }

        while (b > 0) {
            int d = b % 10;
            if (d == 0) return false;
            b = b / 10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) { // Time: O(n log n), Space: O(1)
        for (int i = 1; i <= n / 2; i++) {
            if (isPossible(i, n - i)) return {i, n - i};
        }

        return {};
    }
};