#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/unique-binary-search-trees/

class Solution:
    # @paramn n: An integer
    # @return: An integer
    def numTrees(self, n):
        # write your code here
        return self.work_with_dp(n)

    def work_with_dp(self, n):
        dp = [0 for i in xrange(n+1)]

        dp[0] = 1
        for i in xrange(1, n+1):
            r = 0
            for j in xrange(1, i+1):
                r += dp[j-1]*dp[i-j]
            dp[j] = r

        return dp[-1]

    def work_with_recursion(self, n):
        if n <= 1:
            return 1

        res = 0
        for i in xrange(1, n+1):
            res += self.work_with_recursion(i-1) * self.work_with_recursion(n-i)

        return res

if __name__ == '__main__':
    s = Solution()
    print s.numTrees(3)
    print s.numTrees(1)

