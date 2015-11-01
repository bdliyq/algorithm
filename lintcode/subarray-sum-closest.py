#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/subarray-sum-closest/

import sys
class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number
             and the index of the last number
    """
    def subarraySumClosest(self, nums):
        # write your code here
        ans = [0, 0]
        min_diff = sys.maxint
        sums = [[0, 0] for i in xrange(len(nums))]

        for i in xrange(len(nums)):
            if i == 0:
                sums[i] = nums[i], i
            else:
                sums[i] = sums[i-1][0] + nums[i], i

        sums.sort(cmp=lambda x,y:cmp(x[0],y[0]))
        for i in xrange(len(sums)-1):
            diff = abs(sums[i+1][0] - sums[i][0])
            if min_diff > diff:
                min_diff = diff
                del ans[:]
                ans.extend([min(sums[i][1], sums[i+1][1]) + 1, max(sums[i][1], sums[i+1][1])])
        return ans



if __name__ == '__main__':
    s = Solution()
    print s.subarraySumClosest([-3, 1, 1, -3, 5])


