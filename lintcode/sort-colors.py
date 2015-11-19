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
        r = 0
        while r <= q:
            if nums[r] == 0:
                if r > p:
                    nums[r], nums[p] = nums[p], nums[r]
                else:
                    r += 1
                p += 1
            elif nums[r] == 1:
                r += 1
            else:
                if r < q:
                    nums[r], nums[q] = nums[q], nums[r]
                    q -= 1
                else:
                    break

if __name__ == '__main__':
    s = Solution()
    for array in [[0,0,0,1,1,0,0,1,0],[2,0,0,1,2,0,2],[1,0,1,2],[0,2,2,2,2,1,0,1,0,0,0,1,0,2,0]]:
        s.sortColors(array)
        print array

