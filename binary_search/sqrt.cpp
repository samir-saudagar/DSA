// https://leetcode.com/problems/sqrtx?envType=problem-list-v2&envId=binary-search
// x is a non-negative integer
class Solution {
public:
    int mySqrt(int x) { // Time: O(log x), Space: O(1)
        if(!x) return 0;
        int i = 1, j = x;
        while(i <= j) {
            int mid = i + (j - i) / 2;

            if((long long)mid * mid == x) return mid;
            else if((long long)mid * mid > x) j = mid - 1;
            else i = mid + 1;
        }
        return j; 
    }
};