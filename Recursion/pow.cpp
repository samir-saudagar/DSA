// https://leetcode.com/problems/powx-n?envType=problem-list-v2&envId=recursion

// iterative approach
class Solution {
public:
    double myPow(double x, int n) { // Time: O(log n), Space: O(1)
        long long exp = n;
        double ans = 1.0;

        if (n < 0) {
            x = 1 / x;
            exp = -exp;
        }

        while(exp > 0) {
            if(exp % 2) {
                ans *= x;
            }
            x *= x;
            exp /= 2;
        }
        return ans;
    }
};

// recursive approach
class Solution {
public:
    double powRec(double base, long long exp) { // Time: O(log exp), Space: O(log exp) due to recursion stack
        if (exp == 0) {
            return 1;
        }

        if (exp < 0) {
            return powRec(1 / base, -exp);
        }

        double half = powRec(base, exp / 2);

        if (exp % 2) {
            return half * half * base;
        } else {
            return half * half;
        }
    }

    double myPow(double x, int n) { // Time: O(log n), Space: O(log n)
        return powRec(x, (long long)n);
    }
};
