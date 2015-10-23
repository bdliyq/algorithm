#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sliding-window-maximum/

class Solution:
    """
    @param nums: A list of integers.
    @return: The maximum number inside the window at each moving.
    """
    def maxSlidingWindow(self, nums, k):
        # write your code here
        if len(nums) == 0 or len(nums) < k:
            return []

        deque = []
        for i in xrange(k):
            while deque and nums[i] >= nums[deque[-1]]:
                deque.pop()
            deque.append(i)

        res = []
        for i in xrange(k, len(nums)):
            res.append(nums[deque[0]])
            while deque and nums[i] >= nums[deque[-1]]:
                deque.pop()
            while deque and deque[0] <= i-k:
                deque.pop(0)
            deque.append(i)

        res.append(nums[deque[0]])
        return res

if __name__ == '__main__':
    s = Solution()
    print s.maxSlidingWindow([1, 2, 7, 7, 8], 3)
