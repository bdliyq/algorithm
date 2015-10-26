#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/

class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, num):
        # write your code here
        if len(num) == 0:
            return 0
        if num[0] < num[-1]:
            return num[0]

        l = 0
        r = len(num) - 1

        while l+1 < r:
            m = l + (r-l)/2
            if num[m] > num[l]:
                l = m
            else:
                r = m
        return min(num[l], num[r])

if __name__ == '__main__':
    s = Solution()
    print s.findMin([1,2,3])
