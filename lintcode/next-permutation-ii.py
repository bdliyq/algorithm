#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/next-permutation-ii/

class Solution:
    # @param nums: a list of integer
    # @return: return nothing (void), do not return anything, modify nums in-place instead
    def nextPermutation(self, num):
        # write your code here
        if not num:
            return num

        for i in xrange(len(num)-2, -1, -1):
            if num[i+1] > num[i]:
                for j in xrange(len(num)-1, i-1, -1):
                    if num[j] > num[i]:
                        break
                num[i], num[j] = num[j], num[i]
                num[i+1:] = num[:i:-1]
                return
        num.reverse()
