#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/maximum-subarray-difference/

import sys
class Solution:
    """
    @param nums: A list of integers
    @return: An integer indicate the value of maximum difference between two
             Subarrays
    """
    def maxDiffSubArrays(self, nums):
        # write your code here
        max_dp_left = [-sys.maxint for i in xrange(len(nums)+1)]
        max_dp_right = [-sys.maxint for i in xrange(len(nums)+1)]
        min_dp_right = [sys.maxint for i in xrange(len(nums)+1)]
        min_dp_left = [sys.maxint for i in xrange(len(nums)+1)]
        end_max = -sys.maxint
        end_min = sys.maxint

        for i in xrange(1, len(nums)+1):
            if i == 1:
                max_dp_left[i] = nums[i-1]
                end_max = nums[i-1]
            else:
                end_max = max(end_max + nums[i-1], nums[i-1])
                max_dp_left[i] = max(end_max, max_dp_left[i-1])

            if i == 1:
                min_dp_left[i] = nums[i-1]
                end_min = nums[i-1]
            else:
                end_min = min(end_min + nums[i-1], nums[i-1])
                min_dp_left[i] = min(end_min, min_dp_left[i-1])

        for i in xrange(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                max_dp_right[i] = nums[i]
                end_max = nums[i]
            else:
                end_max = max(end_max + nums[i], nums[i])
                max_dp_right[i] = max(end_max, max_dp_right[i+1])

            if i == len(nums)-1:
                min_dp_right[i] = nums[i]
                end_min = nums[i]
            else:
                end_min = min(end_min + nums[i], nums[i])
                min_dp_right[i] = min(end_min, min_dp_right[i+1])

        ans = -sys.maxint
        for i in xrange(1, len(nums)):
            ans = max(ans, abs(max_dp_left[i]-min_dp_right[i]), abs(min_dp_left[i]-max_dp_right[i]))
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.maxDiffSubArrays([-5,3,-4,0,0,0,-1,20,1,1,-1,-1,-1,-1,-1])
