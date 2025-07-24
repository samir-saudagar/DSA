//https://leetcode.com/problems/zigzag-conversion/submissions/1706098592

// n = length of string s
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) { // Time Complexity: O(n), Space Complexity: O(n)
        if (numRows == 1 || numRows >= s.length()) return s;

        vector<string> rows(numRows);
        int row = 0;
        bool goingDown = false;

        for (const char &c : s) {
            rows[row] += c;
            if (row == 0 || row == numRows - 1)
                goingDown = !goingDown;
            row += goingDown ? 1 : -1;
        }

        string result;
        result.reserve(s.size());  
        for (const string &r : rows)
            result += r;

        return result;
    }
};
