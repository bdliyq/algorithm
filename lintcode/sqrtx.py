#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sqrtx/

class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        if x < 0:
            return -1
        if x == 0:
            return 0

        l, h = 1, x
        while l+1 < h:
            mid = (l+h)/2
            p = pow(mid, 2)
            if p == x:
                return mid
            elif p > x:
                h = mid
            else:
                l = mid

        return l

if __name__ == '__main__':
    s = Solution()
    print s.sqrt(0)
    print s.sqrt(1)
    print s.sqrt(2)
    print s.sqrt(9)
    print s.sqrt(10)
    print s.sqrt(11)
    print s.sqrt(12)
