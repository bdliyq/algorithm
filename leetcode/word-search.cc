// Question: https://leetcode.com/problems/word-search/

#include "headers.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }

        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (helper(board, word, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool helper(vector<vector<char>>& board, string word, int i, int j) {
        if (word.empty()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]) {
            return false;
        }

        board[i][j] = '*';
        string sub = word.substr(1);
        bool ans = helper(board, sub, i+1, j) ||
            helper(board, sub, i-1, j) ||
            helper(board, sub, i, j+1) ||
            helper(board, sub, i, j-1);
        board[i][j] = word[0];

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<vector<char>> board;
        board.push_back(vector<char>{'A','B','C','E'});
        board.push_back(vector<char>{'S','F','C','S'});
        board.push_back(vector<char>{'A','D','E','E'});
        cout << s.exist(board, "ABCCED") << endl;
        cout << s.exist(board, "SEE") << endl;
        cout << s.exist(board, "ABCB") << endl;
    }
    {
        vector<vector<char>> board;
        board.push_back(vector<char>{'a','b'});
        cout << s.exist(board, "ba") << endl;
    }
    return 0;
}
