#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock/

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        if len(prices) == 0:
            return 0

        max_profit = 0
        min_price = prices[0]
        for i in xrange(1, len(prices)):
            min_price = min(prices[i], min_price)
            max_profit = max(prices[i] - min_price, max_profit)

        return max_profit


        # max_profit = 0
        # i = 1
        # while i < len(prices):
        #     while i < len(prices) and prices[i] <= prices[i-1]:
        #         i += 1
        #     j = i + 1
        #     while j < len(prices) and prices[j] >= prices[j-1]:
        #         j += 1
        #     next_i = j
        #     while j <= len(prices):
        #         profit = prices[j-1] - prices[i-1]
        #         if max_profit < profit:
        #             max_profit = profit
        #         j += 1

        #     i = next_i

        # return max_profit

        # max_profit = 0
        # i = 1
        # while i < len(prices):
        #     if prices[i] <= prices[i-1]:
        #         i += 1
        #         continue
        #     j = i
        #     while j < len(prices):
        #         profit = prices[j] - prices[i-1]
        #         if max_profit < profit:
        #             max_profit = profit
        #         j += 1
        #     i += 1
        # return max_profit

if __name__ == '__main__':
    s = Solution()
    print s.maxProfit([2,4,1,7])
    print s.maxProfit([3,2,3,1,2])
    print s.maxProfit([3,2])
    print s.maxProfit([2,3])
