// Question: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        int total = 1;
        while (total <= amount) {
            int minimum = INT_MAX;
            for (int coin : coins) {
                int diff = total - coin;
                if (diff >= 0 && dp[diff] >= 0) {
                    minimum = min(minimum, dp[diff]+1);
                }
            }
            dp[total++] = minimum == INT_MAX ? -1 : minimum;
        }
        return dp.back();
    }
};
