#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/number-of-islands/

class Solution:
    def dfs(self, grid, x, y):
        if x >= len(grid) or y >= len(grid[0]) or x < 0 or y < 0:
            return
        if grid[x][y] != 1:
            return
        grid[x][y] = -1
        self.dfs(grid, x + 1, y)
        self.dfs(grid, x, y + 1)
        self.dfs(grid, x - 1, y)
        self.dfs(grid, x, y - 1)

    # @param {boolean[][]} grid a boolean 2D matrix
    # @return {int} an integer
    def numIslands(self, grid):
        # Write your code here
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0

        count = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j] == 1:
                    count += 1
                    self.dfs(grid, i, j)

        return count

if __name__ == '__main__':
    s = Solution()
    print s.numIslands([
        [1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1],
        [0, 0, 0, 1, 1],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1]
    ])
