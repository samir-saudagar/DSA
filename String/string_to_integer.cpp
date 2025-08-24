//https://leetcode.com/problems/string-to-integer-atoi?envType=problem-list-v2&envId=string

// iterative solution
class Solution {
public:
    int myAtoi(string s) { // Time: O(n), Space: O(1)
        int i = 0, n = s.size();
        int sign = 1;
        int res = 0;

        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if(res > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * sign;
    }
};

// recursive solution

class Solution {
public:
    int atoi(int i, string s, int n, int sign, int res) { // Time: O(n), Space: O(n)
        if(i >= n || !isdigit(s[i])) {
            return res * sign;
        }

        int digit = s[i] - '0';

        if(res > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        return atoi(i + 1, s, n, sign, res * 10 + digit);
    }
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;

        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        return atoi(i, s, n, sign, 0);
    }
};