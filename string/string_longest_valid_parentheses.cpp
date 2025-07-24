//https://leetcode.com/problems/longest-valid-parentheses?envType=problem-list-v2&envId=string
// n = length of string s
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
