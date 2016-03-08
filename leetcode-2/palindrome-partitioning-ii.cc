// Question: https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if (len <= 1) {
            return 0;
        }

        vector<bool> is_pal(len, false);
        vector<int> dp(len+1, -1);
        for (int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1] + 1;
        }

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == i) {
                    is_pal[j] = true;
                } else if (j == i-1) {
                    is_pal[j] = s[j] == s[i];
                } else {
                    is_pal[j] = (s[j] == s[i] && is_pal[j+1]);
                }
                if (is_pal[j]) {
                    dp[i+1] = min(dp[i+1], dp[j]+1);
                }
            }
        }
        return dp.back();
    }
};
