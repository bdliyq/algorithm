#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/single-number-ii/

class Solution:
    """
    @param A : An integer array
    @return : An integer
    """
    def singleNumberII(self, A):
        # write your code here
        ones, twos, threes = 0, 0, 0
        for a in A:
            twos |= ones & a
            ones ^= a
            threes = ones & twos
            ones &= ~threes
            twos &= ~threes
        return ones
