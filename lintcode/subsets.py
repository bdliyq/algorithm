#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/subsets/

class Solution:
    def work_with_recursion(self, s, path, res):
        res.append(path[:])
        if len(s) == 0:
            return

        for i in xrange(len(s)):
            path.append(s[i])
            self.work_with_recursion(s[i+1:], path, res)
            path.pop()

    def work_with_iteration(self, s):
        ans = [[]]
        if not s:
            return ans

        for c in s:
            count = len(ans)
            for i in xrange(count):
                ac = ans[i][:]
                ac.append(c)
                ans.append(ac)

        return ans

    """
    @param S: The set of numbers.
    @return: A list of lists. See example.
    """
    def subsets(self, S):
        # write your code here
        # res = []
        # self.work_with_recursion(sorted(S), [], res)
        # return res
        return self.work_with_iteration(sorted(S))

if __name__ == '__main__':
    s = Solution()
    print s.subsets([1,2,3])
    print s.subsets([])
