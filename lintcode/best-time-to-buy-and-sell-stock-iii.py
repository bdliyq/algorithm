#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-iii/

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        if len(prices) == 0:
            return 0

        one = [0 for i in xrange(len(prices))]
        one.append(prices[0])
        min_price = prices[0]
        for i in xrange(1, len(prices)):
            min_price = min(min_price, prices[i])
            one[i] = max(prices[i] - min_price, one[i-1])

        two = [0 for i in xrange(len(prices))]
        two.append(prices[-1])
        max_price = prices[-1]
        for i in xrange(len(prices) - 2, -1, -1):
            max_price = max(max_price, prices[i])
            two[i] = max(max_price - prices[i], two[i+1])

        max_profit = one[0] + two[0]
        for i in xrange(1, len(prices)):
            max_profit = max(max_profit, one[i] + two[i])

        return max_profit

if __name__ == '__main__':
    s = Solution()
    print s.maxProfit([4,4,6,1,1,4,2,5])
