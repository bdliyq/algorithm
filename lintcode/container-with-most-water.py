#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/container-with-most-water/

class Solution:
    # @param heights: a list of integers
    # @return: an integer
    def maxArea(self, heights):
        # write your code here
        l = 0
        r = len(heights) - 1
        ans = 0
        while l < r:
            if heights[l] < heights[r]:
                ans = max(ans, heights[l] * (r-l))
                l += 1
            else:
                ans = max(ans, heights[r] * (r-l))
                r -= 1
        return ans


if __name__ == '__main__':
    s = Solution()
    print s.maxArea([1,3,2])
