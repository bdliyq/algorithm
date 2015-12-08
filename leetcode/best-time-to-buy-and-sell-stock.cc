// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include "headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = INT_MAX;
        for (auto p : prices) {
            min_price = min(min_price, p);
            ans = max(ans, p - min_price);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
}
