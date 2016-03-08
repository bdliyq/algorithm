// Question: https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size();
        int col = word2.size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        for (int i = 1; i <= row; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= col; ++j) {
            dp[0][j] = j;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j]) + 1);
                } else {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
                }
            }
        }

        return dp.back().back();
    }
};
