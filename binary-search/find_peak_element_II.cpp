// imp problem
// https://leetcode.com/problems/find-a-peak-element-ii?envType=problem-list-v2&envId=binary-search

class Solution {
public:
    int find_row(vector<vector<int>>& mat, int rows,  int cols, int mid) { // Time: O(rows), Space: O(1)
        int index = -1, min_value = -1;
        for(int i = 0; i < rows; i++){
            if(mat[i][mid] > min_value) {
                min_value = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) { // Time: O(rows * log(cols)), Space: O(1)
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0, high = cols - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int i = find_row(mat, rows, cols, mid );

            bool is_l_ok = (mid == 0) ? true : (mat[i][mid] > mat[i][mid - 1]);
            bool is_r_ok = (mid == cols - 1) ? true : (mat[i][mid] > mat[i][mid + 1]);
        
            if(is_l_ok && is_r_ok ) 
                return {i, mid};   
            else if(mid < cols - 1 && mat[i][mid] < mat[i][mid + 1]) 
                low = mid + 1;
            else
                high = mid - 1;    
        }
        return {-1, -1};
    }
};
