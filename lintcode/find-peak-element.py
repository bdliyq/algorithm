#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/find-peak-element/

class Solution:
    #@param A: An integers list.
    #@return: return any of peek positions.
    def findPeak(self, A):
        # write your code here
        l, r = 0, len(A)-1
        while l < r:
            m = l + (r-l)/2
            if A[m] > A[m+1]:
                r = m
            else:
                l = m+1
        return l

