// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> ones(prices.size(), 0);
        int sofar_min = INT_MAX;
        int max_profit = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            sofar_min = min(sofar_min, prices[i]);
            max_profit = max(max_profit, prices[i] - sofar_min);
            ones[i] = max_profit;
        }

        vector<int> twos(prices.size(), 0);
        int sofar_max = INT_MIN;
        max_profit = INT_MIN;
        for (int i = (int)prices.size()-1; i >= 0; --i) {
            sofar_max = max(sofar_max, prices[i]);
            max_profit = max(max_profit, sofar_max - prices[i]);
            twos[i] = max_profit;
        }

        int ans = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ones[i] + twos[i], ans);
        }
        return ans;
    }
};
