#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/submatrix-sum/

class Solution:
    def subarraySum(self, array):
        d = {}
        d[0] = -1
        s = 0
        for i in xrange(len(array)):
            s += array[i]
            if d.has_key(s):
                return [d[s]+1, i]
            else:
                d[s] = i
        return [-1,-1]

    # @param {int[][]} matrix an integer matrix
    # @return {int[][]} the coordinate of the left-up and right-down number
    def submatrixSum(self, matrix):
        # Write your code here
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return [[]]

        row = len(matrix)
        col = len(matrix[0])
        ans = [[]]

        for i in xrange(col):
            temp = [0 for m in xrange(row)]
            for j in xrange(i, col):
                for k in xrange(row):
                    temp[k] += matrix[k][j]
                start, end = self.subarraySum(temp)
                if start >= 0 and end >= 0:
                    ans = [[start, i], [end, j]]
                    return ans
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.submatrixSum([[1,5,7],[3,7,-8],[4,-8,9]])
