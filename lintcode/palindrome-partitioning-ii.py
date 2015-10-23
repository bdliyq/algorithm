#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/palindrome-partitioning-ii/

class Solution:
    # @param s, a string
    # @return an integer
    def minCut(self, s):
        # write your code here
        if len(s) <= 0:
            return 0

        dp = [i for i in xrange(-1, len(s))]
        for i in xrange(len(s)):
            j = 0
            while i-j>=0 and i+j<len(s) and s[i-j] == s[i+j]:
                dp[i+j+1] = min(dp[i-j]+1, dp[i+j+1])
                j += 1

            j = 0
            while i-j>=0 and i+j+1<len(s) and s[i-j] == s[i+j+1]:
                dp[i+j+2] = min(dp[i-j]+1, dp[i+j+2])
                j += 1

        return dp[len(s)]


