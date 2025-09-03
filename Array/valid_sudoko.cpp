// https://leetcode.com/problems/valid-sudoku?envType=problem-list-v2&envId=array
// brute force approach with unordered map

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { // Time: O(81+81+81) = O(243) ~ O(1) Space: O(9) ~ O(1)
        
        // row check
        for (int i = 0; i < 9; i++) {
            unordered_map<int, bool> mapping = {
                {1, false}, {2, false}, {3, false}, {4, false}, {5, false}, {6, false}, {7, false}, {8, false}, {9, false}
            };

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!mapping[board[i][j] - '0']) {
                        mapping[board[i][j] - '0'] = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        // col check
        for (int i = 0; i < 9; i++) {
            unordered_map<int, bool> mapping = {
                {1, false}, {2, false}, {3, false}, {4, false}, {5, false}, {6, false}, {7, false}, {8, false}, {9, false}
            };

            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (!mapping[board[j][i] - '0']) {
                        mapping[board[j][i] - '0'] = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        // grid check
        for (int startRow = 0; startRow < 9; startRow += 3) {
            for (int startCol = 0; startCol < 9; startCol += 3) {
                
                unordered_map<int, bool> mapping = {
                    {1, false}, {2, false}, {3, false}, {4, false}, {5, false}, {6, false}, {7, false}, {8, false}, {9, false}
                };

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[startRow + i][startCol + j];
                        if (c != '.') {
                            if (!mapping[c - '0']) {
                                mapping[c - '0'] = true;
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};


// optimization: Use boolean arrays instead of sets for constant time checks
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { // Time: O(81) ~ O(1) Space: O(243) ~ O(1)
        // 9 rows, 9 cols, 9 subgrids
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1'; 
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if (row[i][num] || col[j][num] || box[boxIndex][num]) {
                        return false;
                    }

                    row[i][num] = col[j][num] = box[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};
