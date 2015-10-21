#!/usr/bin/env python
# encoding: utf-8

# Question: https://leetcode.com/problems/combination-sum-ii/

class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        stack = []
        res = []
        exist = set()
        for i in xrange(len(candidates)):
            if candidates[i] not in exist and target-candidates[i] >= 0:
                stack.append([[i], target-candidates[i]])
                exist.add(candidates[i])

        while stack:
            path, left = stack.pop()
            if left == 0:
                r = []
                for i in path:
                    r.append(candidates[i])
                res.append(r)
            elif left > 0:
                exist = set()
                for i in xrange(path[-1]+1, len(candidates)):
                    if candidates[i] not in exist and left >= candidates[i]:
                        path_copy = path[:]
                        path_copy.append(i)
                        stack.append([path_copy, left-candidates[i]])
                        exist.add(candidates[i])

        return res



if __name__ == '__main__':
    s = Solution()
    print s.combinationSum2([6,7,2,3], 7)
    print s.combinationSum2([10,1,2,7,6,1,5], 8)

