// https://leetcode.com/problems/n-queens?envType=problem-list-v2&envId=backtracking

// n is the number of queens and the size of the chessboard is n x n
class Solution {
public:
    bool isSafe(vector<string> &temp, int row, int col, int n) { // Time: O(n), Space: O(1)
        // column check
        for (int i = 0; i < row; i++) {
            if(temp[i][col] == 'Q') {
                return false;
            }
        }

        // left diagonal check
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(temp[i][j] == 'Q') {
                return false;
            }
        }

        // right diagonal check
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(temp[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &temp, int row, int n) { // Time: O(n! * n), Space: O(n ^ 2)
        if (row == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(temp, row, j, n)) {
                temp[row][j] = 'Q';
                backtrack(ans, temp, row + 1, n);
                temp[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) { // Time: O(n! * n), Space: O(n ^ 2) - sting consist only one char '.' and 'Q'
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));

        backtrack(ans, temp, 0, n);

        return ans;
    }
};

// Optimized space solution
class Solution {
public:
    void backtrack(int row, int n, vector<string> &board,
                   vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2,
                   vector<vector<string>> &ans) { // Time: O(n! * n), Space: O(n)
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (col[j] || diag1[row - j + n - 1] || diag2[row + j]) continue;

            board[row][j] = 'Q';
            col[j] = diag1[row - j + n - 1] = diag2[row + j] = true;

            backtrack(row + 1, n, board, col, diag1, diag2, ans);

            board[row][j] = '.';
            col[j] = diag1[row - j + n - 1] = diag2[row + j] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) { // Time: O(n! * n), Space: O(n)
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2*n - 1, false);
        vector<bool> diag2(2*n - 1, false); 

        backtrack(0, n, board, col, diag1, diag2, ans);
        return ans;
    }
};