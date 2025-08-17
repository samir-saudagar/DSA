// https://leetcode.com/problems/two-sum
// n is the size of the input array
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
