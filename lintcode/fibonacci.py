#!/usr/bin/env python
# encoding: utf-8
# Question: http://www.lintcode.com/en/problem/fibonacci/

class Solution:
    # @param n: an integer
    # @return an integer f(n)
    def fibonacci(self, n):
        # write your code here
        if n == 1:
            return 0
        if n == 2:
            return 1

        i = 0
        j = 1
        r = 0
        for x in xrange(2, n):
            r = i + j
            i = j
            j = r

        return r

if __name__ == '__main__':
    s = Solution()
    print s.fibonacci(10)

