// https://leetcode.com/problems/majority-element-ii?envType=problem-list-v2&envId=array

// using unordered_map

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { // Time: O(n), Space: O(n)
        unordered_map<int, int> mp;
        vector<int> ans;

        int n = nums.size();
        for (int num : nums) 
            mp[num]++;

        for (auto it : mp) 
            if (it.second > n / 3) 
                ans.push_back(it.first);

        return ans;
    }
};

// optimized approach (moore voting algorithm)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { // Time: O(n), Space: O(1)
        int n = nums.size(); 
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        
        for (int num : nums) {
            if (cand1 == num) cnt1++;
            else if (cand2 == num) cnt2++;
            else if (cnt1 == 0) {
                cand1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                cand2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
        }

        if (cnt1 > n / 3 && cnt2 > n / 3) return {cand1, cand2};
        else if (cnt1 > n / 3) return {cand1};
        else if (cnt2 > n / 3) return {cand2};

        return {};
    }
};