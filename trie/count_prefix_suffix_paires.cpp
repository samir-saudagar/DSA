//https://leetcode.com/problems/count-prefix-and-suffix-pairs-i?envType=problem-list-v2&envId=trie

// n = number of words, m = length of longest word
// method 1
#include <bits/stdc++.h>
class Solution {
public:
    bool isPrefixAndSuffix(string &small, string &large) {  //Time Complexity: O(n^2 * m), Space Complexity: O(n.m)
        int n = small.length(), m = large.length();

        if(n > m) return false;

        return large.substr(0, n) == small && large.substr(m-n, n) == small;
    }
    int countPrefixSuffixPairs(vector<string>& words) {

        int count = 0;
        int n = words.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j< n; j++) {
                if(isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};

// method 2
#include <bits/stdc++.h>
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) { // Time Complexity: O(n^2 * m), Space Complexity: O(n.m)
        int count = 0;
        int n = words.size();
        for(int i = 0; i<n; i++){
            string small = words[i];
            for(int j = i+1; j< n; j++) {
                string large = words[j];
                if(large.starts_with(small) && large.ends_with(small)) count++;
            }
        }
        return count;
    }
};
