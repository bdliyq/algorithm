#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/print-numbers-by-recursion/

class Solution:
    def work_with_recursion(self, n, res):
        if n == 0:
            return
        self.work_with_recursion(n-1, res)
        base = pow(10, n-1)

        size = len(res)
        for i in xrange(1, 10):
            res.append(base * i)
            for j in xrange(0, size):
                res.append(res[j] + base * i)

    # @param n: An integer.
    # return : A list of integer storing 1 to the largest number with n digits.
    def numbersByRecursion(self, n):
        # write your code here
        res = []
        self.work_with_recursion(n, res)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.numbersByRecursion(0)
    print s.numbersByRecursion(1)
    print s.numbersByRecursion(2)
    print s.numbersByRecursion(3)
