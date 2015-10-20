#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/binary-search/

class Solution:
    # @param nums: The integer array
    # @param target: Target number to find
    # @return the first position of target in nums, position start from 0
    def binarySearch(self, nums, target):
        # write your code here
        if len(nums) == 0:
            return -1

        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + (high - low)/2
            if nums[mid] == target:
                if mid == 0:
                    return 0
                for i in xrange(mid - 1, -1, -1):
                    if nums[i] == target:
                        continue
                    else:
                        return i+1
            elif nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1

        return -1

if __name__ == '__main__':
    s = Solution()
    # print s.binarySearch([1, 2, 3, 3, 4, 5, 10], 6)
    print s.binarySearch([1,4,4,5,7,7,8,9,9,10], 1)
