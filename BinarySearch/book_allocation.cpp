// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// n is size of arr, k is number of students
// binary search on answer

class Solution {
  public:
    bool is_possible(vector<int> &arr, int k, int mid) { // Time: O(n), Space: O(1)
        int page_sum = 0, student_count = 1;
        
        for(int p : arr) {
            if(p > mid) return false;
            
            if(page_sum + p > mid) {
                student_count++;
                page_sum = p;
            }else page_sum += p; 
        }
        
        if(student_count <= k) return true;  // minimize the maximum number of pages
        return false;
    }
    int findPages(vector<int> &arr, int k) { // Time: O(n log(sum(arr) - max(arr))), Space: O(1)
        if(arr.size() < k) return -1; // not enough books for students
        int i = INT_MIN, j = 0, ans = -1;
        
        for(int p : arr) {
            i = max(i, p);
            j += p; 
        }
        
        while(i <= j) {
            int mid = i + (j - i) / 2;
            
            if(is_possible(arr, k, mid)){
                ans = mid;
                j = mid - 1;
            }else i = mid + 1;
        }
        return ans;
    }
};

// here we have to find the minimum maximum number of pages that can be allocated to students such that k students can read the books
// Note: observation:
// If we can allocate books so that no student gets more than mid pages, then we can also allocate them with a maximum page limit greater than mid.
// Since we want to minimize the maximum pages, we discard the right half of the search space and search in the left half.