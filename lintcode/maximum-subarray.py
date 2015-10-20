#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/maximum-subarray/

import sys
class Solution:
    """
    @param nums: A list of integers
    @return: An integer denote the sum of maximum subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        if len(nums) == 0:
            return 0

        summary = nums[0]
        max_sum = nums[0]

        for n in nums[1:]:
            if summary > max_sum:
                max_sum = summary
            if summary < 0:
                summary = 0
            summary += n

        if max_sum < summary:
            max_sum = summary

        return max_sum

if __name__ == '__main__':
    s = Solution()
    print s.maxSubArray([-2,2,-3,4,-1,2,1,-5,3])
    print s.maxSubArray([-2,-1,-2,-3,-4,-5])
