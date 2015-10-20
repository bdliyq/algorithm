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
        summary = 0
        max_result = 0
        max_element = -sys.maxint

        for n in nums:
            summary += n
            if summary < 0:
                summary = 0
            max_result = max(max_result, summary)
            max_element = max(max_element, n)

        if max_element < 0:
            return max_element

        return max_result

if __name__ == '__main__':
    s = Solution()
    print s.maxSubArray([-2,2,-3,4,-1,2,1,-5,3])
    print s.maxSubArray([-2,-1,-2,-3,-4,-5])
