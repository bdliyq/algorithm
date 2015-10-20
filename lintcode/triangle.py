#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/triangle/

import sys
from matrix import *

class Solution:
    def minimum_total_with_1darray(self, triangle):
        x = len(triangle)
        if x == 0:
            return 0

        if x == 1:
            return triangle[0][0]

        last_array = [sys.maxint] * x
        last_array[0] = last_array[1] = triangle[0][0]
        curr_array = [sys.maxint] * x

        for row in xrange(1, x):
            for col in xrange(0, x):
                if col < len(triangle[row]):
                    left, right = sys.maxint, sys.maxint
                    if col > 0:
                        right = triangle[row][col] + last_array[col-1]
                    left = triangle[row][col] + last_array[col]
                    curr_array[col] = min(left, right)
                else:
                    if col == len(triangle[row]):
                        curr_array[col] = curr_array[col-1]
                    else:
                        curr_array[col] = sys.maxint
            last_array, curr_array = curr_array, last_array

        minimum = last_array[0]
        for a in last_array[1:]:
            if a < minimum:
                minimum = a

        return minimum

    def minimum_total_with_2dmatrix(self, triangle):
        x = len(triangle)
        if x == 0:
            return 0

        if x == 1:
            return triangle[0][0]

        matrix = [[0] * x for i in xrange(x)]
        matrix[0][0] = matrix[0][1] = triangle[0][0]
        for i in xrange(2, x):
            matrix[0][i] = sys.maxint

        for row in xrange(1, x):
            for col in xrange(0, x):
                if col < len(triangle[row]):
                    left, right = sys.maxint, sys.maxint
                    if col > 0:
                        right = triangle[row][col] + matrix[row-1][col-1]
                    left = triangle[row][col] + matrix[row-1][col]

                    matrix[row][col] = min(left, right)
                else:
                    if col == len(triangle[row]):
                        matrix[row][col] = matrix[row][col-1]
                    else:
                        matrix[row][col] = sys.maxint

        minimum = matrix[x-1][0]
        for m in matrix[x-1][1:]:
            if m < minimum:
                minimum = m

        return minimum

    """
    @param triangle: a list of lists of integers.
    @return: An integer, minimum path sum.
    """
    def minimumTotal(self, triangle):
        # write your code here
        # return self.minimum_total_with_2dmatrix(triangle)
        return self.minimum_total_with_1darray(triangle)

if __name__ == '__main__':
    s = Solution()
    print s.minimumTotal([[-7],[-2,1],[-5,-5,9],[-4,-5,4,4],[-6,-6,2,-1,-5],[3,7,8,-3,7,-9],[-9,-1,-9,6,9,0,7],[-7,0,-6,-8,7,1,-4,9],[-3,2,-6,-9,-7,-6,-9,4,0],[-8,-6,-3,-9,-2,-6,7,-5,0,7],[-9,-1,-2,4,-2,4,4,-1,2,-5,5],[1,1,-6,1,-2,-4,4,-2,6,-6,0,6],[-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1]])
