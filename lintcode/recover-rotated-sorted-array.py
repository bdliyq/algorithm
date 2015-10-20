#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/recover-rotated-sorted-array/

class Solution:
    def rotate(self, nums, start, end):
        i, j = start, end
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

    """
    @param nums: The rotated sorted array
    @return: nothing
    """
    def recoverRotatedSortedArray(self, nums):
        # write your code here
        if len(nums) <= 1:
            return

        i = 1
        while i < len(nums) and nums[i] >= nums[i-1]:
            i += 1
        if i == len(nums):
            return

        self.rotate(nums, 0, i-1)
        self.rotate(nums, i, len(nums)-1)
        self.rotate(nums, 0, len(nums)-1)

if __name__ == '__main__':
    s = Solution()
    nums = [1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    # nums = [4, 5, 1, 2, 3]
    s.recoverRotatedSortedArray(nums)
    print nums
