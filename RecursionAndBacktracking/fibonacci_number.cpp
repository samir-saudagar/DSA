// https://leetcode.com/problems/fibonacci-number?envType=problem-list-v2&envId=recursion

// Recursive approach
class Solution {
public:
    int fib(int n) { // Time: O(2^n), Space: O(n)
        if(n <= 1) return 0;
        if(n == 1) return 1;

        return fib(n - 1) + fib(n - 2); 
    }
};

// Dynamic programming approach(Memoization - Top Down)
class Solution {
public:
    int fib(int n) { // Time: O(n), Space: O(n)
        vector<int> memo(n + 1, -1); 
        return fibMemo(n, memo);
    }

    int fibMemo(int n, vector<int>& memo) { // Time: O(n), Space: O(n)
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo[n] != -1) return memo[n]; 

        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
        return memo[n];
    }
};

// Dynamic programming approach(Tabulation - Bottom Up)
class Solution {
public:
    int fib(int n) { // Time: O(n), Space: O(n)
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Iterative approach
class Solution {
public:
    int fib(int n) { // Time: O(n), Space: O(1)
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int sum = a + b;
            a = b;
            b = sum;
        }
        return b;
    }
};

