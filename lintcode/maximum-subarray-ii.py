#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/maximum-subarray-ii/

import sys
class Solution:
    """
    @param nums: A list of integers
    @return: An integer denotes the sum of max two non-overlapping subarrays
    """
    def maxTwoSubArrays(self, nums):
        # write your code here
        dp_left = [-sys.maxint for i in xrange(len(nums)+1)]
        dp_right = dp_left[:]
        end_max = -sys.maxint
        for i in xrange(1, len(nums)+1):
            if i == 1:
                end_max = nums[i-1]
                dp_left[i] = nums[i-1]
            else:
                end_max = max(end_max + nums[i-1], nums[i-1])
                dp_left[i] = max(end_max, dp_left[i-1])
        for i in xrange(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                end_max = nums[i]
                dp_right[i] = nums[i]
            else:
                end_max = max(end_max + nums[i], nums[i])
                dp_right[i] = max(end_max, dp_right[i+1])

        ans = -sys.maxint
        for i in xrange(1, len(nums)):
            ans = max(ans, dp_left[i] + dp_right[i])
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.maxTwoSubArrays([1, 3, -1, 2, -1, 2])
    print s.maxTwoSubArrays([-1,-1])

