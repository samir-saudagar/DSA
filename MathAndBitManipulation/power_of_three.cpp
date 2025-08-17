// https://leetcode.com/problems/power-of-three
// log is base 3
// recursion based approach
class Solution {
public:
    bool isPowerOfThree(int n) { // Time: O(log n), Space: O(log n) due to recursion stack 
        if(n == 1) return true;
        if(n <= 0 || n % 3 != 0) return false;

        return isPowerOfThree(n / 3);
    }
};

// iterative based approach
class Solution {
public:
    bool isPowerOfThree(int n) { // Time: O(log n), Space: O(1)
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

