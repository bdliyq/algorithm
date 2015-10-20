#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sort-colors/

class Solution:
    """
    @param nums: A list of integer which is 0, 1 or 2
    @return: nothing
    """
    def sortColors(self, nums):
        # write your code here
        if len(nums) <= 1:
            return

        p, q = 0, len(nums) - 1
        r = p
        while r <= q:
            if nums[r] == 0:
                nums[r], nums[p] = nums[p], nums[r]
                while p < len(nums) and nums[p] == 0:
                    p += 1
                if r < p:
                    r = p
            elif nums[r] == 1:
                r += 1
            else:  # nums[r] == 2
                nums[r], nums[q] = nums[q], nums[r]
                while q >= 0 and nums[q] == 2:
                    q -= 1
        print p,r,q,nums
        return r

if __name__ == '__main__':
    s = Solution()
    for array in [[0,0,0,1,1,0,0,1,0],[2,0,0,1,2,0,2],[1,0,1,2],[0,2,2,2,2,1,0,1,0,0,0,1,0,2,0]]:
        r = s.sortColors(array)

