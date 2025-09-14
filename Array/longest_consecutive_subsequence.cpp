// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// optimal approach using unordered_set

class Solution {
public:
    int longestConsecutive(vector<int>& arr) { // Time: O(N), Space: O(N)
        unordered_set<int> s(arr.begin(), arr.end());  
        int maxSeq = 0;

        for (int num : s) { 
            if (s.find(num - 1) == s.end()) { 
                int currNum = num;
                int currSeq = 1;

                while (s.find(currNum + 1) != s.end()) {
                    currNum++;
                    currSeq++;
                }
                maxSeq = max(maxSeq, currSeq);
            }
        }
        
        return maxSeq;
    }
};


// for brute force approach - sort the array and then find the longest consecutive subsequence
// Time: O(N log N), Space: O(1)