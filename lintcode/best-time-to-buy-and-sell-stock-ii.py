#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-ii/

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        result = 0
        i = 1
        while i < len(prices):
            while i < len(prices) and prices[i] <= prices[i-1]:
                i += 1

            j = i
            while j < len(prices) and prices[j] >= prices[j-1]:
                j += 1

            result += prices[j-1] - prices[i-1]
            i = j

        return result

if __name__ == '__main__':
    s = Solution()
    print s.maxProfit([2,1,2,0,1])
