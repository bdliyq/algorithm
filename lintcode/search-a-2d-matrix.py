#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-a-2d-matrix/

class Solution:
    """
    @param matrix, a list of lists of integers
    @param target, an integer
    @return a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        l, h = 0, len(matrix)-1
        while l <= h:
            mid = (l+h)/2
            if target < matrix[mid][0]:
                h = mid-1
            elif target == matrix[mid][0]:
                return True
            else:
                l = mid+1

        if l == 0 and matrix[l][0] < target:
            return False
        if l == len(matrix) or matrix[l][0] > target:
            l -= 1

        row = l
        l, h = 0, len(matrix[0])-1
        while l <= h:
            mid = (l+h)/2
            if target < matrix[row][mid]:
                h = mid-1
            elif target == matrix[row][mid]:
                return True
            else:
                l = mid+1

        return False

if __name__ == '__main__':
    matrix = [[1, 3, 5, 7],[10, 11, 16, 20],[23, 30, 34, 50]]
    s = Solution()
    print s.searchMatrix(matrix, 3)
    print s.searchMatrix(matrix, 11)
    print s.searchMatrix(matrix, -1)
    print s.searchMatrix(matrix, 100)
    print s.searchMatrix(matrix, 22)
