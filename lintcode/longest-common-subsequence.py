#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-common-subsequence/

class Solution:
    # @param A, B: Two string.
    # @return: the length of the longest common subsequence.
    def longestCommonSubsequence(self, A, B):
        # write your code here
        if len(A) == 0 or len(B) == 0:
            return 0

        row = len(A) + 1
        col = len(B) + 1
        dp = [[0] * col for i in xrange(row)]
        for i in xrange(1, row):
            for j in xrange(1, col):
                if A[i-1] == B[j-1]:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + 1)
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

        return dp[len(A)][len(B)]


if __name__ == '__main__':
    s = Solution()
    print s.longestCommonSubsequence('ABCD', 'CBCE')
    print s.longestCommonSubsequence('ABCBDC', 'CBCE')
