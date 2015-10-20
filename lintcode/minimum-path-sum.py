#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/minimum-path-sum/

class Solution:
    """
    @param grid: a list of lists of integers.
    @return: An integer, minimizes the sum of all numbers along its path
    """
    def minPathSum(self, grid):
        # write your code here
        row = len(grid)
        if row == 0:
            return 0
        col = len(grid[0])
        if col == 0:
            return 0

        dp = [[0] * col for i in xrange(row)]
        dp[row-1][col-1] = grid[row-1][col-1]
        for i in xrange(row-2, -1, -1):
            dp[i][col-1] = dp[i+1][col-1] + grid[i][col-1]
        for j in xrange(col-2, -1, -1):
            dp[row-1][j] = dp[row-1][j+1] + grid[row-1][j]

        for i in xrange(row-2, -1, -1):
            for j in xrange(col-2, -1, -1):
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]

        return dp[0][0]

if __name__ == '__main__':
    s = Solution()
    print s.minPathSum([[0]])

