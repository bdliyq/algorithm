#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/coins-in-a-line/

class Solution:
    # @param n: an integer
    # @return: a boolean which equals to True if the first player will win
    def firstWillWin(self, n):
        # write your code here
        if n == 0:
            return False
        if n == 1 or n == 2:
            return True

        i = True
        j = True
        r = True
        for x in xrange(3, n+1):
            r = (not i) or (not j)
            i = j
            j = r

        return r


if __name__ == '__main__':
    s = Solution()
    print s.firstWillWin(1)
    print s.firstWillWin(2)
    print s.firstWillWin(3)
    print s.firstWillWin(4)
    print s.firstWillWin(5)
    print s.firstWillWin(6)
