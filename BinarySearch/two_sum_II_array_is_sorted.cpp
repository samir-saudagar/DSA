// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted?envType=problem-list-v2&envId=binary-search
// n is the size of the input array
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { // Time: O(n), Space: O(1)
        int i = 0, j = numbers.size() - 1;
        
        while(i <= j){
            if(numbers[i] + numbers[j] == target) return {i + 1, j + 1};
            else if(numbers[i] + numbers[j] > target) j--;
            else i++;
        }
        return {};
    }
};

// we can also use binary search to find the second number but it will take O(n log n) time
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { // Time: O(n log n), Space: O(1)
        int n = numbers.size(); 

        for (int i = 0; i < n - 1; ++i) {
            int left = i + 1;
            int right = n - 1;
            int complement = target - numbers[i];

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < complement) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return {};
    }
};
