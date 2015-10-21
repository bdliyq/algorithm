#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/combination-sum/

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        # write your code here
        candidates.sort()
        stack = []
        res = []
        for i in xrange(len(candidates)):
            if target-candidates[i] >= 0:
                stack.append([[i], target-candidates[i]])

        while stack:
            path, left = stack.pop()
            if left == 0:
                r = []
                for i in path:
                    r.append(candidates[i])
                res.append(r)
            elif left > 0:
                for i in xrange(path[-1], len(candidates)):
                    if left >= candidates[i]:
                        path_copy = path[:]
                        path_copy.append(i)
                        stack.append([path_copy, left-candidates[i]])

        return res



if __name__ == '__main__':
    s = Solution()
    print s.combinationSum([6,7,2,3], 7)
