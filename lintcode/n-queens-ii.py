#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/n-queens-ii/

class Solution:
    def check(self, queens_pos, current_row, n):
        for i in xrange(current_row):
            if queens_pos[i] == queens_pos[current_row] or abs(i - current_row) == abs(queens_pos[i] - queens_pos[current_row]):
                return False
        return True

    def work_with_no_recursion(self, n):
        count = 0
        queens_pos = [-1 for i in xrange(n)]
        current_row = 0
        while current_row >= 0:
            queens_pos[current_row] += 1
            while queens_pos[current_row] < n and not self.check(queens_pos, current_row, n):
                queens_pos[current_row] += 1
            if queens_pos[current_row] < n:
                if current_row == n-1:
                    count += 1
                else:
                    current_row += 1
                    queens_pos[current_row] = -1
            else:
                current_row -= 1  # back-track
        return count

    def work_with_recursion(self, queens_pos, current_row, n):
        count = 0
        if current_row == n:
            count = 1
        else:
            for i in xrange(n):
                queens_pos[current_row] = i
                if self.check(queens_pos, current_row, n):
                    count += self.work_with_recursion(queens_pos, current_row + 1, n)
        return count

    """
    Calculate the total number of distinct N-Queen solutions.
    @param n: The number of queens.
    @return: The total number of distinct solutions.
    """
    def totalNQueens(self, n):
        # write your code here

        # queens_pos = [-1 for i in xrange(n)]
        # return self.work_with_recursion(queens_pos, 0, n)

        return self.work_with_no_recursion(n)


if __name__ == '__main__':
    s = Solution()
    print s.totalNQueens(4)
