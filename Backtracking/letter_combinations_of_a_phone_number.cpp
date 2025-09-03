// https://leetcode.com/problems/letter-combinations-of-a-phone-number?envType=problem-list-v2&envId=backtracking

// n is the length of digits
class Solution {
public:
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(vector<string> &ans, const string digits, string &temp, int i) { // Time: O(4^n), Space: O(n)
        if (i == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mapping[digits[i] - '0'];

        for (int k = 0; k < letters.size(); k++) {
            temp.push_back(letters[k]);
            backtrack(ans, digits, temp, i + 1);
            temp.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) { // Time: O(4^n), Space: O(n)
        vector<string> ans;
        string temp;


        if (digits.empty()) {
            return ans;
        }

        backtrack(ans, digits, temp, 0);

        return ans;
    }
};




