#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/permutations/

class Solution:
    def helper(self, nums, visited, path, ans):
        if len(path) == len(nums):
            ans.append(path[:])
            return

        for i in xrange(len(nums)):
            if nums[i] in visited:
                continue
            visited.add(nums[i])
            path.append(nums[i])
            self.helper(nums, visited, path, ans)
            visited.remove(nums[i])
            path.pop()

    """
    @param nums: A list of Integers.
    @return: A list of permutations.
    """
    def permute(self, nums):
        # write your code here
        if not nums:
            return []

        ans = []
        self.helper(nums, set(), [], ans)
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.permute([1,2,3])

