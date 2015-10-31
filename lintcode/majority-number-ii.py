#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/majority-number-ii/

class Solution:
    """
    @param nums: A list of integers
    @return: The majority number occurs more than 1/3
    """
    def majorityNumber(self, nums):
        # write your code here
        candidate1 = 0
        candidate2 = 0
        count1 = 0
        count2 = 0

        for n in nums:
            if count1 != 0 and n == candidate1:
                count1 += 1
            elif count2 != 0 and n == candidate2:
                count2 += 1
            elif count1 != 0 and count2 != 0:
                count1 -= 1
                count2 -= 1
            elif count1 == 0:
                count1 = 1
                candidate1 = n
            elif count2 == 0:
                count2 = 1
                candidate2 = n

        count1 = nums.count(candidate1)
        count2 = nums.count(candidate2)

        if count1 > count2:
            return candidate1
        return candidate2


