// Question: https://leetcode.com/problems/sudoku-solver/

#include "headers.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> square(9, vector<bool>(10, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    row[i][n] = true;
                    col[j][n] = true;
                    square[3*(i/3)+j/3][n] = true;
                }
            }
        }
        bool solved = false;
        helper(board, row, col, square, solved, 0, 0);
    }

private:
    void helper(vector<vector<char>>& board,
            vector<vector<bool>>& row,
            vector<vector<bool>>& col,
            vector<vector<bool>>& square,
            bool& solved, int x, int y) {
        if (solved) {
            return;
        }
        if (x >= 9) {
            solved = true;
            return;
        }

        if (board[x][y] == '.') {
            for (int i = 1; i <= 9; ++i) {
                if (!row[x][i] && !col[y][i] && !square[3*(x/3)+y/3][i]) {
                    row[x][i] = col[y][i] = square[3*(x/3)+y/3][i] = true;
                    board[x][y] = i + '0';
                    if (y < 8) {
                        helper(board, row, col, square, solved, x, y+1);
                    } else {
                        helper(board, row, col, square, solved, x+1, 0);
                    }
                    row[x][i] = col[y][i] = square[3*(x/3)+y/3][i] = false;
                    if (solved) {
                        return;
                    }
                }
            }
            board[x][y] = '.';
        } else {
            if (y < 8) {
                helper(board, row, col, square, solved, x, y+1);
            } else {
                helper(board, row, col, square, solved, x+1, 0);
            }
            if (solved) {
                return;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<char>> board;
    board.push_back(vector<char>{'5','3','.','.','7','.','.','.','.'});
    board.push_back(vector<char>{'6','.','.','1','9','5','.','.','.'});
    board.push_back(vector<char>{'.','9','8','.','.','.','.','6','.'});
    board.push_back(vector<char>{'8','.','.','.','6','.','.','.','3'});
    board.push_back(vector<char>{'4','.','.','8','.','3','.','.','1'});
    board.push_back(vector<char>{'7','.','.','.','2','.','.','.','6'});
    board.push_back(vector<char>{'.','6','.','.','.','.','2','8','.'});
    board.push_back(vector<char>{'.','.','.','4','1','9','.','.','5'});
    board.push_back(vector<char>{'.','.','.','.','8','.','.','7','9'});

    s.solveSudoku(board);

    for (auto line : board) {
        for (auto elem : line) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
