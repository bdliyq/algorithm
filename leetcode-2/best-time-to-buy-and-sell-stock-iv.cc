// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        if (k >= prices.size() / 2) {
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i-1]) {
                    ans += prices[i] - prices[i-1];
                }
            }
            return ans;
        }

        vector<int> max_profit(k+1, 0);
        vector<int> min_prices(k+1, INT_MAX);
        for (int p : prices) {
            for (int i = k; i >= 1; --i) {
                max_profit[i] = max(max_profit[i], p-min_prices[i]);
                min_prices[i] = min(min_prices[i], p-max_profit[i-1]);
            }
        }
        return max_profit[k];
    }
};
