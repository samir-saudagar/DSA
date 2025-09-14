// https://leetcode.com/problems/3sum?envType=problem-list-v2&envId=array

// n is the size of the input array

// optimized approach using sorting and two-pointer technique
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // Time: O(n^2), Space: O(1)
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r]; 
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if(sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return ans;
    }
};

// using set and sorting the triplets before inserting into the set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // Time: O(n^2 log n), Space: O(n)
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> m;
            for (int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]);
                if (m.find(third) != m.end()) {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());
                    s.insert(triplet);
                }
                m.insert(nums[j]);
            }
        }

        for (auto triplet : s) {
            ans.push_back(triplet);
        }

        return ans;
    }
};

// for brute force approach use three nested loops and a set to avoid duplicates
// Time: O(n^3), Space: O(n)
