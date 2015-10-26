#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-a-2d-matrix-ii/

class Solution:
    """
    @param matrix: An list of lists of integers
    @param target: An integer you want to search in matrix
    @return: An integer indicates the total occurrence of target in the given matrix
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        ans = 0
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return ans

        x = 0
        y = len(matrix[0]) - 1
        while x < len(matrix):
            while y >= 0 and matrix[x][y] > target:
                y -= 1
            if matrix[x][y] == target:
                ans += 1
            x += 1

        return ans

if __name__ == '__main__':
    s = Solution()
    print s.searchMatrix([[1, 3, 5, 7],[2, 4, 7, 8],[3, 5, 9, 10]], 3)


