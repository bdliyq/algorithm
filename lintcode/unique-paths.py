#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/unique-paths/

class Solution:
    """
    @param n and m: positive integer(1 <= n , m <= 100)
    @return an integer
    """
    def uniquePaths(self, m, n):
        # write your code here
        if m == 0 or n == 0:
            return 0

        matrix = [[0] * n for i in xrange(m)]
        for x in xrange(m):
            matrix[x][0] = 1
        for y in xrange(n):
            matrix[0][y] = 1

        for x in xrange(1, m):
            for y in xrange(1, n):
                matrix[x][y] = matrix[x-1][y] + matrix[x][y-1]

        return matrix[m-1][n-1]

if __name__ == '__main__':
    s = Solution()
    print s.uniquePaths(2, 3)
