// https://leetcode.com/problems/valid-palindrome
// recursive approach
class Solution {
public:
    bool isPalindromeCheck(int i, string& str, int n) { // Time: O(n), Space: O(n)
        if (i >= n / 2) return true;
        if (str[i] != str[n - i - 1]) return false;
        return isPalindromeCheck(i + 1, str, n); 
    }

    bool isPalindrome(string s) { // Time: O(n), Space: O(n)
        string str;
        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }
        int n = str.size(); 
        return isPalindromeCheck(0, str, n);
    }
};

// iterative approach
class Solution {
public:
    bool isPalindromeCheck(int i, string& str, int n) { // Time: O(n), Space: O(1)
        while (i < n / 2) {
            if (str[i] != str[n - i - 1]) return false;
            i++;
        }
        return true; 
    }

    bool isPalindrome(string s) { // Time: O(n), Space: O(n)
        string str;
        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }
        int n = str.size(); 
        return isPalindromeCheck(0, str, n);
    }
};
