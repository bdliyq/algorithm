#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/median/

class Solution:
    """
    @param nums: A list of integers.
    @return: An integer denotes the middle number of the array.
    """
    def median(self, nums):
        # write your code here
        size = len(nums)
        if size == 0:
            return 0

        k = (size - 1) / 2
        next_low = 0
        next_high = size - 1
        while True:
            low = next_low
            high = next_high
            pivot = nums[low]
            while low < high:
                while low < high and nums[high] >= pivot:
                    high -= 1
                if low < high:
                    nums[low] = nums[high]
                    low += 1

                while low < high and nums[low] <= pivot:
                    low += 1
                if low < high:
                    nums[high] = nums[low]
                    high -= 1

            nums[low] = pivot

            if k == low:
                return nums[k]
            elif k > low:
                next_low = low + 1
            else:
                next_high = low - 1

if __name__ == '__main__':
    s = Solution()
    print s.median([4,5])
    print s.median([4, 5, 1, 2, 3])
    print s.median([7,9,4,5])

