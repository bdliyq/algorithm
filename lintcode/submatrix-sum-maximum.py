#!/usr/bin/env python
# encoding: utf-8

# Question: 给定矩阵，求sum最大的子矩阵的左上、右下坐标。

class Solution:
    def subarraySum(self, array):
        max_sum = 0
        cur_sum = 0
        start = 0
        end = -1
        for i in xrange(len(array)):
            cur_sum += array[i]
            if cur_sum < 0:
                cur_sum = 0
                start = i
            else:
                if max_sum < cur_sum:
                    max_sum = cur_sum
                    end = i

        if end != -1:
            return max_sum, start, end

        max_sum = array[0]
        start = 0
        end = 0
        for i in xrange(1, len(array)):
            if max_sum < array[i]:
                max_sum = array[i]
                start = i
                end = i
        return max_sum, start, end


    # @param {int[][]} matrix an integer matrix
    # @return {int[][]} the coordinate of the left-up and right-down number
    def submatrixSum(self, matrix):
        # Write your code here
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0

        max_sum = 0
        ans = [[-1,-1],[-1,-1]]
        row = len(matrix)
        col = len(matrix[0])
        for i in xrange(col):
            temp = [0 for m in xrange(row)]
            for j in xrange(i, col):
                for k in xrange(0, row):
                    temp[k] += matrix[k][j]
                tsum, tstart, tend = self.subarraySum(temp)
                if max_sum < tsum:
                    max_sum = tsum
                    ans = [[i, tstart], [tend, j]]
        print max_sum
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.submatrixSum([[1,5,7],[3,7,-8],[4,-8,9]])
