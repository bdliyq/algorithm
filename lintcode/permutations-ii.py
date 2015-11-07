#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/permutations-ii/

class Solution:
    def helper(self, nums, visited, path, ans):
        if len(path) == len(nums):
            ans.append(path[:])
            return

        existed = set()
        for i in xrange(len(nums)):
            if i in visited or nums[i] in existed:
                continue

            visited.add(i)
            existed.add(nums[i])
            path.append(nums[i])
            self.helper(nums, visited, path, ans)
            path.pop()
            visited.remove(i)

    """
    @param nums: A list of integers.
    @return: A list of unique permutations.
    """
    def permuteUnique(self, nums):
        # write your code here
        if not nums:
            return []

        ans = []
        self.helper(nums, set(), [], ans)
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.permuteUnique([1,2,2])
