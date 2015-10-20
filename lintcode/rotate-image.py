#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/rotate-image/

class Solution:
    """
    @param matrix: A list of lists of integers
    @return: Nothing
    """
    def rotate(self, matrix):
        # write your code here
        n = len(matrix)
        for i in xrange(n/2):
            for j in xrange(i, n-i-1):
                oldx, oldy = i, j
                temp = matrix[oldx][oldy]
                while True:
                    newx, newy = oldy, n-1-oldx
                    matrix[newx][newy], temp = temp, matrix[newx][newy]
                    if newx == i and newy == j:
                        break
                    oldx, oldy = newx, newy
        return matrix

if __name__ == '__main__':
    s = Solution()
    print s.rotate([[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]])
    print s.rotate([[1,2],[3,4]])
