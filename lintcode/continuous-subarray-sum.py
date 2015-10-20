#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/continuous-subarray-sum/

class Solution:
    # @param {int[]} A an integer array
    # @return {int[]}  A list of integers includes the index of the
    #                  first number and the index of the last number
    def continuousSubarraySum(self, A):
        # Write your code here
        if len(A) == 0:
            return []

        summary = A[0]
        max_sum = A[0]
        res = [0, 0]
        start, end = 0, 0

        for i in xrange(1, len(A)):
            if summary > max_sum:
                max_sum = summary
                res = (start, i-1)

            if summary < 0:
                summary = 0
                start, end = i, i

            summary += A[i]

        if summary > max_sum:
            res = (start, len(A)-1)

        return res

if __name__ == '__main__':
    s = Solution()
    # print [1,1,1,1,1,1,1,1,1,-19,1,1,1,1,1,1,1,-2,1,1,1,1,1,1,1,1,-2,1,-15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1][29:47]
    print s.continuousSubarraySum([1,1,1,1,1,1,1,1,1,-19,1,1,1,1,1,1,1,-2,1,1,1,1,1,1,1,1,-2,1,-15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1])
    print s.continuousSubarraySum([1])
    print s.continuousSubarraySum([-1])
    print s.continuousSubarraySum([-3, -5, -3, -3, -4])
    print s.continuousSubarraySum([-3, 1, 3, -3, 4])
