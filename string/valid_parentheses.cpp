//https://leetcode.com/problems/valid-parentheses?envType=problem-list-v2&envId=string

//n = length of string s 
class Solution {
public:
    bool isValid(string s) { // time: O(n), space: O(n)
        stack<char> st;
        if (s.length() % 2 != 0) return false;
        for (char &ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
