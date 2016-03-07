// Question: https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        if (idx == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || idx > (int)word.size()-1 || word[idx] != board[i][j]) {
            return false;
        }

        board[i][j] = '*';
        vector<int> row_delta{0,1,0,-1};
        vector<int> col_delta{1,0,-1,0};
        for (int k = 0; k < 4; ++k) {
            if (helper(board, word, idx+1, i+row_delta[k], j+col_delta[k])) {
                return true;
            }
        }
        board[i][j] = word[idx];
        return false;
    }
};
