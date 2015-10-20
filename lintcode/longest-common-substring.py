#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-common-substring/

class Solution:
    # @param A, B: Two string.
    # @return: the length of the longest common substring.
    def longestCommonSubstring(self, A, B):
        # write your code here
        if len(A) == 0 or len(B) == 0:
            return 0

        row = len(A) + 1
        col = len(B) + 1
        dp = [[0] * col for i in xrange(row)]
        for i in xrange(1, row):
            for j in xrange(1, col):
                if A[i-1] == B[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = 0

        result = 0
        for i in xrange(1, row):
            for j in xrange(1, col):
                result = max(result, dp[i][j])
        return result

if __name__ == '__main__':
    s = Solution()
    print s.longestCommonSubstring('ABCBDC', 'CBCE')
    print s.longestCommonSubstring('ABCB', 'CBCE')
