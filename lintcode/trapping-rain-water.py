#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/trapping-rain-water/

class Solution:
    def work_with_On(self, heights):
        left_max_heights = [0 for i in xrange(len(heights))]
        right_max_heights = [0 for i in xrange(len(heights))]

        max_height_sofar = 0
        for i in xrange(len(heights)):
            max_height_sofar = max(max_height_sofar, heights[i])
            left_max_heights[i] = max_height_sofar

        max_height_sofar = 0
        for i in xrange(len(heights)-1, -1, -1):
            max_height_sofar = max(max_height_sofar, heights[i])
            right_max_heights[i] = max_height_sofar

        water = 0
        for i in xrange(len(heights)):
            water += min(left_max_heights[i], right_max_heights[i]) - heights[i]
        return water

    def work_with_O1(self, heights):
        left = 0
        right = len(heights)-1
        water = 0
        second_height = 0
        while left < right:
            if heights[left] < heights[right]:
                second_height = max(heights[left], second_height)
                water += (second_height - heights[left])
                left += 1
            else:
                second_height = max(heights[right], second_height)
                water += (second_height - heights[right])
                right -= 1
        return water

    # @param heights: a list of integers
    # @return: a integer
    def trapRainWater(self, heights):
        # write your code here
        return self.work_with_O1(heights)

if __name__ == '__main__':
    s = Solution()
    print s.trapRainWater([0,1,0,2,1,0,1,3,2,1,2,1])
    print s.trapRainWater([])
    print s.trapRainWater([2,3,4])
