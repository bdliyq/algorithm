#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/single-number/

class Solution:
    """
    @param A : an integer array
    @return : a integer
    """
    def singleNumber(self, A):
        # write your code here
        res = 0
        for n in A:
            res ^= n
        return res

