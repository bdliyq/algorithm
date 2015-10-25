#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/subsets/

class Solution:
    def work_with_recursion(self, s, path, res):
        res.append(path)
        if len(s) == 0:
            return

        for i in xrange(len(s)):
            path_copy = path[:]
            path_copy.append(s[i])
            self.work_with_recursion(s[i+1:], path_copy, res)

    """
    @param S: The set of numbers.
    @return: A list of lists. See example.
    """
    def subsets(self, S):
        # write your code here
        res = []
        self.work_with_recursion(sorted(S), [], res)
        return res

if __name__ == '__main__':
    s = Solution()
    print s.subsets([1,2,3])
    print s.subsets([])
