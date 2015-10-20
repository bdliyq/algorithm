#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/o1-check-power-of-2/

class Solution:
    """
    @param n: An integer
    @return: True or false
    """
    def checkPowerOf2(self, n):
        # write your code here
        if n <= 0:
            return False

        if n & (n-1) == 0:
            return True
        else:
            return False
