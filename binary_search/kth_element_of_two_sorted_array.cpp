// imp problem
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// n is the size of array a and m is the size of array b.

// method 1: merge both arrays 
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) { // Time: O(n + m), Space: O(n + m)
        
        int n = a.size(), m = b.size();
        int x = m + n - 1;
        vector<int> merged(n + m);
        
        int i = n - 1, j = m - 1;
        
        while(i >= 0 && j >= 0) {
            if(a[i] > b[j]) merged[x--] = a[i--];
            else merged[x--] = b[j--];
        }
        
        while(i >= 0) merged[x--] = a[i--];
        while(j >= 0) merged[x--] = b[j--];
        
        return merged[k - 1];
        
    }
};

// method 2: binary search

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) { // Time: O(log(min(n, m))), Space: O(1)
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        
        if(n1 > n2) return kthElement(b, a, k);
        
        int i = max(0, k - n2), j = min(k, n1); // i = low, j = high
        
        while(i <= j) {
            int mid1 = i + (j - i) / 2;
            int mid2 = k - mid1;
            
            int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : b[mid2];
            
            if(l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if(l1 > r2) j = mid1 - 1;
            else i = mid1 + 1;
        }
        return 0;
    }
};