// Question: https://leetcode.com/problems/maximal-square/

#include "headers.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix.at(0).size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix.at(0).size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        int max_count = INT_MIN;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i+1][j+1] = min(dp[i][j+1], min(dp[i+1][j], dp[i][j])) + 1;
                    max_count = max(max_count, dp[i+1][j+1]);
                }
            }
        }

        return max_count * max_count;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>{'1','0','1','0'});
    matrix.push_back(vector<char>{'1','0','1','1'});
    matrix.push_back(vector<char>{'1','0','1','1'});
    matrix.push_back(vector<char>{'1','1','1','1'});
    Solution s;
    cout << s.maximalSquare(matrix) << endl;
    return 0;
}
