#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/maximum-subarray/

import sys
class Solution:
    def another_way(self, nums):
        dp = [0 for i in xrange(len(nums))]
        end_max = -sys.maxint
        for i in xrange(len(nums)):
            if i == 0:
                end_max = nums[0]
                dp[i] = nums[0]
            else:
                end_max = max(end_max + nums[i], nums[i])
                dp[i] = max(end_max, dp[i-1])
        return dp[-1]

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
    print s.another_way([-2,2,-3,4,-1,2,1,-5,3])
    print s.another_way([-2,-1,-2,-3,-4,-5])
