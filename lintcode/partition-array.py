#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/partition-array/

class Solution:
    """
    @param nums: The integer array you should partition
    @param k: As description
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        # write your code here
        # you should partition the nums by k
        # and return the partition index as description
        i = 0
        for j in xrange(len(nums)):
            if nums[j] < k:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1

        for i in xrange(len(nums)):
            if nums[i] >= k:
                return i
        return len(nums)

if __name__ == '__main__':
    s = Solution()
    print s.partitionArray([3,2,2,1], 2)
    print s.partitionArray([3,2,2,1], 4)
    print s.partitionArray([3,2,2,1], 0)
