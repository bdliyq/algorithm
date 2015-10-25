#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/minimum-adjustment-cost/

import sys

class Solution:
    # @param A: An integer array.
    # @param target: An integer.
    def MinAdjustmentCost(self, A, target):
        # write your code here
        if len(A) <= 1:
            return 0

        dp = [[sys.maxint] * 101 for i in xrange(len(A))]
        for i in xrange(len(A)):
            for j in xrange(1, 101):
                if i == 0:
                    dp[i][j] = abs(j - A[i])
                else:
                    for k in xrange(max(1, j-target), min(100, j+target+1)):
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(j-A[i]))

        min_diff = sys.maxint
        for i in xrange(1, 101):
            min_diff = min(min_diff, dp[len(A)-1][i])
        return min_diff


if __name__ == '__main__':
    s = Solution()
    print s.MinAdjustmentCost([1,2,3], 1)
