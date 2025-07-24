//https://leetcode.com/problems/valid-number?envType=problem-list-v2&envId=string
// n is the length of the string
class Solution {
public:
    //digits,minus/plus,dot,e/E
    bool isNumber(string s) { // O(n) time, O(1) space
        bool digit_seen = false;
        int plus_minus_count = 0;
        bool dot_seen = false;
        bool eE_seen = false;
        int n = s.length();
        if(!s.length()) return false;

        for (int i = 0; i < n; i++) {

            if(isdigit(s[i])) digit_seen = true;
            else if(s[i] == '+' || s[i] == '-') {
                if(plus_minus_count > 2) return false;
                if(i > 0 && !(s[i - 1] == 'e' || s[i - 1] == 'E')) return false;
                if(i == n - 1) return false;
                if(s[i + 1] == '+' || s[i + 1] == '-') return false;
                plus_minus_count++;
            } else if(s[i] == '.') {
                if(eE_seen || dot_seen) return false;
                if( i == n - 1 && !digit_seen) return false;
                dot_seen = true;
            } else if(s[i] == 'e' || s[i] == 'E') {
                if(eE_seen || !digit_seen || i == n - 1) return false;
                eE_seen = true;
            } else {
                return false;
            }
        }
        return digit_seen;
    }
};