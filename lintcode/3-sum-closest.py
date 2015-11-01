#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/3-sum-closest/

import sys
class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @param target : An integer
    @return : return the sum of the three integers, the sum closest target.
    """
    def threeSumClosest(self, numbers, target):
        # write your code here
        ans = target
        min_diff = sys.maxint
        numbers.sort()
        for i in xrange(len(numbers)):
            l = i+1
            r = len(numbers)-1
            while l < r:
                tmp = numbers[i] + numbers[l] + numbers[r]
                if tmp == target:
                    return target
                else:
                    diff = abs(tmp-target)
                    if diff < min_diff:
                        min_diff = diff
                        ans = tmp
                    if tmp < target:
                        l += 1
                    else:
                        r -= 1
        return ans

