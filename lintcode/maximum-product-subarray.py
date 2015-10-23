#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/maximum-product-subarray/

class Solution:
    # @param nums: an integer[]
    # @return: an integer
    def maxProduct(self, nums):
        # write your code here
        if len(nums) == 0:
            return 0

        max_res = nums[0]
        max_sofar = max_res
        min_sofar = max_res
        for i in xrange(1, len(nums)):
            t_max_sofar = max(nums[i], max_sofar * nums[i], min_sofar * nums[i])
            t_min_sofar = min(nums[i], max_sofar * nums[i], min_sofar * nums[i])
            max_sofar, min_sofar = t_max_sofar, t_min_sofar
            max_res = max(max_res, max_sofar, min_sofar)

        return max_res

if __name__ == '__main__':
    s = Solution()
    print s.maxProduct([2,3,-2,4])
