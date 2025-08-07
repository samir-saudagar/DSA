// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
// n is the degree of the root and m is the number for which we want to find the nth root.
class Solution {
  public:
    long long power(long long base, int exp, int m) { // Time: O(n), Space: O(1)
        long long result = 1;
        for (int i = 0; i < exp; ++i) {
            result *= base;
            if (result > m) return result;
        }
        return result;
    }

    int nthRoot(int n, int m) { // Time: O(n * log m), Space: O(1)
        if (m == 0 || m == 1) return m;

        int low = 1, high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = power(mid, n, m);
            
            if (val == m) return mid;
            else if (val < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1; 
    }
};
