#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/fast-power/

class Solution:
    """
    @param a, b, n: 32bit integers
    @return: An integer
    """
    def fastPower(self, a, b, n):
        # write your code here
        if n == 1:
            return a % b
        if n == 0:
            return 1 % b

        p = self.fastPower(a, b, n/2)
        ans = 0
        if n % 2 == 1:
            ans = (p * p * a) % b
        else:
            ans = (p * p) % b

        return ans
