// https://leetcode.com/problems/word-search?envType=problem-list-v2&envId=backtracking

// S is the total number of cells in the board starting with word[0]
// L is the length of the word to be found
// using used array
class Solution {
public:
    bool backtrack(auto &board, string word, int row, int col, int i, int j, int k, auto &used) { // Time: O(S * 4^L), Space: O(row * col + L) S <= row * col
        if (k == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= row || j >= col || used[i][j] || word[k] != board[i][j]) {
            return false;
        }

        used[i][j] = true;

        bool found = 
            backtrack(board, word, row, col, i + 1, j, k + 1, used) ||
            backtrack(board, word, row, col, i, j - 1, k + 1, used) ||
            backtrack(board, word, row, col, i, j + 1, k + 1, used) ||
            backtrack(board, word, row, col, i - 1, j, k + 1, used);

        used[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) { // Time: O(row * col * 4^L), Space: O(row * col + L) S <= row * col
        int row = board.size();
        int col = board[0].size();

        int found = false;
        int i, j;

        vector<vector<bool>> used(row, vector<bool>(col, false));

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, row, col, i, j, 0, used)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};


// without using used array
class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int i, int j, int k) { // Time: O(S * 4^L), Space: O(L) S <= row * col
        if (k == word.size()) return true;

        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];  
        board[i][j] = '#';       

        bool found =
            backtrack(board, word, row, col, i + 1, j, k + 1) ||
            backtrack(board, word, row, col, i - 1, j, k + 1) ||
            backtrack(board, word, row, col, i, j + 1, k + 1) ||
            backtrack(board, word, row, col, i, j - 1, k + 1);

        board[i][j] = temp;  

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) { // Time: O(row * col * 4^L), Space: O(L) S <= row * col
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (backtrack(board, word, row, col, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// optimized approach
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) { // Time: O(row * col * 4^L), Space: O(row * col + L) S <= row * col
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<bool>> used(row, vector<bool>(col, false));
        
        if (word.size() > row * col)
            return false;
        
        vector<int> counts(256, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                counts[board[i][j]]++;
            }
        }
        
        int len = word.size();
        for (int i = 0; i < len / 2; i++) {
            if (counts[word[i]] > counts[word[len - 1 - i]]) {
                for (int j = 0; j < len / 2; j++) {
                    char temp = word[j];
                    word[j] = word[len - 1 - j];
                    word[len - 1 - j] = temp;
                }
                break;
            }
        }
        
        for (char c : word) {
            if (--counts[c] < 0)
                return false;
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (backtrack(board, word, 0, i, j, row, col, used))
                    return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int k, int i, int j,
             int row, int col, vector<vector<bool>>& used) { // Time: O(S * 4^L), Space: O(row * col + L) S <= row * col
        if (k == word.size())
            return true;
        if (i < 0 || i >= row || j < 0 || j >= col || used[i][j])
            return false;
        if (word[k] != board[i][j])
            return false;
        
        used[i][j] = true;
        
        bool found = backtrack(board, word, k + 1, i + 1, j, row, col, used)
                  || backtrack(board, word, k + 1, i - 1, j, row, col, used)
                  || backtrack(board, word, k + 1, i, j + 1, row, col, used)
                  || backtrack(board, word, k + 1, i, j - 1, row, col, used);
        
        used[i][j] = false;

        return found;
    }
};

