#!/usr/bin/env python
# encoding: utf-8

# Question: https://leetcode.com/problems/combination-sum-iii/

class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        stack = []
        res = []
        for i in xrange(1, 10):
            if n-i >= 0:
                stack.append([[i], n-i])

        while stack:
            path, left = stack.pop()
            if left == 0 and len(path) == k:
                res.append(path)
            if left > 0 and len(path) < k:
                for i in xrange(path[-1]+1, 10):
                    if left >= i:
                        path_copy = path[:]
                        path_copy.append(i)
                        stack.append([path_copy, left-i])

        return res

if __name__ == '__main__':
    s = Solution()
    print s.combinationSum3(3, 9)
