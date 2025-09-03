// https://leetcode.com/problems/generate-parentheses?envType=problem-list-v2&envId=backtracking

// n is the number of pairs of parentheses
class Solution {
public:
    void backtrack(vector<string> &ans, string &temp, int n, int a, int b, int k) { // Time: O(4^n / sqrt(n)), Space: O(n)
        if (k == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (a < n) {
            temp[k] = '(';
            backtrack(ans, temp, n, a + 1, b, k + 1);
        }

        if (b < a) {
            temp[k] = ')';
            backtrack(ans, temp, n, a, b + 1, k + 1);
        }
    }

    vector<string> generateParenthesis(int n) { // Time: O(4^n / sqrt(n)), Space: O(n)
        vector<string> ans;
        string temp(n * 2, ' ');

        backtrack(ans, temp, n, 0, 0, 0);
        return ans;
    }
};

// Another implementation
class Solution {
public:
    void backtrack(vector<string> &ans, string &temp, int open, int close, int n) { // Time: O(4^n / sqrt(n)), Space: O(n)
        if (temp.size() == n * 2) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            temp.push_back('(');
            backtrack(ans, temp, open + 1, close, n);
            temp.pop_back(); // backtrack
        }

        if (close < open) {
            temp.push_back(')');
            backtrack(ans, temp, open, close + 1, n);
            temp.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        backtrack(ans, temp, 0, 0, n);
        return ans;
    }
};

// The number of valid strings = n-th Catalan number:
// cn = (1 / (n + 1)) * (2n choose n) = (2n)! / ((n + 1)! * n!)
// cn ~ 4^n / (n^(3/2) * sqrt(pi))
// Each string has length 2n.
// To build each string, we spend O(2n) = O(n) time.
// So the time complexity is O(n * 4^n / (n^(3/2) * sqrt(pi))) = O(4^n / sqrt(n))
// Auxiliary recursion depth: O(n) (max stack depth).
// Result storage: O(C_n * n) for all strings.
// Overall space complexity: O(n) (ignoring the result storage).