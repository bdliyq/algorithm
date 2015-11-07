#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/single-number-iii/

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def singleNumberIII(self, nums):
        xor = reduce(lambda x, y : x ^ y, nums)
        lowbit = xor & -xor
        a = b = 0
        for num in nums:
            if num & lowbit:
                a ^= num
            else:
                b ^= num
        return [a, b]
