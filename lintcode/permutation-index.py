#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/permutation-index/

class Solution:
    # @param {int[]} A an integer array
    # @return {long} a long integer
    def permutationIndex(self, A):
        # Write your code here
        ans = 1
        factor = 1
        position = 1

        for i in xrange(len(A)-2, -1, -1):
            t = 0
            for j in xrange(i+1, len(A)):
                if A[i] > A[j]:
                    t += 1
            factor *= position
            position += 1
            ans += factor * t

        return ans
