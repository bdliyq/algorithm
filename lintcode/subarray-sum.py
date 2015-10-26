#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/subarray-sum/

class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number
             and the index of the last number
    """
    def subarraySum(self, nums):
        # write your code here
        d = {}
        d[0] = -1
        s = 0
        for i in xrange(len(nums)):
            s += nums[i]
            if d.has_key(s):
                return [d[s]+1, i]
            else:
                d[s] = i
