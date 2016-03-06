// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int sofar_min = INT_MAX;
        int ans = INT_MIN;
        for (auto p : prices) {
            sofar_min = min(sofar_min, p);
            ans = max(ans, p - sofar_min);
        }
        return ans;
    }
};
