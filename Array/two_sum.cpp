// https://leetcode.com/problems/two-sum?envType=problem-list-v2&envId=array

// n is the size of the input array

// using unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { // Time: O(n), Space: O(n)
        unordered_map<int, int> map; 
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int comp = target - nums[i];

            if (map.count(comp)) return {map[comp], i};

            map[nums[i]] = i;
        }

        return {};
    }
};

// using two pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { // Time: O(n log n), Space: O(n)
        int n = nums.size();
        vector<pair<int, int>> arr; 

        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end()); 

        int left = 0, right = n - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) return {arr[left].second, arr[right].second};
            else if (sum < target) left++;
            else right--;
        }

        return {};
    }
};