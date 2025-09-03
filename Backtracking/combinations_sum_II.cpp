// https://leetcode.com/problems/combination-sum-ii?envType=problem-list-v2&envId=backtracking


// n is the size of arr
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp,
                   const vector<int> &arr, vector<bool> &visited,
                   int target, int start) { // Time: O(2^n * n), Space: O(n)

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < arr.size(); i++) {
            if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) continue;

            if (arr[i] > target) break;

            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(arr[i]);

                backtrack(ans, temp, arr, visited, target - arr[i], i + 1);

                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) { // Time: O(2^n * n), Space: O(n)
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(arr.size(), false);

        sort(arr.begin(), arr.end()); 

        backtrack(ans, temp, arr, visited, target, 0);

        return ans;
    }
};
