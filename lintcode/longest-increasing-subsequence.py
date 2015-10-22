#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-increasing-subsequence/

class Solution:
    """
    @param nums: The integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        # write your code here
        if len(nums) == 0:
            return 0

        dp = [1 for i in xrange(len(nums))]
        res = 0
        for i in xrange(len(nums)):
            for j in xrange(i):
                if nums[j] <= nums[i]:
                    dp[i] = max(dp[j]+1, dp[i])
                    res = max(res, dp[i])
        return res

if __name__ == '__main__':
    s = Solution()
    print s.longestIncreasingSubsequence([4,2,4,5,3,7])
    print s.longestIncreasingSubsequence([1,1,1,1,1,1])
    print s.longestIncreasingSubsequence([5,4,1,2,3])
