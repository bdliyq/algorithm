#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/unique-paths-ii/

class Solution:
    """
    @param obstacleGrid: An list of lists of integers
    @return: An integer
    """
    def uniquePathsWithObstacles(self, obstacleGrid):
        # write your code here
        m = len(obstacleGrid)
        if m == 0:
            return 0
        n = len(obstacleGrid[0])
        if n == 0:
            return 0

        matrix = [[0] * n for i in xrange(m)]
        for x in xrange(m):
            if obstacleGrid[x][0] == 1:
                matrix[x][0] = 0
            else:
                if x > 0:
                    matrix[x][0] = matrix[x-1][0]
                else:
                    matrix[x][0] = 1
        for y in xrange(n):
            if obstacleGrid[0][y] == 1:
                matrix[0][y] = 0
            else:
                if y > 0:
                    matrix[0][y] = matrix[0][y-1]
                else:
                    matrix[0][y] = 1

        for x in xrange(1, m):
            for y in xrange(1, n):
                if obstacleGrid[x][y] == 1:
                    matrix[x][y] = 0
                else:
                    matrix[x][y] = matrix[x-1][y] + matrix[x][y-1]

        return matrix[m-1][n-1]

if __name__ == '__main__':
    s = Solution()
    print s.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]])
