#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/k-sum/

class Solution:
    """
    @param A: An integer array.
    @param k: a positive integer (k <= length(A))
    @param target: integer
    @return an integer
    """
    def kSum(self, A, k, target):
        # write your code here
        if len(A) < k:
            return 0

        icnt = k+1
        jcnt = len(A)+1
        vcnt = target+1
        dp = [[[0 for v in xrange(vcnt)] for j in xrange(jcnt)] for i in xrange(icnt)]

        for j in xrange(1, jcnt):
            if target >= A[j-1]:
                for m in xrange(j, jcnt):
                    dp[1][m][A[j-1]] = 1

        for i in xrange(2, icnt):
            for j in xrange(i, jcnt):
                for v in xrange(1, vcnt):
                    dp[i][j][v] = 0
                    if j > i:
                        dp[i][j][v] += dp[i][j-1][v]
                    if v >= A[j-1]:
                        dp[i][j][v] += dp[i-1][j-1][v-A[j-1]]

        return dp[k][len(A)][target]

if __name__ == '__main__':
    s = Solution()
    print s.kSum([1,2,3,4], 2, 5)
