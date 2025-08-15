// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
// top down approach
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) { // Time: O(rows + cols), Space: O(1)
        int rows = arr.size();
        int cols = arr[0].size();
        
        int max_row_index = -1, i = 0, j = cols - 1;
        while(i < rows && j >= 0){
            if(arr[i][j] == 1) {
                max_row_index = i;
                j--;
            }else i++;
        }
        return max_row_index;
    }
};

// binary search approach
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) { // Time: O(rows * log(cols)), Space: O(1)
        int rows = arr.size();
        int cols = arr[0].size();
        int max_row_index = -1;
        int max_ones = 0;

        for(int i = 0; i < rows; i++) {
            int low = 0, high = cols - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[i][mid] == 1) {
                    high = mid - 1; 
                } else low = mid + 1;
            }
            if(cols - low > max_ones) {
                max_ones = cols - low;
                max_row_index = i;
            }
        }
        return max_row_index;
    }
};

// Note: binarry search approach is not optimal as it takes O(rows * log(cols)) time, but the top down approach is optimal with O(rows + cols) time complexity.

