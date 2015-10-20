#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/climbing-stairs/

class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        # write your code here
        if n <= 2:
            return n

        i = 1
        j = 2
        r = 0
        for z in xrange(2, n):
            r = i + j
            i = j
            j = r
        return r


if __name__ == '__main__':
    s = Solution()
    print s.climbStairs(3)
    print s.climbStairs(4)
    print s.climbStairs(5)
