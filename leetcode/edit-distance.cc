// Question: https://leetcode.com/problems/edit-distance/

#include "headers.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size();
        int col = word2.size();
        if (row == 0) {
            return col;
        }
        if (col == 0) {
            return row;
        }
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        for (int i = 0; i <= row; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= col; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j]+1, dp[i][j+1]+1));
                } else {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;
                }
            }
        }
        return dp[row][col];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.minDistance("abcd", "bacd") << endl;
    return 0;
}
