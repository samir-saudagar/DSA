// https://leetcode.com/problems/sudoku-solver?envType=problem-list-v2&envId=backtracking

// n is board size(rows or columns for square board)

// standard backtracking approach
class Solution {
public:
    bool isPossible(vector<vector<char>> &board, int row, int col, char c) { // Time: O(9) Space: O(1)
        // row check
        for (int i = 0; i < 9; i++) {
            if(board[row][i] == c) {
                return false;
            }
        }

        // column check
        for (int i = 0; i < 9; i++) {
            if(board[i][col] == c) {
                return false;
            }
        } 

        // sub grid check
        int rowS = row - row % 3;
        int colS = col - col % 3;

        for (int i = rowS;  i < rowS + 3; i++) {
            for (int j = colS; j < colS + 3; j++) {
                if (board[i][j] == c) {
                    return false;
                }
            }
        }

        return true;
    }

    bool backtrack(vector<vector<char>> &board, int row, int col) { // Time: O(9^(n*n)) Space: O(1)
        if (row == 9) return true;

        if (col == 9) return backtrack(board, row + 1, 0);

        if (board[row][col] != '.') {
            return backtrack(board, row, col + 1);
        }

        for (char c = '1'; c<= '9'; c++) {
            if (isPossible(board, row, col, c)) {
                board[row][col] = c;
                if (backtrack(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board) { // Time: O(9^(n*n)) Space: O(1)
        
        backtrack(board, 0, 0); 
    }
};

// another approach using hashmaps to store row, column and subgrid information

class Solution {
public:
    bool row[9][10], col[9][10], box[9][10];

    bool backtrack(vector<vector<char>> &board, int r, int c) { // Time: O(9^(n*n)) Space: O(1)
        if (r == 9) return true;
        if (c == 9) return backtrack(board, r + 1, 0);

        if (board[r][c] != '.') {
            return backtrack(board, r, c + 1);
        }

        int b = (r / 3) * 3 + (c / 3);

        for (int d = 1; d <= 9; d++) {
            if (!row[r][d] && !col[c][d] && !box[b][d]) {
                board[r][c] = '0' + d;
                row[r][d] = col[c][d] = box[b][d] = true;

                if (backtrack(board, r, c + 1)) return true;

                board[r][c] = '.';
                row[r][d] = col[c][d] = box[b][d] = false;
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board) { // Time: O(9^(n*n)) Space: O(1)
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(box, false, sizeof(box));

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int d = board[r][c] - '0';
                    int b = (r / 3) * 3 + (c / 3);
                    row[r][d] = col[c][d] = box[b][d] = true;
                }
            }
        }

        backtrack(board, 0, 0);
    }
};


