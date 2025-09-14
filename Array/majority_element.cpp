// https://leetcode.com/problems/majority-element?envType=problem-list-v2&envId=array

// unordered_map approach
class Solution {
public:
    int majorityElement(vector<int>& nums) { // Time: O(n), Space: O(n)
        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        for (auto it : mp) {
            if (it.second > nums.size()/2) return it.first;
        }

        return 0;
    }
};

// you can use sorting to solve this problem
// use sort function and then return nums[nums.size() / 2];

// optimized approach (moore voting algorithm)

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) { // Time: O(n), Space: O(1)
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
