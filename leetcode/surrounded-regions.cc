// Question: https://leetcode.com/problems/surrounded-regions/

#include "headers.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int row = board.size();
        int col = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
            }
            if (board[i][col-1] == 'O') {
                q.push(make_pair(i, col-1));
            }
        }
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') {
                q.push(make_pair(0, i));
            }
            if (board[row-1][i] == 'O') {
                q.push(make_pair(row-1, i));
            }
        }

        vector<int> dx{-1, 1,  0, 0};
        vector<int> dy{0,  0, -1, 1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (board[x][y] == 'O') {
                board[x][y] = '1';
                for (int i = 0; i < 4; ++i) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if (newx >= 0 && newx < row && newy >= 0 && newy < col && board[newx][newy] == 'O') {
                        q.push(make_pair(newx, newy));
                    }
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void helper(vector<vector<char>>& board, int x, int y) {
        int row = board.size();
        int col = board[0].size();
        board[x][y] = '1';
        vector<int> dx{-1, 1,  0, 0};
        vector<int> dy{0,  0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx >= 0 && newx < row && newy >= 0 && newy < col && board[newx][newy] == 'O') {
                helper(board, newx, newy);
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<char>> board;
    board.push_back(vector<char>{'X','O','X','O','X','O'});
    board.push_back(vector<char>{'O','X','O','X','O','X'});
    board.push_back(vector<char>{'X','O','X','O','X','O'});
    board.push_back(vector<char>{'O','X','O','X','O','X'});
    s.solve(board);
    for (auto v : board) {
        for (auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
