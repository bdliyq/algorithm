#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/edit-distance/

class Solution:
    # @param word1 & word2: Two string.
    # @return: The minimum number of steps.
    def minDistance(self, word1, word2):
        # write your code here
        if len(word1) == 0 or len(word2) == 0:
            return abs(len(word1) - len(word2))

        row = len(word1) + 1
        col = len(word2) + 1

        dp = [[0] * col for i in xrange(row)]
        for i in xrange(1, row):
            dp[i][0] = i
        for j in xrange(1, col):
            dp[0][j] = j

        for i in xrange(1, row):
            for j in xrange(1, col):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1)
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1

        return dp[row-1][col-1]

if __name__ == '__main__':
    s = Solution()
    print s.minDistance('mart', 'karma')
    print s.minDistance('a', 'a')

