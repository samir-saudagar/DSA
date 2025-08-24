// https://leetcode.com/problems/count-good-numbers?envType=problem-list-v2&envId=recursion

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp);
    int countGoodNumbers(long long n) { // Time: O(log n), Space: O(log n)
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        long long res1 = modPow(5, evenCount);
        long long res2 = modPow(4, oddCount);

        return (res1 * res2) % MOD;
    }
};

long long Solution ::modPow(long long base, long long exp) { // Time: O(log exp), Space: O(log exp)
    if(exp == 0) return 1;

    long long half = modPow(base, exp / 2);
    half = (half * half) % MOD;
    if(exp % 2 == 0) return half;
    else return (half * base) % MOD;
}

// iterative approach
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) { // Time: O(log exp), Space: O(1)
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) { // Time: O(log n), Space: O(1)
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        long long res1 = modPow(5, evenCount);
        long long res2 = modPow(4, oddCount);

        return (res1 * res2) % MOD;
    }
};
