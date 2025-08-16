// https://leetcode.com/problems/power-of-two?envType=problem-list-v2&envId=bit-manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) { // Time: O(1), Space: O(1)
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

// Note observation: for positive number n, if n is a power of two, then it has exactly one bit set in its binary representation.
// so n & (n - 1) will be zero.
// Example:
// n = 4 (100 in binary), n - 1 = 3 (011 in binary)
// 4 & 3 = 100 & 011 = 000 (which is zero)