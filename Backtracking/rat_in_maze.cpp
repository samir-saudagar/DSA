// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
    void backtrack(vector<vector<int>> &maze, vector<string> &ans, string &temp, int i, int j, int row, int col, vector<vector<bool>> &visited) { // Time: O(4^(row * col)), Space: O(row * col)
        if (i == row - 1 && j == col - 1) {
            ans.push_back(temp);
            return;
        }
        
        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || maze[i][j] == 0) {
            return;
        }
        
        visited[i][j] = true;
        
        temp.push_back('D');
        backtrack(maze, ans, temp, i + 1, j, row, col, visited);
        temp.pop_back();
        
        temp.push_back('L');
        backtrack(maze, ans, temp, i, j - 1, row, col, visited);
        temp.pop_back();
        
        temp.push_back('R');
        backtrack(maze, ans, temp, i, j + 1, row, col, visited);
        temp.pop_back();
        
        temp.push_back('U');
        backtrack(maze, ans, temp, i - 1, j, row, col, visited);
        temp.pop_back();
        
        visited[i][j] = false;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) { // Time: O(4^(row * col)), Space: O(row * col)
        // code here
        int row = maze.size();
        int col = maze[0].size();
        
        vector<string> ans;
        string temp;
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        backtrack(maze, ans, temp, 0, 0, row, col, visited);
        
        return ans;
        
    }
};