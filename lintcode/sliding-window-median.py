#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sliding-window-median/

import heapq

class Solution:
    def push_heap(self, i):
        if num > self.mid:
            heapq.heappush(self.min_heap, (i, nums[i]))
        else:
            heapq.heappush(self.max_heap, (-i, -nums[i]))

        if len(self.min_heap) - len(self.max_heap) == 2:
            heapq.heappush(self.max_heap, -self.mid)
            self.mid = heapq.heappop(self.min_heap)
        elif len(self.max_heap) - len(self.min_heap) == 2:
            heapq.heappush(self.min_heap, self.mid)
            self.mid = -heapq.heappop(self.max_heap)

    def get_median(self):
        if len(self.min_heap) == len(self.max_heap):
            return mid
        if len(self.min_heap) > len(self.max_heap):
            return -self.max_heap[0]
        else:
            return self.min_heap[0]

    """
    @param nums: A list of integers.
    @return: The median of element inside the window at each moving.
    """
    def medianSlidingWindow(self, nums, k):
        # write your code here
        if len(nums) == 0 or len(nums) < k:
            return []

        self.max_heap = []
        self.min_heap = []
        self.mid = nums[0]
        res = []
        for i in xrange(1, k):
            self.push_heap(nums[i])
        res.append(self.get_median())


if __name__ == '__main__':
    s = Solution()
    print s.medianSlidingWindow([1,2,7,8,5], 3)
