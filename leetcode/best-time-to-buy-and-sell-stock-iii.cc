// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include "headers.h"

void print_vec(vector<int>& nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if (prices.empty()) {
            return ans;
        }

        int len = prices.size();

        vector<int> one(len, 0);
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min_price = min(min_price, prices[i]);
            one[i] = max(one[i-1], max(prices[i] - min_price, 0));
        }

        vector<int> two(len, 0);
        int max_price = prices.back();
        for (int i = (int)prices.size()-2; i >= 0; --i) {
            max_price = max(max_price, prices[i]);
            two[i] = max(two[i+1], max(max_price - prices[i], 0));
        }

        for (int i = 0; i < len; ++i) {
            ans = max(ans, one[i] + two[i]);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    vector<int> nums{4,4,6,1,1,4,2,5};
    Solution s;
    cout << s.maxProfit(nums) << endl;
    return 0;
}
