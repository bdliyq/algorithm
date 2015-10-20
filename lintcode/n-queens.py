#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/n-queens/

from matrix import *
import copy
import time

class Solution:
    def check(self, queens_pos, current_row, n):
        for i in xrange(current_row):
            if queens_pos[i] == queens_pos[current_row] or abs(i-current_row) == abs(queens_pos[i]-queens_pos[current_row]):
                return False
        return True

    def work_with_recursion(self, queens_pos, current_row, n, results):
        if current_row == n:
            res = []
            for pos in queens_pos:
                res.append(str('.' * pos) + 'Q' + str('.' * (n-pos-1)))
            results.append(res)
        else:
            for i in xrange(n):
                queens_pos[current_row] = i
                if self.check(queens_pos, current_row, n):
                    self.work_with_recursion(queens_pos, current_row+1, n, results)

    def work_with_no_recursion(self, n):
        queens_pos = [-1 for i in xrange(n)]
        current_row = 0
        results = []
        while current_row >= 0:
            queens_pos[current_row] += 1
            while queens_pos[current_row] < n and not self.check(queens_pos, current_row, n):
                queens_pos[current_row] += 1
            if queens_pos[current_row] < n:
                if current_row == n-1:
                    res = []
                    for pos in queens_pos:
                        res.append(str('.' * pos) + 'Q' + str('.' * (n-pos-1)))
                    results.append(res)
                else:
                    current_row += 1
                    queens_pos[current_row] = -1
            else:
                current_row -= 1
        return results

    def work_with_recursion_and_2dmatrix(self, matrix, results, queens_count, n):
        if queens_count == n:
            res = []
            for i in xrange(n):
                res.append(''.join(matrix[i]).replace('-', '.'))
            results.append(res)
        else:
            for i in xrange(n):
                if matrix[queens_count][i] == '.':
                    temp_matrix = copy.deepcopy(matrix)
                    temp_matrix[queens_count][i] = 'Q'
                    for row in xrange(queens_count+1, n):
                        if temp_matrix[row][i] != 'Q':
                            temp_matrix[row][i] = '-'
                    for j in xrange(1, n):
                        for xfactor, yfactor in [[1, 1], [1, -1]]:
                            row = queens_count + j*xfactor
                            col = i + j*yfactor
                            if row >= 0 and row < n and col >= 0 and col < n and row > queens_count:
                                if temp_matrix[row][col] != 'Q':
                                    temp_matrix[row][col] = '-'
                    self.work_with_recursion_and_2dmatrix(temp_matrix, results, queens_count+1, n)

    """
    Get all distinct N-Queen solutions
    @param n: The number of queens
    @return: All distinct solutions
    """
    def solveNQueens(self, n):
        # write your code here
        # matrix = [['.'] * n for i in xrange(n)]
        # results = []
        # self.work_with_recursion_and_2dmatrix(matrix[:], results, 0, n)
        # return results

        queens_pos = [-1 for i in xrange(n)]
        results = []
        self.work_with_recursion(queens_pos, 0, n, results)
        return results

        # return self.work_with_no_recursion(n)

if __name__ == '__main__':
    s = Solution()
    start = time.time()
    results = s.solveNQueens(4)
    end = time.time()
    print end-start

    print results
