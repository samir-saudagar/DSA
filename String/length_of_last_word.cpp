//https://leetcode.com/problems/length-of-last-word?envType=problem-list-v2&envId=string
// n is the length of the string

class Solution {
public:
    int lengthOfLastWord(string s) { // O(n) time, O(1) space
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                count++;
            } else if (count > 0) {
                break;
            }
        }
        return count;
    }
};
