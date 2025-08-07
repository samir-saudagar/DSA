// https://leetcode.com/problems/search-a-2d-matrix-ii?envType=problem-list-v2&envId=binary-search
// n is no of rows, m is no of columns

// method 1:binary search on each row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // Time: O(n * log m), Space: O(1)
        int rows = matrix.size(), cols = matrix[0].size();

        for(int k = 0; k < rows; ++k) {
            int i = 0, j = cols - 1;
            while(i <= j){
                int mid = i + (j - i) / 2;
                if(matrix[k][mid] == target) return true;
                else if(matrix[k][mid] > target) j = mid - 1;
                else i = mid + 1; 
            }
        }
        return false; 
    }
};

// method 2: top down approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // Time: O(n + m), Space: O(1)
        int rows = matrix.size(), cols = matrix[0].size();

        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) return true; 
            else if (matrix[i][j] > target) j--; 
            else i++; 
        }
        return false;
    }
};

// method 3: bottom up approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // Time: O(n + m), Space: O(1)
        int rows = matrix.size(), cols = matrix[0].size();

        int i = rows - 1, j = 0;
        while (i >= 0 && j < cols) {
            if (matrix[i][j] == target) return true; 
            else if (matrix[i][j] > target) i--; 
            else j++; 
        }
        return false;
    }
};

// here top down and bottom up approaches are the optimal solutions as they have linear time complexity O(n + m) and constant space complexity O(1).
// we cant aplly binary search on the whole matrix as it is not sorted in a linear way, it is sorted in a 2D way.
// but you can apply binary search on each row or column as they are sorted in a linear way while iterating trough the columns or rows respectively.
