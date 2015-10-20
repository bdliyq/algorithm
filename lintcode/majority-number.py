#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/majority-number/

class Solution:
    """
    @param nums: A list of integers
    @return: The majority number
    """
    def majorityNumber(self, nums):
        # write your codeare
        if len(nums) == 0:
            return 0

        count = 1
        last_num = nums[0]

        for n in nums[1:]:
            if n == last_num:
                count += 1
            else:
                count -= 1
                if count == 0:
                    last_num = n
                    count += 1

        return last_num

if __name__ == '__main__':
    s = Solution()
    print s.majorityNumber([1, 1, 1, 1, 2, 2, 2])
