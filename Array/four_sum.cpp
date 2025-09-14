// https://leetcode.com/problems/4sum?envType=problem-list-v2&envId=array 

//  n is the size of the input array

// optimized approach using two pointers and sorting
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { // Time: O(n^3) Space: O(1)
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;

                while(l < r) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[l];
                    sum += nums[r];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    } else if (sum < target) l++;
                    else r--;
                }
            }
        }

        return ans;
    }
};

// using set and sorting the quadruplets before inserting into the set
class Solution {
public: 
    vector<vector<int>> fourSum(vector<int>& nums, int target) { // Time: O(n^3 log n), Space: O(n)
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                unordered_set<long long> m;
                for (int k = j + 1; k < nums.size(); k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if (m.find(fourth) != m.end()) {
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(quadruplet.begin(), quadruplet.end());
                        s.insert(quadruplet);
                    }
                    m.insert(nums[k]);
                }
            }
        }

        for (auto quadruplet : s) {
            ans.push_back(quadruplet);
        }

        return ans;
    }
};