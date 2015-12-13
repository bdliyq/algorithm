// Question: https://leetcode.com/problems/valid-sudoku/

#include "headers.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9, unordered_set<char>());
        vector<unordered_set<char>> cols(9, unordered_set<char>());
        vector<unordered_set<char>> mats(9, unordered_set<char>());

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (rows[i].count(board[i][j]) > 0) {
                    return false;
                } else {
                    rows[i].insert(board[i][j]);
                }

                if (cols[j].count(board[i][j]) > 0) {
                    return false;
                } else {
                    cols[j].insert(board[i][j]);
                }

                if (mats[3*(i/3)+j/3].count(board[i][j]) > 0) {
                    return false;
                } else {
                    mats[3*(i/3)+j/3].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};
