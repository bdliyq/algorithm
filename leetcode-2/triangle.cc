// Question: https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }

        int len = triangle.size();
        vector<int> dp(len, INT_MAX);
        for (int i = 0; i < len; ++i) {
            dp[i] = triangle.back().at(i);
        }

        for (int i = len-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};
