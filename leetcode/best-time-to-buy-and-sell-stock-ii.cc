// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include "headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int ans = 0;
        int min_price = prices[0];
        int i = 1;
        int len = prices.size();
        while (i < len) {
            int j = i;
            while (i < len && prices[i] >= prices[i-1]) {
                ++i;
            }
            ans += prices[i-1] - min_price;
            if (j == i) {
                ++i;
            }

            if (i == len) {
                break;
            }
            min_price = prices[i-1];
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    vector<int> nums{1,4,2};
    Solution s;
    cout << s.maxProfit(nums) << endl;
    return 0;
}
