// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros?envType=problem-list-v2&envId=backtracking

// n is the length of the binary strings to be generated
class Solution {
public:
    bool isPossible(const string &temp, int n) { // Time: O(n), Space: O(1)
        for (int i = 1; i < n; i++) {
            if (temp[i] == temp[i - 1] && temp[i] == '0') {
                return false;
            }
        }
        return true;
    }
    
    void backtrack(vector<string> &ans, int n, int k, string &temp) { // Time: O(2^n * n), Space: O(n)
        if (k == n) {
            if (isPossible(temp, n)) {
                ans.push_back(temp);
            }
            return;
        }
        
        temp[k] = '0';
        backtrack(ans, n, k + 1, temp);
        
        temp[k] = '1';
        backtrack(ans, n, k + 1, temp);
    }

    vector<string> validStrings(int n) { // Time: O(2^n * n), Space: O(n)
        vector<string> ans;
        string temp(n, '0');   
        backtrack(ans, n, 0, temp);
        return ans;
    }
};
