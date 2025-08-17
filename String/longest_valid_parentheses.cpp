//https://leetcode.com/problems/longest-valid-parentheses?envType=problem-list-v2&envId=string
// n = length of string s

// stack based approach
class Solution {
public:
    int longestValidParentheses(string s) { // time: O(n), space: O(n)
        int maxLen = 0;
        stack<int> st;
        st.emplace(-1);  

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.emplace(i);
            } else {
                st.pop();
                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top());
                } else {
                    st.emplace(i);  
                }
            }
        }

        return maxLen;
    }
};

// dp(bottom up) based approach
class Solution {
public:
    int longestValidParentheses(string s) { // Time: O(n), Space: O(n)
        int n = s.size();
        vector<int> dp(n, 0);
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] - 2 >= 0) {
                        dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};
