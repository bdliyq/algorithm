// Question: https://leetcode.com/problems/surrounded-regions/

#include "headers.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }

        int row = board.size();
        int col = board[0].size();
        queue<pair<int, int>> q;
        for (int x = 0; x < row; ++x) {
            if (board[x][0] == 'O') {
                q.push(make_pair(x, 0));
            }
            if (board[x][col-1] == 'O') {
                q.push(make_pair(x, col-1));
            }
        }
        for (int y = 0; y < col; ++y) {
            if (board[0][y] == 'O') {
                q.push(make_pair(0, y));
            }
            if (board[row-1][y] == 'O') {
                q.push(make_pair(row-1, y));
            }
        }

        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        while (!q.empty()) {
            auto xy = q.front();
            q.pop();
            int x = xy.first;
            int y = xy.second;
            if (x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O') {
                board[x][y] = '#';
                for (int i = 0; i < 4; ++i) {
                    q.push(make_pair(x+dx[i], y+dy[i]));
                }
            }
        }

        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                if (board[x][y] == 'O') {
                    board[x][y] = 'X';
                }
            }
        }

        for (int x = 0; x < row; ++x) {
            for (int y = 0; y < col; ++y) {
                if (board[x][y] == '#') {
                    board[x][y] = 'O';
                }
            }
        }
    }

    void helper(vector<vector<char>>& board, int x, int y, int row, int col) {
        if (x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O') {
            board[x][y] = '#';
            vector<int> x_delta{0,1,0,-1};
            vector<int> y_delta{1,0,-1,0};
            for (int i = 0; i < 4; ++i) {
                helper(board, x+x_delta[i], y+y_delta[i], row, col);
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
