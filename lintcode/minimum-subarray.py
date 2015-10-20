#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/minimum-subarray/

class Solution:
    """
    @param nums: a list of integers
    @return: A integer denote the sum of minimum subarray
    """
    def minSubArray(self, nums):
        # write your code here
        if len(nums) == 0:
            return 0

        summary = nums[0]
        min_sum = nums[0]
        for n in nums[1:]:
            if summary < min_sum:
                min_sum = summary
            if summary > 0:
                summary = 0
            summary += n
        if min_sum > summary:
            min_sum = summary

        return min_sum

if __name__ == '__main__':
    s = Solution()
    print s.minSubArray([1, -1, -2, 1])

