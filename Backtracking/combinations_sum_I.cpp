// https://leetcode.com/problems/combination-sum?envType=problem-list-v2&envId=backtracking

// n is the size of arr
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, const vector<int> &arr, int target, int i) { // Time: O(n ^ (target / min(arr))), Space: O(target / min(arr))
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < arr.size(); j++) {
            if (arr[j] > target) {
                return;
            }

            temp.push_back(arr[j]);
            backtrack(ans, temp, arr, target - arr[j], j);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int target) { // Time: O(n ^ (target / min(arr))), Space: O(target / min(arr))
        vector<vector<int>> ans;
        vector<int> temp;

        sort(arr.begin(), arr.end());

        backtrack(ans, temp, arr, target, 0);

        return ans;

    }
};