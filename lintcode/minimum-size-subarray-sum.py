#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/minimum-size-subarray-sum/

import sys

class Solution:
     # @param nums: a list of integers
     # @param s: an integer
     # @return: an integer representing the minimum size of subarray
    def minimumSize(self, nums, s):
        # write your code here
        i = 0
        j = 0
        ans = sys.maxint
        cur_sum = 0
        while i < len(nums):
            while j < len(nums) and cur_sum < s:
                cur_sum += nums[j]
                j += 1
            if cur_sum >= s:
                ans = min(ans, j-i)
                cur_sum -= nums[i]
                i += 1
            elif cur_sum < s:
                break
        return ans if ans < sys.maxint else -1

if __name__ == '__main__':
    s = Solution()
    print s.minimumSize([100,50,99,50,100,50,99,50,100,50], 250)
    print s.minimumSize([2,3,1,2,4,3], 7)
    print s.minimumSize([], 0)
