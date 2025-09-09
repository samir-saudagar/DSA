// https://leetcode.com/problems/palindrome-partitioning?envType=problem-list-v2&envId=backtracking

// n is the length of the string s
// using backtracking only
class Solution {
public:
    bool isPalindrome(const string& s) { // Time: O(n), Space: O(1)
    if (s.length() <= 1) {
        return true;
    }

    return equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());

    }

    void backtrack(const string &s, vector<string> &temp, vector<vector<string>> &ans) { // Time: O(n * 2^n), Space: O(n)
        if (s.size() == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (isPalindrome(s.substr(0, i + 1))) {
                temp.push_back(s.substr(0, i + 1));
                backtrack(s.substr(i + 1), temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) { // Time: O(n * 2^n), Space: O(n)
        vector<vector<string>> ans;
        vector<string> temp;

        backtrack(s, temp, ans);

        return ans;
    }
};


// Optimized version using DP to precompute palindromic substrings
class Solution {
public:
    void backtrack(const string &s, int start, vector<string> &temp, 
                   vector<vector<string>> &ans, vector<vector<bool>> &isPal) { // Time: O(n * 2^n), Space: O(n)
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPal[start][end]) {
                temp.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, temp, ans, isPal);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) { // Time: O(n * 2^n), Space: O(n^2)
        int n = s.size(); 
        vector<vector<string>> ans;
        vector<string> temp;

        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        backtrack(s, 0, temp, ans, isPal);
        return ans;
    }
};